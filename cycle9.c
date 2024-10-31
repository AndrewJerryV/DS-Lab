#include <stdio.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void insert(int key) {
    int index = key % TABLE_SIZE;
    while (hashTable[index] != -1) 
        index = (index + 1) % TABLE_SIZE;  
    hashTable[index] = key;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) 
            printf("[%d] :\n", i);
        else 
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

// int search(int key) {
//     int index = key % TABLE_SIZE;
//     int startIndex = index;
//     while (hashTable[index] != -1) {
//         if (hashTable[index] == key) 
//             return index;  
//         index = (index + 1) % TABLE_SIZE;
//         if (index == startIndex) 
//             break;
//     }
//     return -1;  
// }

int main() {
    int choice, key;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("1.Insert key\n2.Display\n0.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                printf("Key %d inserted.\n", key);
                break;
            case 2:
                display();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
