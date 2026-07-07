int bulbSwitch(int n) {
    if (n == 0) return 0;
    int result = 1;

    while (result <= n) {
        if (result*result == n) return result;
        else if (result*result < n) result++;
        else return result - 1;
    }
    return result;
}