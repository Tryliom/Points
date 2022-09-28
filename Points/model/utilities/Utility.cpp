#include "Utility.h"

#include <chrono>

namespace Utility
{
	void sleep(const int milliseconds)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
}
