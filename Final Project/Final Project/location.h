#pragma once
#include "pch.h"
#include <string>
#include <list>
#include <Windows.h>
#include "item.h"

using namespace std;

class location
{
private:
	string desc;
	string name;

	list <item*> objectlist;


public: 
	location(string inName);
	location(const char*inName, const char* description);

	~location();
	
	void look();

	string getLocName() const;

	void addobj(string objname,string describe, bool eqp, string inDeets);
	void addobj(item* myItem);
	void remobj(item* myItem);

	item* getobj(string objnme);
	void showInv();
	bool useObj(string objName);

};
