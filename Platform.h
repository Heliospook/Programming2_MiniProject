#ifndef PLATFROM_H
#define PLATFROM_H

#include<bits/stdc++.h>

class Seller;

using namespace std;

class Platform {
private:
	vector<Seller*> sellers;

public:
	bool add_seller(Seller* seller);
	void process_requests();
};

#endif