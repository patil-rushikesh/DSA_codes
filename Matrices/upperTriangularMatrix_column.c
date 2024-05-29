#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *A;
    int n;
};

int index(int n, int i, int j)
{
    return ((j * (j - 1)) / 2 + (i - 1));
}

void set(struct matrix *m, int i, int j, int x)
{
    if (i <= j)
    {
        m->A[index(m->n, i, j)] = x;
    }
}
int get(struct matrix m, int i, int j)
{
    if (i <= j)
    {
        return m.A[index(m.n, i, j)];
    }
    else
    {
        return 0;
    }
}

void display(struct matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i <= j)
            {
                printf("%d ", m.A[index(m.n, i, j)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct matrix m;
    int i, j, x;

    printf("Enter Dimension: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc((m.n * (m.n + 1) / 2) * sizeof(int)); // Allocate the correct amount of memory

    printf("Enter all elements:\n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\nMatrix:\n");
    display(m);

    // Free the allocated memory
    free(m.A);

    return 0;
}
