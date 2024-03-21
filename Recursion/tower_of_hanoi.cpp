#include <iostream>
using namespace std;
void toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        cout << a << " to "
             <<  c  << endl;
        toh(n - 1, b, a, c);
    }
}
int main()
{
    int n, a, b, c;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of b : ";
    cin >> b;
    cout << "Enter the value of c : ";
    cin >> c;
    toh(n, a, b, c);
    return 0;
}