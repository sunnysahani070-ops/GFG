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
        // code here
        int freq[3]={0};
        Node* temp=head;
        while(temp){
            freq[temp->data]++;
            temp=temp->next;
        }
        temp=head;
        while(freq[0]!=0){
            temp->data=0;
            temp=temp->next;
            freq[0]--;
            
            
        }
        while(freq[1]!=0){
            temp->data=1;
            temp=temp->next;
            freq[1]--;
            
            
        }while(freq[2]!=0){
            temp->data=2;
            temp=temp->next;
            freq[2]--;
            
            
        }
        return head;
    }
};