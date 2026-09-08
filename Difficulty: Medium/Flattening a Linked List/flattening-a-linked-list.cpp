class Solution {
  public:
    // Custom comparator for the priority queue to create a min-heap
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    Node* flatten(Node* root) {
        if (!root) return nullptr;

        priority_queue<Node*, vector<Node*>, compare> pq;

        // Push the head nodes of all the sub-linked lists into the min-heap
        Node* curr = root;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }

        // Dummy node to help build the flattened list
        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Process the min-heap until it's empty
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();

            // Connect the smallest node to the bottom of our result list
            tail->bottom = temp;
            tail->next = nullptr; // Ensure next pointers are nullified
            tail = tail->bottom;

            // If the popped node has a bottom child, push it into the min-heap
            if (temp->bottom) {
                pq.push(temp->bottom);
            }
        }

        tail->bottom = nullptr; // Ground the final node

        Node* ans = dummy->bottom;
        delete dummy;
        return ans;
    }
};