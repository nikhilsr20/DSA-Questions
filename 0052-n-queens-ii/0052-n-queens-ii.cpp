void find(int i,int &n,unordered_map<int,int> &col,  unordered_map<int,int> &diag,unordered_map<int,unordered_map<int,int>> &diagonal,int &count){

    if(i==n){
        count++;
        return;
    }


    for(int j=0;j<n;j++){
        int q=i*n+j;
        if(col[j]==0 && diag[q]==0){
        for(auto x: diagonal[q]){
             diag[diagonal[q][x.first]]++;
        }

        col[j]=1;

         find(i+1,n,col,diag,diagonal,count);

         for(auto x: diagonal[q]){
             diag[diagonal[q][x.first]]--;
        }
     
        col[j]=0;
        }


    }
}


class Solution {
public:
    int totalNQueens(int n) {
   
        unordered_map<int,int> col;
        unordered_map<int,int> diag;
        unordered_map<int,unordered_map<int,int>> diagonal;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=(i*n)+j;

                int x=i;
                int y=j;
            
                // i-- and j--
                while(x>=0 && y>=0){
                    int p=(x*n)+y;
           
                    diagonal[val][p]=p;
                    x--;
                    y--;
                }
                // i++ and j--
                x=i;
                y=j;
                while(x<n && y>=0){
                    int p=(x*n)+y;
                   
                    diagonal[val][p]=p;
                    x++;
                    y--;
                }
                // i++ and j++
                x=i;
                y=j;
                while(x<n && y<n){
                    int p=(x*n)+y;
             
                    diagonal[val][p]=p;
                    x++;
                    y++;
                }
                // i++ and j--
                x=i;
                y=j;
                while(x>=0 && y<n){
                    int p=(x*n)+y;
            
                    diagonal[val][p]=p;
                    x--;
                    y++;
                }
            }

        }

        int count=0;
        find(0,n,col,diag,diagonal,count);
        return count;
    }
};