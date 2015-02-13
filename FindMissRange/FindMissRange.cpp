#include "../common/comm.h"

using namespace std;

class Solution {
public:
	/* 
	The following two function only used to transfer from integer to string representation, and overload two function
	*/
	string intToString(int start) {
		stringstream ss;
		ss<<start;
		return ss.str();
	}

	string intToString(int start, int end) {
		stringstream ss;
		ss<<start<<"->"<<end;
		return ss.str();
	}

	/*
	This helper function deal include the range from A[start] to A[end]
	Using Binary search to solve this problem, if A[end] - A[start] ==  end - start, then there is no gap from start to end
	Between two halves, it is necessary to deal with the middle gap from A[mid] to A[mid+1] scenario
	*/
	void findMissingRangesHelper(int A[], int start, int end, vector<string> &res) {
		string temp;
		if (end == start) 
			return;
		int mid = (start + end)/2;
		if ((A[mid] - A[start]) != (mid - start))
			findMissingRangesHelper(A, start, mid, res);
		if (A[mid+1] != A[mid] + 1) {
			temp = (A[mid+1] == A[mid]+2) ? intToString(A[mid]+1) : intToString(A[mid]+1, A[mid+1]-1);
			res.push_back(temp);
		}
		if (A[end] - A[mid+1] != end - mid - 1)
			findMissingRangesHelper(A, mid+1, end, res);
	}

	/*
	This function deal with the head and tail part.
	Other part from A[start] to A[end] is solved by helper function
	*/
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    	vector<string> res;
    	if (n == 0)
    		return res;
    	string temp;
    	if (A[0] != lower) {
    		temp = (A[0] == lower+1) ? intToString(lower) : intToString(lower, A[0]-1);
    		res.push_back(temp);
    	}
    	findMissingRangesHelper(A, 0, n-1, res);
    	if (A[n-1] != upper) {
    		temp = (A[n-1] == upper-1) ? intToString(upper) : intToString(A[n-1]+1, upper);
    		res.push_back(temp);
    	}
    	return res;
    }
};

int main() {
	cout<<"Hello World!"<<endl;
	Solution sl;
	cout<<sl.intToString(1,2)<<endl;
	return 1;
}