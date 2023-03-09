//
// Created by ahmed-kashkoush on 3/5/23.
//
#include<iostream>
#include<vector>
using namespace std;
class Payable{
    double PayCost;
public:
    virtual double GetPayCost(){
        return PayCost;
    }
    virtual string GetName()=0;//
    virtual Payable *Clone()=0;
    Payable(double k):PayCost(k){}
    Payable():PayCost(0.0){}
};
class Worker:public Payable{
public:
    using Payable::Payable;
    virtual string GetName()=0;
};
class Employee:public Worker{
public:
    using Worker::Worker;
    virtual Payable *Clone()=0;
    virtual string GetName()=0;
};
class HourlyEmployee:public Employee{
    int NumberOfHours;
    double PayPerHour;
public:
    HourlyEmployee(int n, double pph)
        :NumberOfHours(n),PayPerHour(pph), Employee((double)n*pph){}
    double GetPayCost()override{
//        cout<<"Hourly Employee: "<<(double) NumberOfHours*PayPerHour<<"\n";
        return (double) NumberOfHours*PayPerHour;
    }
    virtual string GetName(){return string("Hourly Employee");}
    Payable *Clone(){return new HourlyEmployee(*this);}
};
class SalaryEmployee:public Employee{
public:
    SalaryEmployee(double k):Employee(k){}
    SalaryEmployee():Employee(0.0){}
    virtual string GetName(){return string("Salary Employee");}
    Payable *Clone(){return new SalaryEmployee(*this);}

};
class CommisionEmployee:public SalaryEmployee{
    double Sales;
    double CommsionRate;
public:
    CommisionEmployee(double salary,double sales, double commisionrate)
        :SalaryEmployee(salary),Sales(sales), CommsionRate(commisionrate){}
    Payable *Clone(){return new CommisionEmployee(*this);}
    string GetName()override{return string("Commision Employee");}
    double GetPayCost()override{
        return SalaryEmployee::GetPayCost()+Sales*CommsionRate;
    }

};
class LaborerEmployee:public HourlyEmployee{
public:
    using HourlyEmployee::HourlyEmployee;
    Payable *Clone()override{return new LaborerEmployee(*this);}
    string GetName()override{return string("Laborer Employee");}
};
class Volunteer:public Worker{
public:
    Volunteer():Worker(0.0){}
    Volunteer(double k):Worker(0.0){}
    double GetPayCost()override{return 0.0;}
    string GetName()override{return string("Volunteer Employee");}
    Payable *Clone()override{return new Volunteer(*this);}
};
class Item{
    double Price;
public:
   Item(double k):Price(k){}
   virtual Item *Clone()=0;
   virtual double GetPrice(){return Price;}
};
class book: public Item{
public:
    using Item::Item;
    Item *Clone()override{return new book(*this);}
};
class Food:public Item{
public:
    using Item::Item;
    Item *Clone()override{return new Food(*this);}
};
class Invoice:public Payable{
    vector<Item *> Items;
public:
    void AddItem(Item *item){
        Items.emplace_back(item->Clone());
    }
    double GetPayCost()override{
        double ans=0.0;
        for(auto item:Items)
            ans+=item->GetPrice();
        return ans;
    }
    virtual string GetName(){return string("Paid Items");}
    Payable *Clone(){return new Invoice(*this);}
    ~Invoice(){
        for(auto item:Items)
            delete item;
        Items.clear();
    }
};
class Payroll{
private:
    // payable -->worker -->[employee->[hourly-->laborer,salarided->commision],volunteer]
    // payable --> invoice[contain(item-->[food, books])
    vector<Payable *> Payables;// worker and invoice
public:
        void AddPayable(Payable *payable){
            Payables.emplace_back(payable->Clone());//hourly
        }
        void Pay(){
            for(const auto payable: Payables){
                cout<<payable->GetName()<<" "<<payable->GetPayCost()<<"\n";
            }
        }
        ~Payroll(){
            for(auto payable:Payables)
                delete payable;
            Payables.clear();
        }

};
class Company{
private:
    Payroll payroll;
    void Add(){
        Invoice *k=new Invoice;
        k->AddItem(new book(20.0));
        k->AddItem(new book(300.0));
        k->AddItem(new Food(350.0));
        k->AddItem(new Food(220.0));
        payroll.AddPayable(new SalaryEmployee(50.0));
        payroll.AddPayable(new HourlyEmployee(8, 13.0));
        payroll.AddPayable(new LaborerEmployee(9, 20.5));
        payroll.AddPayable(new CommisionEmployee(10.20, 15, .15));
        payroll.AddPayable(new Volunteer);

        payroll.AddPayable(k);
        


    }
public:
    Company()= default;
    void Run(){
        Add();
        payroll.Pay();
    }

};

int main(){
    Company company;
    company.Run();
    return 0;
}