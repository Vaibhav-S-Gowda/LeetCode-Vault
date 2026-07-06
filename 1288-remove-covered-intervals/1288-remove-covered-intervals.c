#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int** intervals, int low, int high) {
    int pivot = intervals[high][0]; 
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (intervals[j][0] < pivot) {
            i++;
            swap(&intervals[i][0], &intervals[j][0]);
            swap(&intervals[i][1], &intervals[j][1]);
        }
        // Tie-breaker: if start points are equal, sort descending by end point
        else if (intervals[j][0] == pivot) {
            if (intervals[j][1] > intervals[high][1]) {
                i++;
                swap(&intervals[i][0], &intervals[j][0]);
                swap(&intervals[i][1], &intervals[j][1]);
            }
        }
    }
    swap(&intervals[i + 1][0], &intervals[high][0]);
    swap(&intervals[i + 1][1], &intervals[high][1]);
    return (i + 1);
}

void quickSort(int** intervals, int low, int high) {
    if (low < high) {
        int pi = partition(intervals, low, high);

        quickSort(intervals, low, pi - 1);
        quickSort(intervals, pi + 1, high);
    }
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize <= 1) return intervalsSize;

    quickSort(intervals, 0, intervalsSize - 1);

    int remainingCount = 0;
    int curr_max_end = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][1] > curr_max_end) {
            remainingCount++;
            curr_max_end = intervals[i][1]; 
        }
    }

    return remainingCount;
}