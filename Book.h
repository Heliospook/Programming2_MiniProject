#ifndef BOOK_H
#define BOOK_H

#include<bits/stdc++.h>
#include"Products.h"
#include"Globals.h"

using namespace std;

class Book: public Products {
private:
    string product_id, name;
    Globals::Category category = Globals::Category::Book;
    float price;
    int quantity;

public:
    Book(string prod_id, string nam, float prc, int qnty);
    Globals::Category get_category() override;
    string get_name()  override;
    string get_product_id() override;
    float get_price() override;
    int get_quantity() override;
    void set_quantity(int am) override;
};

#endif