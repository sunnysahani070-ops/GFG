/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
public:
    // Helper function to merge two sorted linked lists using the bottom pointer
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        
        // Ensure the next pointer is set to nullptr as per flattening rules
        result->next = nullptr; 
        return result;
    }

    Node* flatten(Node* root) {
        // Base case: if list is empty or there is no next list
        if (!root || !root->next) {
            return root;
        }
        
        // Recur for the list on the right
        root->next = flatten(root->next);
        
        // Merge the current list with the flattened right list
        root = merge(root, root->next);
        
        return root;
    }
};