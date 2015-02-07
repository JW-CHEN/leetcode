#include "../common/comm.h"

class Solution {

private:

    queue<TreeNode*> que;

    

public:

    void pushComplete(int len, vector<vector<int> > &res) {

        int currLen = len;

        int nextLen = 0;

        int index = 1; // start from 1

        TreeNode *tmp;

        vector<int> curr;

        while (!que.empty()) {

            tmp = que.front();

            que.pop();

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

            if (index > currLen)

                break;

        }

        if (que.empty()) {

            res.push_back(curr);

            return;

        }

        pushComplete(nextLen, res);

        res.push_back(curr);

    }



    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vector<vector<int> > res;

        if (root == NULL)

            return res;

        que.push(root);

        pushComplete(1, res);

        return res;

    }

};

