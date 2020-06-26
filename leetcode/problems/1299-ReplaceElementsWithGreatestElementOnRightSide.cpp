/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    vector<int> replaceElements(vector<int>& arr) {
        int curelem, size = arr.size();
        if (size == 1){
            arr[0] = -1;
            return arr;
        }
        
        for (int i = size-2; i >= 0; --i){
            if (i == size-2){
                curelem = arr[size-1];
                arr[size-1] = -1;
            }
            
            if (arr[i] > curelem){
                int temp = curelem;
                curelem = arr[i];
                arr[i] = temp;
            }
            else{
                arr[i] = curelem;
            }
        }
        return arr;
    }
};