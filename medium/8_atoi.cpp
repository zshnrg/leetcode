#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string s) {
    long res = 0;
    int idx = 0, sign = 1;

    while (s[idx] == ' ' && idx < s.size()) idx++;
    if (s[idx] == '-' || s[idx] == '+') {
        sign = s[idx] == '-'  ? -1 : 1; 
        idx++;
    }

    for (int i = idx; i < s.size(); i++) {
        if (!isdigit(s[i])) break;
        res = res * 10L + (s[i] - '0');

        if (res * sign < INT_MIN) return INT_MIN;
        if (res * sign > INT_MAX) return INT_MAX;
    }

    return res * sign;
}

int main() {
    string s;
    
    getline(cin, s);

    cout << myAtoi(s) << endl;
    return 0;
}