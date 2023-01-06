#include<bits/stdc++.h>
#include"./demo/DemoPlatform.h"
#include"./ecomm/Seller.h"
#include"./ecomm/Seller016.h"
#include"./ecomm/Book.h"
#include"./ecomm/Products.h"
#include"./ecomm/Globals.h"

#include"./demo/DemoPlatform.cpp"
#include"./ecomm/Seller.cpp"
#include"./ecomm/Seller016.cpp"
#include"./ecomm/Book.cpp"
#include"./ecomm/Products.cpp"
#include"./ecomm/Globals.cpp"


using namespace std;

int main() {

    Platform* pf = new DemoPlatform();
    Seller* seller016 = new Seller016("Seller016");
    
    seller016->add_platform(pf);

    while(1) {
        string s;
        cin >> s;
        if (s == "check") {
            pf->process_requests();
        }
    }

}