class Solution {
public:
    bool isHappy(int res) {
        unordered_set<int> mp;
        while(true){
            mp.insert(res);
            int sum = 0;
            while(res){
                sum += (res%10 * (res%10));
                res/=10;
            }
            if(sum == 1) return true;
            if(mp.count(sum)) return false;
            res = sum;
        }
        return false;
    }
};