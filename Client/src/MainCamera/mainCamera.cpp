
#include <GLFW/glfw3.h>
#include "mainCamera.hpp"
#include "../Utility/utility.hpp"


MainCamera::MainCamera(const Vec3f& pos,
                       const Vec3f& target,
                       const float near,
                       const float far,
                       const float fovy,
                        const Vec2i& window) :
pos_(pos),
target_(target),
up_(Vec3f::yAxis()),
near_(near),
far_(far),
fovy_(fovy),
aspect_(window.x / (float)window.y) {}


void MainCamera::perspView() {
  float f = float(1. / std::tan(toRadians(fovy_) * 0.5));
  float g = -((far_ + near_) / (far_ - near_));
  float h = -((2 * far_ * near_) / (far_ - near_));
  float i = f / aspect_;

  Eigen::Matrix4f m;
  m <<    i, 0.0f, 0.0f, 0.0f,
       0.0f,    f, 0.0f, 0.0f,
       0.0f, 0.0f,    g,    h,
       0.0f, 0.0f,   -1, 0.0f;

  glMultMatrixf(m.data());
}

void MainCamera::perspTrans() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  perspView();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void MainCamera::lookToTarget() {
  Vec3f z = getForward() / getForward().length();

  Vec3f b = up_.cross(z);
  Vec3f x = b / b.length();

  Vec3f y = z.cross(x);

  Eigen::Matrix4f R;
  R << x.x,   x.y,  x.z, 0.0f,
       y.x,   y.y,  y.z, 0.0f,
       z.x,   z.y,  z.z, 0.0f,
       0.0f, 0.0f, 0.0f, 1.0f;

  Eigen::Matrix4f T;
  T << 1.0f, 0.0f, 0.0f, -pos_.x,
       0.0f, 1.0f, 0.0f, -pos_.y,
       0.0f, 0.0f, 1.0f, -pos_.z,
       0.0f, 0.0f, 0.0f,    1.0f;

  Eigen::Matrix4f m = R * T;
  glMultMatrixf(m.data());
}

void MainCamera::update() {
  perspTrans();
  lookToTarget();
}

void MainCamera::windowSizeCallBack(const int width, const int height) {
  aspect_ = width / (float)height;
}


void MainCamera::setPos(const Vec3f& pos) { pos_ = pos; }
void MainCamera::setTarget(const Vec3f& target) { target_ = target; }
void MainCamera::setUp(const Vec3f& up) { up_ = up; }

void MainCamera::setNear(const float near) { near_ = near; }
void MainCamera::setFar(const float far) { far_ = far; }
void MainCamera::setFovy(const float fovy) { fovy_ = fovy; }

const Vec3f& MainCamera::getPos() const { return pos_; }
const Vec3f& MainCamera::getTarget() const { return target_; }
const Vec3f& MainCamera::getUp() const { return up_; }

const float& MainCamera::getNear() const { return near_; }
const float& MainCamera::getFar() const { return far_; }
const float& MainCamera::getFovy() const { return fovy_; }

Vec3f MainCamera::getForward() const {
  return pos_ - target_;
}