#include <iostream>

#include "array.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"

using namespace std;

int main() {
    Rhomb a;
    cin >> a;
    cout << a << endl << a.square() << endl << a.center() << endl << endl;

    Pentagon b;
    cin >> b;
    cout << b << endl << b.square() << endl << b.center() << endl << endl;

    Hexagon c;
    cin >> c;
    cout << c << endl << c.square() << endl << c.center() << endl << endl;
}