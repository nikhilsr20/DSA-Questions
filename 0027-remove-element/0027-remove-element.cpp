class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int count=0;
       for(int i=0;i<a.size();i++){
        if(a[i]!=val){
            a[count]=a[i];
            count ++;
        }
       }
       return count ;
    }
};