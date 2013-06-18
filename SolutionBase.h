#pragma once
#include <iostream>
#include "NonCopyable.h"

using namespace std;

namespace POJ {
	class SolutionBase : Utility::NonCopyable {
	public:
		virtual void Run(istream &in, ostream &out) = 0;
	};
}
