#pragma once
#include <iostream>
class NoPersonException
{
private:
	int person;
public:
	NoPersonException(int p) { person = p; }
	int getPersons() { throw person; }
};

