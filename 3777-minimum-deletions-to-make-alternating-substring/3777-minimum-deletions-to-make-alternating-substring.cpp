int buildtree(vector<int>& segment, int l, int r, int i, string& s) {
    if (l == r) {
        return segment[i] = 0;
    }
    int mid = (l + r) / 2;

    segment[i] = buildtree(segment, l, mid, 2 * i + 1, s) +
                 buildtree(segment, mid + 1, r, 2 * i + 2, s);
    if (s[mid] == s[mid + 1]) {
        segment[i]++;
    }
    return segment[i];
}

void update(int y, vector<int>& segment, string& s, int i, int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        if (s[y] == 'A') {
            s[y] = 'B';
        } else {
            s[y] = 'A';
        }
        return;
    } else if (y <= mid) {
        update(y, segment, s, 2 * i + 1, l, mid);
    } else {
        update(y, segment, s, 2 * i + 2, mid + 1, r);
    }

    segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    if (s[mid] == s[mid + 1]) {
        segment[i]++;
    }
}

void find(int left, int right, vector<int>& segment, int i, int l, int r,
          int &count,char &prev,string &s) {

    if (r < left || l > right)
        return;

    if (left <= l && r <= right) {
        if(prev=='0'){
            prev=s[r];
        }
        else{
            if(prev==s[l]){
                count++;
            }
             prev=s[r];
        }
        count += segment[i];
        return;
    }

    int mid = (l + r) / 2;

    find(left, right, segment, 2*i+1, l, mid, count,prev,s);
    find(left, right, segment, 2*i+2, mid+1, r, count,prev,s);
}

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        vector<int> segment(s.size() * 4, 0);
        buildtree(segment, 0, s.size() - 1, 0, s);

        vector<int> ans;
        for (auto p : queries) {
            int x = p[0];
            int y = p[1];
            int z;
            if (x == 2) {
                z = p[2];
            }

            if (x == 1) {
                update(y, segment, s, 0, 0, s.size() - 1);
            } else {
                if (y == z) {
                    ans.push_back(0);
                    continue;
                }
                int count = 0;
                char prev='0';
                find(y, z, segment, 0, 0, s.size() - 1, count,prev,s);

                ans.push_back(count);
            }
        }

        return ans;
    }
};