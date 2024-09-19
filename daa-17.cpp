#include <stdio.h>
int main() {
    int array[] = {12, 4, 78, 56, 89, 23, 45};
    int length = sizeof(array) / sizeof(array[0]);
    int low = 0;
    int high = length - 1;
    int max, min;
    if (low == high) {
        max = min = array[low];
    } else if (high == low + 1) {
        if (array[low] > array[high]) {
            max = array[low];
            min = array[high];
        } else {
            max = array[high];
            min = array[low];
        }
    } else {
        int mid = (low + high) / 2;
        int max1, min1;
        if (low == mid) {
            max1 = min1 = array[low];
        } else if (mid == low + 1) {
            if (array[low] > array[mid]) {
                max1 = array[low];
                min1 = array[mid];
            } else {
                max1 = array[mid];
                min1 = array[low];
            }
        } else {
            max1 = min1 = array[low];
            for (int i = low; i <= mid; i++) {
                if (array[i] > max1) max1 = array[i];
                if (array[i] < min1) min1 = array[i];
            }
        }
        int max2, min2;
        if (mid + 1 == high) {
            max2 = min2 = array[mid + 1];
        } else if (high == mid + 2) {
            if (array[mid + 1] > array[high]) {
                max2 = array[mid + 1];
                min2 = array[high];
            } else {
                max2 = array[high];
                min2 = array[mid + 1];
            }
        } else {
            max2 = min2 = array[mid + 1];
            for (int i = mid + 1; i <= high; i++) {
                if (array[i] > max2) max2 = array[i];
                if (array[i] < min2) min2 = array[i];
            }
        }
        max = (max1 > max2) ? max1 : max2;
        min = (min1 < min2) ? min1 : min2;
    }
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    return 0;
}
