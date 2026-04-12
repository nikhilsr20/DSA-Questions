int find(char a,char b,int i,string &word, vector<vector<vector<int>>> &dp){
    if(i==word.size()){
        return 0;
    }

    if(dp[a-'A'][b-'A'][i]!=-1){
                 return dp[a-'A'][b-'A'][i];
    }

    int p=INT_MAX;
    int q=INT_MAX;
    
    if(a -('Z'+1)==0){
        p=find(word[i],b,i+1,word,dp);
    }
    else{
        int x=a-'A';
        int y=word[i]-'A';
        int plus=abs((x/6)-(y/6))+abs((x%6)-(y%6));
          
          p=find(word[i],b,i+1,word,dp)+plus;
          
    }

    if(b - ('Z'+1) ==0){
        q=find(a,word[i],i+1,word,dp);
    }
    else{
        int x=b-'A';
        int y=word[i]-'A';

        int plus=abs((x/6)-(y/6))+abs((x%6)-(y%6));
          
          q=find(a,word[i],i+1,word,dp)+plus;
           
    }

    return dp[a-'A'][b-'A'][i]=min(p,q);
    
}



class Solution {
public:
    int minimumDistance(string word) {
        char a='Z'+1;
        char b='Z'+1;
        int ans=INT_MAX;
        vector<vector<vector<int>>> dp(27,vector<vector<int>> (27,vector<int>(word.size(),-1)));
        return find(a,b,0,word,dp);

    }
};