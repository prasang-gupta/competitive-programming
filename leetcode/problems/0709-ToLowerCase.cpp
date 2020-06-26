/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    string toLowerCase(string str) {
        for (auto &s : str){
            if (s >= 'A' && s <= 'Z'){
                s += 'a' - 'A';
            }
        }
        return str;
    }
};