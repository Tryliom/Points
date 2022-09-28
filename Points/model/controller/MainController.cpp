#include "MainController.h"
#include "../view/views/MainView.h"
#include "../utilities/Utility.h"

MainController::MainController()
{
	ChangeView(new MainView());
}

void MainController::update()
{
	// Update the view
	if (this->_view != nullptr)
	{
		this->_view->Update(this, this->_screen);
	}
}

void MainController::onKeyPressed(const char key)
{
	// If the view is not null, call the view's onKeyPressed method
	if (this->_view != nullptr)
	{
		this->_view->OnKeyPressed(this, key);
	}

	// If the key is Escape, exit the program or go back to the last view
	if (key == KEY_ESC)
	{
		if (_views.empty())
		{
			// Close the program
			this->_view = nullptr;
			Utility::sleep(300);
			exit(0);
		}

		GoBack();
	}
}