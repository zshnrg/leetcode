#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  vector<int> mem;
  int s = nums1.size() + nums2.size();

  for (int i = 0, j = 0; i + j < s / 2 + 1;) {
      if (i >= nums1.size()) {
          mem.push_back(nums2[j++]);
      } else if (j >= nums2.size()) {
          mem.push_back(nums1[i++]);
      } else {
          if (nums1[i] > nums2[j]) {
              mem.push_back(nums2[j++]);
          } else {
              mem.push_back(nums1[i++]);
          }
      }
  }

  return s % 2 ? mem[mem.size() - 1] : (mem[mem.size() - 1] + mem[mem.size() - 2]) / 2.0;
}

int main() {
    int n1, n2;
    
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}