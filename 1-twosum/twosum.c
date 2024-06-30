#include <stdio.h>
#include <stdlib.h>

// 定义哈希表节点结构
typedef struct HashTableNode {
    int key;
    int value;
    struct HashTableNode *next;
} HashTableNode;

// 定义哈希表结构
typedef struct {
    HashTableNode **buckets;
    int size;
} HashTable;

// 创建哈希表
HashTable* createHashTable(int size) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    table->buckets = (HashTableNode**)calloc(size, sizeof(HashTableNode*));
    table->size = size;
    return table;
}

// 哈希函数
int hashFunction(int key, int size) {
    return abs(key) % size;
}

// 插入到哈希表
void insertHashTable(HashTable *table, int key, int value) {
    int hashIndex = hashFunction(key, table->size);
    HashTableNode *newNode = (HashTableNode*)malloc(sizeof(HashTableNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table->buckets[hashIndex];
    table->buckets[hashIndex] = newNode;
}

// 从哈希表查找
int findHashTable(HashTable *table, int key, int excludeIndex) {
    int hashIndex = hashFunction(key, table->size);
    HashTableNode *node = table->buckets[hashIndex];
    while (node != NULL) {
        if (node->key == key && node->value != excludeIndex) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // 未找到
}

// 释放哈希表
void freeHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        HashTableNode *node = table->buckets[i];
        while (node != NULL) {
            HashTableNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// 查找两数之和
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable *table = createHashTable(numsSize); // 创建哈希表
    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = findHashTable(table, complement, i);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            freeHashTable(table);
            return result;
        }
        insertHashTable(table, nums[i], i);
    }

    // 理论上不会到达这里，因为题目保证有解
    *returnSize = 0;
    free(result);
    freeHashTable(table);
    return NULL;
}

// 测试代码
int main() {
    int nums[] = {0, 4, 3, 0};
    int target = 0;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
