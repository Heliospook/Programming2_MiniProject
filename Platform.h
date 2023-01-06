#ifndef PLATFROM_H
#define PLATFROM_H

#include<bits/stdc++.h>

class Seller;

using namespace std;

class Platform {
protected:
	vector<Seller*> sellers;
	map<string,int> done_req;

public:
	virtual bool add_seller(Seller* seller){};
	virtual void process_requests(){};
};

#endif