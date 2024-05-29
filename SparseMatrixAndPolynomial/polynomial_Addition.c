#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term of the polynomial
struct term {
    int coef; // coefficient
    int exp;  // exponent
};

// Structure to represent the polynomial
struct polynomial {
    int n;         // number of non-zero terms
    struct term *t; // array to store non-zero terms
};

// Function to create a polynomial
void create(struct polynomial *p) {
    printf("Enter number of non-zero terms: ");
    scanf("%d", &p->n);

    // Allocate memory for the non-zero terms
    p->t = (struct term *)malloc(p->n * sizeof(struct term));

    // Read non-zero terms
    for (int i = 0; i < p->n; i++) {
        printf("Enter term %d (coefficient and exponent): ", i + 1);
        scanf("%d %d", &p->t[i].coef, &p->t[i].exp);
    }
}

// Function to add two polynomials
struct polynomial *add(struct polynomial *p1, struct polynomial *p2) {
    struct polynomial *sum = (struct polynomial *)malloc(sizeof(struct polynomial));
    sum->t = (struct term *)malloc((p1->n + p2->n) * sizeof(struct term));

    int i = 0, j = 0, k = 0;

    // Loop through both polynomials' terms
    while (i < p1->n && j < p2->n) {
        if (p1->t[i].exp > p2->t[j].exp) {
            sum->t[k++] = p1->t[i++];
        } else if (p1->t[i].exp < p2->t[j].exp) {
            sum->t[k++] = p2->t[j++];
        } else {
            // If both terms have the same exponent, add their coefficients
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coef = p1->t[i++].coef + p2->t[j++].coef;
        }
    }

    // Copy remaining terms from p1
    while (i < p1->n) {
        sum->t[k++] = p1->t[i++];
    }

    // Copy remaining terms from p2
    while (j < p2->n) {
        sum->t[k++] = p2->t[j++];
    }

    sum->n = k; // Update the number of terms in the result

    return sum;
}

// Main function
int main() {
    struct polynomial p1, p2, *p3;

    // Create first polynomial
    printf("Create first polynomial:\n");
    create(&p1);

    // Create second polynomial
    printf("Create second polynomial:\n");
    create(&p2);

    // Add the two polynomials
    p3 = add(&p1, &p2);

    // Display the result
    printf("Resultant polynomial after addition:\n");
    for (int i = 0; i < p3->n; i++) {
        printf("%dx^%d ", p3->t[i].coef, p3->t[i].exp);
        if (i != p3->n - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    // Free allocated memory
    free(p1.t);
    free(p2.t);
    free(p3->t);
    free(p3);

    return 0;
}
