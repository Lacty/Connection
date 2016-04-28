
#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "../Vector/vector.hpp"
#include "../Color/color.hpp"


void drawLine(const Vec2f& begin, const Vec2f& end, const float width = 1, const ColorA& color = ColorA::white());

void drawRect(const Vec3f& pos, const Vec2f& size, const ColorA& color);

void drawCircle(const Vec3f& center, int vertex_num,
                float radius, float width, const ColorA& color);