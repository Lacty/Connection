
#pragma once
#include "../Scene/sceneBase.hpp"
#include "../Network/network.hpp"
#include "../Tcp/tcp.hpp"


class Title : public SceneBase {
private:
  Font font_;
  Vec2d pos_;
  Network net_;

  std::thread th_;
  bool enable_;;
  
public:
  Title(AppNative* app);
  ~Title();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};

// �x���ւ̑΍�
// C4005 'APIENTRY': �}�N�����Ē�`����܂����B minwindef.h 130
#undef APIENTRY