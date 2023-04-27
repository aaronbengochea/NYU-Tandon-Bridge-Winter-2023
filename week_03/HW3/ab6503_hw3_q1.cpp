#include <iostream>
using namespace std;

const float MEMBER_DISCOUNT = .10;
const float PROMOTION_DISCOUNT = .50;

int main () {
    int itemOne, itemTwo;
    float basePrice, bogoPrice, adjustedPrice, finalPrice, taxRate;
    char clubMember;

    cout << "Enter price of first item: ";
    cin >> itemOne;

    cout << "Enter price of second item: ";
    cin >> itemTwo;

    cout << "Does the customer have a club card? (Y/N): ";
    cin >> clubMember;

    cout << "Enter tax rate, e.g 5.5 for 5.5% tax: ";
    cin >> taxRate;

    basePrice = itemOne + itemTwo;

    if (itemOne >= itemTwo) {
        itemTwo = itemTwo * PROMOTION_DISCOUNT;
    }
    else {
        itemOne = itemOne * PROMOTION_DISCOUNT;
    }

    bogoPrice = itemOne + itemTwo;
    
    if ((clubMember == 'Y') || (clubMember == 'y')){
        adjustedPrice = bogoPrice - (MEMBER_DISCOUNT * bogoPrice);
    }
    else {
        adjustedPrice = bogoPrice;
    }

    finalPrice = adjustedPrice + (adjustedPrice * (taxRate / 100.0));

    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << adjustedPrice << endl;
    cout << "Total price: " << finalPrice << endl;



    return 0;
}