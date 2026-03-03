class Solution {
public:
    char findKthBit(int n, int k) {
        string S="0";
        for(int i=1;i<n;i++){
           string temp=S;
           reverse(temp.begin(),temp.end());
           S+='1';
             for(int j=0;j<temp.size();j++){
                 if(temp[j]=='1'){
                    S+='0';
                 }
                 else{
                    S+='1';
                 }
             }
        }
        
        return S[k-1];
    }
};