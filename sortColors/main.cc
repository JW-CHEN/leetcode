#include "../common/comm.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        if (n == 0)
            return;
        int ind1 = -1, ind2 = -1;
        int prev = A[0];
        if (A[0] == 1)
            ind1 = 0;
        else if (A[0] == 2)
            ind2 = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] >= prev) {
                if (A[i] == 1 && ind1 == -1)
                    ind1 = i;
                else if (A[i] == 2 && ind2 == -1)
                    ind2 = i;
            }
            // other scenarios for 1->0, 2->1, 2->0
            else if (A[i] == 0 && prev == 1) {
                A[ind1] = 0;
                A[i] = 1;
                ind1++;
            }
            else if (A[i] == 0 && prev == 2) {
                A[i] = 2;
                if (ind1 == -1) {
                    A[ind2] = 0;
                }
                else {
                    A[ind1] = 0;
                    A[ind2] = 1;
                    ind1++;
                }
                ind2++;
            }
            else if (A[i] == 1 && prev == 2) {
                A[i] = 2;
                A[ind2] = 1;
                if (ind1 == -1) ind1 = ind2;
                ind2++;
            }
            prev = A[i];
        }
    }
};

int main() {
    cout<<"Hello World!"<<endl;
    return 1;
}