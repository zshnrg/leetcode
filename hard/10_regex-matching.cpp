#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    if (p == "") return s == "";

    bool match = s != "" && (p[0] == s[0] || p[0] == '.');

    if (p.size() >= 2 && p[1] == '*') {
        return isMatch(s, p.substr(2)) || (
            match && isMatch(s.substr(1), p)
        );
    } else {
        return match && isMatch(s.substr(1), p.substr(1));
    }
}

int main() {
    string s, p;
    
    cin >> s >> p;

    cout << (isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}