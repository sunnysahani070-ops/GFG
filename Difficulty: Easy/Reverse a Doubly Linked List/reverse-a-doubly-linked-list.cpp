/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if (head == NULL)
            return NULL;

        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {
            
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        
        if (temp != NULL)
            head = temp->prev;

        return head;
    }
};