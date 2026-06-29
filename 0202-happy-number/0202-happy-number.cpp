class Solution {
public:
    bool isHappy(int n) {
        int res = n;
        unordered_map<int,int> mp;
        mp[res]++;
        while(true){
            int num = 0;
            while(res){
                num += pow(res%10,2);
                res/=10;
            }
            if(num == 1) return true;
            if(mp.find(num)!=mp.end()) return false;
            mp[num]++;
            res=num;
        }
        return false;
    }
};