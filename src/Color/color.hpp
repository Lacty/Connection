
#pragma once
#include <iostream>


template<typename T>
class ColorT {
public:
  T r, g, b;

  ColorT() : r(0), g(0), b(0) {}
  ColorT(T r, T g, T b) : r(r), g(g), b(b) {}
  ColorT(const ColorT<T>& src) : r(src.r), g(src.g), b(src.b) {}
  template<typename U>
    explicit ColorT(const ColorT<U>& src) : r(static_cast<U>(src.r)), g(static_cast<U>(src.g)), b(static_cast<U>(src.b)) {}

  static ColorT<T> white() { return ColorT<T>(1, 1, 1); }
  static ColorT<T> red() { return ColorT<T>(1, 0, 0); }
  static ColorT<T> green() { return ColorT<T>(0, 1, 0); }
  static ColorT<T> blue() { return ColorT<T>(0, 0, 1); }
  static ColorT<T> orange() { return ColorT<T>(1.0f, 0.6f, 0.0f); }
  static ColorT<T> gray() { return ColorT<T>(0.3f, 0.3f, 0.3f); }

  ColorT<T>& operator+=(const ColorT<T>& rhs) {
    r += rhs.r;
    g += rhs.g;
    b += rhs.b;
    return *this;
  }
  ColorT<T>& operator-=(const ColorT<T>& rhs) {
    r -= rhs.r;
    g -= rhs.g;
    b -= rhs.b;
    return *this;
  }
  ColorT<T>& operator*=(const T& rhs) {
    r *= rhs;
    g *= rhs;
    b *= rhs;
    return *this;
  }
  ColorT<T> operator+(const ColorT<T>& rhs) const {
    return ColorT<T>(r + rhs.r, g + rhs.g, b + rhs.b);
  }
  ColorT<T> operator-(const ColorT<T>& rhs) const {
    return ColorT<T>(r - rhs.r, g - rhs.g, b - rhs.b);
  }
  ColorT<T> operator*(const T& rhs) const {
    return ColorT<T>(r * rhs, g * rhs, b * rhs);
  }

  friend std::ostream& operator<<(std::ostream& os, const ColorT<T>& rhs) {
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    return os;
  }
};

template<typename T>
class ColorAT {
public:
  T r, g, b, a;

  ColorAT() : r(0), g(0), b(0), a(0) {}
  ColorAT(T r, T g, T b, T a) : r(r), g(g), b(b), a(a) {}
  ColorAT(const ColorAT<T>& src) : r(src.r), g(src.g), b(src.b), a(src.a) {}
  ColorAT(const ColorT<T>& src) : r(src.r), g(src.g), b(src.b), a(1) {}
  template<typename U>
    explicit ColorAT(const ColorAT<U>& src) : r(static_cast<U>(src.r)), g(static_cast<U>(src.g)), b(static_cast<U>(src.b)), a(static_cast<U>(src.a)) {}
  template<typename U>
    explicit ColorAT(const ColorT<U>& src) : r(static_cast<U>(src.r)), g(static_cast<U>(src.g)), b(static_cast<U>(src.b)), a(1) {}

  static ColorAT<T> white() { return ColorAT<T>(1, 1, 1, 1); }
  static ColorAT<T> red() { return ColorAT<T>(1, 0, 0, 1); }
  static ColorAT<T> green() { return ColorAT<T>(0, 1, 0, 1); }
  static ColorAT<T> blue() { return ColorAT<T>(0, 0, 1, 1); }
  static ColorAT<T> orange() { return ColorAT<T>(1.0f, 0.6f, 0.0f, 1.0f); }
  static ColorAT<T> gray() { return ColorAT<T>(0.3f, 0.3f, 0.3f, 1.0f); }

  ColorAT<T>& operator+=(const ColorAT<T>& rhs) {
    r += rhs.r;
    g += rhs.g;
    b += rhs.b;
    a += rhs.a;
    return *this;
  }
  ColorAT<T>& operator-=(const ColorAT<T>& rhs) {
    r -= rhs.r;
    g -= rhs.g;
    b -= rhs.b;
    a -= rhs.a;
    return *this;
  }
  ColorAT<T>& operator*=(const T& rhs) {
    r *= rhs;
    g *= rhs;
    b *= rhs;
    a *= rhs;
    return *this;
  }
  ColorAT<T> operator+(const ColorAT<T>& rhs) const {
    return ColorAT<T>(r + rhs.r, g + rhs.g, b + rhs.b, a + rhs.a);
  }
  ColorAT<T> operator-(const ColorAT<T>& rhs) const {
    return ColorAT<T>(r - rhs.r, g - rhs.g, b - rhs.b, a - rhs.a);
  }
  ColorAT<T> operator*(const T& rhs) const {
    return ColorAT<T>(r * rhs, g * rhs, b * rhs, a * rhs);
  }

  friend std::ostream& operator<<(std::ostream& os, const ColorAT<T>& rhs) {
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "," << rhs.a << "]";
    return os;
  }
};

typedef ColorT<float>  Color;
typedef ColorAT<float> ColorA;