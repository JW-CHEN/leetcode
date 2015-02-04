//TODO implement these heap operation 
#include "comm.h"

using namespace std;

int main() {
    int a[] = {1,2,3,4,5};
    vector<int> v(a,a+5);
    // make_heap: BuildHeap() 
    make_heap(v.begin(), v.end());
    cout<<v.front()<<endl;
    // pop_heap: DeleteMax (STL only support maximum heap
    pop_heap(v.begin(), v.end());
    // pop_back: Delete last elem in the heap
    // This function always use after pop_heap()
    // pop_heap() can format the heap and leave last number free, so need to pop_back()
    v.pop_back();
    cout<<v.front()<<endl;
    // first add number to the tail of vector and wait to be formatted
    v.push_back(10);
    // format, given first len-1 elem should be in heap structure
    push_heap(v.begin(), v.end());
    cout<<v.front()<<endl;
    return 1;
}
