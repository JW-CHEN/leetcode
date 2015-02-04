/*
The purpose of this iterator is start from the least member
Each next operation will fetch the next smallest element if itself is removed
hasNext is simply judge whether there is next element exist
*/
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
    //All the left children series should be pushed to stack first
    //until get the least number
        TreeNode *tmp = root;
        while (tmp != NULL) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res;
        TreeNode *curr;
        // get next smallest number from the top of stack
        curr = st.top();
        st.pop();
        res = curr->val;
        // check whether there are smaller number need to be push to stack
        if (curr->right != NULL) {
            // right child are always checked after its parents have been checked (in-order traverse)
            curr = curr->right;
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
        }
        return res;
    }
};

