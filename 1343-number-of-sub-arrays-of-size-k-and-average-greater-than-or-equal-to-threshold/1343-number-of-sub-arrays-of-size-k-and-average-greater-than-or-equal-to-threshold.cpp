class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int i=0;
        int j=k;
        int count=0;

        if(sum>=t*k){
            count++;
        }

        while(j<arr.size()){
             sum-=arr[i];
             sum+=arr[j];
             if(sum>=t*k){
                count++;
             }
             
             


             
          
             j++;
             i++;
        }
        return count;
    }
};