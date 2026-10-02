#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    int height;
    int balanceFactor;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        data = val;
        height = 0;
        left = right = NULL;
    }
};

struct AVLTree{
    TreeNode *root;
    AVLTree() {
        root = NULL;
    }
    int Height(TreeNode *Node) {
        if(Node == nullptr) return 0;
        return Node->height;
    }

    TreeNode *rightRotate(TreeNode *P){
        TreeNode *X = P->left;
        TreeNode *Y = X->right;

            //Changes
        X->right = P;
        P->left = Y;

            //Update Height of X and P
        X->height = max(Height(X->left), Height(X->right)) + 1;
        P->height = max(Height(P->left), Height(P->right)) + 1;
        return X;
    }

    TreeNode *leftRotate(TreeNode *P) {
            TreeNode *X = P->right;
            TreeNode *Y = X->left;

            //changes
            X->left = P;
            P->right = Y;
            X->height = max(Height(X->left), Height(X->right)) + 1;
            P->height = max(Height(P->left), Height(P->right)) + 1;   
            return X;         
    }

    TreeNode *ADD(TreeNode *root, int val) {
        if(root == nullptr) return new TreeNode(val);
        if(val < root->data) {
            root->left = ADD(root->left, val);
        } else if(val > root->data) {
            root->right = ADD(root->right, val);
        } else{
            return root;
        }
        root->balanceFactor = Height(root->left) - Height(root->right);
        root->height = max(Height(root->left), Height(root->right)) + 1;

        //Conditions for rotations
        //1. rightRotate - balanceFactor > 1 and val less than root left data
        //2. leftRotate - balanceFactor > -1 
        //3. rightRotateLeft - balanceFactor > 1 
        //4. leftRotateRight - balanceFactor > -1
        if(root->balanceFactor > 1 && val < root->left->data){
            root = rightRotate(root);
        }
        if(root->balanceFactor > 1 && val > root->left->data) {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        if(root->balanceFactor < -1 && val > root->right->data){//78 val root->right->data - 57
            root = leftRotate(root);
        }
        if(root->balanceFactor < -1 && val < root->right->data){
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        return root;
    }

    void Insert(int val) {
        root = ADD(root, val);
    }
    TreeNode *FindMin(TreeNode *Node){
        while(Node && Node->left) Node = Node->left;
        return Node;
    }
    //DELETE
    TreeNode *Delete(TreeNode *root, int val){
        if(root == nullptr) return nullptr;
        if(val < root->data){
            root = Delete(root->left, val);
        } else if(val > root->data){
            root = Delete(root->right, val);
        } else {
        //0 children
        if(root->left == nullptr && root->right == nullptr){
            free(root);
        } else if(root->left == nullptr || root->right == nullptr){
            TreeNode *temp;
            if(root->left == nullptr){
                temp = root->right;
            } else {
                temp = root->left;
            }
            root->data = temp->data;
            free(temp);
        } else{
            TreeNode *temp = FindMin(root->right);
            root->data = temp->data;
            free(temp);
        }
    }
        int balanceFactor = Height(root->left) - Height(root->right);
        root->height = max(Height(root->left), Height(root->right))+1;
        if(balanceFactor > 1 && val < root->left->data){
            root = rightRotate(root);
        } 
        if(balanceFactor > 1 && val > root->left->data){

        }
        if(balanceFactor < -1){
            root = leftRotate(root);
        }

    }

    void Remove(int val){
        root = Delete(root, val);
    }


    // void printInorder(TreeNode *root) {
    //     if (root == nullptr) return;
    //         printInorder(root->left);
    //         cout << root->data << " ";
    //         printInorder(root->right);
    // }

    // void Inorder() {
    //     printInorder(root);
    // }
};



int main() {
    AVLTree AVL;
    // int n;
    // cin >> n;
    // vector<int>arr(n);
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // } 
    // for(int i = 0; i < arr.size(); i++) {
    //     AVL.Insert(arr[i]);
    // }
    AVL.Insert(33);
    AVL.Insert(57);
    AVL.Insert(12);
    AVL.Insert(72);
    AVL.Insert(78);
    cout << AVL.root->data << " ";
}