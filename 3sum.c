#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void find3Sum(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);

                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    find3Sum(nums, n);

    free(nums);
    return 0;
}