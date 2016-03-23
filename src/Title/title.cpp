
#include "title.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Game/game.hpp"


Title::Title(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font_(loadAsset("rounded-l-mplus-1c-regular.ttf")) {
  font_.setSize(50);
  std::cout << "start title" << std::endl;

  sender_.initAddr(12345, "127.0.0.1");
  receiver_.initAddr(12345, "");

  std::vector<char> data;
  int hp = 10;
  float speed = 3.141592;
  data = addArithmeticDataToVector(hp,    std::move(data));
  data = addArithmeticDataToVector(speed, std::move(data));

  for (char i : data) {
    std::cout << i << std::endl;
  }
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app_->isPushKey(GLFW_KEY_N)) { is_finish_ = true; }
}

void Title::draw() {
  font_.draw("Title", Vec2f(app_->windowCenter()));
}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}