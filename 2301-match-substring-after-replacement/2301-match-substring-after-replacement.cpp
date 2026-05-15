class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {

        unordered_map<char, unordered_set<char>> mp;

        for(auto &v : mappings){
            mp[v[0]].insert(v[1]);
        }

        int n = s.size();
        int m = sub.size();

        for(int i=0; i+m<=n; i++){

            bool ok = true;

            for(int j=0; j<m; j++){

                char a = sub[j];
                char b = s[i+j];

                if(a == b) continue;

                if(!mp[a].count(b)){
                    ok = false;
                    break;
                }
            }

            if(ok) return true;
        }

        return false;
    }
};