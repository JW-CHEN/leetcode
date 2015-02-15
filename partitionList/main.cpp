#include "../common/comm.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return head;
        ListNode *ptSmall, *ptLarge = NULL, *scan;
        int deleteFlag = 0;
        scan = head;
        if (scan->val < x) 
            ptSmall = scan;
        else {
            ptSmall = new ListNode(0);
            ptSmall->next = scan;
            ptLarge = scan;
            deleteFlag = 1;
        }
        ListNode *tmp, *preScan;
        int first = 1;
        while (scan->next != NULL) {
            preScan = scan;
            scan = scan->next;
            if (ptLarge != NULL && scan->val < x) {
                tmp = ptSmall->next;
                ptSmall->next = scan;
                preScan->next = scan->next;
                scan->next = tmp;
                if (deleteFlag == 1 && first == 1)
                    head = scan;
                ptSmall = scan;
                scan = preScan;
                if (first == 1) 
                    first = 0;
            }
            if (ptLarge == NULL) {
                if (scan->val < x)
                    ptSmall = scan;
                else 
                    ptLarge = scan;
            }
        }
        return head;
    }   
};

int main() {
    cout<<"Hello Word!"<<endl;
    return 1;
}