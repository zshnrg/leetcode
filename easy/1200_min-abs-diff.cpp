#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int m = INT_MAX;
    vector<vector<int>> res;
    for (int i = 1; i < arr.size(); i++) {
        int diff = abs(arr[i] - arr[i - 1]); 
        if (diff < m) {
            res.clear();
            m = diff;
            res.push_back({arr[i - 1], arr[i]});
        } else if (diff == m) {
            res.push_back({arr[i - 1], arr[i]});
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    while (n--) cin >> arr[n];

    auto res = minimumAbsDifference(arr);

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) cout << ",";
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
    }
    cout << "]" << endl;

    return 0;
}

