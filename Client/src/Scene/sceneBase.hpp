
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Fade/fade.hpp"


class SceneBase {
protected:
  AppNative* app_;
  Fade       fade_;
  bool       is_finish_;

public:
  SceneBase(AppNative* app, Fade fade) :
    app_(app),
    fade_(fade),
    is_finish_(false){}
  virtual ~SceneBase() = default;
	
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual std::shared_ptr<SceneBase> nextScene(AppNative* app) = 0;

  void drawFade();

  bool shouldClose();
};

// 警告への対策
// C4005 'APIENTRY': マクロが再定義されました。 minwindef.h 130
#undef APIENTRY