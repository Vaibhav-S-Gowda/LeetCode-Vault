#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int binarySearch(int* positions, int size, int target, int mode) {
    int low = 0, high = size - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mode == 0) {
            if (positions[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (positions[mid] <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return ans;
}

int* sumAndMultiply(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = strlen(s);

    int* digits = (int*)malloc(n * sizeof(int));
    int* positions = (int*)malloc(n * sizeof(int));
    int m = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            digits[m] = s[i] - '0';
            positions[m] = i;
            m++;
        }
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    if (m == 0) {
        for (int i = 0; i < queriesSize; i++) {
            ans[i] = 0;
        }
        free(digits);
        free(positions);
        return ans;
    }

    long long* pow10 = (long long*)malloc((m + 1) * sizeof(long long));
    pow10[0] = 1;
    for (int i = 1; i <= m; i++) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }

    long long* pref_sum = (long long*)malloc((m + 1) * sizeof(long long));
    long long* pref_val = (long long*)malloc((m + 1) * sizeof(long long));
    pref_sum[0] = 0;
    pref_val[0] = 0;

    for (int i = 0; i < m; i++) {
        pref_sum[i + 1] = pref_sum[i] + digits[i];
        pref_val[i + 1] = (pref_val[i] * 10 + digits[i]) % MOD;
    }

    // Run Queries
    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];

        int L = binarySearch(positions, m, l, 0);
        int R = binarySearch(positions, m, r, 1);

        if (L == -1 || R == -1 || L > R) {
            ans[i] = 0;
            continue;
        }

        long long length = R - L + 1;
        long long x = (pref_val[R + 1] - (pref_val[L] * pow10[length]) % MOD + MOD) % MOD;
        long long digit_sum = pref_sum[R + 1] - pref_sum[L];
        ans[i] = (int)((x * digit_sum) % MOD);
    }

    free(digits);
    free(positions);
    free(pow10);
    free(pref_sum);
    free(pref_val);

    return ans;
}