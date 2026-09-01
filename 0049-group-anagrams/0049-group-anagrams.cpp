class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> v(strs.size(), vector<int>(26, 0));
        int j = 0;
        for (string i : strs) {
            int x = 0;
            while (x < i.size()) {
                v[j][i[x]-'a']++;
                x++;
            }
            j++;
        }
        vector<vector<string>> final;
        vector<bool> visited(strs.size(), false);
        for (int i = 0; i < strs.size(); i++) {
            if (visited[i])
                continue;
            vector<string> v1;
            for (int j = i; j < v.size(); j++) {
                if (!visited[j] && v[i] == v[j]) {
                    v1.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            final.push_back(v1);
        }
        return final;
    }
};