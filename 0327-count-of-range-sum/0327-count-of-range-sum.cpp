class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
       multiset<long long> x;
        x.insert(0);

        long long count = 0;
        long long pre = 0;

        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];

            long long l = pre - upper;
            long long u = pre - lower;

            auto w1 = x.lower_bound(l);
            auto w2 = x.upper_bound(u);

            count += distance(w1, w2);

            x.insert(pre);
        }

        return count;
    }
};