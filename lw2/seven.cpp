#include "seven.hpp"

void remove_fisrt_zeros(std::string & str) {
    int position = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != '0') {
            position = i;
            break;
        }
    }
    str = str.substr(position);
}

Seven::Seven() {
    std::cout << "construct" << std::endl;

    size = 1;
    number = new unsigned char[size]{'0'};
}

Seven::Seven(const std::string& number) {
    std::cout << "modify construct" << std::endl;

    std::string modified_number = number;
    remove_fisrt_zeros(modified_number);

    size = modified_number.size();

    this->number = new unsigned char[size];

    for (int i = size - 1; i >= 0; --i) {
        this->number[size - 1 - i] = modified_number[i];
    }
}

Seven::Seven(const Seven &other) {
    std::cout << "copy" << std::endl;
    
    this->size = other.size;

    this->number = new unsigned char[other.size];

    for (int i = 0; i < this->size; ++i) {
        this->number[i] = other.number[i];
    }
}

std::string Seven::get() {
    std::string temp = "";
    for (int i = size - 1; i >= 0; i--) {
        temp += number[i];
    }
    return temp;
}

Seven &Seven::operator = (const Seven &other) {
    this->size = other.size;

    delete[] this->number;

    this->number = new unsigned char[this->size];

    for (int i = 0; i < this->size; ++i) {
        this->number[i] = other.number[i];
    }

    return *this;
}

bool Seven::operator == (const Seven &other) {
    if (this->size == other.size) {
        for (int i = 0; i < this->size; ++i) {
            if (this->number[i] != other.number[i]) return false;
        }
        return true;
    }
    return false;
}

bool Seven::operator != (const Seven &other) {
    return !(*this == other);
}

bool Seven::operator > (const Seven &other){
    if (this->size != other.size) {
        return this->size > other.size;
    }

    for (int i = this->size - 1; i >= 0; --i) {
        if (this->number[i] != other.number[i]) {
            return this->number[i] > other.number[i];
        }
    }

    return false;
}

bool Seven::operator < (const Seven &other){
    if (this->size != other.size) {
        return this->size < other.size;
    }

    for (int i = this->size - 1; i >= 0; --i) {
        if (this->number[i] != other.number[i]) {
            return this->number[i] < other.number[i];
        }
    }

    return false;
}

bool Seven::operator <= (const Seven &other){
    return !(*this > other);
}

bool Seven::operator >= (const Seven &other){
    return !(*this < other);
}

Seven::~Seven() {
    if (number != nullptr) {
        size = 0;
        delete[] number;
        number = nullptr;
    }
    std::cout << "Distuctor" << std::endl;
}

void Seven::print() {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << number[i];
    }
    std::cout << std::endl;
}