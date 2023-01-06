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

    category_to_list_map[Globals::Category::Book].push_back(book);
    category_to_list_map[Globals::Category::Book].push_back(book1);
    category_to_list_map[Globals::Category::Book].push_back(book2);
    category_to_list_map[Globals::Category::Book].push_back(book3);
    category_to_list_map[Globals::Category::Book].push_back(book4);
};

void Seller016::add_platform(Platform* the_platform) {
    clog << "Added platform\n" << endl;
    the_platform->add_seller(this);
}

void Seller016::add_product(Products* prod, Globals::Category category) {
    clog << "added product\n";
    category_to_list_map[category].push_back(prod);
};

vector<Products*> Seller016::find_products(Globals::Category which_one) {
    return category_to_list_map[which_one];
}

bool Seller016::buy_product(string product_id, int quantity) {
    int available = 0;

    for (auto key_value : category_to_list_map) {
        for (auto prod : key_value.second) {
            if (prod->get_product_id() == product_id) {
                available = prod->get_quantity();
            }
        }
    }

    if (available < quantity) {
        return false;
    }
    
    int saved = available - quantity;
    for (auto &key_value : category_to_list_map) {
        vector<Products*> new_list;
        for (auto prod : key_value.second) {
            if (prod->get_product_id() == product_id) {
                prod->set_quantity(saved);
                new_list.push_back(prod);
            }
            else {
                new_list.push_back(prod);
            }
        }
        key_value.second = new_list;
        
    }
    return true;
}