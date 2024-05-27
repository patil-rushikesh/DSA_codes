#include <iostream>
using namespace std;
class str
{
private:
    char *A;

public:
    str();
    void getstr();
    void dup_individually();
    // void dup_hash();
    // void dup_bit();
    ~str();
};
str::str()
{
    A = new char[100];
}
void str::getstr()
{
    cout << "Enter String : ";
    cin >> A;
}
void str::dup_individually()
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == -1)
        {
            continue; // Skip already counted characters
        }

        cout << A[i] << " : ";
        int count = 1;
        for (int j = i + 1; A[j] != '\0'; j++)
        {
            if (A[j] == A[i])
            {
                count++;
                A[j] = -1; // Mark as counted
            }
        }
        cout << count << endl;
    }
}
str::~str()
{
    delete[] A;
}

int main()
{
    str s;
    s.getstr();
    s.dup_individually();
}