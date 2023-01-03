#include <bits/stdc++.h>
#include "Globals.h"

using namespace std;

string Globals::get_category_name(Category c) {
	switch(c) {
		case Mobile:
			return "Mobile";
		case Book:
			return "Book";
		default:
			return "Error";
	}
}
