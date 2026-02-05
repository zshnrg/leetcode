#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    for (char c: letters) {
        if (c > target) return c;
    }

    return letters[0];
}

int main() {
    int n;
    cin >> n;

    vector<char> letters(n);
    for (int i = 0; i < n; i++) cin >> letters[i];

    char target;
    cin >> target;

    cout << nextGreatestLetter(letters, target) << endl;

    return 0;
}