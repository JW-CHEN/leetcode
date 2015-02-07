#include "../common/comm.h"

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {

public:
    void quickSortSet(int* startSet, int* endSet, int left, int right) {
        //remeber to add new feature
        if (left >= right)
            return;
        int l = left;
        int r = right;
        int pivot = startSet[l];
        int backup = endSet[l];
        while (l < r) {
            while (l < r && startSet[r] > pivot || startSet[r] == pivot && endSet[r] > backup) r--;
            startSet[l] = startSet[r];
            endSet[l] = endSet[r];
            while (l < r && startSet[l] < pivot || startSet[r] == pivot && endSet[r] <= backup ) l++;
            startSet[r] = startSet[l];
            endSet[r] = endSet[l];
        }
        // Complexity analyze
        startSet[l] = pivot;
        endSet[l] = backup;
        quickSortSet(startSet, endSet, left, l-1);
        quickSortSet(startSet, endSet, l+1, right);
        return;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        int sz = intervals.size();
        int numInt = 0;
        vector<Interval> nullRes;
        if (sz == 0)
            return nullRes;
        int* startSet = new int[sz];
        int* endSet = new int[sz];
        for (int i = 0; i < sz; i++) {
            startSet[i] = intervals[i].start;
            endSet[i] = intervals[i].end;
        }
        quickSortSet(startSet, endSet, 0, sz-1);
        stack<int> stk;
        stk.push(startSet[0]);
        stk.push(endSet[0]);
        numInt++;
        int preEnd;
        for (int i = 1; i < sz; i++) {
            preEnd = stk.top();
            if (startSet[i] <= preEnd && endSet[i] > preEnd) {
                stk.pop();
                stk.push(endSet[i]);
            }
            else if (preEnd < startSet[i]) {
                stk.push(startSet[i]);
                stk.push(endSet[i]);
                numInt++;
            }
        }
        vector<Interval> res(numInt, Interval(0,0));
        for (int i = numInt-1; i >= 0; i--) {
            res[i].end = stk.top();
            stk.pop();
            res[i].start = stk.top();
        }
        return res;
    }
};


int main() {
    vector<Interval> test;
    vector<Interval> res;
    Interval elem1(1,4);
    Interval elem2(1,4);
    test.push_back(elem1);
    test.push_back(elem2);
    Solution sl;
    res = sl.merge(test);
    cout<<res[0].start<<endl<<res[0].end<<endl;
    return 1;
}
