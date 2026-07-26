class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = INT_MIN;
        for(vector<int> v:accounts){
            int sum = 0;
            for(int i:v){
                sum+=i;
            }
            max_wealth = max(max_wealth,sum);
        }
        return max_wealth;
    }
};