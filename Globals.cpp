#include <bits/stdc++.h>
#include "Globals.h"
using namespace std;

string Globals::to_platfrom = "PortalToPlatform.txt";
string Globals::from_platform = "PlatformToPortal.txt";

map<string, Globals::Category> Globals::string_to_category_map = {
	{"Mobile", static_cast<Category>(Category(1))},
	{"Book", static_cast<Category>(Category(2))},
};

string Globals::get_category_name(Category c)
{
	cerr << c << " " << Mobile << " " << Book << endl;
	switch (c)
	{
	case Mobile:
		return "Mobile";
	case Book:
		return "Book";
	default:
		return "Error";
	}
}

Globals::Category Globals::get_category_enum(string s)
{
	cerr << s << endl;
	Globals global;

	cerr << global.get_category_name(string_to_category_map[s]) << endl;
	return string_to_category_map[s];
}