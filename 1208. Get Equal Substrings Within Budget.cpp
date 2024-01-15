class Solution {
public:
    int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum <= k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>nums;
        for(int i=0;i<s.size();i++){
            nums.push_back(abs(s[i]-t[i]));
        }
        return getLongestSubarray(nums,maxCost); // Longest Subarray with given Sum K
    }
};
