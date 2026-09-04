/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node* newNode = new Node(x);

        if (head == nullptr)
            return newNode;

        Node* curr = head;

        // Move to the p-th node
        for (int i = 0; i < p && curr != nullptr; i++) {
            curr = curr->next;
        }

        // If p is invalid
        if (curr == nullptr)
            return head;

        newNode->next = curr->next;
        newNode->prev = curr;

        if (curr->next)
            curr->next->prev = newNode;

        curr->next = newNode;

        return head;
    }
};