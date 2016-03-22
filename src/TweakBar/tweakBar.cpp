
#include "tweakBar.hpp"


TweakBar::TweakBar(const Vec2i& size) {
  TwInit(TW_OPENGL, nullptr);
  TwWindowSize(size.x, size.y);
}

TweakBar::~TweakBar() {
  TwTerminate();
}

void TweakBar::draw() {
  TwDraw();
}

void TweakBar::mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods) {
  TwEventMouseButtonGLFW(button, action);
}

void TweakBar::mousePosCallBack(GLFWwindow* window, double xpos, double ypos) {
  TwMouseMotion(int(xpos), int(ypos));
}

void TweakBar::mouseWheelCallBack(GLFWwindow* window, double xoffset, double yoffset) {
  TwMouseWheel(int(yoffset));
}

void TweakBar::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
  TwEventKeyGLFW(key, action);
}

void TweakBar::charCallBack(GLFWwindow* window, int codepoint) {
  TwEventCharGLFW(codepoint, GLFW_PRESS);
}

void TweakBar::windowSizeCallBack(GLFWwindow* window, int width, int height) {
  TwWindowSize(width, height);
}