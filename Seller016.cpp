#include<bits/stdc++.h>
#include"Seller.h"
#include"Seller016.h"
#include"Products.h"

Seller016::Seller016(string id):Seller(id){};

void Seller016::add_platform(Platform* the_platform) {
    cerr << "Added platform\n" << endl;
    the_platform->add_seller(this);
}

vector<Products*> Seller016::find_products(Globals::Category which_one) {
    vector<Products*> filtered;
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
        if (prod->get_product_id() == product_id) available++;
    }

    if (available < quantity) {
        return false;
    }
    vector<Products*> new_list;
    for (auto prod : product_list) {
        if (prod->get_product_id() == product_id) {
            if (available) {
                new_list.push_back(prod);
                available--;
            }
        }
        else {
            new_list.push_back(prod);
        }
    }
    product_list = new_list;
}