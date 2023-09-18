#include "count_ones.hpp"

int count_ones(int first, int second) {
    if (first < 0 or second < first) {
        return -1;
    } else {
        int counter = 0;
        for (int i = first; i <= second; ++i) {
            int tmp_vlaue = i;
            while (tmp_vlaue) {
                if (tmp_vlaue & 1) {
                    counter++;
                }
                tmp_vlaue >>= 1;
            }
        }
        return counter;
    }
}