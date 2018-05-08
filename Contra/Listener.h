#pragma once

class CoreEvent;
class Listener
{
public:
	Listener();
	virtual ~Listener();
	virtual void OnEvent(CoreEvent& _event) = 0;
};

