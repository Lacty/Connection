
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Scene/sceneBase.hpp"
#include "../Noncopyable/noncopyable.hpp"
#include "sceneMaker.hpp"


class SceneManager : Noncopyable {
private:
  AppNative* app_;
  std::shared_ptr<SceneBase> scene_;

public:
  SceneManager(AppNative* app);

  void run();
};