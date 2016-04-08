
#include "title.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Game/game.hpp"


Title::Title(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font_(loadAsset("rounded-l-mplus-1c-regular.ttf")),
pos_(0, 0),
net_("112.78.125.193", 12345) {
  font_.setSize(50);
  std::cout << "start title" << std::endl;
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app_->isPushKey(GLFW_KEY_N)) { is_finish_ = true; fade_ = Fade(Fade::Type::Out); }

  if (app_->isPressKey(GLFW_KEY_D)) { pos_.x += 10; }
  if (app_->isPressKey(GLFW_KEY_A)) { pos_.x -= 10; }
  if (app_->isPressKey(GLFW_KEY_W)) { pos_.y += 10; }
  if (app_->isPressKey(GLFW_KEY_S)) { pos_.y -= 10; }


  net_.clear();
  net_.add("posx", pos_.x);
  net_.add("posy", pos_.y);
  net_.connect();
}

void Title::draw() {
  font_.draw("Title", Vec2f(app_->windowCenter()));

  drawRect(Vec3f(pos_), Vec2f(50, 50), ColorA::white());
}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}