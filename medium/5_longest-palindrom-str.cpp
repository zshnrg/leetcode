#include <iostream>
#include <string>

using namespace std;


string findExpand(string s, int l, int r, int n) {
    while (l >= 0 && r <= n && s[l] == s[r]) {
        l--; r++;
    }

    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
    if (s.size() == 0) return "";

    int n = s.size();
    int max = 0;
    string res;

    for (int i = 0; i < n; i++) {
        string odd = findExpand(s, i, i, n);
        string even = findExpand(s, i, i + 1, n);

        if (odd.size() > max) {
            res = odd; max = odd.size();
        }
        if (even.size() > max) {
            res = even; max = even.size();
        }
    }

    return res;
}

int main() {
    string s;
    
    cin >> s;

    cout << longestPalindrome(s) << endl;
    return 0;
}