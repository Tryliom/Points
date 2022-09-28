#pragma once
#include <stack>

#include "../view/Screen.h"
#include "../view/View.h"

class View;

#pragma region constants

int constexpr FPS = 60;
bool constexpr LIMIT_FPS = true;
// Useful key codes
constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_ESC = 27;
constexpr auto KEY_BACKSPACE = 8;

#pragma endregion

class Controller
{
protected:
	Screen _screen;
	bool _canPressKey{ true };
	// The current view
	View* _view{ nullptr };
	// The previous views
	std::stack<View*> _views;

	/**
	 * \brief Used to draw things on the screen before rendering
	 */
	virtual void update() = 0;
	/**
	 * \brief Called when a key is pressed
	 * \param key The key pressed
	 */
	virtual void onKeyPressed(char key) = 0;
private:
	/**
	 * \brief Refresh screen rendering
	 */
	void refresh();
	/**
	 * \brief Start a thread to update the screen
	 */
	void startRenderingThread();
public:
	int CurrentFPS{0};
	int Tick{0};
	/**
	 * \brief Start the controller
	 */
	void Start();
	/**
	 * \brief Switch to a new view
	 * \param view The new view
	 */
	void ChangeView(View* view);
	/**
	 * \brief Go back to previous view
	 */
	void GoBack();
	Screen GetScreen();
};

