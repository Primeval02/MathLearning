// Bradley Tate
//
// How to approximate radicals using first order 
// Taylor Series centered around the closest solution

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    /*
     * Note: the parent function is sqrt(x), or x^(1/2), making the first derivative
     * 1/(2 * sqrt(x)) or 1/2 * x^(-1/2).
     *
     * Using x = 36 as an example, we know y = sqrt(x) will give us 6 for a point of (36, 6)
     *
     * We also know the slope of the tangent line, or derivative, m as 1/(2 * sqrt(x)) making a 
     * Point slope equation of y - 6 = m(x - 36).
     *
     * Solving for y gives y = 6 + (x - 36)/(2 * sqrt(x)) which we can approximate with!
     * General form: y = prev_root + (x - prev_square)/(2 * sqrt(prev_square))
     *
     * But remember since we are using the tangent line our guesses will always be slightly over due to function & graph behavior!
     *
     */

    int input = 0;

    cout << "Enter a number to approximate the square root of: ";
    cin >> input;

    double actual_root = sqrt(input);
    // long long will truncate the decimals giving only the whole number giving previous perfect square!
    long long prev_root = sqrt(input);
    double prev_square = prev_root * prev_root;

    double approximate = prev_root + (input - prev_square) / (2 * prev_root);

    cout << "\nClosest perfect square to " << input << " is " << prev_square << " with root " << prev_root << endl;
    cout << "Slope of tangent line is 1/(2 * sqrt(" << prev_square << "))" << endl;
    cout << "Manipulated Point-Slope equation of tangent line gives: " << prev_root << " + (" << input << " - " << prev_square << ")/(2 * sqrt(" 
    << prev_square << "))" << endl;

    cout << "Approximation: " << approximate << endl;
    cout << "Actual Answer: " << actual_root << endl;
    cout << "Error of only: " << ((approximate - actual_root)/actual_root) * 100 << "% nice!" << endl;
    return 0;
}
