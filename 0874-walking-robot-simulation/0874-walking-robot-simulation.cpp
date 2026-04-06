class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        int dir=1;
        int m=0;
        unordered_set<long long> a;
        for(int i=0;i<obstacles.size();i++){
               long long key=(long long)obstacles[i][0]<<32 | (obstacles[i][1]& 0xffffffff);
               a.insert(key);
        }
        
        for(int i=0;i<commands.size();i++){
            cout<<dir<<endl;
            if(commands[i]==-1){
                 dir = (dir + 1) % 4;
    
            }
            else if(commands[i]==-2){
                 dir = (dir + 3) % 4;

            }
            
            else{
                for(int j=0;j<commands[i];j++){
                       if(dir==1){
                        long long key=(long long)x<<32 | ((y+1) & 0xffffffff);
                        if(a.count(key)){
                            break;
                        }
                        y++;
               
                       }
                        if(dir==2){
                             long long key=(long long)(x+1)<<32 | (y & 0xffffffff);
                             if(a.count(key)){
                            break;
                        }
                        x++;
                       }
                        if(dir==3){
                             long long key=(long long)x<<32 | ((y-1) & 0xffffffff);
                             if(a.count(key)){
                            break;
                        }
                        y--;
                       }
                        if(dir==0){
                            long long key=(long long)(x-1)<<32 | ((y) & 0xffffffff);
                            if(a.count(key)){
                            break;
                        }
                        x--;
                       }  
                }
            }
            m=max(m,(x*x)+(y*y));
                
        }

        return m;
        
    }
};