#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int specialTriplets(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> freq(1e5 + 1, 0);
    vector<int> freqPrev(1e5 + 1, 0);

    for (int n: nums) freq[n]++;

    long cnt = 0;
    for (int n: nums) {
        int target = n * 2;
        freq[n]--;
        if (target <= 1e5) cnt = (cnt + (long)freq[target] * (long)freqPrev[target]) % MOD;
        freqPrev[n]++;
    }

    return (int) cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << specialTriplets(nums) << endl;

    return 0;
}