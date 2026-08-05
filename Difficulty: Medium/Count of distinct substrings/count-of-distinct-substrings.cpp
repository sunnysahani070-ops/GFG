#include <string>
#include <vector>

class Solution {
    struct Node {
        Node* links[26] = {nullptr};
        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }
        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }
        Node* get(char ch) {
            return links[ch - 'a'];
        }
    };

public:
    int countSubs(std::string& s) {
        int count = 0;
        Node* root = new Node();
        int n = s.length();

        for (int i = 0; i < n; i++) {
            Node* node = root;
            for (int j = i; j < n; j++) {
                if (!node->containsKey(s[j])) {
                    count++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }

        return count;
    }
};