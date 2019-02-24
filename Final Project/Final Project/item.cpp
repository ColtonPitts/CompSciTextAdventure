#pragma once
#include "pch.h"
#include "item.h"

using namespace std;

item::item(string inName, string description,bool usable, string inDeets) {
	descr = description;
	name = inName;
	use = usable;
	deets = inDeets;
}
item::~item()
{
}

string item::look()
{
	return descr;
}
bool item::isUsable() {
	return use;
}

string item::getName() {
	return name;
}

string item::getDeets()
{
	return deets;
}
