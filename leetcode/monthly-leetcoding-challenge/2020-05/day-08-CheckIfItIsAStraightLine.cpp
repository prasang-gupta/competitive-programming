/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

class Solution {
public:
    Solution () {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope,x1,x2,y1,y2;
        if (coordinates.size() == 2){
            return true;
        }
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        x2 = coordinates[1][0];
        y2 = coordinates[1][1];
        
        if (x2 == 0 && x1 == 0){
            for (int i = 2; i < coordinates.size(); ++i){
                if (coordinates[i][0] != 0){
                    return false;
                }
            }
            return true;
        }
        
        slope = (y2-y1)/(x2-x1);
        
        for (int i = 2; i < coordinates.size(); ++i){
            if (slope != (coordinates[i][1]-y1)/(coordinates[i][0]-x1)){
                return false;
            }
        }
        return true;
    }
};