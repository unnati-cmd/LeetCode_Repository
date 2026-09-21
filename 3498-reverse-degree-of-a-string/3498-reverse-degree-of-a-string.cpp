class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0, j = 1;
        for(char i: s){
            sum += ((26 - (i-'a')) * j++);
        }
        return sum;
    }
};