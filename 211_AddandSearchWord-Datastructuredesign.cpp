class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWord(word, root);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
private:
    struct TrieNode {
        bool isword;
        vector<TrieNode*> next;  
        TrieNode(): isword(false), next(vector<TrieNode*> (26)){}   // Initialization.
        ~TrieNode() {
            for (TrieNode* n : next) {
                delete n;
            }
        }
    };
    TrieNode* root;
    
    void addWord(string word, TrieNode* root) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (cur->next[index] == NULL) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
        cur->isword = true;
    }
    
    bool search(string word, int step, TrieNode* cur) {
        if (step == word.length()) {
            return cur->isword;
        }
        if (word[step] != '.') {
            if (cur->next[word[step] - 'a'] == NULL) {
                return false;
            }
            return search(word, step + 1, cur->next[word[step] - 'a']);
        } else {
            bool res = false;;
            for (int i = 0; i <  26; ++i) {
                if (cur->next[i] != NULL) {
                    res = res || search(word, step + 1, cur->next[i]);
                }
            }
            return res;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */