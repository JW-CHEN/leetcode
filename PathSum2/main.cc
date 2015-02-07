#include "../common/comm.h"

class Solution {
public:
    void reverseVector(vector<vector<int> > &res) {
        int sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < res[i].size()/2; j++) {
                swap(res[i][j], res[i][res[i].size()-1-j]);
            }
        }
    }
    
    vector<vector<int> > pathSumHelper(TreeNode *root, int sum) {
        vector<vector<int> > res, leftRet, rightRet;
        if (root == NULL) 
            return res;
        if (root->val == sum && root->left == NULL && root->right == NULL) {
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
            return res;
        }
        if (root->left != NULL) {
            leftRet = pathSumHelper(root->left, sum - root->val);
            if (leftRet.size() > 0) 
                for (int i = 0; i < leftRet.size(); i++) {
                    leftRet[i].push_back(root->val);
                    res.push_back(leftRet[i]);
                }
        }
        if (root->right != NULL) {
            rightRet = pathSumHelper(root->right, sum - root->val);
            if (rightRet.size() > 0) 
                for (int i = 0; i < rightRet.size(); i++) {
                    rightRet[i].push_back(root->val);
                    res.push_back(rightRet[i]);
                }
        }
        return res;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res = pathSumHelper(root, sum);
        reverseVector(res);
        return res;
    }
};

int main() {
    char testcase[] = {'1','2','#','3','#','4','#','5'};
    TreeNode *root = buildTree(testcase, 8);
    Solution sl;
    vector<vector<int> > res;
    res = sl.pathSum(root, 15);
    for (int i = 0; i < res[0].size(); i++) {
        cout<<res[0][i]<<endl;
    }
    return 1;
}
