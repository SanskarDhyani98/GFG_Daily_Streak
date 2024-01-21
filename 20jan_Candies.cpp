#include<iostream>
using namespace std;
struct Node {
	int key;
	Node *left, *right;
};
class Solution {
    int ans;
    public:
    int distributeCandy(Node* root) 
    {
        ans = 0;
        dfs(root);
        return ans;
    }

     int dfs(Node* node) {
        if (node == NULL) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        ans += abs(L) + abs(R);
        return node->key + L + R - 1;
    }
};