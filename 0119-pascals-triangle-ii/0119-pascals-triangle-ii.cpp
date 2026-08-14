class Solution {
public:
    double factorial(double n){
        double fact = 1;
        for (int i = 1; i<=n; i++){
            fact*=i;
        }
        return fact;
    }
    double combination(double i, double j){
        return round(factorial(i)/(factorial(j)*factorial(i-j)));
    }
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        for (int i = 0; i<=rowIndex; i++){
            v.push_back(combination(rowIndex,i));
        }
        return v;
    }
};