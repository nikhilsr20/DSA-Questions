class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int pivot) {
   vector<int> b;

    for(int i=0;i<a.size();i++){
        if(a[i]<pivot ){
            b.push_back(a[i]);
        }
    }
     for(int i=0;i<a.size();i++){
        if(a[i]==pivot){
            b.push_back(a[i]);
        }
    }

     for(int i=0;i<a.size();i++){
        if(a[i]>pivot){
            b.push_back(a[i]);
        }
    }
    
   return b;
    }
};