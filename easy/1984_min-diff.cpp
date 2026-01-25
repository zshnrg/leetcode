#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    if (k == 1) return 0;
    sort(nums.begin(), nums.end());
    
    int res = INT_MAX;
    k--;
    for (int i = 0; i < nums.size() - k; i++) {
        res = min(nums[i + k] - nums[i], res);
    }

    return res;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cin >> k;
    cout << minimumDifference(nums, k) << endl;
}