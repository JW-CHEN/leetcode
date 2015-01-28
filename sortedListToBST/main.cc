#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public: 
    /* 
    remember !!! in C++ if you want your pointer to change when go out of the function use reference as well
    The idea of this ALG is that: if you know the totoal number of element, even you can not access half of it in O(1)
        But whenever you know the index, you can know it is in the left tree of the root or right tree
    The ordering of ascend list is just the ordering of midOrder of the tree (this ordering of tree with monotonically
        increasing is just the condition for Binary search tree.
    */
    TreeNode *buildBST(ListNode* &head, int start, int end) {
        TreeNode *res, *left, *right;
        if (start > end)
            return NULL;
        if (start == end) {
            res = new TreeNode(head->val);
            head = head->next;
            return res;
        }
        int mid = (start + end)/2;
        left = buildBST(head, start, mid-1);
        // mid one as the root
        res = new TreeNode(head->val);
        head = head->next;
        right = buildBST(head, mid+1, end);
        res->left = left;
        res->right = right;
        return res;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            len++;
            tmp = tmp->next;
        }
        if (len == 0)
            return NULL;
        tmp = head;
        return buildBST(tmp, 0, len-1);
    }
};

    
/*
    This is just a test class written before to check whether a tree is a balanced tree
*/
class BalanceCheck {
public:
    int isBalancedHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lt_height, rt_height;
        if ((lt_height = isBalancedHeight(root->left)) == -1)
            return -1;
        if ((rt_height = isBalancedHeight(root->right)) == -1)
            return -1;
        if (abs(lt_height - rt_height) > 1)
            return -1;
        else
            return max(lt_height, rt_height) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return isBalancedHeight(root) != -1 ? true : false;
    }
};

int main() {
    Solution sl;
    TreeNode* result;
    ListNode* head = new ListNode(3);
    ListNode* tmp = head;
    tmp->next = new ListNode(5);
    tmp = tmp->next;
    tmp->next = new ListNode(8);
    /*
    for (int i = 1; i < 10; i++) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;    
    }
    */
    result = sl.sortedListToBST(head);
    cout<<result->val<<endl<<result->left->val<<endl<<result->right->val<<endl;
    BalanceCheck bck;
    cout<<"is blanced tree or not: "<<bck.isBalanced(result)<<endl;
    cout<<"Hello World!"<<endl;
    return 1;
}
