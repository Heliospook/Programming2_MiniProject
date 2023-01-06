#include<bits/stdc++.h>
#include "DemoPlatform.h"
#include "../ecomm/Seller.h"
#include "../ecomm/Globals.h"
#include "../ecomm/Products.h"
using namespace std;

bool DemoPlatform::add_seller(Seller* seller) {
    // error check
    if (seller == NULL) { 
        return false;
    }
    sellers.push_back(seller);
    return true;
}

void DemoPlatform::process_requests() {
    Globals global;
    ifstream file(global.to_platfrom);
    freopen(global.from_platform.c_str(), file_open_mode.c_str(), stdout);
    file_open_mode = "a";
    string s;

    vector<string> req;

    while(getline(file,s)) {
        req.push_back(s);
    }


    // processing requests
    for (auto s1 : req) {
        
        vector<string> v;
        istringstream ss(s1);
        string temp;

        while (ss >> temp) {
            v.push_back(temp);
        }

        if (done_req.find({v[0],v[1]}) != done_req.end()) {
            continue;
        }
        done_req[{v[0],v[1]}] = 1;

        if (v[2] == "Start") {
            cout << v[0] << " " << v[1] << " ";  // prints <Portal ID> <RequestID>
            for (Globals::Category cat = Globals::Category::Enum_start; cat != Globals::Category::Enum_end; cat = static_cast<Globals::Category>(static_cast<int>(cat) + 1)) {
                if (cat != Globals::Category::Enum_start)cout << global.get_category_name(cat) << " ";
		    }
            cout << "\n";
        }

        else if (v[2] == "List") {
            
            Globals::Category category = global.get_category_enum(v[3]);
            for (Seller* seller : sellers) {
                
                vector<Products*> products = seller->find_products(category);
                for (auto prod : products) {
                    cout << v[0] << " " << v[1] << " ";  // prints <Portal ID> <RequestID>
                    cout << prod->get_name() << " " << prod->get_product_id() << " " << prod->get_price() << " " << prod->get_quantity() << "\n";
                }
            }
        }

        else if (v[2] == "Buy") {
            int quantity;
            stringstream ss(v[4]);
            ss >> quantity;
            cout << v[0] << " " << v[1] << " ";  // prints <Portal ID> <RequestID>
            int flag = 0;
            for (Seller* seller : sellers) {
                if (seller->buy_product(v[3], quantity)) {
                    flag = 1;
                    cout << "Success" << "\n";
                    break;
                }
            }
            if (flag == 0) {
                cout << "Failure" << "\n";
            }
        }

    }
}