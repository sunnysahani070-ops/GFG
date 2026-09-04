/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    Node* delPos(Node* head, int x) {
        if (head == NULL) {
            return NULL;
        }

        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }

        Node* curr = head;
        for (int i = 1; i < x && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            return head;
        }

        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }

        delete curr;

        return head;
    }
};