class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m1;
        for(char i:magazine){
            m1[i]++;
        }
        for (char i: ransomNote){
            if(m1[i]==0) return false;
            m1[i]--;
        }
        return true;
    }
};