#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

struct BinarySearchTree{
    TreeNode *root = nullptr;

    TreeNode* Add(TreeNode *root, int val) {
        if(root == nullptr) return new TreeNode(val);
        if(val < root->data) {
            root->left = Add(root->left, val);
        } 
        else if(val > root->data) {
            root->right = Add(root->right, val);
        }
        //If there are any duplicates ignore
        return root;
    }

    void Insert(int val) {
        root = Add(root, val);
    }

    TreeNode *FindMin(TreeNode *Node){
        while(Node && Node->left) Node = Node->left;
        return Node;
    }

    TreeNode *Remove(TreeNode *root, int val) {
        if(root->left == NULL && root->right == NULL){
            free(root);
            return nullptr;
        }
        else if(root->left == NULL || root->right == NULL){
            TreeNode *temp;
            if(root->left == NULL){
                temp = root->right;
                root->data = temp->data;
            } else {
                temp = root->left;
                root->data = temp->data;
            }
            free(temp);
            return root;
        } else {
            TreeNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Remove(root->right, temp->data);
        }
    }
    void Delete(int val){
        root = Remove(root, val);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int>arr;
    BinarySearchTree Bst;
    for(int i = 0; i < arr.size(); i++) cin >> arr[i];
    for(int i = 0; i < arr.size(); i++) {
        Bst.Insert(arr[i]);
    }

}