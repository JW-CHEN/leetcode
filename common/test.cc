#include "comm.h"

int main() {
    int x = 10;
    int &r = x;
    int y = 5;
    r = y;
    r = 20;
    cout<<x<<endl<<r<<endl<<y<<endl;
    cout<<&x<<endl<<&r<<endl<<&y<<endl;
    return 1;
}
    
