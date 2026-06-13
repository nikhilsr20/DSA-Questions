class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> a;
        for(int i=0;i<barcodes.size();i++){
            a[barcodes[i]]++;
        }
        priority_queue<pair<int,int>> b;

        for(auto i : a){
            b.push({i.second,i.first});
        }
        vector<int> ans(barcodes.size(),0);
        int i=0;
        int n,x;
        while(!b.empty()){
             n=b.top().first;
             x=b.top().second;
            b.pop();
            while(i<ans.size() && n!=0){
                ans[i]=x;
                i+=2;
              n--;
            }

           
            if(i>=ans.size()){
                break;
            }

            
        }
        i=1;

        while(n!=0 && i<ans.size()){
            ans[i]=x;
            n--;
           i+=2;


        }

        i=0;
         while(i<ans.size() && ans[i]!=0){
                i++;
             }

         
        while(!b.empty()){
             n=b.top().first;
             x=b.top().second;
             b.pop();

             while(n!=0){
                ans[i]=x;
                n--;
                while(i<ans.size() && ans[i]!=0){
                i++;
               }
             }



            



        }
        return ans;
        

    }
};