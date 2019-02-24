#pragma once
#include <string>

using namespace std;

class item {
private:
	string descr;
	string name;
	string deets;
	bool use;
public:
	item(string inName, string description, bool usable, string inDeets);

	~item();
	
	string look();
	string getName();
	string getDeets();
	bool isUsable();
	
};