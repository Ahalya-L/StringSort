#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

void sortStrings(char arr[][MAX_LENGTH], int n) {
    char temp[MAX_LENGTH];
    for (int i = 0; i < n - 1; i++) {// for the sorting process
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    char arr[MAX_STRINGS][MAX_LENGTH];
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();  // Consume the newline character after the number

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove the newline character
    }

    sortStrings(arr, n);

    printf("\nSorted strings:\n");//To print the sorted strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
