/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
public:
    Node* removeDuplicates(Node* headRef) {
        if (!headRef) return headRef;

        Node* curr = headRef;
        Node* temp = headRef->next;

        while (temp) {
            if (curr->data == temp->data) {
                Node* del = temp;

                curr->next = temp->next;

                if (temp->next)
                    temp->next->prev = curr;

                temp = temp->next;
                delete del;
            } else {
                curr = temp;
                temp = temp->next;
            }
        }

        return headRef;
    }
};