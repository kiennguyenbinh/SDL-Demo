#pragma once
#include "Object.h"
class Command
{
public:
	Command();
	~Command();
	void execute(Object* obj) {
		obj->execute();
	}
};

