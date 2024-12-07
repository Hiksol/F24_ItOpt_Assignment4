#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function f(x) = (x - 2)^2 + 3
double f(double x) {
    return pow(x - 2, 2) + 3;
}

// Golden Section Method
double goldenSection(double a, double b, double epsilon) {
    const double phi = (1 + sqrt(5)) / 2; //Golden section
    double c = b - (b - a) / phi;
    double d = a + (b - a) / phi;

    while ((b - a) > epsilon) {
        if (f(c) < f(d)) {
            b = d;
        }
        else {
            a = c;
        }
        c = b - (b - a) / phi;
        d = a + (b - a) / phi;
    }
    return (a + b) / 2;
}

int main() {
    double a, b, epsilon;
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter tolerance (epsilon): ";
    cin >> epsilon;
    double xmin = goldenSection(a, b, epsilon);
    cout << "Approximate xmin: " << setprecision(10) << xmin << "\n";
    cout << "f(xmin): " << f(xmin) << "\n";
    return 0;
}