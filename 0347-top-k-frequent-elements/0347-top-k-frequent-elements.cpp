class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp1;
        map<int,vector<int>> mp2;
        vector<int> v;
        for(int i:nums){
            mp1[i]++;
        }
        for(auto i:mp1){
            mp2[i.second].push_back(i.first);
        }
        for(auto it = mp2.rbegin(); it != mp2.rend() && k > 0; ++it){

            for(int num : it->second){

                v.push_back(num);
                k--;

                if(k == 0)
                    break;
            }
        }
        return v;
    }
};