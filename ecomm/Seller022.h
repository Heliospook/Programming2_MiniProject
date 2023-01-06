#ifndef SELLER022_h
#define SELLER022_H

#include <iostream>

#include"Seller.h"
#include"Platform.h"
#include"Globals.h"

#include"Book.h"
#include"Mobile.h"
#include"Products.h"

using namespace std;

class Seller022: public Seller {
private:
    map<Globals::Category, map<string, Products*>> products;
public:
    Seller022(string);
    void add_platform(Platform*) override;
    void add_product(Products* prod, Globals::Category category) override;
    vector<Products*> find_products(Globals::Category) override;
    bool buy_product(string, int) override;
};

#endif