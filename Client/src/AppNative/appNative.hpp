
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

#include "../Noncopyable/noncopyable.hpp"
#include "../Vector/vector.hpp"
#include "../Color/color.hpp"
#include "../Rect/rect.hpp"
#include "../Key/key.hpp"
#include "../Mouse/mouse.hpp"
#include "../Font/font.hpp"
#include "../LoadPath/loadPath.hpp"
#include "../Graphic/graphic.hpp"
#include "../Audio/audio.hpp"
#include "../Random/random.hpp"
#include "../CatmullRom/catmullRom.hpp"
#include "../TweakBar/tweakBar.hpp"
#include "../Utility/utility.hpp"
#include "../MainCamera/mainCamera.hpp"


class AppNative : public Noncopyable {
private:
  GLFWwindow* gl_win_;
  Recti       window_;
  Key         key_;
  Mouse       mouse_;
  Audio       audio_;
  Random      random_;
  TweakBar    tweakBar_;
  MainCamera  camera_;

  GLFWwindow* createWindow(const Vec2i& size, const std::string& title);

  static void mouseButtomCallback(GLFWwindow* window, int button, int action, int mods);
  static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
  static void mouseWheelCallBack(GLFWwindow* window, double xoffset, double yoffset);
  static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
  static void charCallBack(GLFWwindow* window, uint32_t codepoint);
  static void windowSizeCallBack(GLFWwindow* window, int width, int height);

  void setCallBackFunc();
  
  AppNative& begin();
  AppNative& end();

public:
  AppNative() = delete;
  AppNative(const Vec2i& size,
            const std::string& title);

  bool isOpen();

  AppNative& setClearColor(const ColorA& color);

  Vec2i windowSize() const;
  Vec2i windowCenter() const;


  // Key Events
  bool isPushKey(int key);
  bool isPullKey(int key);
  bool isPressKey(int key);


  // Mouse Events
  bool isPushMouse(int buttom);
  bool isPullMouse(int buttom);
  bool isPressMouse(int buttom);

  Vec2d mousePos() const;
  AppNative& setMousePos(const Vec2d& pos);


  // Camera Events
  AppNative& updateCam();

  AppNative& setCamPos(const Vec3f& pos);
  AppNative& setCamTarget(const Vec3f& target);
  AppNative& setCamUp(const Vec3f& up);

  AppNative& setCamNear(const float near);
  AppNative& setCamFar(const float far);
  AppNative& setCamFovy(const float fovy);

  const Vec3f camPos() const;
  const Vec3f camTarget() const;
  const Vec3f camUp() const;

  const float camNear() const;
  const float camFar() const;
  const float camFovy() const;

  // Rnadom
  template<typename RandType>
  RandType rand(RandType range) {
    return Random::distribusion_t<RandType>(0, range)(random_.mt_);
  }
};