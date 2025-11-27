class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
       unordered_map<int,int> count;
       int i = 0 , j = 0 ;
         int maxFruits = 0 ;

         while(j < fruits.size()){

            count[fruits[j]]++;

            while(i <=j && count.size() >2){
                count[fruits[i]]--;
                if(count[fruits[i]]==0){
                    count.erase(fruits[i]);
                }
                i++;
            }
            maxFruits = max(maxFruits , j - i + 1);
            j++;
         }
        
        return maxFruits;
    }
};