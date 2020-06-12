#include <bits/stdc++.h>

class Solution {
    //Write your code here

    private:
        stack <char> s;
        queue <char> q;
    
    public:
        void pushCharacter(char a) {
            s.push(a);
        }

        void enqueueCharacter(char a) {
            q.push(a);
        }

        char popCharacter() {
            char temp = s.top();
            s.pop();
            return temp;
        }

        char dequeueCharacter() {
            char temp = q.front();
            q.pop();
            return temp;
        }
};
