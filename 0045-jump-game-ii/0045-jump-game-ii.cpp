class Solution {
public:
    int jump(vector<int>& a) {
        if(a.size()==1){
            return 0;
        }
        int m=a[0];
        int i=1;
        int sm=0;
        int count=1;
        while(m!=0){
           sm=max(sm-1,a[i]);
           i++;
           if(i>=a.size()){
            break;
           }
           m--;
           if(m==0){
            m=sm;
            sm=0;
            count++;
           }
        }
        return count;
        
        

       
    }
};