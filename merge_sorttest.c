#include <stdio.h>

void m(int a[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_A[n1], right_A[n2];

    for (i = 0; i < n1; i++) {
        left_A[i] = a[left + i];
    }
    for (j = 0; j < n2; j++) {
        right_A[j] = a[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (left_A[i] <= right_A[j]) {
            a[k] = left_A[i];
            i++;
        } else {
            a[k] = right_A[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left_A[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = right_A[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        m(a, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of terms:\n");
    scanf("%d", &n); 
    printf("Enter the elements:\n");
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    mergeSort(a, 0, n - 1);
    
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}