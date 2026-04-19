class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        int i=0;
        int time=1;
         vector<vector<int>> a(n,vector<int> (m,0));
        vector<vector<int>> b(n,vector<int> (m,0));
        for(int j=0;j<sources.size();j++){
            int x=sources[j][0];
                int y=sources[j][1];
                int z=sources[j][2];
            a[x][y]=z;
            b[x][y]=0;
        }
        
        sources.push_back({-1,-1,-1});
       
        
        while(i<sources.size()){
           
            if(sources[i][2]==-1){
              
                time++;
                i++;
                if(i<sources.size()){
                sources.push_back({-1,-1,-1});
                }
                
                continue;
            }
            else{
                int x=sources[i][0];
                int y=sources[i][1];
                int z=sources[i][2];
                if(b[x][y]<time){
                    z=a[x][y];
                }
                
                
               if(x-1>=0 &&  a[x-1][y]==0){
                  a[x-1][y]=z;
                   b[x-1][y]=time;
                   
                  sources.push_back({x-1,y,z});
               }  
         
                
                else if(x-1>=0 && a[x-1][y]!=0 && b[x-1][y]==time){
                  a[x-1][y]=max(a[x-1][y],z);
                   
               }  
                 
                
               if(x+1<n &&  a[x+1][y]==0){
                  a[x+1][y]=z;
                   b[x+1][y]=time;
                    sources.push_back({x+1,y,z});
               } 
                 
               else if(x+1<n && a[x+1][y]!=0 && b[x+1][y]==time){
                  a[x+1][y]=max(a[x+1][y],z);
                   
               }  
             
                if(y-1>=0 &&  a[x][y-1]==0){
                  a[x][y-1]=z;
                    b[x][y-1]=time;
                     sources.push_back({x,y-1,z});
               }
        
                else if(y-1>=0 && a[x][y-1]!=0 && b[x][y-1]==time){
                  a[x][y-1]=max(a[x][y-1],z);
                   
               }  
         
                if(y+1<m &&  a[x][y+1]==0){
                  a[x][y+1]=z;
                    b[x][y+1]=time;
                     sources.push_back({x,y+1,z});
               } 
                 
               else if(y+1<m && a[x][y+1]!=0 && b[x][y+1]==time){
                  a[x][y+1]=max(a[x][y+1],z);
                   
               }  
        

                i++;
            }
            
        }
        return a;
        
    }
};