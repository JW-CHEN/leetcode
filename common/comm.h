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
    int x;
    TreeNode *l;
    TreeNode *r;
    TreeNode(int x) : x(x), l(NULL), r(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
            tmp->l = new TreeNode((int)testcase[ind] - 48);
            que.push(tmp->l);
        }
        ind++;
        if (testcase[ind] != '#') {
            tmp->r = new TreeNode((int)testcase[ind] - 48);
            que.push(tmp->r);
        }
        ind++;
    }
    return root;
}
