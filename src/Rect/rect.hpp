
#pragma once
#include "../Vector/vector.hpp"


template<typename T>
class Rect2d {
public:
  Vec2<T> pos_;
  Vec2<T> size_;

  Rect2d() = default;
  Rect2d(const T& width, const T& height) : pos_(width * 0.5f, height * 0.5f), size_(width, height) {}
  Rect2d(const Vec2<T>& size) : pos_(int(size.x * 0.5f), int(size.y * 0.5f)), size_(size) {}
  Rect2d(const Vec2<T>& pos, const Vec2<T>& size) : pos_(pos), size_(size) {}

  T left()   const { return static_cast<T>(-size_.x * 0.5f); }
  T right()  const { return static_cast<T>(size_.x * 0.5f); }
  T top()    const { return static_cast<T>(size_.y * 0.5f); }
  T bottom() const { return static_cast<T>(-size_.y * 0.5f); }

  T width()  const { return size_.x; }
  T height() const { return size_.y; }

  Vec2<T> leftTop()     const { return Vec2<T>(left(), top()); }
  Vec2<T> leftBottom()  const { return Vec2<T>(left(), bottom()); }
  Vec2<T> rightTop()    const { return Vec2<T>(right(), top()); }
  Vec2<T> rightBottom() const { return Vec2<T>(right(), bottom()); }

  friend std::ostream& operator<<(std::ostream& os, const Rect2d<T>& rhs) {
    os << rhs.pos_ << rhs.size_;
    return os;
  }
};

typedef Rect2d<int>    Recti;
typedef Rect2d<float>  Rectf;
typedef Rect2d<double> Rectd;