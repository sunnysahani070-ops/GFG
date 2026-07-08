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
    void paths(Node* root, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;

        path.push_back(root->data);

        
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        }
        else {
            paths(root->left, path, ans);
            paths(root->right, path, ans);
        }

      
        path.pop_back();
    }

public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;

        paths(root, path, ans);

        return ans;
    }
};