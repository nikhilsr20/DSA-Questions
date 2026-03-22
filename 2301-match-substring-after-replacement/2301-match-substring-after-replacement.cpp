


class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<unordered_map<char,int>> a(128);
        for(int i=0;i<mappings.size();i++){
                
                a[mappings[i][0]][mappings[i][1]]=1;
           
        }
        
        string p=s.substr(0,sub.size());
        for(int i=0;i<sub.size();i++){
                if( p[i]==sub[i] || (p[i]!=sub[i] && a[sub[i]][p[i]]==1)){
                     if(i==sub.size()-1){
                         return true;
                     }
                }
                else{
                    break;
                }
            }
    
        int j=sub.size();
        while(j<s.size()){
            p.erase(p.begin());
            p=p+s[j];

            for(int i=0;i<sub.size();i++){
                if( p[i]==sub[i] || (p[i]!=sub[i] && a[sub[i]][p[i]]==1)){
                     if(i==sub.size()-1){
                         return true;
                     }
                }
                else{
                    break;
                }
            }


      
            j++;
        }



        



               
        return false;
    }
};