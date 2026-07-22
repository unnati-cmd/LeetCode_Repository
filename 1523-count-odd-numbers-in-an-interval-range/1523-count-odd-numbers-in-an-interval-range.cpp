class Solution {
public:
    bool check(int i){
        if(i%2!=0) return true;
        return false;
    }
    int countOdds(int low, int high) {
        int count = 0;
        for(int i = low; i<=high; i++){
            if(check(i)) count++;
        }
        return count;
    }
};