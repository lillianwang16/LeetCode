//*****Initialize the vector, otherwise the content would be not weill-defined.
class TrieNode {
public:
    bool isend;
    //vector<TrieNode*> children;
    //int shared;             //For implementation of delete function.
    //TrieNode(): isend(false), children(vector<TrieNode*> (26)){}
    TrieNode* children[26] = {0};
    ~TrieNode() {
        for (auto child : children) {
            delete child;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        int i = 0;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->children[word[i] - 'a'] == NULL) {
                cur->children[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->children[word[i] - 'a'];
        }
        cur->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        int i = 0;
        while (i < word.length()) {
            if (cur->children[word[i] - 'a'] == NULL) {
                return false;
            }
            cur = cur->children[word[i] - 'a'];
            ++i;
        }
        return cur->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int i = 0;
        while (i < prefix.length()) {
            if (cur->children[prefix[i] - 'a'] == NULL) {
                return false;
            }
            cur = cur->children[prefix[i] - 'a'];
            ++i;
        }
        return true;
    }
    ~Trie() {
        delete root;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */