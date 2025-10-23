/*
 * @lc app=leetcode id=3669 lang=cpp
 *
 * [3669] Balanced K-Factor Decomposition
 */

// @lc code=start

// Without start, for n = 12, k = 3, you could generate:

// [2,2,3] ✅

// [2,3,2] ❌ (same numbers, just reordered)

// [3,2,2] ❌

// All of these multiply to 12, but they are the same combination in our problem.
class Solution {
public:

    vector<int> ans;
    int diff = INT_MAX;

    void check(vector<int>& curr){
        int n = curr.size();
        int mx  = curr[n - 1];
        int mn  = curr[0];
        if(mx - mn < diff){
            diff = mx - mn;
            ans = curr;
        }
    }

    void helper(int n , int k , int start ,vector<int>& curr){

       if(k==1){
          if(n >= start){
                curr.push_back(n);
                check(curr);
                curr.pop_back();
          }
       }

        for(int i  = start ; i <= n ; i++){
              
            if(n % i == 0){
                curr.push_back(i);
                helper(n / i , k - 1 , i , curr);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {

        helper(n,k,1,vector<int>());

        return ans;
    }
};
// @lc code=end

