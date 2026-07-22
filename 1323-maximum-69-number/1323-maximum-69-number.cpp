class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        int maxi = num;
        for(int i = 0; i<str.size(); i++){
            (str[i] == '6')? str[i] = '9': str[i] = '6';
            maxi = max(maxi,stoi(str));
            (str[i] == '6')? str[i] = '9': str[i] = '6';
        }
        return maxi;
    }
};