
#include "sceneBase.hpp"


void SceneBase::drawFade() {
  fade_.draw((Vec2f)app_->windowSize());
}

bool SceneBase::shouldClose() {
  return is_finish_ && fade_.isFinish();
}