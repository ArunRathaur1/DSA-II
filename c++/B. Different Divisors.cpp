#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>
#include <iostream>

// Function to return an unordered set of prime numbers up to n
std::unordered_set<int> generatePrimes(int n) {
    if (n < 2) return {}; // No primes below 2

    // Create a boolean array to mark prime numbers
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Collect prime numbers into an unordered set
    std::unordered_set<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.insert(i);
        }
    }

    return primes;
}

int main() {
    int t;
    unordered_set<int> primes = generatePrimes(50000);
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        int d2 = 1 + d;
        while (primes.find(d2) == primes.end()) {
            d2++;
        }
        int d3 = d2 + d;
        while (primes.find(d3) == primes.end()) {
            d3++;
        }
        cout << d2 * d3 << endl;
    }

    return 0;
}
