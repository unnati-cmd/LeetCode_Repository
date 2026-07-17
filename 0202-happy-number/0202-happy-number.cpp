class Solution {
public:
    bool isHappy(int res) {
        unordered_map<int,int> mp;
        while(true){
            mp[res]++;
            int sum = 0;
            while(res){
                sum += pow(res%10,2);
                res/=10;
            }
            if(sum == 1) return true;
            if(mp.find(sum)!=mp.end()) return false;
            res = sum;
        }
        return false;
    }
};