#include "../common/comm.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> incHeight;
        stack<int> width;
        incHeight.push(0);
        width.push(0);
        int sz = height.size();
        // hint: calculate lots of height increasing series
        int currHt, maxArea = 0, minHt, wid;
        for (int i = 0; i < sz; i++) {
            currHt = height[i];
            // TODO equal scenario need to consider
            if (currHt >= incHeight.top()) {
                incHeight.push(currHt);
                width.push(1);
            }
            else {
                minHt = INT_MAX;
                wid = 0;
                while (incHeight.top() > currHt) {
                    // TODO since this is increasing order, no need for min() operation ???
                    //minHt = min(minHt, incHeight.top());
                    wid += width.top();
                    //maxArea = max(maxArea, wid*minHt);
                    maxArea = max(maxArea, wid*incHeight.top());
                    incHeight.pop();
                    width.pop();
                }
                incHeight.push(currHt);
                width.push(wid+1);
            }
        }
        // last time scanning the whole incHeight, this operation ensure we can stop measure the area when...
        // stack top element's height less than currHt value. In the end, it will calc all this kind of area from back to front
        wid = 0;
        while (!incHeight.empty()) {
            wid += width.top();
            maxArea = max(maxArea, incHeight.top()*wid);
            incHeight.pop();
            width.pop();
        }
        return maxArea;
    }
};

int main() {
    cout<<"Hello World!"<<endl;
    return 1;
}