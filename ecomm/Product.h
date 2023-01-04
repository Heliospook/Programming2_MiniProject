#include <iostream>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
    public:
        virtual string getCategory(){}
        virtual string getName(){}
        virtual int getProductID(){}
        virtual double getPrice(){}
        virtual int getQuantity(){}
};

#endif 