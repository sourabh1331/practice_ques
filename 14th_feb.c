#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10000

typedef struct HashNode {
    int key;
    int value;
} HashNode;

typedef struct hashmap {
    HashNode* table[TABLE_SIZE];
} hashmap;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

hashmap* createhashmap() {
    hashmap* map = (hashmap*)malloc(sizeof(hashmap));
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
    return map;
}

void insert(hashmap* map, int key, int value) {
    int index = hash(key);
    while (map->table[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    map->table[index] = (HashNode*)malloc(sizeof(HashNode));
    map->table[index]->key = key;
    map->table[index]->value = value;
}

int search(hashmap* map, int key) {
    int index = hash(key);
    while (map->table[index] != NULL) {
        if (map->table[index]->key == key) {
            return map->table[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashmap* map = createhashmap();
    int* result = (int*)malloc(2 * sizeof(int));
    if (returnSize != NULL) {
        *returnSize = 2;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = search(map, complement);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            return result;
        }
        insert(map, nums[i], i);
    }
    return NULL;
}

int main() {
    int nums[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int returnSize;
    int* result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    
    if (result != NULL) {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found\n");
    }

    int num[] = {3,3};
    int targets = 6;
    int returnSi;
    int* results = twoSum(num, sizeof(num) / sizeof(num[0]), targets, &returnSi);
    
    if (results != NULL) {
        printf("[%d,%d]\n", results[0], results[1]);
        free(results);
    } else {
        printf("No solution found\n");
    }
    
    return 0;
}
