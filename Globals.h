#ifndef GLOBALS_H
#define GLOBALS_H

#include<bits/stdc++.h>
using namespace std;

class Globals {
public:
	enum Category {
		Mobile,
		Book
	};

	Category category;

	string get_category_name(Category c);

	static string to_platfrom;
	static string from_platform;
};

#endif