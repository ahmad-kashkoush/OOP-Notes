#include<iostream>
#include<vector>
using namespace std;

// PayPalCreditCard and PayPalOnlinePaymentAPI are NOT our code. They are Paypal API.
// We have to use them to be able to call PayPal service


class PayPalCreditCard {
public:
    string name;
    string address;
    string id;
    string expire_date;
    int ccv;
};

class PayPalOnlinePaymentAPI {
public:
    void SetCardInfo(const PayPalCreditCard* const card) {
    }
    bool MakePayment(double money) {
        return true;
    }
};

class StripeUserInfo {
public:
    string name;
    string address;
};

class StripeCardInfo {
public:
    string id;
    string expire_date;
};

class StripePaymentAPI {
public:
    bool static WithDrawMoney(StripeUserInfo user,
                              StripeCardInfo card,
                              double money) {
        return true;
    }
};

class TransactionInfo {
public:
    double required_money_amount;
    string name;
    string address;
    string id;
    string expire_date;
    int ccv;
};
class IPayment{

public:
    IPayment()=default;
    virtual void SetUserInfo(const string&, const string &)=0;
    virtual void SetCardInfo(const string &, const string &, int ccv)=0;
    virtual bool MakePayment(double k)=0;
};
class PaypalPayment:public IPayment{
    PayPalCreditCard card;
    PayPalOnlinePaymentAPI PP;
public:
    PaypalPayment()=default;
    void SetCardInfo(const string &id, const string &expireDate, int ccv) override{
            card.id=id;
            card.expire_date=expireDate;
            card.ccv=ccv;
    }
    void SetUserInfo(const string &name, const string &address) override{
        card.name=name;
        card.address=address;
    }
    bool MakePayment(double d){
        PP.SetCardInfo(&card);
        return PP.MakePayment(d);
    }

};
class StripePayment:public IPayment{
private:
    StripeCardInfo card;
    StripeUserInfo usr;
    StripePaymentAPI SS;
public:
    StripePayment()=default;
    void SetCardInfo(const string &id, const string &expireDate, int ccv) override{
        card.id=id;
        card.expire_date=expireDate;
    }
    void SetUserInfo(const string &name, const string &address) override{
        usr.name=name;
        usr.address=address;
    }
    bool MakePayment(double d)override{
        return StripePaymentAPI::WithDrawMoney(usr, card, d);
    }

};
class Factory{
public:
    static IPayment *GetPaymentMethod(){
        if(true)
            return new PaypalPayment;
        else
            return new StripePayment;
    }
};

class Craigslist {
    IPayment *p;
public:
    Craigslist(){
       p=Factory::GetPaymentMethod();
    }
    bool Pay(TransactionInfo t) {
        p->SetCardInfo(t.id, t.expire_date, t.ccv);
        p->SetUserInfo(t.name, t.address);
        return p->MakePayment(t.required_money_amount);
    }
};


int main()
{
    return 0;
}
/*
 forest[cat-dog-lion]
 animal---> foreset


 * */