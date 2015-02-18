#include "../common/comm.h"

class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        int start, end = 1;
	long temp;
        // first find the boundary
	temp = end * end;
        while (temp < x && temp != 0) {
            end *= 2;
	    temp = end * end;
	}
        start = end/2;
        // then do binary search
        int mid;
        while (start < end) {
            cout<<start<<" "<<end<<endl;
            if (start == end - 1)
                return start;
            mid = (start + end)/2;
	    temp = mid * mid;
            if (temp < x && temp > 0) {
                start = mid;
	    }
            else if (temp > x || temp < 0) {
                end = mid;
	    }
            else
                return mid;
        }
    }
};

int main() {
    Solution sl;
    cout<<sl.sqrt(2147395599)<<endl;
    return 1;
}
