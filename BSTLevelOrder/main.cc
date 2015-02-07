#include "../common/comm.h"
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        int currLen = 1;
        int nextLen;
        int index = 1; // start from 1
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp;
        vector<int> curr;
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if (index == 1) {
                nextLen = 0;
            }
            curr.push_back(tmp->val);
            if (tmp->left != NULL) {
                que.push(tmp->left);
                nextLen++;
            }
            if (tmp->right != NULL) {
                que.push(tmp->right);
                nextLen++;
            }
            index++;
            if (index > currLen) {
                currLen = nextLen;
                index = 1;
                res.push_back(curr);
                curr.erase(curr.begin(), curr.end());
            }
        }
        vector<vector<int> > realRes;
        int sz = res.size();
        for (int i = sz-1; i >= 0; i--) {
            realRes.push_back(res[i]);
        }
        return realRes;
    }
};
