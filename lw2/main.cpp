#include "seven.hpp"

int main() {
    std::string number, number1;
    std::cin >> number >> number1;
    Seven a(number);
    Seven b(number1);
    std::cout << a.get() << " == " << b.get() << "  " << (a == b) << std::endl;
    std::cout << a.get() << " != " << b.get() << "  " << (a != b) << std::endl;
    std::cout << a.get() << " > " << b.get() << "  " << (a > b) << std::endl;
    std::cout << a.get() << " < " << b.get() << "  " << (a < b) << std::endl;
    std::cout << a.get() << " <= " << b.get() << "  " << (a <= b) << std::endl;
    std::cout << a.get() << " >= " << b.get() << "  " << (a >= b) << std::endl;
}