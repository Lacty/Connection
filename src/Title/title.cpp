
#include "title.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Game/game.hpp"


Title::Title(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font_(loadAsset("rounded-l-mplus-1c-regular.ttf")) {
  font_.setSize(50);
  std::cout << "start title" << std::endl;
  net_.add("posx", "aa");
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app_->isPushKey(GLFW_KEY_N)) { is_finish_ = true; fade_ = Fade(Fade::Type::Out); }
}

void Title::draw() {
  font_.draw("Title", Vec2f(app_->windowCenter()));
}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}