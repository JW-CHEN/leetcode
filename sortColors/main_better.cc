#include "../common/comm.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        int i = 0, lo = 0, hi = n - 1;
        // invariants: A[0..lo-1] are less than pivot 1, A[lo..i-1] equal, A[hi+1..end] greater
        while (i <= hi)
            if (A[i] < 1)
                swap(A[i++], A[lo++]);  // A[lo] must be less than or equal to 1, so A[i++] can skip the test of A[i] next iteration
            else if (A[i] > 1)
                swap(A[i], A[hi--]);   // A[hi] can be any number, so A[i] should be test next time
            else
                i++;
    }
};

int main() {
    cout<<"Hello World!"<<endl;
    return 1;
}