#define MIN(a, b) ((a) < (b) ? (a) : (b))

int numberOfSubstrings(char* s) {
    int n = strlen(s);
    int count = 0;
    
    // Store the last seen index of 'a', 'b', and 'c'
    // Initialize with -1 to mean "not seen yet"
    int last_seen[3] = {-1, -1, -1};
    
    for (int j = 0; j < n; j++) {
        last_seen[s[j] - 'a'] = j;
        
        if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
            int min_idx = MIN(last_seen[0], MIN(last_seen[1], last_seen[2]));
            
            count += (min_idx + 1);
        }
    }
    
    return count;
}