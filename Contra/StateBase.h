#pragma once
#include <iostream>

class StateBase
{
public:
	virtual bool Init() = 0;
	virtual bool Update() = 0;
	virtual bool Draw() = 0;
	virtual bool Suppend() = 0;
	virtual bool Resume() = 0;
	virtual bool Destroy() = 0;
};

