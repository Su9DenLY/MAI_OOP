#include <iostream>

#include "array.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"

using namespace std;

int main() {
    try {
        Array r;
        Rhomb a;
        cin >> a;
        r.push_back(&a);

        Pentagon b;
        cin >> b;
        r.push_back(&b);

        Hexagon c;
        cin >> c;
        r.push_back(&c);

        cout << *(r[0]) << "Square = " << r[0]->square() << " Center = " << r[0]->center() << endl;
        cout << *(r[1]) << "Square = " << r[1]->square() << " Center = " << r[1]->center() << endl;
        cout << *(r[2]) << "Square = " << r[2]->square() << " Center = " << r[2]->center() << endl;

    } catch (const exception &ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}