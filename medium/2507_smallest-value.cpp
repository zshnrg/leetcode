#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, bool> memo;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    if (memo.count(n)) return memo[n];

    for (int i = 3; 1LL * i * i <= n; i += 2)
        if (n % i == 0)
            return memo[n] = false;

    return memo[n] = true;
}


int smallestValue(int n) {
    int temp = n;
    if (isPrime(n)) return n;

    int sum = 0;
    int i = 2;
    while (n > 1) {
        if (!isPrime(i)) i++;
        while (n % i == 0) {
            sum += i;
            n /= i;
        }
        i++;
    }

    if (temp == sum) return temp;
    return smallestValue(sum);
}

int main() {
    int n;
    cin >> n;

    cout << smallestValue(n) << endl;

    return 0;
}