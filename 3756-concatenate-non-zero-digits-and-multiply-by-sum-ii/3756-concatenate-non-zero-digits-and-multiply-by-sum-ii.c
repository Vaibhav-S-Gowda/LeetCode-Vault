#ifndef LOCAL_BUILD
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("abm,avx,avx2,bmi,bmi2,fma,popcnt,lzcnt,tune=znver5")
#define NO_SANITIZE __attribute__((no_sanitize("all")))
#else
#define NO_SANITIZE
#endif

#define MOD 1000000007LL
#define DECIMAL_BASE 10
#define MAX_LEN 100001

struct PrefixEntry {
    int sum;
    int concat;
};

static int next_nz[MAX_LEN];
static struct PrefixEntry prefix[MAX_LEN];
static int pow10_arr[MAX_LEN];
static int result_arr[MAX_LEN];

// NOLINTNEXTLINE(readability-identifier-naming)
NO_SANITIZE int* sumAndMultiply(const char* restrict str, int** queries,
                                int queries_size, int* queries_col_size,
                                int* return_size) {
    (void)queries_col_size;

    int nz_count = 0;
    prefix[0].sum = 0;
    prefix[0].concat = 0;
    pow10_arr[0] = 1;

    int len = 0;
    while (str[len] != '\0') {
        int digit = str[len] - '0';
        next_nz[len] = nz_count;
        if (digit != 0) {
            prefix[nz_count + 1].sum = prefix[nz_count].sum + digit;
            prefix[nz_count + 1].concat =
                (int)(((long long)prefix[nz_count].concat * DECIMAL_BASE +
                       digit) %
                      MOD);
            pow10_arr[nz_count + 1] =
                (int)(((long long)pow10_arr[nz_count] * DECIMAL_BASE) % MOD);
            nz_count++;
        }
        len++;
    }

    *return_size = queries_size;
    for (int idx = 0; idx < queries_size; idx++) {
        int left = queries[idx][0];
        int right = queries[idx][1];

        if (left < 0 || right < 0 || left > right || right >= len) {
            result_arr[idx] = 0;
            continue;
        }

        int left_idx = next_nz[left];
        int right_idx = next_nz[right] - (str[right] == '0');

        if (left_idx < 0 || right_idx < 0 || left_idx > right_idx ||
            left_idx >= nz_count || right_idx >= nz_count) {
            result_arr[idx] = 0;
            continue;
        }

        int count = right_idx - left_idx + 1;
        int digit_sum = prefix[right_idx + 1].sum - prefix[left_idx].sum;

        long long concat_value =
            ((long long)prefix[right_idx + 1].concat -
             (long long)prefix[left_idx].concat * pow10_arr[count] % MOD +
             MOD) %
            MOD;

        result_arr[idx] = (int)(concat_value * digit_sum % MOD);
    }

    return result_arr;
}