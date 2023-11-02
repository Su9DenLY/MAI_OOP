#include <iostream>

#include "array.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"

using namespace std;

int main() {
    try {
        Array<std::shared_ptr<Figure<double>>> r;
        shared_ptr<Rhomb<double>> rhomb_ptr = make_shared<Rhomb<double>>();
        cin >> *rhomb_ptr;
        r.push_back(rhomb_ptr);

        shared_ptr<Pentagon<double>> pentagon_ptr = make_shared<Pentagon<double>>();
        cin >> *pentagon_ptr;
        r.push_back(pentagon_ptr);

        shared_ptr<Hexagon<double>> hexagon_ptr = make_shared<Hexagon<double>>();
        cin >> *hexagon_ptr;
        r.push_back(hexagon_ptr);

        cout << *(r[0]) << "Square = " << r[0]->square() << " Center = " << r[0]->center() << endl;
        cout << *(r[1]) << "Square = " << r[1]->square() << " Center = " << r[1]->center() << endl;
        cout << *(r[2]) << "Square = " << r[2]->square() << " Center = " << r[2]->center() << endl;
    } catch (const exception &ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}