#include <iostream>
using namespace std;

// Class to represent an element of the sparse matrix
class element {
public:
    int i; // row index
    int j; // column index
    int x; // value
};

// Class to represent the sparse matrix
class sparse {
private:
    int m;      // number of rows
    int n;      // number of columns
    int num;    // number of non-zero elements
    element *e; // array to store non-zero elements

public:
    sparse(int rows, int cols, int nonZero) : m(rows), n(cols), num(nonZero) {
        e = new element[num];
    }

    ~sparse() {
        delete[] e;
    }

    sparse operator+(sparse &s);

    friend istream &operator>>(istream &in, sparse &s);
    friend ostream &operator<<(ostream &out, sparse &s);
};

// Function to add two sparse matrices
sparse sparse::operator+(sparse &s) {
    if (m != s.m || n != s.n) {
        return sparse(0, 0, 0); // Matrices dimensions do not match
    }

    // Allocate memory for the result matrix
    sparse sum(m, n, num + s.num);

    int i = 0, j = 0, k = 0;

    // Loop through both matrices' non-zero elements
    while (i < num && j < s.num) {
        // Compare row indices of current elements
        if (e[i].i < s.e[j].i) {
            // If s1's element is in an earlier row, add it to the sum matrix
            sum.e[k++] = e[i++];
        } else if (e[i].i > s.e[j].i) {
            // If s2's element is in an earlier row, add it to the sum matrix
            sum.e[k++] = s.e[j++];
        } else {
            // If both elements are in the same row, compare column indices
            if (e[i].j < s.e[j].j) {
                // If s1's element is in an earlier column, add it to the sum matrix
                sum.e[k++] = e[i++];
            } else if (e[i].j > s.e[j].j) {
                // If s2's element is in an earlier column, add it to the sum matrix
                sum.e[k++] = s.e[j++];
            } else {
                // If both elements are in the same position, add their values
                sum.e[k] = e[i];
                sum.e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }

    // Copy any remaining elements from the first matrix
    while (i < num) {
        sum.e[k++] = e[i++];
    }

    // Copy any remaining elements from the second matrix
    while (j < s.num) {
        sum.e[k++] = s.e[j++];
    }

    sum.num = k; // Update the number of non-zero elements in the result

    return sum;
}

// Overload the >> operator to input elements of the sparse matrix
istream &operator>>(istream &in, sparse &s) {
    cout << "Enter non-zero elements : \n";
    for (int i = 0; i < s.num; i++) {
        in >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return in;
}

// Overload the << operator to output the sparse matrix
ostream &operator<<(ostream &out, sparse &s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num && s.e[k].i == i && s.e[k].j == j) {
                out << s.e[k++].x << " ";
            } else {
                out << "0 ";
            }
        }
        out << endl;
    }
    return out;
}

// Main function
int main() {
    sparse s1(5, 6, 5);
    sparse s2(5, 6, 6);

    cout << "Enter elements for first matrix:\n";
    cin >> s1;

    cout << "Enter elements for second matrix:\n";
    cin >> s2;

    sparse sum = s1 + s2;

    cout << "First matrix:\n" << s1;
    cout << "Second matrix:\n" << s2;
    cout << "Sum matrix:\n" << sum;
  
    return 0;
}
