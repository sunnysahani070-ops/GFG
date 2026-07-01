
class Solution {
  public:
    int getCount(Node* head) {
        int count=0;
        Node* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
        
    }
};