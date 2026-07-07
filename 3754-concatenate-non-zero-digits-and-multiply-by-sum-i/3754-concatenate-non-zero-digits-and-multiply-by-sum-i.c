long long sumAndMultiply(int n) {
    if (n == 0) return 0;

    long long x = 0;
    long long sum = 0;
    int multiplier = 1;

    while (n > 0) {
        int digit = n % 10;
        if (digit != 0) {
            sum += digit;
            x = digit * multiplier + x;
            multiplier *= 10;
        }
        n /= 10;
    }
    return x * sum;
}