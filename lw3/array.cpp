#include "array.hpp"

Array::Array() {
    len = 0;
    capacity = 1;
    array = nullptr;
}

Array::Array(size_t len) {
    this->len = len;
    capacity = len;
    array = new Figure *[capacity];
}

Array::Array(size_t len, size_t capacity) {
    this->len = len;
    this->capacity = capacity;
    array = new Figure *[capacity];
}

Array::~Array() {
    if (array != nullptr) {
        len = capacity = 0;
        delete[] array;
    }
}

void Array::reallocate(size_t capacity) {
    this->capacity = capacity;
    Array temp(this->len, capacity);
    for (int i = 0; i < this->len; ++i) {
        temp.array[i] = this->array[i];
    }
    (*this) = temp;
}

Array::Array(const Array &other) {
    if (other.array == nullptr) {
        throw std::domain_error("The object is not initialized");
    }
    this->len = other.len;
    this->capacity = other.capacity;

    this->array = new Figure *[capacity];

    for (int i = 0; i < len; ++i) {
        this->array[i] = other.array[i];
    }
}

Array::Array(Array &&other) noexcept {
    this->len = other.len;
    this->capacity = other.capacity;
    this->array = other.array;

    other.len = 0;
    other.capacity = 0;
    other.array = nullptr;
}

Array &Array::operator=(const Array &other) {
    if (this == &other) {
        return *this;
    }

    if (other.array == nullptr) {
        throw std::domain_error("The object is not initialized");
    }

    this->len = other.len;
    this->capacity = other.capacity;

    delete[] this->array;

    this->array = new Figure *[capacity];

    for (int i = 0; i < len; ++i) {
        this->array[i] = other.array[i];
    }

    return *this;
}

Array &Array::operator=(Array &&other) {
    if (this == &other) {
        return *this;
    }

    this->len = other.len;
    this->capacity = other.capacity;
    delete[] this->array;
    this->array = other.array;

    other.len = 0;
    other.capacity = 0;
    other.array = nullptr;

    return *this;
}

void Array::push_back(Figure *elem) {
    if (capacity < len + 1 || this->array == nullptr) {
        this->reallocate(2 * capacity);
    }

    array[len++] = elem;
}

void Array::pop_back() {
    if (len > 0) {
        len--;
    }
}

void Array::remove(int index) {
    if (index >= len || index < 0) {
        throw std::out_of_range("Out of range");
    }

    for (int i = index + 1; i < len; i++) {
        array[i - 1] = array[i];
    }
    len--;
}

void Array::insert(Figure *elem, int index) {
    if (index >= len || index < 0) {
        throw std::out_of_range("Out of range");
    }

    if (capacity < len + 1) {
        this->reallocate(2 * capacity);
    }

    len++;
    for (int i = len - 2; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = elem;
}

Figure *Array::operator[](int index) {
    if (index >= len || index < 0) {
        throw std::out_of_range("Out of range");
    }

    return array[index];
}

size_t Array::length() const noexcept {
    return len;
}