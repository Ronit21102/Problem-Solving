 /*
 * @lc app=leetcode id=3542 lang=cpp
 *
 * [3542] Minimum Operations to Convert All Elements to Zero
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        stack<int> st;
        int ans = 0;
        int n  = nums.size();

        for(int i = 0 ; i < n ; i++){

            while(!st.empty() && st.top() > nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(nums[i]);
                ans++;
            }
            else
            if(st.top() < nums[i]){
                st.push(nums[i]);
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

