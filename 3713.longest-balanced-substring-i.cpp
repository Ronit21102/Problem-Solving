/*
 * @lc app=leetcode id=3713 lang=cpp
 *
 * [3713] Longest Balanced Substring I
 */

// @lc code=start
class Solution {
public:
    bool helper(unordered_map<char,int>& mp){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it : mp){
            mini = min(mini , it.second);
            maxi = max(maxi , it.second);
        }

        return mini == maxi;

    }
    int longestBalanced(string s) {
        
        int n = s.size();
        int ans  = 0;
        for(int i = 0 ; i < n ; i++){
            unordered_map<char,int> mp;
            for(int j = i ; j < n ; j++){

                mp[s[j]]++;
                if(helper(mp)){
                    ans = max(ans , j - i + 1);
                }

           }
       }
       return ans;
   }
};
// @lc code=end


// @lc code=end

