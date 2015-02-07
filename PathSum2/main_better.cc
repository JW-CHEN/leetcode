#include "../common/comm.h"

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > finishedSearch;
        vector<int> currentSearch;
        pathDesend(root, sum, currentSearch, finishedSearch);
        return finishedSearch;
    }

    void pathDesend(TreeNode* current_root, int sum, vector<int> currentSearch, vector<vector<int> > & finishedSearch){
        if(current_root==NULL) return;
        currentSearch.push_back(current_root->val);
        if(sum == current_root->val && current_root->left==NULL && current_root->right==NULL){
              finishedSearch.push_back(currentSearch);
              return;
        }
        pathDesend(current_root->left, sum-current_root->val,currentSearch,finishedSearch);
        pathDesend(current_root->right,sum-current_root->val,currentSearch,finishedSearch);
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

