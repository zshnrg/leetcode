#include <iostream>
#include <vector>

using namespace std;

vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        res[i] = nums[(((i + nums[i]) % n) + n ) % n];
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = constructTransformedArray(nums);

    cout << '[';
    for (int i = 0; i < n; i++) {
        if (i) cout << ',';
        cout << res[i];
    }
    cout << ']' << endl;

    return 0;
}