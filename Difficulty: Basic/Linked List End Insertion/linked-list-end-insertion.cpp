/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Create a new node with the given data
        Node* newNode = new Node(x);

        // If the linked list is empty, the new node becomes the head
        if (head == nullptr) {
            return newNode;
        }

        // Otherwise, traverse to the very last node in the list
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        // Attach the new node to the end of the list
        curr->next = newNode;

        // Return the original head of the list
        return head;
    }
};