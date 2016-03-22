
#include "font.hpp"


Font::Font(const std::string& str) :
font_(str.c_str()) {}


void Font::setSize(int size) {
  font_.FaceSize(size);
}

void Font::draw(const std::string& str, const Vec2f& pos) {
  font_.Render(str.c_str(), (int)str.size(), FTPoint(pos.x, pos.y));
}

void Font::drawCenter(const std::string& str, const Vec2f& pos) {
  float offset_x = (float)font_.BBox(str.c_str(), (int)str.size()).Upper().X();
  font_.Render(str.c_str(), (int)str.size(), FTPoint(pos.x - offset_x * 0.5f, pos.y));
}
