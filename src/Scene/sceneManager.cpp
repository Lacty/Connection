
#include "sceneManager.hpp"
#include "sceneMaker.hpp"

#include "../Title/title.hpp"
#include "../Game/game.hpp"


SceneManager::SceneManager(AppNative* app) :
app_(app) {
  scene_ = sceneCreate<Title>(app);
}

void SceneManager::run() {
  scene_->update();
  scene_->draw();
  scene_->drawFade();
  
  if(scene_->shouldClose()) {
    scene_ = scene_->nextScene(app_);
  }
}