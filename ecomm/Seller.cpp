#include <bits/stdc++.h>
#include "Globals.h"
#include "Seller.h"


using namespace std;

Seller::Seller(string id) {
	my_id = id;
}

string Seller::get_id() {
	return my_id;
}