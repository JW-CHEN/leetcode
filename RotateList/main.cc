#include <../comm/comm.h>

class Solution {
public:
/*
    First reach the last element, calculate the length of list
    Then link the last element to the head
    Find the split point at (len - k%len - 1) place
*/
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0)
            return head;
        int len = 1;
        ListNode *tmp = head;
        while (tmp->next != NULL) {
            len++;
            tmp = tmp->next;
        }
        tmp->next = head;
        k = len - k%len - 1;
        ListNode *slow = head;
        while (k--) {
            slow = slow->next;
        }
        if (slow->next == NULL)
            return head;
        ListNode *res = slow->next;
        slow->next = NULL;
        return res;
    }
};
