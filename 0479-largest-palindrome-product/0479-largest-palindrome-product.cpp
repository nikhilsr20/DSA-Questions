bool check(string x,int e){
    long long num=stoll(x);
   long long mini = pow(10, e-1);
long long maxi = pow(10, e) - 1;
   for(long long i = maxi; i>mini; i--){
           if(i*i<num){
            break;
           }
           if(num%i==0){
            long long y=num/i;
                if(y>=mini && y<=maxi){
                    return true;
                }
           }
   }
    
    return false;
}





void find2(int n,string s,int l,bool &ch,int &e,string &ans){
    if(ch==true){

        return;
    }
    if(n==0){
          
        if(l==0){
        string k=s;
        reverse(s.begin(),s.end());
           ch=check(k+s,e);
           if(ch){
            ans=k+s;
            return;
           }
        
        }
        else{
            string k=s;
        reverse(s.begin(),s.end());
         for(char i='9';i>='0';i--){ 
              ch=check(k+i+s,e);
              if(ch){
            ans=k+i+s;
            return;
           }
         }

        }
        return;
    }

    for(char i='9';i>='0';i--){
        if(s.size()==0 && i=='0'){
                continue;
              }
        find2(n-1,s+i,l,ch,e,ans);
    }
}

class Solution {
public:
    int largestPalindrome(int n) {
        
        string ans;
        int e=n;
        bool ch=false;
        find2(n,"",0,ch,e,ans);
        find2(n-1,"",1,ch,e,ans);

     
        return stoll(ans)%1337;

        

        

        



        

     
    }
};