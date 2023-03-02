//
// Created by ahmed-kashkoush on 2/28/23.
//
#include "macros.h"
class Address{
private:
    string name, city;
public:
    void SetName(const string &a){name=a;}
    void SetCity(const string &a){city=a;}
    void SetAddress(const string &a, const string&b){
        SetName(a);
        SetCity(b);
    }
    const string &GetName()const{return name;}
    const string &GetCity()const{return city;}
};
class Package{
private:
    Address Sender, receiver;
    int weight, price_per_kg;

public:
    Package():weight(0),price_per_kg(0){}
    Package(Address s,Address r, int weight, int price):
    Sender(std::move(s)),receiver(std::move(r)),weight(weight),price_per_kg(price){}
    int GetWeight()const{return weight;}
    int GetPricePerKg()const{return price_per_kg;}
    int GetTotalCost()const {return weight*price_per_kg;}
    const Address &GetSender()const{return Sender;}
    const Address &GetReceiver()const{return receiver;}
    int setWeight(int a){weight=a;}
    int setPricePerKg(int a){price_per_kg=a;}
    void setSender(const string &a, const string &b){Sender.SetAddress(a, b);}
    void setReceiver(const string &a, const string &b){receiver.SetAddress(a, b);}

};
class TwoDayPackage:public Package{
private:
    int AddedFee;
public:
    TwoDayPackage(int AddFee, Address s,Address r, int weight, int price):
        AddedFee(AddFee),Package(s, r, weight,price){}
    TwoDayPackage():
        AddedFee(0), Package(){}
    int GetTotalCost()const{return Package::GetTotalCost()+AddedFee;}
    int GetAddedFee()const{return AddedFee;}
    void SetAddedFee(int value){AddedFee=value;}

};
class HeavyPackage:public Package{
private:
    int extra;
    const int heavy_weight_limit;
public:
    HeavyPackage(int AddFee, Address s,Address r, int weight, int price):
            extra(AddFee),heavy_weight_limit(100),Package(s, r, weight,price){}
    HeavyPackage():
            extra(0),heavy_weight_limit(100), Package(){}
    int GetTotalCost()const{
        int a=0;
        if(Package::GetWeight()>heavy_weight_limit)
            a=(Package::GetWeight()-heavy_weight_limit)*extra;
        return Package::GetTotalCost()+a;
    }
    int GetExtra()const{return extra;}
    void SetExtra(int ex){extra=ex;}

};
class PaymentCard{
private:
    string cardNumber;
    string ExpiryDate;
public:
    PaymentCard(){}
    PaymentCard(const string &a, const string &b):
        cardNumber(a),ExpiryDate(b){}
    // Getters and setters

};
class shipment{
private:
    vector<Package> v;
    vector<TwoDayPackage> v2;
    vector<HeavyPackage> v3;
    int TotalShipmentPrice;
    PaymentCard card;

public:
    shipment():TotalShipmentPrice(0){}
    void AddStandaredPackage(const Package &a){v.push_back(a);TotalShipmentPrice+=a.GetTotalCost();}
    void AddTwoDayPackage(const TwoDayPackage &a){v2.push_back(a);TotalShipmentPrice+a.GetTotalCost();}
    void AddHeavyPackage(const HeavyPackage &a){v3.push_back(a);TotalShipmentPrice+a.GetTotalCost();}
    int GetTotalShipmentPrice()const{return TotalShipmentPrice;}
};
class Customer{
private:
    vector<shipment> v;
    vector<PaymentCard> credit;
    vector<PaymentCard> debit;
public:
    void AddShipment(){

    }
};