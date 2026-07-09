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
    int findCeil(Node* root, int x) {
        int ceil = -1;
        
        while (root != nullptr) {
            if (root->data == x) {
                return root->data;
            }
            
            if (root->data < x) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        
        return ceil;
    }
};
