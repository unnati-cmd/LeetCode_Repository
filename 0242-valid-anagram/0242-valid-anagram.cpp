class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int i = 0;
        for(char p:s){
            long long idx = t.find(p);
            if(idx==string::npos) return false;
            t.erase(idx,1);
            i++;
        }
        return true;
    }
};