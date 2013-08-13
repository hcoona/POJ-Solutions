#include "EntryPoint.h"
#include <iostream>
#include <tuple>
#include <cmath>
#include <cstdlib>

using namespace std;

namespace POJ {
    class P1061 : public SolutionBase {
    public:
        static constexpr int INVALID = -1;
    public:
        virtual void Run(istream &in, ostream &out) override;
        int Solve(int x, int y, int m, int n, int L) const;
    private:
        tuple<int, int, int> Extended_GCD(int a, int b) const;
    };

    void P1061::Run(istream &in, ostream &out)
    {
        int x, y, m, n, L;
        in >> x >> y >> m >> n >> L;
        int result = Solve(x, y, m, n, L);
        if (result != INVALID) {
            out << result << endl;
        } else {
            out << "Impossible" << endl;
        }
    }

    int P1061::Solve(int x, int y, int m, int n, int L) const
    {
        int a = m - n, b = L, c = y - x;
        int x0, gcd;
        tie(x0, ignore, gcd) = Extended_GCD(a, b);
        if (a && (c % gcd == 0)) {
            int scale = c / gcd;
            double t = -static_cast<double>(x0) * c / b;
            int x = x0 * scale + b / gcd * static_cast<int>(floor(t));
            return x < 0 ? (x + b / gcd) : x;
        } else if (c % L == 0) {
            return 0;
        } else {
            return INVALID;
        }
    }
    
    tuple<int, int, int> P1061::Extended_GCD(int a, int b) const
    {
        int x = 0, y = 1;
        int lastx = 1, lasty = 0;
        while (b != 0) {
            auto qr = div(a, b);
            a = b, b = qr.rem;
            int tmpx = x, tmpy = y;
            x = lastx - qr.quot * x, lastx = tmpx;
            y = lasty - qr.quot * y, lasty = tmpy;
        }
        return make_tuple(lastx, lasty, a);
    }
}

ENTRY_POINT(POJ::P1061)
