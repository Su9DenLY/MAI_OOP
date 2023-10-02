#include "seven.hpp"

using namespace std;

int main() {
    try {
        string number1, number2;

        cout << "a = ";
        cin >> number1;
        cout << "b = ";
        cin >> number2;
        cout << endl;

        Seven a(number1);
        Seven b(number2);

        cout << a << "\t==\t" << b << "  " << "\t|\t" << ((a == b) ? "true" : "false") << endl;
        cout << a << "\t!=\t" << b << "  " << "\t|\t" << ((a != b) ? "true" : "false") << endl;
        cout << a << "\t>\t" << b << "  " << "\t|\t" << ((a > b) ? "true" : "false") << endl;
        cout << a << "\t<\t" << b << "  " << "\t|\t" << ((a < b) ? "true" : "false") << endl;
        cout << a << "\t<=\t" << b << "  " << "\t|\t" << ((a <= b) ? "true" : "false") << endl;
        cout << a << "\t>=\t" << b << "  " << "\t|\t" << ((a >= b) ? "true" : "false") << endl << endl;

        cout << "a + b = " << a + b << endl;
        cout << "a - b = " << a - b << endl;

    } catch (const domain_error &ex) {
        cerr << "Domain_error: " << ex.what() << endl;
    } catch (const invalid_argument &ex) {
        cerr << "Invalid_argument: " << ex.what() << endl;
    } catch (const logic_error &ex) {
        cerr << "Logic_error: " << ex.what() << endl;
    }
}