#pragma once
#include <string>

using namespace std;

class item {
private:
	string descr;
	string nme;
	bool eq;
public:
	item(string name, string description, bool equip);

	~item();
	
	string look();
	
	bool isequip();
	
};