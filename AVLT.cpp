#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    int height;
    int balanceFactor;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        data = val;
        height = 0;
        left = right = nullptr;
    }
};

struct AVL{

    TreeNode *root;

    AVL() {
        root = NULL;
    }

    int Height(TreeNode *Node){
        if(Node == nullptr) return 0;
        return Node->height;
    }

    TreeNode *rightRotate(TreeNode *P){
        TreeNode *X = P->left;
        TreeNode *Y = X->right;
        //changes
        X->right = P;
        P->left = Y;

        X->height = max(Height(X->left), Height(X->right)) + 1;
        P->height = max(Height(P->left), Height(P->right)) + 1;
        return X;
    }

    TreeNode *leftRotate(TreeNode *P){
        TreeNode *X = P->right;
        TreeNode *Y = X->left;
        //changes
        X->left = P;
        P->right = Y;

        X->height = max(Height(X->left), Height(X->right)) + 1;
        P->height = max(Height(P->left), Height(P->right)) + 1;
        return X;
    }
    TreeNode *Add(TreeNode *root, int val){
        if(root == nullptr) return new TreeNode(val);
        if(val < root->data){
            root->left = Add(root->left, val);
        } else if(val > root->data){
            root->right = Add(root->right, val);
        }

        root->balanceFactor = Height(root->left) - Height(root->right);
        root->height = max(Height(root->left), Height(root->right))+1;

        if(root->balanceFactor > 1 && val < root->left->data){
            root = rightRotate(root);
        }
        if(root->balanceFactor > 1 && val > root->left->data){
            root->left = leftRotate(root->left);
            root = rightRotate(root->right);

        }
        if(root->balanceFactor < -1 && val < root->right->data){
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        if(root->balanceFactor < -1 && val > root->right->data){
            root = leftRotate(root);
        }
        return root;
    }
    void Insert(int val){
        root = Add(root, val);
    }
    TreeNode *FindMin(TreeNode *Node){
        while (Node && Node->left) Node = Node->left;
        return Node;
    }
    TreeNode *Delete(TreeNode *root, int val){
        if(root == nullptr) return nullptr;
        if(val < root->data){
            root->left = Delete(root->left, val);
        } else if(val > root->data){
            root->right = Delete(root->right, val);
        } else {
            //0 child
            if(root->left == nullptr && root->right == nullptr){
                delete(root);
            }
            //1 child
             else if(root->left == nullptr || root->right == nullptr){
                TreeNode *temp;
                if(root->left == nullptr){
                    temp = root->right;
                } else {
                    temp = root->left;
                }
                root->data = temp->data;
                delete(temp);
            } 
            //2 child
            else{
                TreeNode *temp= FindMin(root->right);                
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
            root->balanceFactor = Height(root->left) - Height(root->right);
        root->height = max(Height(root->left), Height(root->right))+1;
        }
         if(root->balanceFactor > 1 && root->left->balanceFactor >= 0){
            root = rightRotate(root);
        } 
        if(root->balanceFactor > 1 && root->left->balanceFactor <= -1){
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        if(root->balanceFactor < -1 && root->right->balanceFactor <= 0){
            root = leftRotate(root);
        }
        if(root->balanceFactor < -1 && root->right->balanceFactor >= 1){
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        return root;
    }
    void Remove(int val){
        root = Delete(root, val);
    }
};

int main() {
    AVL AVLTree;
    AVLTree.Insert(10);
    // AVLTree.Insert(30);
    AVLTree.Insert(20);
    AVLTree.Insert(5);
    AVLTree.Insert(70);
    AVLTree.Insert(90);
    AVLTree.Remove(90);
    AVLTree.Remove(70);
    cout << AVLTree.root->data << endl;
}