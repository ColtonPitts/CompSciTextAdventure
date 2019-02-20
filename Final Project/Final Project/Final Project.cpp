#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "location.h"


using namespace std;

location* current = new location("Farmhouse","my home");

void testStringSplitting()
{
	bool done = false;
	while (!done)
	{
		std::string line;
		std::cout << "Enter string: ";
		std::getline(std::cin, line);

		// This is from https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
		std::istringstream iss(line);
		std::vector<std::string> tokens;
		std::copy(std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			back_inserter(tokens));

		for (std::string value : tokens)
		{
			std::cout << "  '" << value << "'" << std::endl;
		}
		if (tokens[0] == "quit")
		{
			done = true;

		}
		else if (tokens[0] == "go" || tokens[0] =="move") {

			cout << "I am going" << endl;
		}
		else if (tokens[0] == "use") {

			cout << "I am using" << endl;
		}
		else if (tokens[0] == "look") {

			cout << current->look() << endl;
		}
		else if (tokens[0] == "drop") {

			cout << "I am dropping" << endl;
		}
		else if (tokens[0] == "inventory") {

			cout << "Opening Inventory" << endl;
		}
		else if (tokens[0] == "	help") {
			cout << "I am helping" << endl;
		}
	}


}




int main()
{
	cout << "Welcome to my game" << endl;
	cout << "This is the year 2250. The galaxy war caused chaos in the universe and caused dark times humans that outlive the nuclear world wars," << endl; 
	cout << "which caused damage to the earth. The superpower leaders wanted more power and made a deal with the aliens. "<< endl;
	cout << "This negotiation lead to extraordinary technology and human genes became splice with different species Dna to fight in galaxies wars. " << endl;
	cout <<	"The aliens had full control of the earth providing food and survival of the people.Cyborgs were used to control the masses on earth." << endl;
	cout << "There was a prophecy that someone will be born to the the freedom of the masses both on heaven and earth." << endl;
	cout << "The privacy of the masses was always monitored in public and through their devices" << endl;
	cout << "Some mothers have their babies and never seen their child again." << endl;
	cout << "These children were used as soldiers in the galaxy wars.The new world consist of learn alien language and education." << endl;
    
	cout << "You are in a farmhouse in the future, there is a computer in front of you with a usb device in it. You are currently hacking into the computer." << endl;
	cout << "The aliens have heard you and have arrived outside your house, there is a window to escape, be sure to take the usb as well" << endl;
	testStringSplitting();

}

