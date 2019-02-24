#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <Windows.h>
#include "location.h"
#include "world.h"
#include "player.h"


using namespace std;

//location* current = new location("FARMHOUSE");

world* myWorld = new world();

location* current = myWorld->getCurrLoc();

player* me = new player();

void testStringSplitting()
{
	bool done = false;

	while (!done)
	{
		std::string line;
		std::cout << "Type the action that you want to take (\"quit\" to exit): ";
		std::getline(std::cin, line);

		// This is from https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
		std::istringstream iss(line);
		std::vector<std::string> tokens;
		std::copy(std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			back_inserter(tokens));

		if (upper(tokens[0]) == upper("quit"))
		{
			done = true;

		}
		else if ((upper(tokens[0]) == upper("go")) || (upper(tokens[0]) == upper("move"))) {

			if (tokens.size() == 1) {
				cout << "Invalid command need direction to " << tokens[0] << endl;
				continue;
			}
			else if (tokens.size() > 2) {
				cout << "Invalid command move takes only one direction" << endl;
				continue;
		}

			std::string curLocName = current->getLocName();
			std::string dir = tokens[1];

			std::string dest = myWorld->getLoc(curLocName, dir);

			cout << dest << endl;
			if ((dest != "NOTHING THERE") && (dest != "NOT VALID DIRECTION"))
			{
				delete current;
				current = NULL;

				current = new location(dest);
			}
		}
		else if (upper(tokens[0]) == upper("take")) {
			if (tokens.size() == 1) {
				cout << "Invalid command need object to " << tokens[0] << endl;
				continue;
			}
			else if (tokens.size() > 2) {
				cout << "Invalid command, take takes only one object" << endl;
				continue;
			}
			std::string objname = upper(tokens[1]);
			me->take(objname);

		}
		else if (upper(tokens[0]) == upper("use")) {
			if (tokens.size() == 1) {
				cout << "Invalid command need object to " << tokens[0] << endl;
				continue;
			}
			else if (tokens.size() > 2) {
				cout << "Invalid command, use takes only one object" << endl;
				continue;
			}
			std::string objname = upper(tokens[1]);
			me->use(objname);

		}
		else if (upper(tokens[0]) == upper("look"))
		{
			if (tokens.size() == 1)
			{
				current->look();
			}
			else if (tokens.size() > 2)
			{
				cout << "Invalid command, look cannot take more than one object" << endl;
				continue;
			}
			else
			{
				std::string objName = upper(tokens[1]);
				me->look(objName);
			}
		}

		else if (upper(tokens[0]) == upper("drop")) {
			if (tokens.size() == 1) {
				cout << "Invalid command need object to " << tokens[0] << endl;
				continue;
			}
			else if (tokens.size() > 2) {
				cout << "Invalid command, drop takes only one object" << endl;
				continue;
			}
			else
			{
				std::string objname = upper(tokens[1]);
				item *myItem = myWorld->getItem(objname);
				me->drop(myItem);
			}
		}
		else if (tokens[0] == "inventory") {
			if (tokens.size() != 1) {
				cout << "Invalid command, inventory has no parameters " << tokens[0] << endl;
				continue;
			}
			
			me->showInv();
		}
		else if (tokens[0] == "help") {
			cout << "MENU OPTIONS: " << endl;
			cout << "Move - Move the player, need to specify direction" << endl;
			cout << "Take - Take an object, need to specify the name of the object to be taken" << endl;
			cout << "Use  - Use object, need to specify name of object to be used" << endl;
			cout << "Drop - Drop an object, need to specify name of object to be used" << endl;
			cout << "Inventory - Shows Inventory" << endl;
		}
		else {
			cout << "I don't understand the command \"" << tokens[0] << "\""<< endl;
		}
	}


}


void intro()
{
		cout << "Welcome to my game" << endl;
		cout << "\n";
		Sleep(2000);
		cout << "This is the year 2250. The galaxy war has caused chaos in the universe" << endl;
		cout << "\n";
		Sleep(2000);
		cout << "and caused dark times to the humans that have outlived the nuclear world wars," << endl;
		cout << "\n";
		Sleep(2000);
		cout << "which has caused damage to Earth. " << endl;
		cout << "\n";
		Sleep(2000);
		cout << "The superpower leaders wanted more power and have made a deal with the aliens. " << endl;
		cout << "\n";
		Sleep(2000);
		cout << "This negotiation lead to extraordinary technology and started with human gene experimentation" << endl;
		cout << "\n";
		Sleep(2000);
		cout << "the experimentation led to human gene splicing with different species to fight in the galaxies wars." << endl;
		cout << "\n";
		Sleep(2000);
		cout << "The aliens had full control of Earth including providing food and water to the people." << endl;
		cout << "\n";
		Sleep(2000);
		cout << "Cyborgs were used to control the masses on earth." << endl;
		cout << "\n";
		Sleep(2000);
		cout << "There was a prophecy that someone will be born to save the masses" << endl;
		cout << "\n";
		Sleep(1000);
		cout << "There is no privacy to humans and they are always monitored in public and through their control devices" << endl;
		cout << "\n";
		Sleep(2000);
		cout << "These children were used as soldiers in the galaxy wars.The new world consist of learning alien language and education." << endl;
		Sleep(2000);
		cout << "\n";
		cout << "\n";
		cout << "\n";

		Sleep(2000);
		cout << "You are in a farmhouse in the future, there is a computer in front of you with a usb device in it. You are currently hacking into the computer." << endl;
		cout << "\n";
		Sleep(1000);
		cout << "The aliens have heard you and have arrived outside your house, there is a window to escape, be sure to take the usb as well" << endl;
		cout << "\n";
		Sleep(1000);
		return;
	}

void delGlobals()
{
	delete current;
	delete myWorld;
	delete me;	
}


int main()
{
	//intro();

	testStringSplitting();


	//delGlobals();
}
