#ifndef GLOBALS_H
#define GLOBALS_H

#include<bits/stdc++.h>
using namespace std;

class Globals {
public:
	enum Category {
		Enum_start,
		Mobile,
		Book,
		Enum_end
	};
private:
	static map<string,Category> string_to_category_map;

public:
	Category category;

	string get_category_name(Category c);
	Category get_category_enum(string s);

	static string to_platfrom;
	static string from_platform;
};

#endif