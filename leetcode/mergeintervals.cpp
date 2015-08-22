#include "common_header.h"


 // Definition for an interval.
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

bool intervalCompare(Interval i1, Interval i2)
{
        return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0) return res;

        sort(intervals.begin(), intervals.end(), intervalCompare);

        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i].start <= end)
            {
                if(end < intervals[i].end)
                {
                    end = intervals[i].end;
                }
            }
            else
            {
                Interval it(start, end);
                res.push_back(it);

                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        
        Interval it(start, end);
        res.push_back(it);
        return res;
    }

    
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    vector<Interval> res = s.merge(intervals);
    for (int i = 0; i < res.size(); ++i)
    {
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }

    return 0;
}