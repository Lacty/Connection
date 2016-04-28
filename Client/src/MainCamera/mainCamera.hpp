
#pragma once
#include "../Noncopyable/noncopyable.hpp"
#include "../Vector/vector.hpp"


class MainCamera : public Noncopyable {
private:
  Vec3f pos_;
  Vec3f target_;
  Vec3f up_;

  float near_;
  float far_;
  float fovy_;
  float aspect_;

  void perspView();
  void perspTrans();
  void lookToTarget();

public:
  MainCamera() = default;
  MainCamera(const Vec3f& pos,
             const Vec3f& target,
             const float near,
             const float far,
             const float fovy,
             const Vec2i& window);

  void update();
  void windowSizeCallBack(const int width, const int height);


  void setPos(const Vec3f& pos);
  void setTarget(const Vec3f& target);
  void setUp(const Vec3f& up);

  void setNear(const float near);
  void setFar(const float far);
  void setFovy(const float fovy);

  const Vec3f& getPos() const;
  const Vec3f& getTarget() const;
  const Vec3f& getUp() const;

  const float& getNear() const;
  const float& getFar() const;
  const float& getFovy() const;

  Vec3f getForward() const;
};