class Solution {
public:
    ListNode *mergeTwoLists(ListNode* front, ListNode* back) {
        if (front == NULL)
            return back;
        if (back == NULL)
            return front;
        ListNode *res, *nextHead, *ptFront, *ptBack;
        res = front->val <= back->val ? front : back;
        nextHead = res;
        if (front->val <= back->val) {
            ptFront = nextHead->next;
            ptBack = back;
        }
        else {
            ptBack = nextHead->next;
            ptFront = front;
        }
        while (ptFront != NULL && ptBack != NULL) {
            if (ptFront->val <= ptBack->val) {
                nextHead->next = ptFront;
                nextHead = ptFront;
                ptFront = ptFront->next;
            }
            else {
                nextHead->next = ptBack;
                nextHead = ptBack;
                ptBack = ptBack->next;
            }
        }
        if (ptFront == NULL)
            nextHead->next = ptBack;
        else
            nextHead->next = ptFront;
        return res;
    }

    ListNode *mergeBS(vector<ListNode *> &lists, int start, int end) {
        if (start == end)
            return lists[start];
        int mid = (start + end)/2;
        ListNode *front, *back;
        front = mergeBS(lists, start, mid);
        back = mergeBS(lists, mid+1, end);
        return mergeTwoLists(front, back);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        return mergeBS(lists, 0, k-1);
    }
};
