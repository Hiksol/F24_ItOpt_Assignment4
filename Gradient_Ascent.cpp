#include <iostream>
#include <cmath>
#include <functional>
#include <string>
#include <iomanip>

using namespace std;

// Gradient Ascent Method to maximize a differentiable function
double gradientAscent(double x0, double alpha, int iterations, function<double(double)> f, function<double(double)> df) {
    double x = x0; // Starting point
    for (int i = 0; i < iterations; ++i) {
        double grad = df(x); // Compute the gradient at x
        x += alpha * grad;   // Update x using the learning rate

        // Optional: Output intermediate results for debugging
        // cout << "Iteration " << (i + 1) << ": x = " << x << "      \t f(x) = " << f(x) << "\n";
    }
    return x; // Return the approximate maximum point
}

int main() {
    double x0, alpha;
    int iterations;

    // Input initial guess, learning rate, and number of iterations
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter learning rate alpha: ";
    cin >> alpha;
    cout << "Enter number of iterations: ";
    cin >> iterations;

    // Define the function and its derivative
    auto f = [](double x) {
        return -pow(x, 2) + 4 * x + 1; // Example: f(x) = -x^2 + 4x + 1
        };

    auto df = [](double x) {
        return -2 * x + 4; // Derivative: f'(x) = -2x + 4
        };

    // Call Gradient Ascent Method
    double xmax = gradientAscent(x0, alpha, iterations, f, df);
    cout << "\nApproximate xmax: " << setprecision(10) << xmax << "\n";
    cout << "f(xmax): " << f(xmax) << "\n";

    return 0;
}