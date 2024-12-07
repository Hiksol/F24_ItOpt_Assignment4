#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function f(x) = x^3 - 6x^2 + 11x - 6
double f(double x) {
    return pow(x, 3) - 6 * pow(x, 2) + 11 * x - 6;
}

// Bisection Method to find the root of the function
double bisection(double a, double b, double epsilon) {
    // Check if the interval is valid
    if (f(a) * f(b) >= 0) {
        cerr << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
        return NAN;
    }

    double c = a; // Midpoint initialization
    while ((b - a) >= epsilon) {
        c = (a + b) / 2; // Compute midpoint
        if (fabs(f(c)) < epsilon) break; // Stop if function value is within tolerance

        // Narrow the interval based on the sign of f(c)
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c; // Approximate root
}

int main() {
    double a, b, epsilon;

    // Input the interval [a, b] and the tolerance epsilon
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter tolerance (epsilon): ";
    cin >> epsilon;

    // Call the Bisection Method
    double root = bisection(a, b, epsilon);
    if (!isnan(root)) {
        cout << "Approximate root: " << setprecision(10) << root << "\n";
    }
    return 0;
}
