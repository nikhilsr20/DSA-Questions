class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > p;
        priority_queue<pair<int,int>> q;

        int i=0;
        int j=0;
        long long count=0;

        while(j<nums.size()){
            p.push({nums[j],j});
            q.push({nums[j],j});
            if(abs(p.top().first-q.top().first)>2){
                int c=0;
            while(abs(p.top().first-q.top().first)>2){
                 i++;
                 c++;

                while(p.top().second<i){
                    p.pop();
                }
                while(q.top().second<i){
                    q.pop();
                }
            }
         
            }
            long long n=j-i+1;
            count=count+n;
            j++;
            
        }
        return count;
    }
};