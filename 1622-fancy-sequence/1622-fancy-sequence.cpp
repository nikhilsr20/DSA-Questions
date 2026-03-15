class Fancy {
public:
    vector<pair<int,int>> a;
    vector<pair<int,char>> op;
    Fancy() {
        
    }
    
    void append(int val) {
        a.push_back({val,op.size()});
    }
    
    void addAll(int inc) {
        op.push_back({inc,'+'});
    }
    
    void multAll(int m) {
        op.push_back({m,'x'});
    }
    
    int getIndex(int idx) {
        if(a.size()==0 || idx>=a.size()){
             return -1;
        }
        long long val=a[idx].first;
        for(int i=a[idx].second;i<op.size();i++){
                  if(op[i].second=='+'){
                      val+=(op[i].first);
                  }
                  else{
                      val*=(1LL*op[i].first);
                      val=val%1000000007;
                  }
        }
        a[idx].first=val;
        a[idx].second=op.size();

        return val%1000000007;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */