/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
    bool check(Node* root){
        if(root == nullptr)
            return true;

        if(root->left == nullptr && root->right == nullptr)
            return true;

        int left = (root->left) ? root->left->data : 0;
        int right = (root->right) ? root->right->data : 0;

        if(root->data != left + right)
            return false;

        return check(root->left) && check(root->right);
    }

public:
    bool isSumProperty(Node *root) {
        return check(root);
    }
};