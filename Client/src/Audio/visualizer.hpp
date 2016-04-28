
#pragma once
#include "../Vector/vector.hpp"


class Media;

class Visualizer {
private:
  Media* media_;
  Vec2f  pos_;
  Vec2f  size_;
  float  width_;
  int    split_num_;
  float  height_upper_;
  float  height_lower_;

public:
  Visualizer() = default;
  Visualizer(Media* media);
  Visualizer(Media* media, const Vec2f& pos, const Vec2f& size, int split_num = 20);

  
  void drawTest(const Vec2f& pos, const Vec2f& size);

  void draw(const Vec2f& pos, const Vec2f& size);
  void drawWithFFT(const Vec2f& pos, const Vec2f& size);

  Visualizer& setPos(const Vec2f& pos);
  Visualizer& setSize(const Vec2f& size);
  Visualizer& setLineWidth(const float width);
  Visualizer& setSplitNum(const int num);
  Visualizer& setHeightUpper(const float limit);
  Visualizer& setHeightLower(const float limit);
};