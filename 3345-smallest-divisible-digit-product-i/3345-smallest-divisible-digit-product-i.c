int smallestNumber(int n, int t) {
    int prod = 1;
    int n1 = n;
    while (n1 > 0) {
        prod *= (n1%10);
        n1 /= 10;
    }

    if (prod%t == 0){
        return n;
    }
    return smallestNumber(n+1, t);
}