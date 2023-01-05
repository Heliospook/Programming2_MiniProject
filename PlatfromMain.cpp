#include<bits/stdc++.h>
#include"DemoPlatform.h"
#include"Seller.h"
#include"Seller016.h"
#include"Book.h"
#include"Products.h"

using namespace std;

int main() {

    Platform* pf = new DemoPlatform();
    Seller* seller016 = new Seller016("Seller016");
    Products* book = new Book("book1", "book016", 69.69, 69);
    Products* book1 = new Book("book2", "book017", 69.699, 690);
    Products* book2 = new Book("book3", "book018", 69.6999, 691);
    Products* book3 = new Book("book4", "book019", 69.70, 693);
    Products* book4 = new Book("book5", "book020", 69.6969, 6969);


    seller016->add_platform(pf);
    seller016->add_product(book);
    seller016->add_product(book1);
    seller016->add_product(book2);
    seller016->add_product(book3);
    seller016->add_product(book4);

    while(1) {
        string s;
        cin >> s;
        if (s == "check") {
            pf->process_requests();
        }
    }

}