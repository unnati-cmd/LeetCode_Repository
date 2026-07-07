class Solution {
public:
    long long sumAndMultiply(long long n) {
        string str = to_string(n), newstr = "";
        int sum = 0;
        for(char i:str){
            if(i != '0') newstr += i;
            sum += (i - '0');
        }
        n = newstr.empty() ? 0 : stoll(newstr);
        return n*sum;
    }
};