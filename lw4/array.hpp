#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <concepts>
#include <memory>

template <typename T>
    requires std::is_default_constructible_v<T>

class Array final {
private:
    size_t len;
    size_t capacity;
    std::shared_ptr<T[]> array;

    void reallocate(size_t capacity) {
        this->capacity = capacity;
        Array temp(this->len, capacity);
        for (int i = 0; i < this->len; ++i) {
            temp.array[i] = this->array[i];
        }
        (*this) = temp;
    }

public:
    Array() {
        len = 0;
        capacity = 1;
        array = nullptr;
    }

    Array(size_t len) {
        this->len = len;
        capacity = len;
        this->array = std::shared_ptr<T[]>(new T[capacity]);
    }

    Array(size_t len, size_t capacity) {
        this->len = len;
        this->capacity = capacity;
        this->array = std::shared_ptr<T[]>(new T[capacity]);
    }

    ~Array() = default;

    Array(const Array<T> &other) {
        if (other.array == nullptr) {
            throw std::domain_error("The object is not initialized");
        }
        this->len = other.len;
        this->capacity = other.capacity;

        this->array = std::shared_ptr<T[]>(new T[capacity]);

        for (int i = 0; i < len; ++i) {
            this->array[i] = other.array[i];
        }
    }

    Array(Array<T> &&other) noexcept {
        this->len = other.len;
        this->capacity = other.capacity;
        this->array = other.array;

        other.len = 0;
        other.capacity = 0;
        other.array = nullptr;
    }

    Array<T> &operator=(const Array<T> &other) {
        if (this == &other) {
            return *this;
        }

        if (other.array == nullptr) {
            throw std::domain_error("The object is not initialized");
        }

        this->len = other.len;
        this->capacity = other.capacity;

        this->array = std::shared_ptr<T[]>(new T[capacity]);

        for (int i = 0; i < len; ++i) {
            this->array[i] = other.array[i];
        }

        return *this;
    }

    Array<T> &operator=(Array<T> &&other) {
        if (this == &other) {
            return *this;
        }

        this->len = other.len;
        this->capacity = other.capacity;
        this->array = other.array;

        other.len = 0;
        other.capacity = 0;
        other.array = nullptr;

        return *this;
    }

    void push_back(T elem) {
        if (capacity < len + 1 || this->array == nullptr) {
            this->reallocate(2 * capacity);
        }

        array[len++] = elem;
    }

    void pop_back() {
        if (len > 0) {
            len--;
        } else {
            throw std::logic_error("Array already is empty");
        }
    }

    void remove(int index) {
        if (index >= len || index < 0) {
            throw std::out_of_range("Out of range");
        }

        for (int i = index + 1; i < len; i++) {
            array[i - 1] = array[i];
        }
        len--;
    }

    void insert(T *elem, int index) {
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

    T operator[](int index) {
        if (index >= len || index < 0) {
            throw std::out_of_range("Out of range");
        }

        return array[index];
    }

    size_t length() const noexcept {
        return len;
    }
};

#endif