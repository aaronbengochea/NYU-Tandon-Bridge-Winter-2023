#include <iostream>
#include <vectors>
using namespace std;

class Discount{
    double amt;
    double pct;
public:
    Discount() : amt(0), pct(0) {}
    Discount(double amt, double pct) : amt(amt), pct(pct) {}
    double getAmt() const;
    double getPct() const;
    virtual double calcFinalDiscount(double originalPrice) = 0;
}

class SingleValueDiscount : public Discount {
    SingleValueDiscount() : discount() {}
    SingleValueDiscount(double amt) : discount(amt, 0) {}
    double calcFinalDiscount(double originalPrice);
}

class SinglePercentDiscount : public Discount {
    SinglePercentDiscount() : discount() {}
    SinglePercentDiscount(double pct) : discount(0,pct) {}
    double calcFinalDiscount(double originalPrice);
}

class MultiDiscount : public Discount {
    MultiDiscount() : discount() {}
    MultiDiscount(double amt, double pct) : discount(amt, pct) {}
    double calcFinalDiscount(double originalPrice);
}

class Order{
    vector<double> prices;
    vector<Discount*> discounts;
public:
    void addItem(double price, Discount* discount);
    double totalCost();
}



double SingleValueDiscount::calcFinalDiscount(double originalPrice){
    return getAmt();
}

double SinglePercentDiscount::calcFinalDiscount(double originalPrice){
    return originalPrice * getPct();
}

double MultiDiscount::calcFinalDiscount(double originalPrice){
    return (orignalPrice - getAmt()) * getPct() + getAmt();
}

void Order::addItem(double price, Discount* discount){
    prices.push_back(price);
    discounts.push_back(discount);
}

double Order::totalCost(){
    double totalCost = 0;
    

    for(int i = 0; i < prices.size(); i++){
        double itemDiscount = 0;
        if (discounts[i] != 0){
            itemDiscount = discounts[i]->calcFinalDiscount(prices[i]);
            totalCost += prices[i] - itemDiscount
        }

    }

    return totalCost;
}