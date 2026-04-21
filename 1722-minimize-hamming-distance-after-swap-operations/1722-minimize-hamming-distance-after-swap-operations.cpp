int findparent(int x,vector<int> &parent){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=findparent(parent[x],parent);
}

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& a) {
        vector<int> parent(source.size());
        vector<int> rank(source.size(),0);
        for(int i=0;i<source.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<a.size();i++){
            int x=a[i][0];
            int y=a[i][1];
            int p1=findparent(x,parent);
            int p2=findparent(y,parent);
            if(p1!=p2){
                if(rank[p1]==rank[p2]){
                    rank[p1]+=1;
                    parent[p2]=p1;
                }
                else if(rank[p1]>rank[p2]){
                    parent[p2]=p1;
                }
                else{
                    parent[p1]=p2;
                }
            }
        }

        unordered_map<int, unordered_map<int,int>> mp;
        for(int i=0;i<source.size();i++){
            int u=findparent(i,parent);
            mp[u][source[i]]++;
        }

         int count=0;
        for(int i=0;i<source.size();i++){
            int u=findparent(i,parent);

            if(mp[u][target[i]]>0){
                count++;
                mp[u][target[i]]--;
            }
        }

        


        return source.size()-count;
    }
};