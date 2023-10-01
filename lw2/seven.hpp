#ifndef SEVEN_HPP
#define SEVEN_HPP

#include <iostream>

void remove_fisrt_zeros(std::string & str);

class Seven {
public:
    Seven();
    Seven(const std::string& number);
    Seven(const Seven &other);
    std::string get();
    Seven & operator = (const Seven &other);
    bool operator == (const Seven &other);
    bool operator != (const Seven &other);
    bool operator > (const Seven &other);
    bool operator < (const Seven &other);
    bool operator <= (const Seven &other);
    bool operator >= (const Seven &other);
    void print();
    ~Seven();
private:
    unsigned char *number;
    int size;
};

#endif