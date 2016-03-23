
#pragma once
#include "../Scene/sceneBase.hpp"
#include "../Udp/udp.hpp"


class Title : public SceneBase {
private:
  Font font_;
  Udp sender_;
  Udp receiver_;
  Vec2f self_;
  Vec2f other_;

public:
  Title(AppNative* app);
  ~Title();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};