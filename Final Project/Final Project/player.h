#pragma once
#include <string>	
#include <list>
#include "item.h"
#include "location.h"


using namespace std;

class player {
protected:
	string name;
	location* loc;
	list <item*> inventory;
public:
	

	player();
	~player();
	void look(const string objName); 
	void take(const string obj);
	void drop(item* myItem);
	void showInv();
	bool checkInv(string objName);
	void use(const string obj);
	

};