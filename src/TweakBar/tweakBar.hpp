
#pragma once
#include <GLFW/glfw3.h>
#include <AntTweakBar.h>
#include "../Noncopyable/noncopyable.hpp"
#include "../Vector/vector.hpp"


class TweakBar : public Noncopyable {
public:
  TweakBar(const Vec2i& size);
  ~TweakBar();

  void draw();
  
  static void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
  static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
  static void mouseWheelCallBack(GLFWwindow* window, double xoffset, double yoffset);
  static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void charCallBack(GLFWwindow* window, int codepoint);
  static void windowSizeCallBack(GLFWwindow* window, int width, int height);
};