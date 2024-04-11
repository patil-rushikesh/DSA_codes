#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution
{
    char arr[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
    // Custom implementation of next_permutation
    bool next_permutation(char a[], int n)
    {
        int i = n - 1;
        while (i > 0 && a[i - 1] >= a[i])
        {
            i--;
        }

        if (i <= 0)
        {
            return false;
        }

        int j = n - 1;
        while (a[j] <= a[i - 1])
        {
            j--;
        }

        swap(a[i - 1], a[j]);

        j = n - 1;
        while (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }

        return true;
    }

    string permute(char a[], int n, int k)
    {
        // Calculate factorial
        int fact = 1;
        for (int i = 1; i <= n; ++i)
        {
            fact *= i;
        }

        // Handle case if k is out of range
        if (k > fact)
        {
            return "";
        }

        // Generate permutations
        while (--k)
        {
            if (!next_permutation(a, n))
            {
                return ""; // Return empty string if k is out of range
            }
        }

        return string(a, a + n);
    }

    string getPermutation(int n, int k)
    {
        char permut[10];
        for (int i = 0; i < n; i++)
        {
            permut[i] = arr[i];
        }
        return permute(permut, n, k);
    }
};