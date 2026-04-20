class Solution {
public:
    int maxDistance(vector<int>& a) {
        int start=0;
        int end=a.size()-1;
        int max;
         while(a[start]==a[end]){
            end--;
         }
         int a1=end-start;
         start=0;
         end=a.size()-1;
         while(a[start]==a[end]){
            start++;
         }
         int a2=end-start;
         
           if(a1>=a2){
            return a1;
           }
          return a2;

        



    }
};