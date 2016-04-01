
#pragma once
#include "../Scene/sceneBase.hpp"


class Title : public SceneBase {
private:
  Font font_;

public:
  Title(AppNative* app);
  ~Title();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};