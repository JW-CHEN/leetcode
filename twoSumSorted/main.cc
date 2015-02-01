#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> formatRes(int index1, int index2) {
        vector<int> ret;
        ret.push_back(index1 + 1);
        ret.push_back(index2 + 1);
        return ret;
    }
    
    int twoSumBS(vector<int> &numbers, int match, int& front, int& back) {
        int mid;
        while (front <= back) {
            mid = (front + back)/2;
            if (numbers[mid] > match)
                back = mid - 1;    // division is roundDown fashion
            else if (numbers[mid] == match) 
                return mid;
            else 
                front = mid + 1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        int sz = numbers.size();
        int front, back, mid, match;
        int index1 = 0;
        int index2 = sz-1;
        front = index1;
        back = index2;
        match = target - numbers[index1];
        while (1) {
            if ((index2 = twoSumBS(numbers, match, front, back)) != -1)
                return formatRes(index1,index2);
            index2 = back;
            front = index1;
            match = target - numbers[index2];
            if ((index1 = twoSumBS(numbers, match, front, back)) != -1)
                return formatRes(index1, index2);
            index1 = front;
            back = index2;
            match = target - numbers[index1];
        }
    }
};


int main() {
    vector<int> numbers, res;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    Solution sl;
    res = sl.twoSum(numbers, 5);
    cout<<res[0]<<endl;
    cout<<res[1]<<endl;
    return 1;
}
