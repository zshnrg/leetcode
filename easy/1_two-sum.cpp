#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {      
  unordered_map<int, int> mem;

  for (int i = 0; i < nums.size(); i++) {
      int t = target - nums[i];
      if (mem.find(t) != mem.end()) {
          return {i, mem[t]};
      } else {
          mem[nums[i]] = i;
      }
  }

  return {0, 0};
}

int main() {
    int n, target;
    
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> target;

    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}