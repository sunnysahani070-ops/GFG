/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next)
            return head;

        Node zeroDummy(0), oneDummy(0), twoDummy(0);

        Node* zero = &zeroDummy;
        Node* one = &oneDummy;
        Node* two = &twoDummy;

        Node* curr = head;

        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr;

        return zeroDummy.next;
    }
};