/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {

    int i, total, x, n, loc;
    n = 5000;
    int v[n];

    for (i = 0; i < n; i++)
        v[i] = i;

    i = 0;
    total = 1000000;

    for (i = 0; i < total; i++) {
        loc = binsearch(4000, v, n);
    }

    return 0;
}


int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1; /* no match */
}


int binsearchnew(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid;
    else
        return -1; /* no match */
}
