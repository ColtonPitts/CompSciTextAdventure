#pragma once
#include <string>	
#include <vector>
#include "item.h"

using namespace std;

class player {
public:
	
	vector <item> inventory;
	player();
	~player();
	bool go(const string direction);
	void look(const string args); 
	bool take(const string obj);
	bool drop(const string args);
	

};