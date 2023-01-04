#ifndef SELLER_H
#define SELLER_H

#include<bits/stdc++.h>
#include"Globals.h"
#include"Products.h"

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
	virtual vector<Products*> find_products(Globals::Category which_one){
		
	};

	virtual bool buy_product(string product_id, int quantity) {return false;};

};

#endif