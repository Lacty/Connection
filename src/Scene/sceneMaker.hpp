
#pragma once
#include <memory>

class SceneBase;
class AppNative;


template<class Scene>
std::shared_ptr<SceneBase> sceneCreate(AppNative* app)
{
  return std::make_shared<Scene>(app);
}