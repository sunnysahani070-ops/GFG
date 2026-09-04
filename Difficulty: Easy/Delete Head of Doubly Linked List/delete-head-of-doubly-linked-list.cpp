class Solution {
public:
    Node* deleteHead(Node* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node* prev = head;
        head = head->next;

        head->prev = nullptr;
        prev->next = nullptr;

        delete prev;
        return head;
    }
};