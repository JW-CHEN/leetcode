class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        stack<Interval> stk;
        vector<Interval> res;
        int sz = intervals.size();
        if (sz == 0) {
            res.push_back(newInterval);
            return res;
        }
        for (int i = sz-1; i >=0; i--)
            stk.push(intervals[i]);
        Interval temp;
        while (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            if (temp.start >= newInterval.end) {
                if (temp.start == newInterval.end) {
                    newInterval.end = temp.end;
                    res.push_back(newInterval);
                }
                else if (temp.start > newInterval.end) {
                    res.push_back(newInterval);
                    res.push_back(temp);
                }
                else {
                    res.push_back(temp);
                }
                while (!stk.empty()) {
                    temp = stk.top();
                    stk.pop();
                    res.push_back(temp);
                }
                break;
            }
            else if (temp.end < newInterval.start) {
                res.push_back(temp);
            }
            else {
                newInterval.start = min(temp.start, newInterval.start);
                newInterval.end = max(temp.end, newInterval.end);
            }
            if (stk.empty())
                res.push_back(newInterval);
        }
        return res;
    }
};