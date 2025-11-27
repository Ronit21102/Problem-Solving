/*
 * @lc app=leetcode id=3686 lang=cpp
 *
 * [3686] Number of Stable Subsequences
 */

// @lc code=start
class Solution {
public:
 
int mod = 1e9 + 7;
int helper(int ind , int prev,int beforePrev,vector<int>&nums){
       
    int not_take = helper(ind+1,prev,beforePrev,nums);

    int take = 0;
    if(prev == -1 && beforePrev == -1){
        take = 1 + helper(ind+1,nums[ind],beforePrev,nums)%mod;
    }else if(beforePrev == -1){
        take = 1+helper(ind+1,nums[ind],prev,nums);
    }else {
        if(nums[ind] != prev || nums[ind] != beforePrev)
        take = 1 + helper(ind+1,nums[ind],prev,nums)%mod;
    }
    return (take + not_take)%mod;
}
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        return helper(0,-1,-1,nums)%mod;
    }
};
// @lc code=end

