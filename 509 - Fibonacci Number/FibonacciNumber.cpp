#include <unordered_map>
#include <iostream>

namespace first {
    // Recursive Fibonacci calculation without memoization
    int fibonacciNumber(int n) {
        if (n <= 1)
            return n;  // Base cases: fib(0) = 0, fib(1) = 1
        // Recursive calls to calculate Fibonacci number
        return fibonacciNumber(n-1) + fibonacciNumber(n-2);
    }
}

namespace second {
    std::unordered_map<int, int> cache;  // Memoization cache to store computed Fibonacci numbers

    // Recursive Fibonacci calculation with memoization
    int fibonacciNumber(int n) {
        if (cache.find(n) != cache.end()) {
            return cache[n];  // Return memoized value if it exists
        } else {
            if (n <= 1)
                return n;  // Base cases: fib(0) = 0, fib(1) = 1
            // Calculate Fibonacci number recursively
            int fib_value = fibonacciNumber(n-1) + fibonacciNumber(n-2);
            cache[n] = fib_value;  // Memoize the computed Fibonacci number
            return fib_value;
        }
    }
}

int main(int argc, char* argv[]) {
    {
        // Calculate and print the 20th Fibonacci number using namespace first (without memoization)
        int fib_value = first::fibonacciNumber(20);
        std::cout << "Fibonacci number (first): " << fib_value << std::endl;
    }
    {
        // Calculate and print the 30th Fibonacci number using namespace second (with memoization)
        int fib_value = second::fibonacciNumber(30);
        std::cout << "Fibonacci number (second): " << fib_value << std::endl;
    }
    return 0;
}
