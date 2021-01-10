/*
Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set <string> dict;
        for (int i = 0; i < wordList.size(); ++i){
            dict.insert(wordList[i]);
        }
        
        if (dict.find(endWord) == dict.end()){
            return 0;
        }
        
        int depth = 0, wordsize = beginWord.size();
        queue <string> q;
        q.push(beginWord);
        while (!q.empty()){
            ++depth;
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i){
                string curword = q.front();
                q.pop();
                for (int j = 0; j < wordsize; ++j){
                    char orig = curword[j];
                    for (char c = 'a'; c <= 'z'; ++c){
                        curword[j] = c;
                        if (curword == endWord){
                            return depth+1;
                        }
                        if (dict.find(curword) == dict.end()){
                            continue;
                        }
                        dict.erase(curword);
                        q.push(curword);
                    }
                    curword[j] = orig;
                }
            }
        }
        return 0;
    }
};
