#include<bits/stdc++.h>
#include "DemoPlatform.h"
#include "Seller.h"
#include "Globals.h"
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
    freopen(global.to_platfrom.c_str(), "r", stdin);
    freopen(global.from_platform.c_str(), "w", stdout);
    string s;
    getline(cin,s);

    // processing requests
    while (s.size()) {
        vector<string> v;
        istringstream ss(s);
        string temp;

        while (ss >> temp) {
            v.push_back(temp);
        }

        if (done_req.find(v[2]) != done_req.end()) {
            getline(cin,s);
            continue;
        }

        if (v[2] == "Start") {
            cout << v[0] << " " << v[1] << " ";  // prints <Portal ID> <RequestID>
            for (Globals::Category cat = Globals::Category::Enum_start; cat != Globals::Category::Enum_end; cat = static_cast<Globals::Category>(static_cast<int>(cat) + 1)) {
                cout << global.get_category_name(cat) << " ";
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
            cout << v[0] << " ";  // prints <Portal ID> <RequestID>
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

        done_req[v[1]] = true;

        getline(cin,s);
    }
}