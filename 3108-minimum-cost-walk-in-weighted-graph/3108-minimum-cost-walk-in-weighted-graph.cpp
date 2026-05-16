class Solution {
public:
    int find(int x,vector<int> &parent){
           if(parent[x]==x){
            return x;
           }
           return parent[x]=find(parent[x],parent);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }

        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];

            int px = find(x,parent);
            int py = find(y,parent);

            if(px!=py){
                if(rank[px] == rank[py]){

        parent[py] = px;
        rank[px]++;
    }
    else if(rank[px] > rank[py]){

        parent[py] = px;
    }
    else{

        parent[px] = py;
    }

            }
        }

        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int px = find(i,parent);
            map[i]=px;
        }

        unordered_map<int,int> a;

        
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
             int z=edges[i][2];
             if(!a.count(map[x])){
                a[map[x]]=z;
             }
             else{
                a[map[x]]&=z;
             }
          

        }

        vector<int> ans;
        for(int i=0;i<query.size();i++){
            int x=query[i][0];
            int y=query[i][1];

            if(map[x]==map[y]){
                ans.push_back(a[map[x]]);
              
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;


    }
};