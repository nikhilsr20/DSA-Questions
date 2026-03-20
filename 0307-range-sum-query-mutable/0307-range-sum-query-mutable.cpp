class NumArray {
public:
vector<int> st;
int n;
     int buildsegmenttree(int s,int end,int i,vector<int> &nums){

    if(s==end){
        return st[i]=nums[s];
    }

    int mid=(s+end)/2;
    return st[i]=buildsegmenttree(s,mid,2*i+1,nums)+buildsegmenttree(mid+1,end,2*i+2,nums);
       
       
}    
    NumArray(vector<int>& nums) {
           st.resize(nums.size()*4);
           n=nums.size();
           buildsegmenttree(0,nums.size()-1,0,nums);
      
    }

    void updatesegtree(int index,int val,int i,int l,int r){
        if(l==r){
            st[i]=val;
            return;
        }
        int mid=(l+r)/2;

        if(index<=mid){
          updatesegtree(index,val,2*i+1,l,mid);
        }
        else{
           updatesegtree(index,val,2*i+2,mid+1,r);
        }
        st[i]=st[2*i+1]+st[2*i+2];
    }


    
    void update(int index, int val) {
        
        updatesegtree(index,val,0,0,n-1);

    }






   int find(int i,int s,int end,int left,int right){
             if(left <= s && end <= right){
        return st[i];
    }
            else if(s>right || end<left){
                return 0;
            }
            else{
                int mid=(s+end)/2;
                return find(2*i+1,s,mid,left,right)+find(2*i+2,mid+1,end,left,right);
            }
        }
    
    int sumRange(int left, int right) {
       
       
        return  find(0,0,n-1,left,right);
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */