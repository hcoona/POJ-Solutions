#include "EntryPoint.h"

namespace POJ {
    class P1001 : public SolutionBase {
    public:
        virtual void Run(istream &in, ostream &out);
    };

    void P1001::Run(istream &in, ostream &out)
    {
        int a, b;
        in >> a >> b;
        out << a + b << endl;
    }
}

ENTRY_POINT(POJ::P1001)
