//TODO add to github

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode *preValid = NULL, *scan;
        scan = head;
        int pivot;
        while (scan->next != NULL) {
            pivot = scan->val;
            if (scan->next->val != pivot) {
                if (preValid == NULL) {
                    preValid = scan;
                    head = preValid;
                }
                else {
                    preValid->next = scan;
                    preValid = scan;
                }
                scan = scan->next;
            }
            else {
                while (scan != NULL && scan->val == pivot) {
                    scan = scan->next;
                }
                if (scan == NULL) {
                    if (preValid != NULL)
                        preValid->next = NULL;
                    break;
                }
                if (scan->next == NULL) {
                    if (preValid != NULL)
                        preValid->next = scan;
                    else {
                        preValid = scan;
                        head = preValid;
                    }
                }
            }
        }
        return (preValid == NULL) ? NULL : head;
    }
};