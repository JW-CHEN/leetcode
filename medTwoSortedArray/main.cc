#include <iostream>

using namespace std; 

class Solution {
public:
    double preGetRes(int R[], int isEven, int lowSize) {
        if (isEven)
            return ((double)R[lowSize] + R[lowSize+1])/2;
        else
            return (double)R[lowSize];
    }
    
    double postGetRes(int A[], int m, int frontA, int backA, int B[], int n, int frontB, int backB, int lowSize, int isEven) {
        double res;
        if (isEven) {
           if (frontA < m-1 && B[lowSize+frontB] >= A[frontA+1])
                res = ((double)A[frontA] + A[frontA+1])/2;
           else {
                if (lowSize + frontB < n-1) {
                    if (A[frontA] <= B[lowSize+frontB-1])
                        res = ((double)B[lowSize+frontB] + B[lowSize+frontB-1])/2;
                    else
                        res = ((double)B[lowSize+frontB] + min(B[lowSize+frontB+1], A[frontA]))/2;
                }
                else {
                        res = ((double)B[lowSize+frontB] + A[frontA])/2;
                }
            }
        }
        else {
            if (A[frontA] < B[frontB+lowSize-1])
                return B[frontB+lowSize-1];
            else
                res = min(B[lowSize+frontB], A[frontA]);
        }
        return res;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // squeeze the range not the index
        // compare two array's middle index element value
        // if the (upper range) > (larger ones' upper part) , eliminate larger one's upper part
        // if the (lower range) > (smaller one's lower part) , eliminate smaller one's lower part
        int isEven = ((m + n)%2 == 0) ? 1 : 0;
        int med = (m + n)/2;
        int low = 0; 
        int high = m + n - 1;
        int frontA, backA, frontB, backB, midA, midB;
        int lowSize, highSize;
        double res;
        frontA = frontB = 0;
        backA = m - 1;
        backB = n - 1;
        if (isEven) {
            lowSize = med - low - 1;
            highSize = high - med + 1;
        }
        else {
            lowSize = med - low;
            highSize = high - med;
        }
        if (m == 0) 
            return preGetRes(B, isEven, lowSize);
        if (n == 0)
            return preGetRes(A, isEven, lowSize);

        while (frontA < backA && frontB < backB) {
            midA = (frontA + backA)/2;
            midB = (frontB + backB)/2;
            if (lowSize > highSize) {
                if (A[midA] < B[midB] || (A[midA] == B[midB] && A[midA-1] < B[midB-1])) {
                    lowSize -= (midA - frontA + 1);
                    frontA = midA + 1;
                }
                else if (A[midA] > B[midB] || A[midA] == B[midB] && A[midA-1] >= B[midB-1]) {
                    lowSize -= (midB - frontB + 1);
                    frontB = midB + 1;
                }
            }
            else {
                if (A[midA] < B[midB] || (A[midA] == B[midB] && A[midA+1] < B[midB+1])) {
                    highSize -= (backB - midB);
                    backB = midB;
                }
                else if (A[midA] > B[midB] || A[midA] == B[midB] && A[midA+1] >= B[midB+1]) {
                    highSize -= (backA - midA);
                    backA = midA;
                }
            }
        }
        if (frontA >= backA) {
            return postGetRes(A, m, frontA, backA, B, n, frontB, backB, lowSize, isEven);    
        }
        else if (frontB >= backB) {
            return postGetRes(B, n, frontB, backB, A, m, frontA, backA, lowSize, isEven);
        }
    }
};


int main() {
    int A[] = {1,4};
    int B[] = {2,3};
    Solution sl;
    cout<<sl.findMedianSortedArrays(A, 2, B, 2)<<endl;
    return 1;
}
