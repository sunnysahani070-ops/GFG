class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string &word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string &word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
    
    bool isPrefix(string &word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};