#include <stdio.h>
#include <stdlib.h>

// Structure to represent an element of the sparse matrix
struct element
{
    int i; // row index
    int j; // column index
    int x; // value
};

// Structure to represent the sparse matrix
struct sparse
{
    int m;    // number of rows
    int n;    // number of columns
    int num;  // number of non-zero elements
    struct element *e; // array to store non-zero elements
};

// Function to create a sparse matrix
void create(struct sparse *s)
{
    printf("Enter Dimension (no. of rows, no. of columns): ");
    scanf("%d %d", &s->m, &s->n); 
    printf("Enter no. of non-zero elements: ");
    scanf("%d", &s->num); 

    // Allocate memory for the non-zero elements
    s->e = (struct element *)malloc(s->num * sizeof(struct element)); 
    printf("Enter all Non-zero elements in format (row, column, element): \n");

    // Read non-zero elements
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x); 
    }
}

// Function to add two sparse matrices
struct sparse *add(struct sparse *s1, struct sparse *s2)
{
    if (s1->m != s2->m || s1->n != s2->n)
    {
        return NULL; // Matrices dimensions do not match
    }

    // Allocate memory for the result matrix
    struct sparse *sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element)); // Allocate maximum possible size

    int i = 0, j = 0, k = 0;
    
    // Loop through both matrices' non-zero elements
    while (i < s1->num && j < s2->num)
    {
        // Compare row indices of current elements
        if (s1->e[i].i < s2->e[j].i)
        {
            // If s1's element is in an earlier row, add it to the sum matrix
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i)
        {
            // If s2's element is in an earlier row, add it to the sum matrix
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            // If both elements are in the same row, compare column indices
            if (s1->e[i].j < s2->e[j].j)
            {
                // If s1's element is in an earlier column, add it to the sum matrix
                sum->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].j > s2->e[j].j)
            {
                // If s2's element is in an earlier column, add it to the sum matrix
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                // If both elements are in the same position, add their values
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    // Copy any remaining elements from s1
    while (i < s1->num)
    {
        sum->e[k++] = s1->e[i++];
    }
    
    // Copy any remaining elements from s2
    while (j < s2->num)
    {
        sum->e[k++] = s2->e[j++];
    }

    sum->num = k; // Set the correct number of elements

    return sum;
}


// Main function
int main()
{
    struct sparse s1, s2, *s3;

    // Create first sparse matrix
    printf("Create first sparse matrix:\n");
    create(&s1);

    // Create second sparse matrix
    printf("Create second sparse matrix:\n");
    create(&s2);

    // Add the two matrices
    s3 = add(&s1, &s2);

    // Check if addition was successful
    if (s3)
    {
        printf("Resultant matrix after addition:\n");
        for (int i = 0; i < s3->num; i++)
        {
            printf("(%d, %d, %d)\n", s3->e[i].i, s3->e[i].j, s3->e[i].x);
        }
    }
    else
    {
        printf("Matrices cannot be added due to different dimensions.\n");
    }

    // Free allocated memory
    free(s1.e);
    free(s2.e);
    free(s3->e);
    free(s3);

    return 0;
}
