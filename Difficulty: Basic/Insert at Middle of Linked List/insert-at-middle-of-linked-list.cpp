/* Strucutre of a link list node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* insertInMiddle(Node* head, int x) {
        if (head == nullptr) {
            return new Node(x);
        }

        Node* slow = head;
        Node* fast = head->next; 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(x);
        newNode->next = slow->next;
        slow->next = newNode;

        return head;
    }
};