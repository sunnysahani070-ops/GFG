/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minValue(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        
        while(root->left!=NULL){
            root=root->left;
            
        }
        
        return root->data;
        
    }
};