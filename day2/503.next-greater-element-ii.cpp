class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        

        stack<int> st;
        vector<int> ans;

        // second pass: real answers for first n elements
        for(int i = 2*n - 1 ; i >= 0 ; i--){
            int num = nums[i%n];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            if(i < n){
              if(st.empty()){
                ans.push_back(-1);
              }else{
                ans.push_back(st.top());
              }
            }
            st.push(num);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
