/*
 * @lc app=leetcode id=3695 lang=cpp
 *
 * [3695] Maximize Alternating Sum Using Swaps
 */

// @lc code=start
class DSU
{
private:
    vector<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int u = find(x);
        int v = find(y);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    void sett(int x, int y) { parent[x] = y; }
};
class Solution {
public:
    
    
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
         DSU dsu(n);

         unordered_map<int, vector<int>> components;
         unordered_set<int> leader;
         unordered_map<int,int>oddCount;

         for(auto &it : swaps){
             dsu.unionSets(it[0],it[1]);
         }

         for(int i = 0 ; i < n ; i++){
            int p = dsu.find(i);

            components[p].push_back(nums[i]);
            leader.insert(p);
            if(i % 2 == 1){
                oddCount[p]++;
            }
         }

            long long result = 0;

            for(auto &it :leader){
                vector<int>& vals = components[it];

                sort(vals.begin(),vals.end());
                 int odds = oddCount[it];
                 int oddSum = 0 , evenSum = 0;
                for(int i = 0 ; i < odds ; i++){
                    oddSum += vals[i];
                }
                for(int i = odds ; i < vals.size() ; i++){
                    evenSum += vals[i];
                }
                result += (long long)(evenSum - oddSum);
            }
            return result;
    }
};
// @lc code=end

