/* Structure of linked list Node
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
    int solve(Node* head) {
        if (head == nullptr)
            return 1;

        int carry = solve(head->next);

        head->data += carry;
        carry = head->data / 10;
        head->data %= 10;

        return carry;
    }

public:
    Node* addOne(Node* head) {
        int carry = solve(head);

        if (carry) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};