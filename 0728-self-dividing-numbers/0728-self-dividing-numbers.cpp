class Solution {
public:
    int check(int i){
        if(i==0) return 0;
        int temp = i;
        while(i){
            if((i%10)==0 || temp%(i%10)!=0) return 0;
            i/=10;
        }
        return temp;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i = left; i <= right; i++){
            if(check(i)) v.push_back(check(i));
        }
        return v;
    }
};