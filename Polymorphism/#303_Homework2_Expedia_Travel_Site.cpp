#include<iostream>
#include<vector>
#define el "\n"
using namespace std;
class Reservation{
public:
    virtual void GetName()=0;
    virtual double GetCost()=0;
    virtual Reservation *Clone() const =0;

};
class Flight:public Reservation{
private:
    double cost;
public:
    Flight(double cost): cost(cost){}
    double GetCost() override{
        return cost;
    }
    void GetName() override{
        cout<<"Flight-----------\n";
        cout<<"Total Cost: "<<GetCost();
    }
    Reservation *Clone()const override{
        return new Flight(*this);
    }
};
class Hotel: public Reservation{
private:
    double Nights, costPerNight;
public:
    Hotel(double Nights, double costPerNight):
        Nights(Nights),costPerNight(costPerNight){}
    void GetName() override{
        cout<<"Hotel----------------\n";
        cout<<"Nights:"<<Nights;
        cout<<"\ncostPerNight: "<<costPerNight;
        cout<<"\nTotalCost: "<<GetCost();

    }
    Reservation * Clone() const override{
        return new Hotel(*this);
    }
    double GetCost() override{
        return Nights * costPerNight;
    }
};
class Itinirary{
private:
    vector<Reservation *> reservation;
public:
    Itinirary()=default;
    void AddReservation(const Reservation &item){
        reservation.emplace_back(item.Clone());
    }
    void Info(){
        for(auto i:reservation) {
            i->GetName();
            cout<<el;
        }
    }
    double total_cost(){
        double sum=0;
        for(auto i:reservation)
            sum+=i->GetCost();
        return sum;
    }
    virtual Itinirary *Clone(){
        return new Itinirary(*this);
    }
};
class User{
private:
    vector<Itinirary *> Itininraries;
public:
    void AddItem(Itinirary *Item){
        Itininraries.emplace_back(Item->Clone());
    }
    void Info(){
        for(auto iti:Itininraries){
            cout<<"-------------------\n";
            iti->Info();
            cout<<"\n-----------------\n";
        }
    }
};
int main(){
    User u;
    // Prepare Itinirary
    Itinirary *iti=new Itinirary;
    iti->AddReservation(Hotel(10.0, 50.0));
    iti->AddReservation(Flight(10.0));
    u.AddItem(iti);
    u.Info();
}