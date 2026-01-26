#include <string>
#include <vector>
#include <iostream>

using namespace std;


int canBeTypedWords(string text, string brokenLetters) {
    text += " ";
    vector<bool> broken(26, false);
    for (char c : brokenLetters) broken[c - 'a'] = true;

    int count = 0;
    int found = false;
    for (char c: text) {
        if (c == ' ') {
            !found ? count++ : found = false;
        } else if (broken[c - 'a']) found = true;
    }

    return count;
}

int main() {
    string text, b;
    getline(cin, text);
    cin >> b;

    cout << canBeTypedWords(text, b) << endl;

    return 0;
}