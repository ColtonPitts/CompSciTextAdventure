#pragma once
#include <string>
#include <vector>
#include "item.h"

using namespace std;

class location
{
private:
	string desc;
	string name;

	vector <item> objectlist;


public: 
	location(const char*inName, const char* description);
	~location();
	
	string look()const;

	void addobj(string objname,string describe, bool eqp);

	item getobj(string objnme);

};
