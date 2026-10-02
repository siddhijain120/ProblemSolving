#include<bits/stdc++.h>
using namespace std;

int main() {
     int height = 0;
        queue<TreeNode*>Q;
        if(root == NULL) return 0;
        Q.push(root);
        while(!Q.empty()) {
            int len = Q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* Node = Q.front();
                Q.pop();
                if(Node->left) {
                    Q.push(Node->left);
                }
                if(Node->right) {
                    Q.push(Node->right);
                }
            }
            height++;
        }
        return height;
}