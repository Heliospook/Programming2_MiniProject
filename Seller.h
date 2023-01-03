#ifndef SELLER_H
#define SELLER_H

#include<bits/stdc++.h>
#include"Globals.h"

using namespace std;

class Platform; // forward declaration to break the infinte space paradox

class Seller {
private:
	string my_id;
public:
	Seller(string id);

	string get_id();

	virtual void add_platform(Platform* the_platform){};

	// change return type to product after implementation of product
	virtual string find_products(Globals::Category which_one){
		Globals global1;
		return global1.get_category_name(which_one);  // for test purpose
	};

	virtual bool buy_product(string product_id, int quantity) {return false;};

};

#endif