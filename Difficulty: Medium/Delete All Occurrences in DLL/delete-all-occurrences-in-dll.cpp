/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
public:
    Node* deleteAllOccurOfX(Node* head, int x) {

        Node* curr = head;

        while (curr) {

            if (curr->data == x) {

                Node* nextNode = curr->next;

                if (curr->prev)
                    curr->prev->next = curr->next;
                else
                    head = curr->next;

                if (curr->next)
                    curr->next->prev = curr->prev;

                delete curr;
                curr = nextNode;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};