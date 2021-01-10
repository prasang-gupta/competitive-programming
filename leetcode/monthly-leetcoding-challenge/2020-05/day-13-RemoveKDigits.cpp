/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }

    string removeKdigits(string num, int k) {
        vector <char> res;
        string result = "";
        int breakflag = 0;
        for (int i = 0; i < num.size(); ++i){
            if (res.size() == 0){
                res.push_back(num[i]);
                continue;
            }
            if (res.back() <= num[i]){
                res.push_back(num[i]);
                continue;
            }
            while(res.size() != 0 && res.back() > num[i]){
                if (res.size() + num.size() - i == num.size() - k){
                    while(i < num.size()){
                        res.push_back(num[i++]);
                    }
                    breakflag = 1;
                    break;
                }
                res.pop_back();
            }
            if (breakflag){
                break;
            }
            res.push_back(num[i]);
        }
        
        int nonzero = 1;
        for (int i = 0; i < num.size() - k; ++i){
            if (nonzero && res[i] == '0'){
                continue;
            }
            if (nonzero && res[i] != '0'){
                nonzero = 0;
            }
            result += res[i];
        }
        
        return (result == "") ? "0" : result;
    }
};