#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A; // Pointer to store elements
    int n;  // Dimension of the matrix
};

int index(int n, int i, int j)
{
    if (i - j == 1)
    {
        return i - 2; // Lower diagonal
    }
    else if (i - j == 0)
    {
        return n - 1 + i - 1; // Main diagonal
    }
    else if (i - j == -1)
    {
        return 2 * n - 1 + i - 1; // Upper diagonal
    }
    return -1; // This case should not occur for a tridiagonal matrix
}

// Function to set the value of the element at (i, j)
void set(struct matrix *m, int i, int j, int x)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
    {
        m->A[index(m->n, i, j)] = x;
    }
}

// Function to get the value of the element at (i, j)
int get(struct matrix m, int i, int j)
{

    if (i - j == 1 || i - j == 0 || i - j == -1)
    {
        return m.A[index(m.n, i, j)];
    }
    else
    {
        return 0;
    }
}

// Function to display the matrix
void display(struct matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            printf("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main()
{
    struct matrix m;
    int i, j, x;

    // Input the dimension of the matrix
    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc((3* m.n -2) * sizeof(int));

    printf("Enter all elements:\n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
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
