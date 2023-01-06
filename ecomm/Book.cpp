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

