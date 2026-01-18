#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
    int res = 0;
    while (x != 0) {
        long temp = 10L * res + x % 10;
        if (temp > INT_MAX || temp < INT_MIN) break;
        res = (int) temp;
        x = x / 10;
    }
    
    if (x) return 0;
    return res;
}

int main() {
    int x;
    
    cin >> x;

    cout << reverse(x) << endl;
    return 0;
}