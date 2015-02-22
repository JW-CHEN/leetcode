class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) 
            return head;
        ListNode* temp = head;
        ListNode* tempNext = temp->next;
        ListNode* nextHead;
        ListNode* prev = new ListNode(0);
        head = tempNext;
        while (1) {
            nextHead = temp->next->next;
            prev->next = tempNext;
            tempNext->next = temp;
            temp->next = nextHead;
            if (nextHead == NULL)
                break;
            prev = temp;
            temp = nextHead;
            tempNext = temp->next;
            if (tempNext == NULL)
                break;
        }
        return head;
    }
};