#include <stdio.h>
#include <assert.h>

int binary_search(int key, int a[], int n) {
    int lo = 0, hi = n - 1;
    int mid;

    while (lo <= hi) {
        mid = lo + (hi- lo) / 2;

        if (key < a[mid]) {
            hi = mid - 1;
        } else if (key > a[mid]) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binary_search_recur(int key, int a[], int lo, int hi) {
    if (lo > hi)
        return -1;

    int mid = lo + (hi - lo) / 2;

    if (key < a[mid])
       return binary_search_recur(key, a, lo, mid - 1);
    else if (key > a[mid])
       return binary_search_recur(key, a, mid + 1, hi); 
    else 
        return mid;
}


int main(void) {
    int a[10] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23};

    assert(binary_search(11, a, 10) == 5);
    assert(binary_search(13, a, 10) == 6);
    assert(binary_search(23, a, 10) == 9);
    assert(binary_search(2, a, 10) == 0);
    assert(binary_search(0, a, 10) == -1);
    assert(binary_search(25, a, 10) == -1);
    assert(binary_search(9, a, 10) == 4);

 
    assert(binary_search_recur(11, a, 0, 9) == 5);
    assert(binary_search_recur(23, a, 0, 9) == 9);
    assert(binary_search_recur(25, a, 0, 9) == -1);
    assert(binary_search_recur(2, a, 0, 9) == 0);
    assert(binary_search_recur(0, a, 0, 9) == -1);

    return 0;
}
