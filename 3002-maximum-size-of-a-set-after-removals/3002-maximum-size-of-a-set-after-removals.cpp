class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> b;
        for(int i=0;i<nums2.size();i++){
            b.insert(nums2[i]);
        }
        unordered_set<int> a;
        for(int i=0;i<nums1.size();i++){
            a.insert(nums1[i]);
        }


        int a1=0;
        for(auto i : a){
            if(!b.count(i)){
                 a1++;
            }
        }
        int b1=0;
        for(auto i : b){
            if(!a.count(i)){
                 b1++;
            }
        }
        int c=0;

        for(auto i : b){
            if(a.count(i)){
                 c++;
            }
        }

        cout<<a1<<b1<<c;


        int ans=0;
     int n=nums1.size()/2;
    
       
       ans+=min(a1,n);
        ans+=min(b1,n);
        ans+=c;



        




        
        int x=nums1.size();
      
       return min(x,ans);
       


    }
};