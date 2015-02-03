#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeSort(ListNode *head, int len) {
        if (len == 1)
            return head;
        ListNode *left, *right;
        ListNode *mid = head;
        ListNode *cut;
        int i = 0;
        while (i < len/2) {
            if (i == len/2-1)
                cut = mid;
            mid = mid->next;
            i++;
        }
        cut->next = NULL;
        left = mergeSort(head, len/2);
        right = mergeSort(mid, len-len/2);
        return merge(left, right, len);
    }
    
    ListNode *merge(ListNode *left, ListNode *right, int len) {
        ListNode *pleft = left;
        ListNode *pright = right;
        ListNode *ret = NULL;
        ListNode *tmp;
        while (pleft != NULL && pright != NULL) {
            if (pleft->val <= pright->val) {
                if (ret == NULL)
                    ret = pleft;
                while (pleft->next != NULL && pright->val > pleft->next->val) {
                    pleft = pleft->next;
                }
                tmp = pleft->next;
                pleft->next = pright;
                pleft = tmp;
            }
            else {
                if (ret == NULL)
                    ret = pright;
                while (pright->next != NULL && pleft->val > pright->next->val) {
                    pright = pright->next;
                }
                tmp = pright->next;
                pright->next = pleft;
                pright = tmp;
                cout<<"xxxx"<<endl;
            }
        }
        return ret;
    }

    ListNode *sortList(ListNode *head) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            len++;
            tmp = tmp->next;
        }
        if (len <= 1)
            return head;
        return mergeSort(head, len);
    }
};

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    Solution sl;
    ListNode *res = sl.sortList(head);
    cout<<res->val<<endl<<res->next->val<<endl;
    return 1;
}
