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
    virtual Payable *Clone(){return nullptr;}
    Payable(double k):PayCost(k){}
    Payable():PayCost(0.0){}
};
class Worker:public Payable{
public:
    using Payable::Payable;
};
class Employee:public Worker{
public:
    using Worker::Worker;
    virtual Payable *Clone(){return nullptr;}

};
class HourlyEmployee:public Employee{
    int NumberOfHours;
    double PayPerHour;
public:
    HourlyEmployee(int n, double pph)
        :NumberOfHours(n),PayPerHour(pph), Employee((double)n*pph){}
    double GetPayCost()override{
        cout<<"Hourly Employee: "<<(double) NumberOfHours*PayPerHour<<"\n";
        return (double) NumberOfHours*PayPerHour;
    }
    Payable *Clone(){return new HourlyEmployee(*this);}
};
class SalaryEmployee:public Employee{
public:
    SalaryEmployee(double k):Employee(k){}
    SalaryEmployee():Employee(0.0){}
    Payable *Clone(){return new SalaryEmployee(*this);}

};
class CommisionEmployee:public SalaryEmployee{
    double Sales;
    double CommsionRate;
public:
    using SalaryEmployee::SalaryEmployee;
    Payable *Clone(){return new CommisionEmployee(*this);}
    double GetPayCost()override{
        return SalaryEmployee::GetPayCost()+Sales*CommsionRate;
    }

};
class LaborerEmployee:public HourlyEmployee{
public:
    using HourlyEmployee::HourlyEmployee;
    Payable *Clone()override{return new LaborerEmployee(*this);}
};
class Volunteer:public Worker{
public:
    Volunteer():Worker(0.0){}
    Volunteer(double k):Worker(0.0){}
    double GetPayCost()override{return 0.0;}
    Payable *Clone()override{return new Volunteer(*this);}
};
class Item{
    double Price;
public:
   Item(double k):Price(k){}
   virtual Item *Clone(){return nullptr;}
   virtual double GetPrice(){return Price;}
       double PayCost;
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
class Invoice: Payable{
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
};
class Payroll{
private:
    vector<Payable *> Cost;
public:


};


int main(){
    return 0;
}