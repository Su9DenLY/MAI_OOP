#include <iostream>
#include "count_ones.hpp"

using namespace std;

int main() {
    int first, second, result;
    cin >> first >> second;

    result = count_ones(first, second);

    if (result >= 0) {
        cout << result << "\n";
    } else {
        cout << "Incorrect input\n";
        return 1;
    }

    return 0;
}