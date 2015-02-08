#include "../common/comm.h"
class Solution {
private:
    vector<int> indata;
    vector<int> postdata;
public:
    TreeNode *buildTreeHelper(int &indRoot, int start, int end) {
        TreeNode *ret;
        if (start > end)
            return NULL;
        vector<int>::iterator it;
        it = find(indata.begin()+start, indata.begin()+end+1, postdata[indRoot]);
        ret = new TreeNode(*it);
        indRoot--;
        TreeNode *right, *left;
        right = buildTreeHelper(indRoot, it-indata.begin()+1, end);
        ret->right = right;
        left = buildTreeHelper(indRoot, start, it-indata.begin()-1);
        ret->left = left;
        return ret;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        indata = inorder;
        postdata = postorder;
        int sz = postorder.size();
        int indRoot = sz-1;
        return buildTreeHelper(indRoot, 0, sz-1);
    }
};

int main() {
    int in[] = {1,2,3,4};
    int post[] = {2,1,4,3};
    vector<int> inorder(in, in+4);
    vector<int> postorder(post, post+4);
    Solution sl;
    TreeNode* root;
    root = sl.buildTree(inorder, postorder);
    cout<<root->val<<endl<<root->right->val<<endl<<root->left->val<<endl;
    return 1;
}
