/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    Node* markparents(Node* root, unordered_map<Node*, Node*>& parents_track, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target)
                targetNode = curr;

            if (curr->left) {
                parents_track[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parents_track[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parents_track;
        Node* targetNode = markparents(root, parents_track, target);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    flag = true;
                }

                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    flag = true;
                }

                if (parents_track.count(curr) && !visited[parents_track[curr]]) {
                    visited[parents_track[curr]] = true;
                    q.push(parents_track[curr]);
                    flag = true;
                }
            }

            if (flag)
                time++;
        }

        return time;
    }
};