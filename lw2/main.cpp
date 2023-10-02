#include "seven.hpp"

int main() {
    // std::string number, number1;
    // std::cin >> number >> number1;
    // Seven a(number);
    // Seven b(number1);
    // Seven c(number);
    // Seven d(number1);
    // Seven ans("0");
    // std::cout << a << " == " << b << "  " << (a == b) << std::endl;
    // std::cout << a << " != " << b << "  " << (a != b) << std::endl;
    // std::cout << a << " > " << b << "  " << (a > b) << std::endl;
    // std::cout << a << " < " << b << "  " << (a < b) << std::endl;
    // std::cout << a << " <= " << b << "  " << (a <= b) << std::endl;
    // std::cout << a << " >= " << b << "  " << (a >= b) << std::endl;

    // ans = a + b;
    // std::cout << ans << std::endl;

    // a += b;
    // a.print();

    // ans = c - d;
    // ans.print();

    // c -= d;
    // c.print();
    // std::string a;
    // std::cin >> a;
    // std::cout << a << "   " << check_seven(a);
    try {
        Seven a;
        Seven b("12");
        std::cout << (a != b);
    }
    catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}