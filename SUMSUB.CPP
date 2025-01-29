#include <stdio.h>

#define MAX 100

int i, j;

void findSubsets(int arr[], int n, int subset[], int subsetSize, int target, int currentSum, int index) {
    if (currentSum == target) {
        printf("Subset: ");
        for (i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (currentSum > target || index >= n) {
        return;
    }

    subset[subsetSize] = arr[index];
    findSubsets(arr, n, subset, subsetSize + 1, target, currentSum + arr[index], index + 1);

    findSubsets(arr, n, subset, subsetSize, target, currentSum, index + 1);
}

int main() {
    int n, target;
    int arr[MAX], subset[MAX];

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d are:\n", target);
    findSubsets(arr, n, subset, 0, target, 0, 0);

    return 0;
}
