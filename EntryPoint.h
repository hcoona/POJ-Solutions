#pragma once
#include <iostream>
#include "SolutionBase.h"

using namespace std;

#define ENTRY_POINT(x) int main(void) { \
    POJ::SolutionBase *p = new x(); \
    p->Run(cin, cout); \
    delete p; \
    return 0; \
}
