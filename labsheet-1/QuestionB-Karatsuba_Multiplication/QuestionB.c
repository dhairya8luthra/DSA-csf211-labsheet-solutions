#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string addStrings(const string &num1, const string &num2)
{
    string result;
    int carry = 0;

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }

    if (carry > 0)
    {
        result = to_string(carry) + result;
    }

    return result;
}

string karatsubaMultiply(const string &x, const string &y)
{
    int n = max(x.size(), y.size());

    // Base case: if n is 1, compute the product and return
    if (n == 1)
    {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }

    // Split the input numbers into halves
    string a = x.substr(0, n / 2);
    string b = x.substr(n / 2);
    string c = y.substr(0, n / 2);
    string d = y.substr(n / 2);

    // Recursive steps
    string p = addStrings(a, b);
    string q = addStrings(c, d);

    string ac = karatsubaMultiply(a, c);
    string bd = karatsubaMultiply(b, d);
    string pq = karatsubaMultiply(p, q);

    string adbe = addStrings(pq, "-" + ac);
    adbe = addStrings(adbe, "-" + bd);

    // Combine the results using the Karatsuba formula
    string result = ac + string(2 * (n - n / 2), '0') + adbe + string(n / 2, '0') + bd;

    return result;
}

int main()
{
    // Input
    string num1, num2;
    cin >> num1 >> num2;

    // Output
    string result = karatsubaMultiply(num1, num2);
    cout << (result[0] == '-' ? result.substr(1) : result) << endl;

    return 0;
}
