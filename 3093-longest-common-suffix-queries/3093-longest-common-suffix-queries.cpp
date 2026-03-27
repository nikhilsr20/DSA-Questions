struct Node{
    Node* a[26];
    int index;
    int size;

    Node(){
        for(int i=0;i<26;i++) a[i]=nullptr;
        index=-1;
        size=INT_MAX;
    }
    ~Node(){
        for(int i=0;i<26;i++){
            delete a[i]; 
        }
    }
};
void buildtrie(string &s,int ind,Node *root,vector<string>& str){

    if(root->size > str[ind].size()){
        root->size = str[ind].size();
        root->index = ind;
    }
    
    for(int i=s.size()-1;i>=0;i--){
        int idx = s[i]-'a';

        if(root->a[idx]==nullptr){
            root->a[idx]=new Node();
        }

        root = root->a[idx];
        
        if(root->size > str[ind].size()){
            root->size = str[ind].size();
            root->index = ind;
        }
    }
}
int find(Node* root,string &l){

    for(int i=l.size()-1;i>=0;i--){
        int idx = l[i]-'a';

        if(root->a[idx]==nullptr){
            return root->index;
        }

        root = root->a[idx];
    }

    return root->index;
}





class Solution {
public:
    vector<int> stringIndices(vector<string>& s, vector<string>& l) {
           Node* root = new Node();
          int p;
          int q=INT_MAX;
           for(int i=0;i<s.size();i++){
               buildtrie(s[i],i,root,s);
               if(s[i].size()<q){
                  p=i;
                  q=s[i].size();
               }
           }

           vector<int> ans;
       
           
          for(int i=0;i<l.size();i++){
               int x=find(root,l[i]);
               if(x==-1){
                ans.push_back(p);
               }
               else{
               ans.push_back(x);
               }
           }
           delete root;
          
           return ans;

        
    }
};