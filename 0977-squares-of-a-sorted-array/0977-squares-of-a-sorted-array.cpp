class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        vector<int> res;
        for(auto i : nums){
            if(i>=0) pos.push_back(i*i);
            else neg.push_back(i*i);
        }
        int i = 0, j = neg.size()-1;
        while(i<pos.size() && j>=0){
            if(pos[i] > neg[j]){
                res.push_back(neg[j]);
                j--;
            }
            else{
                res.push_back(pos[i]);
                i++;
            }
        }
        while(j>=0){
            res.push_back(neg[j]);
            j--;
        }
        while(i<pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        return res;
    }
};