#include<bits/stdc++.h>
using namespace std;

int main() {
    if(root == NULL) return 0;

        int LH = maxDepth(root->left);
        int RH = maxDepth(root->right);

        return max(LH,RH) + 1;
}