int min(int a, int b) {
    return a > b ? b : a;
}

int numberOfSubstrings(char* s) {
    int a = -1, b = -1, c = -1;
    int n = strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a = i;
        else if (s[i] == 'b') b = i;
        else if (s[i] == 'c') c = i;
        int j = min(a, min(b, c));
        ans += j+1;
    }
    return ans;
}