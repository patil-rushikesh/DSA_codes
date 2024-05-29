#include<iostream>
using namespace std;

class matrix {
    private:
    int *A;
    int n;
    public:
    matrix(int n);
    int index(int i, int j);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~matrix();
};

matrix::matrix(int n) {
    this->n = n;
    A = new int[n * (n + 1) / 2];  // Allocate memory for lower triangular matrix
}

int matrix::index(int i, int j) {
    // Calculate the index in the array for the element at (i, j) in the lower triangular matrix
    return (i * (i - 1)) / 2 + (j - 1);
}

void matrix::set(int i, int j, int x) {
    if (i >= j) {
        A[index(i, j)] = x;
    }
}

int matrix::get(int i, int j) {
    if (i >= j) {
        return A[index(i, j)];
    } else {
        return 0;
    }
}

void matrix::display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                cout << A[index(i, j)] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

matrix::~matrix() {
    delete[] A;
}

int main() {
    int n;
    cout << "Enter Dimension: ";
    cin >> n;
    matrix m(n);

    int i, j, x;

    cout << "Enter all elements row by row:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> x;
            m.set(i, j, x);
        }
    }

    cout << "\nMatrix:\n";
    m.display();

    return 0;
}
