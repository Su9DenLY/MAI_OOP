#ifndef SEVEN_HPP
#define SEVEN_HPP

#include <exception>
#include <iostream>

void remove_fisrt_zeros(std::string &str);
bool check_seven(const std::string &number);

class Seven {
public:
    Seven();
    Seven(const std::string &number);
    Seven(const std::initializer_list<unsigned char> &list);
    Seven(const int capacity);


    Seven(const Seven &other);
    Seven(Seven &&other) noexcept;
    Seven &operator=(const Seven &other);
    Seven &operator=(Seven &&other);

    std::string get_number() const;
    int get_size() const;

    friend std::ostream &operator<<(std::ostream &os, const Seven &obj);

    bool operator==(const Seven &other) const;
    bool operator!=(const Seven &other) const;
    bool operator>(const Seven &other) const;
    bool operator<(const Seven &other) const;
    bool operator<=(const Seven &other) const;
    bool operator>=(const Seven &other) const;
    Seven operator+(const Seven &other) const;
    Seven operator-(const Seven &other) const;
    Seven &operator+=(const Seven &other);
    Seven &operator-=(const Seven &other);

    virtual ~Seven() noexcept;

private:
    unsigned char *number;
    int size;
    int capacity;
    
    void reallocate(const int capacity);
};

#endif