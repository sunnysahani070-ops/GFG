/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertPos(Node* head, int pos, int val) {
        Node* newNode = new Node(val);

        if (pos == 1) {
            newNode->next = head;
            return newNode;
        }
        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }
        if (curr != nullptr) {
            newNode->next = curr->next;
            curr->next = newNode;
        }

        return head;
    }
};