class Solution {
public:
    long long countSubarrays(vector<int>& nums, int l, int m) {
        long long count = 0;
        int i = 0;
        int j = 0;

        int dist = 0;
        int mdist = 0;
        int k = 0;

        unordered_map<int, int> q;

        unordered_map<int, int> p;
        while (j < nums.size()) {
            p[nums[j]]++;
            if (p[nums[j]] == 1) {
                dist++;
            }
            if (p[nums[j]] == m) {
                mdist++;
            }

            while (dist > l) {

                if (p[nums[i]] == m) {
                    mdist--;
                }
                p[nums[i]]--;
                if (p[nums[i]] == 0) {
                    dist--;
                }

                if (i < k) {
                    q[nums[k]]--;
                }

                i++;
                k = i;
            }

            if (dist == l && mdist == l) {

                count += 1;

                while (k < j && p[nums[k]] - q[nums[k]] - 1 >= m) {
                    q[nums[k]]++;
                    k++;
                }

                count += k - i;
            }

            j++;
        }
        return count;
    }
};