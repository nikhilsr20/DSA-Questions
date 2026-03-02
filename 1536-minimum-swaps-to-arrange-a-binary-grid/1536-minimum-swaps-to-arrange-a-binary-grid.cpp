class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> a;
        for(int i=0;i<grid.size();i++){
            int count=0;
            for(int j=grid[i].size()-1;j>=0;j--){
              if(grid[i][j]==1){
                break;
              }
              count++;
        }
        a.push_back(count);
        cout<<count<<endl;
        }

         
        int ans=0;
        int x=grid.size()-1;
        for(int i=0;i<a.size()-1;i++){
        int p=-1;
        if(a[i]>=x){
            x--;
            continue;
        }
        else{
            
        for(int j=i+1;j<a.size();j++){
              if(a[j]>=x){
                p=j;
                break;
              }
        }
        if(p==-1){
            return -1;
        }
        else{
            
            while(p>i){
                ans++;
                swap(a[p],a[p-1]);
                p--;
            }
        }
        }



        x--;
        
        }
        return ans;
    }
};