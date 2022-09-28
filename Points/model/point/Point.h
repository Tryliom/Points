#pragma once
struct Point
{
	int X;
	int Y;

	Point operator+ (const Point& other) const
	{
		return Point{ (X + other.X) / 2, (Y + other.Y) / 2 };
	}

	Point operator+= (const Point& other)
	{
		X = (X + other.X) / 2;
		Y = (Y + other.Y) / 2;
		return *this;
	}

	bool operator== (const Point& other) const
	{
		return X == other.X && Y == other.Y;
	}
};

