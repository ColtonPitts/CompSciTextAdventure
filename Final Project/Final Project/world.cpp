#pragma once
#include "pch.h"
#include "world.h"
#include <iostream>

using namespace std;

location* world::currLoc = NULL;

string world::getLoc(string inLocName, string dir)
{
	//Location Map for FARMHOUSE
	if (upper(inLocName) == upper("FARMHOUSE"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("south"))
		{
			std::map<string, location*>::iterator it;
			string locName = "STREET BEHIND HOUSE";
			it = gamelocs.find(locName);
			if ( it != gamelocs.end())
			{
			currLoc = it->second;
			}

			return locName;
		}
		else
		{
			return "NOT VALID DIRECTION";
		}
	}

	//LOCATION 2

	else if (upper(inLocName) == upper("STREET BEHIND HOUSE"))
	{
		if (upper(dir) == upper("north"))
		{
			return "FARMHOUSE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "ALLEY";
		}
		else if (upper(dir) == upper("east"))
		{
			return "TRASH ALLEY";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}
		else
		{
			return "NOT VALID DIRECTION";
		}

	}

	//Location 3

	else if (upper(inLocName) == upper("TRASH ALLEY"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "STREET BEHIND HOUSE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}
		else
		{
			return "NOT VALID DIRECTION";
		}

	}
	//Location 4

	else if (upper(inLocName) == upper("ALLEY"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "STREET BEHIND HOUSE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}

		else if (upper(dir) == upper("down"))
		{

			return "SEWER";
		}

		else
		{
			return "NOT VALID DIRECTION";
		}

	}//Location 5

	else if (upper(inLocName) == upper("SEWER"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "UC";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}

		else if (upper(dir) == upper("up"))
		{

			return "Can't go back there are aliens outside.";
		}

		else
		{
			return "NOT VALID DIRECTION";
		}

	}
	//Location 6

	else if (upper(inLocName) == upper("UC"))
	{
		if (upper(dir) == upper("north"))
		{
			return "PLAZA";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "SEWER";
		}

		else
		{
			return "NOT VALID DIRECTION";
		}

	}

	// Location 7

	else if (upper(inLocName) == upper("PLAZA"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "ALLEY A";
		}
		else if (upper(dir) == upper("east"))
		{
			return "ALLEY B";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("up"))
		{

			return "HQ";
		}
		else
		{
			return "NOT VALID DIRECTION";
		}

	}

	//Location 8 

	else if (upper(inLocName) == upper("ALLEY A"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "PLAZA";
		}
		else if (upper(dir) == upper("east"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}

		else
		{
			return "NOT VALID DIRECTION";
		}

	}

	//Location 9 

	else if (upper(inLocName) == upper("ALLEY B"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "PLAZA";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}

		else
		{	
			return "NOT VALID DIRECTION";
		}

	}//Location 10

	else if (upper(inLocName) == upper("HQ"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "using teleporter to go to OFFICE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}

		else if (upper(dir) == upper("down"))
		{

			return "PLAZA";
		}

		else
		{
			return "NOT VALID DIRECTION";
		}

	}

	//Location 11

	else if (upper(inLocName) == upper("OFFICE"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "GREEN ROOM";
		}
		else if (upper(dir) == upper("east"))
		{
			return "BLUE ROOM";
		}
		else if (upper(dir) == upper("south"))
		{

			return "HQ";
		}
		else
		{
			return "NOT VALID DIRECTION";
		}
	}

	//Location 12

	else if (upper(inLocName) == upper("BLUE ROOM"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "OFFICE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}
		else
		{
			return "NOT VALID DIRECTION";
		}
	}

	//location 13


	else if (upper(inLocName) == upper("GREEN ROOM"))
	{
		if (upper(dir) == upper("north"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("west"))
		{
			return "NOTHING THERE";
		}
		else if (upper(dir) == upper("east"))
		{
			return "OFFICE";
		}
		else if (upper(dir) == upper("south"))
		{

			return "NOTHING THERE";
		}
		else
		{
			return "NOT VALID DIRECTION";
		}
	}

	else { 
		return "NOTHING THERE"; 
	}
}

world::world() {
		addLoc();
		currLoc = gamelocs.find("FARMHOUSE")->second;
		
	}

world::~world() {
}

location* world::getCurrLoc() {

	return currLoc;

}

void world::addLoc()
{
	location* loc = new location("FARMHOUSE");
	gamelocs["FARMHOUSE"] = loc;
	addobj("FARMHOUSE", "USB", "MY USB", TRUE, "This is my USB, it's in blue in color with my name in Silver.\nIt can store upto 10TB of memory.");
	addobj("FARMHOUSE", "COMPUTER", "MY COMPUTER", TRUE, "My trusy rundown computer that has a lifetimes worth of documents about alien eradication.\n ");
	
	loc = new location("STREET BEHIND HOUSE");
	gamelocs["STREET BEHIND HOUSE"] = loc;
	
	loc = new location("TRASH ALLEY");
	gamelocs["TRASH ALLEY"] = loc;
	
	loc = new location("ALLEY");
	gamelocs["ALLEY"] = loc;
	addobj("ALLEY", "BRICK", "Something from a forgotten time period", TRUE, "No one likes this brick, it's been left here for ages, I should take it with me as a souvenir. \n The brick doesn't have any special effects");

	loc = new location("SEWER");
	gamelocs["SEWER"] = loc;
	addobj("SEWER", "LADDER", "A ladder that can be used to go down. Once you move forward you can't return", TRUE, "This ladder will take me away from the nasty aliens, I need to hide somewhere real quick. \n It is very smelly here.");
	addobj("SEWER", "FLASHLIGHT", "A flashlight that can be used to see in the dark.", TRUE, "It's a flashlight, it works, congrats you found a flashlight in the future.\n stop reading and start playing the game.");
	

	loc = new location("UC");
	gamelocs["UC"] = loc;

	loc = new location("PLAZA");
	gamelocs["PLAZA"] = loc;

	loc = new location("ALLEY A");
	gamelocs["ALLEY A"] = loc;

	loc = new location("ALLEY B");
	gamelocs["ALLEY B"] = loc;

	loc = new location("HQ");
	gamelocs["HQ"] = loc;
	addobj("HQ", "TELEPORTER", "This is a teleporter, you can use it to go from HQ to the office.", TRUE, "A teleporter since it's the future, why wouldn't there be one, btw if it fails it's not on me.");
	

	loc = new location("OFFICE");
	gamelocs["OFFICE"] = loc;

	loc = new location("BLUE OFFICE");
	gamelocs["BLUE OFFICE"] = loc;

	loc = new location("GREEN OFFICE");
	gamelocs["GREEN OFFICE"] = loc;
	
}

void world::addobj(string locName, string objname, string describe, bool eqp, string inDeets){

	item* g = new item(objname, describe, eqp, inDeets);
	gameobjs[objname] = g;

	std::map<string, location*>::iterator it;
	it = gamelocs.find(locName);
	location* loc1 = it->second;
	if (it != gamelocs.end())
	{
		cout << " Adding object " << objname << endl;
		loc1->addobj(g);
	}
		
}
item* world::getItem(string itemName)
{
	return gameobjs.find(itemName)->second;
}








