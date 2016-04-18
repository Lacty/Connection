
#pragma once
#define FTGL_LIBRARY_STATIC
#include <FTGL/ftgl.h>
#include "../Vector/vector.hpp"

#include <string>
#include <codecvt>


class Font {
private:
  FTPixmapFont font_;
  std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> cv_;

public:
  Font() = default;
  explicit Font(const std::string& path);

  void setSize(int size);
  void draw(const std::string& str, const Vec2f& pos);
  void drawCenter(const std::string& str, const Vec2f& pos);
};
