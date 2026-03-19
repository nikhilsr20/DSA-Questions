class Solution {
public:
    string orderlyQueue(string s, int k) {
            if(k==1){
                string n=s+s;
                string ans=s;
                for(int i=0;i<s.size();i++){
                    char x=s[0];
                    s.erase(s.begin());
                    s.push_back(x);
                    ans=min(s,ans);
                }
                return ans;
            }
            sort(s.begin(),s.end());
        
        return s;
    }
};