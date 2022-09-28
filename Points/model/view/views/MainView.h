#pragma once
#include "../View.h"
#include "../../point/Point.h"

class MainView: public View
{
private:
	Point _mousePosition{1, 1};
	std::vector<Point> _selectedPoints;
	Point _centerPoint{-1, -1};

public:
	void Update(Controller* controller, Screen& screen) override;
	void OnKeyPressed(Controller* controller, char key) override;
};

