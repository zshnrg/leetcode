#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  unordered_set<int> f;
  int r = 0, l = 0;
  int max = 0;

  while (r < s.size()) {
      char c = s[r];
      if (f.find(c) == f.end()) {
          f.insert(c);
          r++;
      } else {
          f.erase(s[l]);
          l++;
      }

      if (max < r - l) {
          max = r - l;
      }
  }
  
  return max;
}

int main() {
    string s;
    
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}