class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
        }
        else{
            string ans=s;
            for(int i=0;i<s.size();i++){
                char c=ans[0];
                ans.erase(ans.begin());
                ans+=c;
                s=min(ans,s);
            }
        }
        return s;
    }
};