class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        while(true){
            int sum = 0;
            while(num){
                sum += (num%10);
                num/=10;
            }
            if(((int)log10(sum)+1)==1) return sum;
            num = sum;
        }
    }
};