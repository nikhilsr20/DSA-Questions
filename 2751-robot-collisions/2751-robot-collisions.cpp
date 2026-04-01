class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,pair<int,char>>> a;
        unordered_map<int,int> n;
        for(int i=0;i<positions.size();i++){
            n[positions[i]]=i;
        }
        for(int i=0;i<healths.size();i++){
            a.push_back({positions[i],{healths[i],directions[i]}});
        }
        sort(a.begin(),a.end());

        stack<pair<int,pair<int,char>>> ans;
        for(int i=0;i<a.size();i++){
            bool alive=true;
            if(!ans.empty() && ans.top().second.second=='R' && a[i].second.second=='L'){
            while(!ans.empty() && ans.top().second.second=='R' && a[i].second.second=='L'){
                   int x1=ans.top().second.first;
                   int x2=a[i].second.first;
                   int p=ans.top().first;

                   char c1=ans.top().second.second;
                   char c2=a[i].second.second;

                   ans.pop();
                   if(x1==x2){
                     alive=false;
                      break;
                   }
                   if(x1>x2){
                     ans.push({p,{x1-1,c1}});
                      alive = false;  
                     break;
                   }
                   else{
                    a[i].second.first--;
                   }
                    
                
            }
            if(alive){
                 ans.push({n[a[i].first], {a[i].second.first, a[i].second.second}});
            }
            }
            else{
            
                ans.push({n[a[i].first],{a[i].second.first,a[i].second.second}});
            }
            
        }

        vector<pair<int,int>> x;

        while(!ans.empty()){
              x.push_back({ans.top().first,ans.top().second.first});
             
              ans.pop();
        }
        sort(x.begin(),x.end());
        
        vector<int> f;

        for(int i=0;i<x.size();i++){
            f.push_back(x[i].second);
        }
        
        
       return f;
    }
};