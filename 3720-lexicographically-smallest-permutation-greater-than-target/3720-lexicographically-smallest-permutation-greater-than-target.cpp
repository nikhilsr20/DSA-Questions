class Solution {
public:
    string lexGreaterPermutation(string sp, string target) {
        unordered_map<int,int> a;
        vector<string> ans;
        for(int i=0;i<target.size();i++){
            a[sp[i]]++;
        }

        for(int i=0;i<target.size();i++){
            string s="";
            bool valid=true;
            char pos=target[i];
            unordered_map<int,int> b;
            for(int j=0;j<i;j++){
              s+=target[j];
               b[target[j]]++;
               if(b[target[j]]>a[target[j]]){
                // cout<<b[target[j]]<<a[target[j]]<<endl;
                 valid=false;
                  break;
               }
            }
            for(int j=0;j<i;j++){

               a[target[j]]--;
              
            }




            if(valid){
                cout<<i<<endl;
                cout<<pos<<endl;
               for(char c=pos+1;c<='z';c++){
                if(a[c]>0){

                  
                    s+=c;
                    a[c]--;
                    for(char d='a';d<='z';d++){
                       for(int l=0;l<a[d];l++){
                           s+=d;
                       }
                    }
                   
                    ans.push_back(s);
                    break;
                }
               }
            }
            
                a.clear();
                b.clear();
                for(int j=0;j<target.size();j++){
                 a[sp[j]]++;
                }

        }
        if(sp>target){
             ans.push_back(sp);
        }
        sort(ans.begin(),ans.end());
        if(ans.empty()){
            
            return "";
        }
        return ans[0];
    }
};