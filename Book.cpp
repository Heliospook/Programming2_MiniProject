#include<bits/stdc++.h>
#include "Book.h"
#include "Globals.h"

using namespace std;

Book::Book(string nam, string prod_id, float prc, int qnty) {
    product_id = prod_id;
    name = nam;
    price = prc;
    quantity = qnty;
}

Globals::Category  Book::get_category() {
    return category;
}
string Book::get_name() {
    return name;
};
string Book::get_product_id() {
    return product_id;
};
float Book::get_price() {
    return price;
};
int Book::get_quantity() {
    return quantity;
};
void Book::set_quantity(int amt) {
    quantity = amt;
}
