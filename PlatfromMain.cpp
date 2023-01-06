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
    
    seller016->add_platform(pf);

    while(1) {
        string s;
        cin >> s;
        if (s == "check") {
            pf->process_requests();
        }
    }

}