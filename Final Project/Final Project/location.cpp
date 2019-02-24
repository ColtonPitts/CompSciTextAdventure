#pragma once
#include "pch.h"
#include "location.h"
#include <iostream>


using namespace std;

location::location(string inName)
{
	name = inName;

	if (inName == "FARMHOUSE")
	{
		desc = "I'm at home. There is a window on the south side I can escape from.\n Any other directions, aliens will catch you.";
		
	}
	else if (inName == "STREET BEHIND HOUSE")
	{
		desc = "I'm in the street behind my house. There is an alley to the east and west.";
		

	}

	else if (inName == "TRASH ALLEY")
	{
		desc = "I see a trash can, I can hide in there if need be. \nThere is nothing else in this alley but there is a way back to the street.";
		
	}

	else if (inName == "ALLEY")
	{
		desc = "I am in the alley, there is sewer here with a ladder that I can go down. There is a brick lying nearby.";
	

	}

	else if (inName == "SEWER")
	{
		desc = "I am in a smelly sewer. I wonder if there are rats...\n I see a blue light to the east";
	}

	else if (inName == "UC")
	{
		desc = "I am in the underground city, there are a lot of people here, \nit seems like the beginning of the resistance against the aliens.\nKeep going north to reach the plaza.";
	}

	else if (inName == "PLAZA")
	{
		desc = "There are more people here than in the city, \nthere are some stairs going up, and an alley to the east and west.";
	}

	else if (inName == "ALLEY A")
	{
		desc = "An alley with a bunch of rundown buildings, \nthis is where the plebs live. The plaza is to the west.";
	}

	else if (inName == "ALLEY B")
	{
		desc = "An alley that looks a bit more modern and there are some large statues, too bad you don't have any money to live here.";
	}

	else if (inName == "HQ")
	{
		desc = "The leaders of the resistance are looking at down at you from a platform. \nThere are made of different alien races seem happy to see you. \n There is a teleporter to the east.";
	}

	else if (inName == "OFFICE")
	{
		desc = "The mission is to steal some important documents for the resistance, you see a Blue door to the east and a Green door to the west";
	}

	else if (inName == "BLUE OFFICE")
	{
		desc = "There are a bunch of desks in the office, the files are on the table. Get them";
	}
	else if (inName == "GREEN OFFICE")
	{
		desc = "There are just some desks and nothing else.";
	}

}

location::location(const char* inName, const char* description)
{
	name = inName;
	desc = description;
	
}

location::~location()
{

}

void location::look()
{
	cout << desc << endl;
	showInv();
}

void location::addobj(string objname,string describe, bool eqp, string inDeets)
{
	item* g=new item(objname, describe, eqp, inDeets);
	objectlist.push_back(g);
}

void location::addobj(item* myItem)
{
	objectlist.push_back(myItem);
}

string location::getLocName() const
{

	return name;
}

item* location::getobj(string objnme)
{
	item* retItem = NULL;
	list<item*>::iterator myIter;
	for (myIter = objectlist.begin(); myIter != objectlist.end(); myIter++) {
		if ((*myIter)->getName() == objnme)
		{
			if ((*myIter)->isUsable())
			{
				retItem = *myIter;
			}
		} 
	}
	
	return retItem;
}

void location::showInv()
{
	item* myItem;
	string name;
	list<item*>::iterator theiter;
	if (objectlist.empty()) {
		cout << "There are no items in this room that can be taken or used." << endl;
			return;
	}
	cout << "These are the items available in this room: " << endl;
	for (theiter = objectlist.begin(); theiter != objectlist.end(); theiter++) {
	    myItem = *theiter;
		name = myItem->getName();
		cout << name << endl;
	}
}

bool location::useObj(string objName)
{
	if ((objName == "USB") && (name == "FARMHOUSE"))
	{
		return true;
	}
	else if ((objName == "FLASHLIGHT" ) && ( name == "SEWER"))
	{
		return true;
	}
	else if ((objName == "KEY") && (name == "OFFICE"))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void location::remobj(item* myItem) {
	objectlist.remove(myItem);
}