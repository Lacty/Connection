
#pragma once
#define FTGL_LIBRARY_STATIC
#include <FTGL/ftgl.h>
#include "../Vector/vector.hpp"


class Font {
private:
  FTPixmapFont font_;

public:
  Font() = default;
  explicit Font(const std::string& path);

  void setSize(int size);
  void draw(const std::string& str, const Vec2f& pos);
  void drawCenter(const std::string& str, const Vec2f& pos);
};
