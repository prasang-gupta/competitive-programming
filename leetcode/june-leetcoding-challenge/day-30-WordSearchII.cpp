/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

struct TrieNode{
    string item;
    vector <TrieNode*> next;
    
    TrieNode() {
        item = "";
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
        
        iter->item = word;
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
        if (iter->item == word){
            return true;
        }
        return false;
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

class Solution {
public:
    set <string> result;
    
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    void dfs (vector<vector<char>>& board, vector <vector <bool> > &visited, string str, int i, int j, Trie* trie) {
        int m = board.size(), n = board[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n){
            return;
        }
        if (visited[i][j]){
            return;
        }
        
        str += board[i][j];
        
        if (!trie->startsWith(str)){
            return;
        }
        if (trie->search(str)){
            result.insert(str);
            cout << str << endl;
        }
        
        visited[i][j] = true;
        dfs (board, visited, str, i+1, j, trie);
        dfs (board, visited, str, i-1, j, trie);
        dfs (board, visited, str, i, j+1, trie);
        dfs (board, visited, str, i, j-1, trie);
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        int m = board.size(), n = board[0].size();
        vector <vector <bool> > visited (m, vector <bool> (n, false));
        vector <string> ans;
        
        for (auto const & w : words){
            trie->insert(w);
        }
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                dfs (board, visited, "", i, j, trie);
            }
        }
        
        ans.assign(result.begin(), result.end());
        return ans;
    }
};