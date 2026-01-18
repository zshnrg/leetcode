#include <iostream>

bool isPalindrome(int x) {
    long res = 0;
    int copy = x;

    while (x > 0) {
        res = (res * 10) + (x % 10);
        x /= 10;
    }

    return copy == res;
}

int main() {
    int x;
    
    std::cin >> x;

    std::cout << (isPalindrome(x) ? "true" : "false") << std::endl;
    return 0;
}