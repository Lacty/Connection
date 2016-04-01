
// これはWindowsだけの設定
#if _WINDOWS
#if !_DEBUG
  // デバッグ時のみコンソールを表示させる
  #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif
  // 競合がおきるのでmsvcrt.libを除外
  #pragma comment(linker, "/NODEFAULTLIB:\"msvcrt.lib\"")
#endif

#include "appNative.hpp"


AppNative::AppNative(const Vec2i& size,
                     const std::string& title) :
window_(size),
tweakBar_(size),
camera_(Vec3f::zero(), Vec3f(0, 0, -1), 0.0f, 5.0f, 35.0f, size) {
  gl_win_ = createWindow(size, title);
  glfwSetWindowUserPointer(gl_win_, this);
  glfwSwapInterval(1); // 60 fps
  glOrtho(window_.left(), window_.right(), window_.bottom(), window_.top(), .0, -1);
  setCallBackFunc();
}


GLFWwindow* AppNative::createWindow(const Vec2i& size, const std::string& title) {
  if (!glfwInit()) assert(!"");

  auto window = glfwCreateWindow(size.x, size.y,
                                 title.c_str(), nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    assert(!"create window");
  }

  glfwMakeContextCurrent(window);

  return window;
}

void AppNative::mouseButtomCallback(GLFWwindow* window, int button, int action, int mods) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  if (action == GLFW_PRESS) {
    app->mouse_.setButtonPush(button);
    app->mouse_.setButtonPress(button);
  }
  if (action == GLFW_RELEASE) {
    app->mouse_.setButtonPull(button);
    app->mouse_.popButtonPress(button);
  }

  TweakBar::mouseButtonCallBack(window, button, action, mods);
}

void AppNative::mousePosCallBack(GLFWwindow* window, double xpos, double ypos) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  app->mouse_.setPos(xpos, ypos);

  TweakBar::mousePosCallBack(window, xpos, ypos);
}

void AppNative::mouseWheelCallBack(GLFWwindow* window, double xoffset, double yoffset) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  TweakBar::mouseWheelCallBack(window, xoffset, yoffset);
}

void AppNative::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));
  
  if (action == GLFW_PRESS) {
    app->key_.setKeyPush(key);
    app->key_.setKeyPress(key);
  }
  if (action == GLFW_RELEASE) {
    app->key_.setKeyPull(key);
    app->key_.popKeyPress(key);
  }

  TweakBar::keyCallBack(window, key, scancode, action, mods);
}
void AppNative::charCallBack(GLFWwindow* window, uint32_t codepoint) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  TweakBar::charCallBack(window, codepoint);
}

void AppNative::windowSizeCallBack(GLFWwindow* window, int width, int height) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  TweakBar::windowSizeCallBack(window, width, height);
  glViewport(0, 0, width, height);
  app->window_.size_ = Vec2i(width, height);
}

void AppNative::setCallBackFunc() {
  glfwSetMouseButtonCallback(gl_win_, mouseButtomCallback);
  glfwSetCursorPosCallback(gl_win_, mousePosCallBack);
  glfwSetScrollCallback(gl_win_, mouseWheelCallBack);
  glfwSetKeyCallback(gl_win_, keyCallBack);
  glfwSetCharCallback(gl_win_, charCallBack);
  glfwSetWindowSizeCallback(gl_win_, windowSizeCallBack);
}


bool AppNative::isOpen() {
  end().begin();
  key_.clear();
  mouse_.clear();
  return !glfwWindowShouldClose(gl_win_);
}

AppNative& AppNative::begin() {
  glClear(GL_COLOR_BUFFER_BIT);
  return *this;
}

AppNative& AppNative::end() {
  tweakBar_.draw();
  glfwSwapBuffers(gl_win_);
  glfwPollEvents();
  return *this;
}

AppNative& AppNative::setClearColor(const ColorA& color) {
  glClearColor(color.r, color.g, color.b, color.a);
  return *this;
}

Vec2i AppNative::windowSize()   const { return window_.size_; }
Vec2i AppNative::windowCenter() const { return window_.pos_; }


// Key Events
bool AppNative::isPushKey(int key)  { return key_.isPush(key); }
bool AppNative::isPullKey(int key)  { return key_.isPull(key); }
bool AppNative::isPressKey(int key) { return key_.isPress(key); }


// Mouse Events
bool AppNative::isPushMouse(int buttom)  { return mouse_.isPush(buttom); }
bool AppNative::isPullMouse(int buttom)  { return mouse_.isPull(buttom); }
bool AppNative::isPressMouse(int buttom) { return mouse_.isPress(buttom); }

Vec2d AppNative::mousePos() const { return mouse_.pos(); }

AppNative& AppNative::setMousePos(const Vec2d& pos) {
  glfwSetCursorPos(gl_win_, pos.x, pos.y);
  mouse_.setPos(pos.x, pos.y);
  return *this;
}


// Camera Events
AppNative& AppNative::updateCam() { camera_.update(); return *this; }

AppNative& AppNative::setCamPos(const Vec3f& pos)       { camera_.setPos(pos); return *this; }
AppNative& AppNative::setCamTarget(const Vec3f& target) { camera_.setTarget(target); return *this; }
AppNative& AppNative::setCamUp(const Vec3f& up)         { camera_.setUp(up); return *this; }

AppNative& AppNative::setCamNear(const float near) { camera_.setNear(near); return *this; }
AppNative& AppNative::setCamFar(const float far) { camera_.setFar(far); return *this; }
AppNative& AppNative::setCamFovy(const float fovy) { camera_.setFovy(fovy); return *this; }

const Vec3f AppNative::camPos() const    { return camera_.getPos(); }
const Vec3f AppNative::camTarget() const { return camera_.getTarget(); }
const Vec3f AppNative::camUp() const     { return camera_.getUp(); }

const float AppNative::camNear() const { return camera_.getNear(); }
const float AppNative::camFar() const  { return camera_.getFar(); }
const float AppNative::camFovy() const { return camera_.getFovy(); }