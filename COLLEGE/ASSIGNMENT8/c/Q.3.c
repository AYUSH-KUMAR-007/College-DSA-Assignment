#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23};
    int x = 18;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = interpolationSearch(arr, n, x);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n", result);

    return 0;
}
