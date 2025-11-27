/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution {
public:
    int moveI[4] = {0,1,0,-1};
    int moveJ[4] = {1,0,-1,0};

    bool isValid(int i , int j , int n , int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    int helper(int i , int j , vector<vector<int>>& heights,  ){
        

        int mini = INT_MAX;
        for(int k = 0 ; k<4 ;k++){
            int newI = i + moveI[k];
            int newJ = j + moveJ[k];

            if(isValid(newI,newJ,heights.size(),heights[0].size())){
                int effort = abs(heights[newI][newJ] - heights[i][j]);
                mini  = min(mini , max(effort, helper(newI,newJ,heights)));  
            }
        }
        return mini;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        return helper(0, 0, heights);
    }
};
// @lc code=end

