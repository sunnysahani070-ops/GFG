/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;

        while (curr) {
            if (curr->data == key) {
                // Find predecessor (maximum in left subtree)
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }

                // Find successor (minimum in right subtree)
                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }

                break;
            }
            else if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            }
            else {
                pre = curr;
                curr = curr->right;
            }
        }

        return {pre, suc};
    }
};