#pragma once
#include "pch.h"
#include <string>
#include <locale>
using namespace std;

extern inline string upper(string input)
{
	string ret;

	std::locale loc;
	for (int i = 0; i < input.length(); i++)
	{
		ret += std::toupper(input[i], loc);
	}

	
	return ret;
}
