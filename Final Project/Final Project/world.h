#pragma once
#include "pch.h"
#include "location.h"
#include "player.h"
#include <vector>
#include <string>
#include "utils.h"
#include <map>

using namespace std;

enum direction {
	north,
	south,
	west,
	east,
};

class world {
protected:
	map<string, item*> gameobjs;
	map<string, location*> gamelocs;
	//vector<location*> locations;

	static location* currLoc;

public:
	world();
	~world();
	location* getCurrLoc();
	void addobj(string locName, string objname, string describe, bool eqp, string inDeets);
	item* getItem(string itemName);
	void addLoc();

	//string look();
	string getLoc(string inLocName, string dir);
	
};


