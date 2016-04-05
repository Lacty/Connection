
#pragma once
#include "../Scene/sceneBase.hpp"
#include "../Network/network.hpp"


class Title : public SceneBase {
private:
  Font font_;
  Vec2d pos_;
  Network net_;

public:
  Title(AppNative* app);
  ~Title();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};