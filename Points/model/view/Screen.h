#pragma once

#include <string>
#include <vector>

enum class Foreground
{
	NONE,
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37,
};

enum class Background
{
	NONE,
	BLACK = 40,
	RED = 41,
	GREEN = 42,
	YELLOW = 43,
	BLUE = 44,
	MAGENTA = 45,
	CYAN = 46,
	WHITE = 47,
};

struct Text
{
	std::string Str{};
	int X{ 0 };
	int Y{ 0 };
	bool XCentered{ false };
	Background Background{ Background::NONE };
	Foreground Foreground{ Foreground::NONE };
};

struct Button
{
	std::string Str{};
	int X{ 0 };
	int Y{ 0 };
	bool Selected{ false };
	bool XCentered{ false };
	bool YCentered{ false };
};

struct Field
{
	std::string Str{};
	int X{ 0 };
	int Y{ 0 };
	bool Selected{ false };
	bool XCentered{ false };
	bool YCentered{ false };
};

class Screen
{
private:
	std::vector<std::vector<std::string>> _screen;
	// The cache of the previous screen
	std::vector<std::vector<std::string>> _cache;
	int _height;
	int _width;
	// The cursor position on the screen if it is displayed
	int _cursorX;
	int _cursorY;

	static void setPos(int x, int y);
public:
	Screen();

	int GetHeight() const { return this->_height; }
	int GetWidth() const { return this->_width; }

	/**
	 * \brief Clear the screen and prepare it for a new display
	 */
	void Reset();
	/**
	 * \brief Render the screen
	 */
	void Render() const;
	/**
	 * \brief Draw a text on the screen
	 * \param text The text to draw
	 */
	void Draw(Text text);
	/**
	 * \brief Draw a button on the screen
	 * \param button The button to draw
	 */
	void Draw(const Button& button);
	/**
	 * \brief Draw a field on the screen
	 * \param field The field to draw
	 */
	void Draw(const Field& field);
};

