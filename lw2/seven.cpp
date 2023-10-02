#include "seven.hpp"

void remove_fisrt_zeros(std::string &str) {
    int position = 0;
    for (int i = 0; i < str.size(); ++i) {
        position = i;
        if (str[i] != '0') {
            break;
        }
    }
    str = str.substr(position);
}

bool check_seven(const std::string &number) {
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] < '0' || number[i] > '6') {
            return false;
        }
    }
    return true;
}

Seven::Seven() {
    capacity = size = 0;
    number = nullptr;
}

Seven::Seven(const std::string &number) {
    if (!check_seven(number)) {
        throw std::invalid_argument("Is not 7 nymber system");
    }
    std::string modified_number = number;
    remove_fisrt_zeros(modified_number);

    capacity = size = modified_number.size();

    this->number = new unsigned char[capacity];

    for (int i = size - 1; i >= 0; --i) {
        this->number[size - 1 - i] = modified_number[i];
    }
}

Seven::Seven(const std::initializer_list<unsigned char> &list)
    : Seven(std::string(list.begin(), list.end())) {
}

Seven::Seven(const int capacity) {
    this->capacity = capacity;
    number = new unsigned char[capacity];
}

void Seven::reallocate(const int capacity) {
    Seven temp(capacity);

    for (int i = 0; i < this->size; ++i) {
        temp.number[i] = this->number[i];
    }
    temp.size = this->size;
    (*this) = temp;
}

Seven::Seven(const Seven &other) {
    if (other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    this->size = other.size;
    this->capacity = other.capacity;

    this->number = new unsigned char[capacity];

    for (int i = 0; i < size; ++i) {
        this->number[i] = other.number[i];
    }
}

Seven &Seven::operator=(const Seven &other) {
    if (other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    this->size = other.size;
    this->capacity = other.capacity;

    delete[] this->number;

    this->number = new unsigned char[capacity];

    for (int i = 0; i < size; ++i) {
        this->number[i] = other.number[i];
    }

    return *this;
}

Seven::Seven(Seven &&other) noexcept {
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->number;
    this->number = other.number;

    other.size = 0;
    other.capacity = 0;
    other.number = nullptr;
}

std::string Seven::get_number() const {
    std::string temp = "";
    for (int i = size - 1; i >= 0; i--) {
        temp += number[i];
    }
    return temp;
}

int Seven::get_size() const{
    return size;
}

std::ostream &operator<<(std::ostream &os, const Seven &obj) {
    os << obj.get_number();
    return os;
}

bool Seven::operator==(const Seven &other) {
    if (this->number == nullptr || other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    if (this->size == other.size) {
        for (int i = 0; i < this->size; ++i) {
            if (this->number[i] != other.number[i]) return false;
        }
        return true;
    }
    return false;
}

bool Seven::operator!=(const Seven &other) {
    return !(*this == other);
}

bool Seven::operator>(const Seven &other) {
    if (this->number == nullptr || other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
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

bool Seven::operator<(const Seven &other) {
    if (this->number == nullptr || other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
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

bool Seven::operator<=(const Seven &other) {
    return !(*this > other);
}

bool Seven::operator>=(const Seven &other) {
    return !(*this < other);
}

Seven Seven::operator+(const Seven &other) {
    Seven temp = (*this);
    temp += other;

    return temp;
}

Seven Seven::operator-(const Seven &other) {
    Seven temp = (*this);
    temp -= other;

    return temp;
}

Seven &Seven::operator+=(const Seven &other) {
    if (this->number == nullptr || other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    const int max_size = std::max(this->size, other.size);
    const int min_size = std::min(this->size, other.size);

    (*this).reallocate(max_size + 1);

    int carry = 0;
    for (int i = 0; i < max_size; ++i) {
        int summa = 0;
        if (i < min_size) {
            summa = this->number[i] - '0' + other.number[i] - '0';
        } else if (this->size > other.size) {
            summa = this->number[i] - '0';
        } else {
            summa = other.number[i] - '0';
        }
        summa += carry;
        carry = summa / 7;
        summa %= 7;
        this->number[i] = summa + '0';
    }

    if (carry > 0) {
        this->number[max_size] = carry + '0';
        this->size++;
    }

    return *this;
}

Seven &Seven::operator-=(const Seven &other) {
    if (this->number == nullptr || other.number == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    if (*this < other) {
        throw std::logic_error("");
    }
    int carry = 0;
    for (int i = 0; i < this->size; ++i) {
        int subtraction = 0;
        if (i < other.size) {
            subtraction = this->number[i] - other.number[i];
        } else {
            subtraction = this->number[i] - '0';
        }
        subtraction += carry;
        carry = subtraction >= 0 ? 0 : -1;
        subtraction = (subtraction + 7) % 7;
        this->number[i] = subtraction + '0';
    }

    for (int i = this->size - 1; i > 0; --i) {
        if (this->number[i] != '0') {
            break;
        }
        this->size--;
    }

    return *this;
}

Seven::~Seven() noexcept {
    if (number != nullptr) {
        delete[] number;
        number = nullptr;
    }
}