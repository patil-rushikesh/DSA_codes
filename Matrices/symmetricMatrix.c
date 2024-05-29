#include <stdio.h>
#include <stdlib.h>

// Structure to represent the symmetric matrix
struct matrix {
    int *A; // Pointer to store elements
    int n;  // Dimension of the matrix
};

// Function to calculate the index in the array for the element at (i, j)
int index(int i, int j) {
    // Ensure (i, j) is in the upper triangular part or on the diagonal
    if (i <= j) {
        return (i - 1) + (j * (j - 1)) / 2;
    } else {
        return (j - 1) + (i * (i - 1)) / 2;
    }
}

// Function to set the value of the element at (i, j)
void set(struct matrix *m, int i, int j, int x) {
    m->A[index(i, j)] = x;
}

// Function to get the value of the element at (i, j)
int get(struct matrix m, int i, int j) {
    return m.A[index(i, j)];
}

// Function to display the matrix
void display(struct matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            printf("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    struct matrix m;
    int i, j, x;

    // Input the dimension of the matrix
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    // Allocate memory for the elements of the upper triangular part of the matrix
    m.A = (int *)malloc((m.n * (m.n + 1) / 2) * sizeof(int));

    // Input elements row by row
    printf("Enter all elements:\n");
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    // Display the matrix
    printf("\nMatrix:\n");
    display(m);

    // Free the allocated memory
    free(m.A);

    return 0;
}
