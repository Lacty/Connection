
#include "graphic.hpp"


void drawLine(const Vec2f& begin, const Vec2f& end, const float width, const ColorA& color) {
  std::vector<GLfloat> vtx{
    begin.x, begin.y,
    end.x, end.y
  };

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glVertexPointer(2, GL_FLOAT, 0, &vtx[0]);
  glColor4f(color.r, color.g, color.b, color.a);
  glLineWidth(width);

  glEnableClientState(GL_VERTEX_ARRAY);

  glDrawArrays(GL_LINES, 0, 2);

  glDisableClientState(GL_VERTEX_ARRAY);

  glDisable(GL_BLEND);
}

void drawRect(const Vec3f& pos, const Vec2f& size, const ColorA& color) {
  std::vector<GLfloat> vtx{
    pos.x - size.x * 0.5f, pos.y + size.y * 0.5f, pos.z,
    pos.x - size.x * 0.5f, pos.y - size.y * 0.5f, pos.z,
    pos.x + size.x * 0.5f, pos.y - size.y * 0.5f, pos.z,
    pos.x + size.x * 0.5f, pos.y + size.y * 0.5f, pos.z
  };

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glColor4f(color.r, color.g, color.b, color.a);

  glEnableClientState(GL_VERTEX_ARRAY);

  glDrawArrays(GL_QUADS, 0, 4);

  glDisableClientState(GL_VERTEX_ARRAY);

  glDisable(GL_BLEND);
}

void drawCircle(const Vec3f& center, int vertex_num,
                float radius, float width, const ColorA& color)
{
  std::vector<GLfloat> vtx;
  for (int i = 0; i < vertex_num; i++) {
    vtx.push_back(float(center.x + sin(i * 2 * M_PI / vertex_num) * radius));
    vtx.push_back(float(center.y + cos(i * 2 * M_PI / vertex_num) * radius));
    vtx.push_back(center.z);
  }

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glLineWidth(width);
  glColor4f(color.r, color.g, color.b, color.a);

  glEnableClientState(GL_VERTEX_ARRAY);

  glDrawArrays(GL_LINE_LOOP, 0, vertex_num);

  glDisableClientState(GL_VERTEX_ARRAY);

  glDisable(GL_BLEND);
}