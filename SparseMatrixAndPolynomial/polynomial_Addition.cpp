#include <iostream>
using namespace std;

// Class to represent a term of the polynomial
class Term {
public:
    int coef; // coefficient
    int exp;  // exponent
};

// Class to represent the polynomial
class Polynomial {
private:
    int n;       // number of non-zero terms
    Term *terms; // array to store non-zero terms

public:
    Polynomial(int num = 0) {
        n = num;
        terms = new Term[n];
    }

    ~Polynomial() {
        delete[] terms;
    }

    Polynomial operator+(const Polynomial &p) const;
    friend istream &operator>>(istream &in, Polynomial &p);
    friend ostream &operator<<(ostream &out, const Polynomial &p);
};

Polynomial Polynomial::operator+(const Polynomial &p) const {
    Polynomial sum(n + p.n); // Allocate maximum possible size for the result
    int i = 0, j = 0, k = 0;

    // Loop through both polynomials' terms
    while (i < n && j < p.n) {
        if (terms[i].exp > p.terms[j].exp) {
            sum.terms[k++] = terms[i++];
        } else if (terms[i].exp < p.terms[j].exp) {
            sum.terms[k++] = p.terms[j++];
        } else {
            // If both terms have the same exponent, add their coefficients
            sum.terms[k].exp = terms[i].exp;
            sum.terms[k++].coef = terms[i++].coef + p.terms[j++].coef;
        }
    }

    // Copy remaining terms from the first polynomial
    while (i < n) {
        sum.terms[k++] = terms[i++];
    }

    // Copy remaining terms from the second polynomial
    while (j < p.n) {
        sum.terms[k++] = p.terms[j++];
    }

    sum.n = k; // Update the number of terms in the result
    return sum;
}

istream &operator>>(istream &in, Polynomial &p) {
    cout << "Enter number of non-zero terms: ";
    in >> p.n;

    p.terms = new Term[p.n];

    // Read non-zero terms
    for (int i = 0; i < p.n; i++) {
        cout << "Enter term " << i + 1 << " (coefficient and exponent): ";
        in >> p.terms[i].coef >> p.terms[i].exp;
    }

    return in;
}

ostream &operator<<(ostream &out, const Polynomial &p) {
    for (int i = 0; i < p.n; i++) {
        out << p.terms[i].coef << "x^" << p.terms[i].exp;
        if (i != p.n - 1) {
            out << " + ";
        }
    }
    return out;
}

// Main function
int main() {
    Polynomial p1, p2;

    cout << "Create first polynomial:\n";
    cin >> p1;

    cout << "Create second polynomial:\n";
    cin >> p2;

    Polynomial p3 = p1 + p2;

    cout << "First polynomial: " << p1 << endl;
    cout << "Second polynomial: " << p2 << endl;
    cout << "Sum of polynomials: " << p3 << endl;

    return 0;
}
