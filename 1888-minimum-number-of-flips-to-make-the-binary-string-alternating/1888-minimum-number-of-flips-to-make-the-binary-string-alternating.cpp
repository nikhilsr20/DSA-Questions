class Solution {
public:
    int minFlips(string s) {
       int size=s.size();
       s+=s;
       int ans=INT_MAX;
       int st=s[0]-'0';
       int count=0;

       for(int i=0;i<size;i++){
            if(st!=s[i]-'0'){
                count++;
            }

         st =  (st==0) ? 1 : 0 ;
       }
      
       ans=min(count,ans);
       int i=0;
       int j=size-1;
       while(j+1<s.size()){
            i++;
           if(s[i]==s[i-1]){
            count=size-1-count;
           }
          
           j++;
           if(size%2==0 && s[i]==s[j]){
              count++;
           }
           else if(size%2==1 && s[i]!=s[j]){
                count++;
           }
        
        
       
           ans=min(count,ans);
       }
       return ans;


    }
};