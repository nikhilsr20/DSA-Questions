void build(int i, int l, int r,
           vector<unordered_map<int,int>> &segment,
           vector<int> &arr) {

    if(l == r) {
        segment[i][arr[l]]++;
        return;
    }

    int mid = (l + r) / 2;

    build(2*i + 1, l, mid, segment, arr);
    build(2*i + 2, mid + 1, r, segment, arr);

    for(auto &x : segment[2*i + 1]) {
        segment[i][x.first] += x.second;
    }

    for(auto &x : segment[2*i + 2]) {
        segment[i][x.first] += x.second;
    }
}


int ans(int l,int r,int value,int i,int left,int right,vector<unordered_map<int,int>> &segment){
    if(right < l || left > r) return 0;
       if(l <= left && right <= r) {
        if(segment[i].count(value))
            return segment[i][value];
        return 0;
    }
     int mid = (left + right) / 2;


      int x=ans(l,r,value,2*i+1,left,mid,segment);
      
      int y=ans(l,r,value,2*i+2,mid+1,right,segment);

      return x+y;
      
}



class RangeFreqQuery {
public:
    vector<unordered_map<int,int>> segment;
    int n;
    RangeFreqQuery(vector<int>& arr) {
       segment.resize(4 * arr.size());
       n=arr.size();
        build(0,0,n-1,segment,arr);
    }
    
    int query(int left, int right, int value) {
        int count=0;
        return ans(left,right,value,0,0,n-1,segment);
     
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */