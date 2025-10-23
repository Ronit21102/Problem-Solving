/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        bool flag = false;
        for(int i = k-1 ; i< n ;i++ ) {
            
            for(int j = i -k+1 ;j < i ;j++){
                if(nums[j] >= nums[j+1]) {
                    flag = false;
                    break;
                }else{
                    flag = true;
                }  
            }
            for()
        }
    }
};
// @lc code=end

