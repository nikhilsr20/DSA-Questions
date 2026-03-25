int find(string& s, int i, int j, int k, int st) {
    bool found=false;
    while (i >= st && j < s.size() && s[i] == s[j]) {
        if ((j - i) + 1 >= k) {
            found=true;
            break;
        }
        i--;
        j++;
    }
    if(!found){
        return INT_MAX;
    }
    
    return (j - i) + 1;
}

class Solution {
public:
    int maxPalindromes(string s, int k) {

        int st = 0;

        int count = 0;
        if (k == 1) {
            return s.size();
        }
        int i = 0;
        while (i < s.size()) {
          
            int x = find(s, i, i, k, st);

            

            if (x != INT_MAX) {
                x = ((x - 1) / 2);
            } 

            int y = INT_MAX;
            

            if (i<s.size() - 1 && s[i] == s[i + 1]) {
                y = find(s, i, i + 1, k, st);
            }
       

            if (y != INT_MAX) {
                y = ((y) / 2);
            } 

         

            if (min(x, y) == INT_MAX) {
                i++;
            } else {
                i += min(x, y) + 1;
                count++;
                st = i;
                
            }
            cout<<i<<endl;
        }

        return count;
    }
};