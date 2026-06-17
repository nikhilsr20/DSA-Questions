struct Ft{
    vector<int> bit;
    int n;

    Ft(int x){
        this->n=x+1;
        bit.assign(x+1,0);
    }

    void update(int i){
        while(i<n){
         bit[i]+=1;
         i+=(i&(-i));
        }

    }

    int query(int i){
        int ans=0;

       while(i>0){
            ans+=bit[i];
            i-=(i&(-i));
       }
       return ans;
    }

};


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<int> left(n);
        vector<int> right(n);
        int mx = *max_element(rating.begin(), rating.end());

        Ft a(mx);

        for(int i=0;i<rating.size();i++){
            
            left[i]=a.query(rating[i]-1);

            a.update(rating[i]);
        }

        Ft b(mx);

        reverse(rating.begin(),rating.end());
        for(int i=0;i<rating.size();i++){
            
            right[n-(i+1)]=b.query(rating[i]-1);

            b.update(rating[i]);
        }


        reverse(rating.begin(),rating.end());

        int ans=0;
        for(int i=1;i<rating.size()-1;i++){
            int tl=i;
            int tr=rating.size()-(i+1);

            ans+=left[i]*(tr-right[i]);
            ans+=(tl-left[i])*(right[i]);


            
        }
        return ans;


       
    }
};


