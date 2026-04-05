class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<int,int> a;
        int count=0;
        if(s.size()==0){
            return 0;
        }
        
        for(int i=0;i<s.size();i++){
           a[s[i]]++;
        }

        for(char c='a';c<='m';c++){
            int x=c-'a';
            count+=abs(a[c]-a['z'-x]);
        }

        for(char c='0';c<='4';c++){
            int x=c-'0';
             count+=abs(a[c]-a['9'-x]);
            
        }
        return count;
    }
};