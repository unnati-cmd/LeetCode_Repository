class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int ans = 0;

        for(int p:prices){

            mn = min(mn,p);

            ans = max(ans,p-mn);
        }

        return ans;
    }
};