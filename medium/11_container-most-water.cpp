#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int m = min(height[l], height[r]) * (r - l);

    while (l < r) {
        if (height[l] < height[r]) l++;
        else r--;
        m = max(m, min(height[l], height[r]) * (r - l));
    }

    return m;
}

int main() {
    int n;
    
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxArea(height) << endl;
    return 0;
}