#include "MainView.h"
#include "../../controller/MainController.h"

void MainView::Update(Controller* controller, Screen& screen)
{
	for (auto [X, Y] : _selectedPoints)
	{
		screen.Draw(Text{ .Str = " ", .X = X, .Y = Y, .Background = Background::GREEN });
	}

	screen.Draw(Text{ .Str = " ", .X = _mousePosition.X, .Y = _mousePosition.Y, .Background = Background::YELLOW });

	if (_centerPoint.X != -1 && _centerPoint.Y != -1)
	{
		screen.Draw(Text{ .Str = "C", .X = _centerPoint.X, .Y = _centerPoint.Y, .Background = Background::RED, .Foreground = Foreground::WHITE });
	}

	// Display controls for the user
	screen.Draw(Text{
		.Str = "Exit: Esc | Arrows: move | Add/remove point: Space",
		.X = screen.GetWidth() / 2, .Y = screen.GetHeight() - 3, .XCentered = true
	});
}

void MainView::OnKeyPressed(Controller* controller, const char key)
{
	if (key == 32) // Space
	{
		bool found = false;
		for (auto point : _selectedPoints)
		{
			if (point == _mousePosition)
			{
				_selectedPoints.erase(std::remove(_selectedPoints.begin(), _selectedPoints.end(), point), _selectedPoints.end());
				found = true;
			}
		}

		if (!found)
		{
			_selectedPoints.push_back(_mousePosition);
		}

		if (_selectedPoints.size() > 1)
		{
			_centerPoint = { -1, -1 };
			for (const Point point : _selectedPoints)
			{
				if (_centerPoint.X == -1 && _centerPoint.Y == -1)
				{
					_centerPoint = point;
				}
				else
				{
					_centerPoint += point;
				}
			}
		} else
		{
			_centerPoint = { -1, -1 };
		}
	}
	else if (key == KEY_LEFT)
	{
		_mousePosition.X--;
	}
	else if (key == KEY_RIGHT)
	{
		_mousePosition.X++;
	}
	else if (key == KEY_UP)
	{
		_mousePosition.Y--;
	}
	else if (key == KEY_DOWN)
	{
		_mousePosition.Y++;
	}
}