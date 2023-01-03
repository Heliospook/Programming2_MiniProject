#include <bits/stdc++.h>
#include "Globals.h"
#include "Seller.h"

using namespace std;

int main() {

	// showcase of the working of seller and global 
	Seller* seller1 = new Seller("1");  // create a dummy seller for testing
	Globals global;  // global class
	global.category = Globals::Mobile;  // one way of assigning enum value
	Globals::Category temp = global.category;  // another way of assigning enum value
	cout << seller1->find_products(temp) << endl;  // prints out "Mobile"
	temp = Globals::Book;  // another way of assigning enum value
	cout << seller1->find_products(temp) << endl; // print out "Book"
}