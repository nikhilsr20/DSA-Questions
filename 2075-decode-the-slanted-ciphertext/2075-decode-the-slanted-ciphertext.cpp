class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        
        int col=s.size()/rows;
        if(col==0){
            return "";
        }
        int i=0;
        string ans;
        for(int i=0;i<col;i++){
            int x=i;
            

            while(x<s.size()){
               ans+=s[x];
               x+=(col+1);
            }
        }

        while(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
       
       
    }
};