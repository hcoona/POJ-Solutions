#include "EntryPoint.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

namespace POJ {
    class P1018 : public SolutionBase {   
    public:
        virtual void Run(istream &in, ostream &out);
        double Solve(const vector<vector<pair<int, int> > > &deviceData) const;
    };
    
    template<typename _Ty1, typename _Ty2>
    static bool PredByFirstGt(const pair<_Ty1, _Ty2> &a, const pair<_Ty1, _Ty2> &b)
    {
        return a.first > b.first;
    }

    template<typename _Ty1, typename _Ty2>
    static bool PredBySecondLt(const pair<_Ty1, _Ty2> &a, const pair<_Ty1, _Ty2> &b)
    {
        return a.second < b.second;
    }

    void P1018::Run(istream &in, ostream &out)
    {
        const int NMax = 100;
        const int MMax = 100;
        vector<vector<pair<int, int> > > deviceData(NMax, vector<pair<int, int> >(MMax));

        int t;
        in >> t;
        while (t--) {
            int n;
            in >> n;

            for (int nidx = 0; nidx < n; nidx++) {
                int m;
                in >> m;
                for (int midx = 0; midx < m; midx++) {
                    int b, p;
                    in >> b >> p;
                    deviceData[nidx][midx] = make_pair(b, p);
                }
                sort(
                    deviceData[nidx].begin(),
                    deviceData[nidx].end(),
                    PredByFirstGt<int, int>);
            }

            out << setprecision(3) << fixed << Solve(deviceData) << endl;
        }
    }

    double P1018::Solve(const vector<vector<pair<int, int> > > &deviceData) const
    {
        map<int, int> bandwidthToPrice;
        for (auto it = deviceData.begin(); it != deviceData.end(); it++) {
            for (auto iit = it->begin(); iit != it->end(); iit++) {
                bandwidthToPrice[iit->first] = 0;
            }
        }

        const int INVALID_PRICE = -1;
        for (auto dit = deviceData.begin(); dit != deviceData.end(); dit++) {
            for (auto it = bandwidthToPrice.begin(); it != bandwidthToPrice.end(); it++) {
                if (it->second != INVALID_PRICE) {
                    auto beginPosition = dit->begin();
                    auto endPosition = upper_bound(
                        beginPosition,
                        dit->end(),
                        *it,
                        PredByFirstGt<int, int>);
                    if (beginPosition == endPosition) {
                        it->second = INVALID_PRICE;
                    } else {
                        it->second += min_element(beginPosition, endPosition, PredBySecondLt<int, int>)->second;
                    }
                }
            }
        }
        
        double maxBperP = 0.0;
        for (auto it = bandwidthToPrice.begin(); it != bandwidthToPrice.end(); it++) {
            auto BperP = static_cast<double>(it->first) / static_cast<double>(it->second);
            maxBperP = max(maxBperP, BperP);
        }
        return maxBperP;
    }
}

ENTRY_POINT(POJ::P1018)
