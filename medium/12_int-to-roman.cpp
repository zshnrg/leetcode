#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> rom = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"}
    };

    string res;

    for (auto &[value, symbol] : rom) {
        while (num >= value) {
            num -= value;
            res += symbol;
        }
    }

    return res;
}

int main() {
    int num;
    
    cin >> num;

    cout << intToRoman(num) << endl;
    return 0;
}