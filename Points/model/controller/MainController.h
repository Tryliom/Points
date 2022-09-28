#pragma once
#include "Controller.h"

class MainController final: public Controller
{
protected:
	void update() override;
	void onKeyPressed(char key) override;

public:
	MainController();
};

