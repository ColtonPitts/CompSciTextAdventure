#pragma once
#include "pch.h"
#include "location.h"
#include <iostream>


using namespace std;

location::location(const char* inName, const char* description)
{
	name = inName;
	desc = description;
	
}

location::~location()
{

}

string location::look() const
{
	return desc;
}

void location::addobj(string objname,string describe, bool eqp)
{
	item g(objname, describe, eqp);

	objectlist.push_back(g);
}

item location::getobj(string objnme)
{
	
	for (int i = 0; i < objectlist.size; i++) {
		if (objectlist*[i] == objnme)
		{
			
		}
	}
	return 
}

