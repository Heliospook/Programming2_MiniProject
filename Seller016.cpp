#include<bits/stdc++.h>
#include"Seller.h"
#include"Seller016.h"
#include"Products.h"
#include"Book.h"

Seller016::Seller016(string id):Seller(id){
    Products* book = new Book("book1", "book016", 69.69, 69);
    Products* book1 = new Book("book2", "book017", 69.699, 690);
    Products* book2 = new Book("book3", "book018", 69.6999, 691);
    Products* book3 = new Book("book4", "book019", 69.70, 693);
    Products* book4 = new Book("book5", "book020", 69.6969, 6969);

    product_list.push_back(book);
    product_list.push_back(book1);
    product_list.push_back(book2);
    product_list.push_back(book3);
    product_list.push_back(book4);
};

void Seller016::add_platform(Platform* the_platform) {
    clog << "Added platform\n" << endl;
    the_platform->add_seller(this);
}

void Seller016::add_product(Products* prod) {
    clog << "added product\n";
    product_list.push_back(prod);
};

vector<Products*> Seller016::find_products(Globals::Category which_one) {
    vector<Products*> filtered;
    Globals global;
    for (auto prod : product_list) {
        if (prod->get_category() == which_one) {
            filtered.push_back(prod);
        }
    }
    return filtered;
}

bool Seller016::buy_product(string product_id, int quantity) {
    int available = 0;

    for (auto prod : product_list) {
        if (prod->get_product_id() == product_id) {
            available = prod->get_quantity();
        }
    }

    if (available < quantity) {
        return false;
    }
    vector<Products*> new_list;
    int saved = available - quantity;
    for (auto prod : product_list) {
        if (prod->get_product_id() == product_id) {
            prod->set_quantity(saved);
            new_list.push_back(prod);
        }
        else {
            new_list.push_back(prod);
        }
    }
    product_list = new_list;
    return true;
}