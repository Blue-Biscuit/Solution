#pragma once

#include "Solution.h"

namespace cc
{
	//	Interface for types which can be mathematically solved.
	class Solvable
	{
		//	Expresses a class as a mathematical Solution.
		virtual Solution solve() const = 0;
	};
}