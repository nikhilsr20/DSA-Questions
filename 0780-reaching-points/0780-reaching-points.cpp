class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while((tx>=sx && ty>=sy)){
            //  cout<<tx<<"--"<<ty<<endl;
             if(sy==ty && tx==sx){
                return true;
        }
             if((tx==ty && (tx!=sx || ty!=sy)) || (ty==0 || tx==0)){
              return false;
             }
              
            if(tx>ty){
               int p=tx-sx;
                int x=p/ty;
                if(x==0){
                    x=1;
                }
                tx=(tx-(x*ty));
            }
            else if(tx<ty){
                 int p=ty-sy;
                int x=p/tx;
                if(x==0){
                    x=1;
                }

                // cout<<p<<"--"<<x<<endl;
                // if(ty%tx==0){
                //     x--;
                // }
                ty=(ty-(x*tx));
            }
     
       

        }

        return false;
    }
};