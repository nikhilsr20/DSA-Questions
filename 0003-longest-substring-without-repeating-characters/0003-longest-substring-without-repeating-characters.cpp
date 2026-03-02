class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); 
    int maxLen = 0, start = 0;

    for (int end = 0; end < s.size(); end++) {
       
        if (lastIndex[s[end]] >= start) {
            start = lastIndex[s[end]] + 1; 
        }

        lastIndex[s[end]] = end; 
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
    }
};