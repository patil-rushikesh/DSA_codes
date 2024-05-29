#include <stdio.h>
struct matrix
{
    int A[10];
    // as it is sqauare matrix (n = l = m)f
    int n;
};
// Pass matrix as pointer and location with integer
void set(struct matrix *m, int i, int j, int x)
{ // condition of diagonal matrix (no. of column  = no. of row)
    if (i == j)
    {
        // indexing of matrix is from 1 while indexing of array is from 0. So element at 1,1 will be at 0th position, 2,2 will be at 1st position. hence we use (i-1)
        m->A[i - 1] = x;
        // above statment is equivalent to  *m.A[i-1] = x; ---- This statement access the array from the struct 'matrix'
    }
}
int get(struct matrix m, int i, int j)
{ // Pass matrix directly and location
    if (i == j)
    {
        return m.A[i - 1];
    }
    else
    {
        return 0;
    }
}
void display(struct matrix m)
{ // Pass matrix directly
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
            {
                printf("%d ", m.A[i]);
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
    struct matrix m; // create matrix
    m.n = 4;         // set dimension
    //set elements 
    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 12);
    //try to access element from position 2,2
    printf("%d \n", get(m,2,2));
    //display whole matrix
    display(m);
    return 0;
}