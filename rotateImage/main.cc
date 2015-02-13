#include "../common/comm.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	int sz = matrix.size();
    	int temp, curr;
     	for (int i = 0; i < sz/2; i++) {
     		for (int j = 0; j < sz - 1 - 2*i; j++) {
     			// up to right
     			curr = matrix[i][i+j];
     			temp = matrix[i+j][sz-1-i];
     			matrix[i+j][sz-1-i] = curr;
     			// right to bottom
     			curr = temp;
     			temp = matrix[sz-1-i][sz-1-i-j];
     			matrix[sz-1-i][sz-1-i-j] = curr;
     			//bottom to left
     			curr = temp;
     			temp = matrix[sz-1-i-j][i];
     			matrix[sz-1-i-j][i] = curr;
     			//left to top
     			curr = temp;
     			temp = matrix[i][i+j];
     			matrix[i][i+j] = curr;
     		}
     	}
    }
};

int main() { 
	cout<<"Hello World!"<<endl;
	return 1;
}