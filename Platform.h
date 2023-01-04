#ifndef PLATFROM_H
#define PLATFROM_H

#include<bits/stdc++.h>

class Seller;

using namespace std;

class Platform {
protected:
	vector<Seller*> sellers;

public:
	virtual bool add_seller(Seller* seller){};
	virtual void process_requests(){};
};

#endif