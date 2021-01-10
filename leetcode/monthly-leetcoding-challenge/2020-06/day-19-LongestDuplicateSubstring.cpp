/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }
    
    int search (int len, int a, long long modulus, int n, vector <int> &nums) {
        long long h = 0;
        for (int i = 0; i < len; ++i){
            h = (h * a + nums[i]) % modulus;
        }
        
        unordered_set <long long> seen;
        seen.insert(h);
        
        long long alen = 1;
        for (int i = 1; i <= len; ++i){
            alen = (alen * a) % modulus;
        }
        
        for (int start = 1; start < n - len + 1; ++start){
            h = (h * a - nums[start-1] * alen % modulus + modulus) % modulus;
            h = (h + nums[start+len-1]) % modulus;
            if (seen.find(h) != seen.end()){
                return start;
            }
            seen.insert(h);
        }
        return -1;
    }
    
    string longestDupSubstring(string S) {
        int n = S.size(), a = 26, left, right, mid, start;
        long long modulus = pow(2, 32);
        vector <int> nums(n);

        for (int i = 0; i < n; ++i){
            nums[i] = S[i] - 'a';
        }

        left = 1;
        right = n;
        while (left != right){
            mid = left + (right-left)/2;
            if (search(mid, a, modulus, n, nums) != -1){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        start = search (left-1, a, modulus, n, nums);
        return start != -1 ? S.substr(start, left - 1) : "";
    }
};