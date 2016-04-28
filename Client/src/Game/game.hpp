
#pragma once
#include "../Scene/sceneBase.hpp"
#include "../Audio/audio.hpp" 
#include "../Audio/visualizer.hpp"

#include <vector>


class Game : public SceneBase {
private:
  Font font_;
  Media media_;
  Visualizer vis_;

  int index_;
  std::vector<std::string> data_;

  int font_size_;

public:
  Game(AppNative* app);
  ~Game();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};

// 警告への対策
// C4005 'APIENTRY': マクロが再定義されました。 minwindef.h 130
#undef APIENTRY