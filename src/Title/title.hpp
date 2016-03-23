
#pragma once
#include <thread>

#include "../Scene/sceneBase.hpp"
#include "../Udp/udp.hpp"


class Title : public SceneBase {
private:
  Font font_;
  Udp sender_;
  Udp receiver_;

  Vec2f self_;
  Vec2f other_;

  std::thread thread_;
  bool isFinishReceive;

  void setThread();

public:
  Title(AppNative* app);
  ~Title();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};