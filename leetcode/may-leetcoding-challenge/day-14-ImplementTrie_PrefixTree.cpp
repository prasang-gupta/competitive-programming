/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

struct TrieNode{
    bool isword;
    vector <TrieNode*> next;
    
    TrieNode(): isword(false) {
        next = vector <TrieNode*> (26,NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* iter = root;
        
        for (int i = 0; i < word.size(); ++i){
            if (iter->next[word[i]-'a'] == NULL){
                iter->next[word[i]-'a'] = new TrieNode();
            }
            iter = iter->next[word[i]-'a'];
        }
        
        iter->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* iter = root;
        
        for (int i = 0; i < word.size(); ++i){
            if (iter->next[word[i]-'a'] == NULL){
                return false;
            }
            iter = iter->next[word[i]-'a'];
        }
        return iter->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* iter = root;
        
        for (int i = 0; i < prefix.size(); ++i){
            if (iter->next[prefix[i]-'a'] == NULL){
                return false;
            }
            iter = iter->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();