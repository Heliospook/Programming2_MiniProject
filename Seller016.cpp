#include<bits/stdc++.h>
#include"Seller.h"
#include"Seller016.h"
#include"Products.h"

Seller016::Seller016(string id):Seller(id){};

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