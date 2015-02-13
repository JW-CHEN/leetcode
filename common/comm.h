#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(char testcase[], int len) {
    TreeNode* root;
    queue<TreeNode*> que;
    root = new TreeNode((int)testcase[0] - 48);
    que.push(root);
    int ind = 1;
    TreeNode* tmp;
    while (!que.empty()) {
        tmp = que.front();
        que.pop();
        if (ind >= len) 
            return root;
        if (testcase[ind] != '#') {
            tmp->left = new TreeNode((int)testcase[ind] - 48);
            que.push(tmp->left);
        }
        ind++;
        if (testcase[ind] != '#') {
            tmp->right = new TreeNode((int)testcase[ind] - 48);
            que.push(tmp->right);
        }
        ind++;
    }
    return root;
}
