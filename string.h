//
// Created by Dell on 2023/3/2.
//

#ifndef WINSTRING_STRING_H
#define WINSTRING_STRING_H
#include <cstring>
#include <iostream>
#include <stdexcept>

class String {
private:
    char* data_{nullptr};
    size_t size_{0};

public:
    String();
    String(const char* str);
    String(const String& other);
    ~String();
    String& operator=(const String& other);

    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;
    char& operator[](size_t index);
    bool operator==(const String& other);
    String operator+(const String& other);
    const char* c_str() const;
    size_t length();
    friend std::ostream& operator<<(std::ostream& out, const String& str);
    friend std::istream& operator>>(std::istream& in, String& str);

private:
    void __init(const char* str);
    void __clean();
    void __swap(String& other);
};
#endif //WINSTRING_STRING_H
