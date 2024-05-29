#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A; // Pointer to store elements
    int n;  // Dimension of the matrix
};

int index(int n, int i, int j)
{
    if (i <= j)
    {
        return j - i;
    }
    else
    {
        return n + i - j - 1;
    }}

// Function to set the value of the element at (i, j)
void set(struct matrix *m, int i, int j, int x)
{
        m->A[index(m->n, i, j)] = x;
    
}

// Function to get the value of the element at (i, j)
int get(struct matrix m, int i, int j)
{
        return m.A[index(m.n, i, j)];
    
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

    m.A = (int *)malloc((2*m.n-1) * sizeof(int));

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
