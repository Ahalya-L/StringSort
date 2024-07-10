#include <stdio.h>
#include <string.h>
#include <strings.h>  // For strcasecmp

#define MAX_STRINGS 100
#define MAX_LENGTH 100

void sortStrings(char arr[][MAX_LENGTH], int n, int ascending) {
    char temp[MAX_LENGTH];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && strcasecmp(arr[i], arr[j]) > 0) || (!ascending && strcasecmp(arr[i], arr[j]) < 0)) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    char arr[MAX_STRINGS][MAX_LENGTH];
    int n, order;

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();  // Consume the newline character after the number

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove the newline character
    }

    printf("Enter 1 for ascending order, 0 for descending order: ");
    scanf("%d", &order);

    sortStrings(arr, n, order);

    printf("\nSorted strings (case-insensitive):\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}