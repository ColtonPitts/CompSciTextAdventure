#pragma once
#include "pch.h"
#include "player.h"
#include <iostream>


extern location* current;

using namespace std;

player::player()
{
	name = "john doe";

}
player::~player() {

}

void player::look(const string objName)
{
	bool inInv = false;
	item* myItem = NULL;
	//check if object is in inventory 
	list<item*>::iterator theiter;
	for (theiter = inventory.begin(); theiter != inventory.end(); theiter++) {
		if (objName == (*theiter)->getName())
		{
			cout << (*theiter)->getDeets();
			inInv = true;
		}
	}

	if (inInv == false)
	{
		myItem = ::current->getobj(objName);
	   	if (myItem == NULL)
		{
			cout << "Item not in Inventory or Location." << endl;
		}
		else
		{
			cout << myItem->getDeets();
		}
	}
}

void player::take(const string obj) {
	item* myItem = ::current->getobj(obj);
	if (myItem != NULL) {
		inventory.push_back(myItem);
		::current->remobj(myItem);
	}
	else {
		cout << "cannot take " << obj << endl;
	}
	
}

void player::drop(item *myItem) {
	if (inventory.empty()) {
		cout << "Nothing to drop inventory is empty. " << endl;
	}
	else if (checkInv(myItem->getName())) {
		inventory.remove(myItem);
		::current->addobj(myItem);
		cout << "dropped " << myItem->getName() << endl;
	}
	else  {
		cout << "Object cannot be dropped" << endl;
	}
}

void player::showInv()
{
	list<item*>::iterator theiter;
	if (inventory.empty()) {
		cout << "My inventory is empty, start hoarding" << endl;
	}
	else {
		cout << "I have the below items: " << endl;
		for (theiter = inventory.begin(); theiter != inventory.end(); theiter++) {
			string itemname = (*theiter)->getName();
			cout << itemname << endl;
		}
	}
}

bool player::checkInv(string objName)
{
	list<item*>::iterator theiter;
	for (theiter = inventory.begin(); theiter != inventory.end(); theiter++) {
		if (objName == (*theiter)->getName())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void player::use(const string obj) {

	bool inInv = checkInv(obj);
	if (inInv)
	{
		bool locUsage = ::current->useObj(obj);
		if (locUsage)
		{
			if (obj == "USB")
			{
				cout << "Retrieved documents from Computer.";
			}
			else if (obj == "FLASHLIGHT")
			{
				cout << "Using Flashlight. Now there is light";
			}
			else if (obj == "KEY")
			{
				cout << "Door Unlocked";
			}
		}
		else
		{
			cout << "Nothing happens." << endl;
		}
	}
	else
	{
		cout << "Nothing happens." << endl;
	}
	
	//print use message
}