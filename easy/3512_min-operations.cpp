#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    return (sum % k);
}

int main() {
    int n, k;
    
    cin >> n;
    vector<int> nums(n);
    while (n--) {
        cin >> nums[n];
    }

    cin >> k;

    cout << minOperations(nums, k) << endl;
    return 0;
}