#pragma once
#include "pch.h"
#include "item.h"

using namespace std;

item::item(string name, string description,bool equip) {
	descr = description;
	nme = name;
	eq = equip;
}
item::~item()
{
}

string item::look()
{
	return descr;
}
bool item::isequip() {
	return eq;
}

