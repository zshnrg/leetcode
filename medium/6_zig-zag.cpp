#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    int idx = 0, dir = 1;
    vector<string> lines(numRows, "");

    for (char c: s) {
        lines[idx] += c;
        if (numRows > 1) {
            if (idx == numRows - 1 && dir == 1) {
                dir = -1;
            }
            if (idx == 0 && dir == -1) {
                dir = 1;
            }
            idx += dir;
        }
    }

    string res = "";
    for (string line: lines) {
        res += line;
    }

    return res;
}

int main() {
    string s;
    int numRows;

    cin >> s >> numRows;

    cout << convert(s, numRows) << endl;
    return 0;
}