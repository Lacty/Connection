
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

  setThread();
}

Title::~Title() {
  thread_
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app_->isPushKey(GLFW_KEY_N)) { is_finish_ = true; }
  if (app_->isPressKey(GLFW_KEY_A)) { self_.x -= 0.6f; }
  if (app_->isPressKey(GLFW_KEY_D)) { self_.x += 0.6f; }
  if (isFinishReceive) {
    if (thread_.joinable()) { thread_.join(); }
    setThread();
  }
  std::vector<char> data;
  data = addArithmeticDataToVector(self_.x, std::move(data));
  data = addArithmeticDataToVector(self_.y, std::move(data));
  //sender_.send(data);
}

void Title::draw() {
  font_.draw("Title", Vec2f(app_->windowCenter()));

  drawRect(Vec3f(self_),  Vec2f(10, 10), ColorA::white());
  drawRect(Vec3f(other_), Vec2f(10, 10), ColorA::red());
}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}


void Title::setThread() {
  isFinishReceive = false;
  
  thread_ = std::thread([&] {
    std::vector<char> data = std::move(receiver_.recieve());
    std::vector<int> nullPoint;
    nullPoint.push_back(0);

    for (size_t i = 0; i < data.size(); i++) {
      if (data[i] == NULL) {
        std::cout << "[" << i << "] is null" << std::endl;
        nullPoint.push_back(i + 1);
      }
    }

    for (auto i : nullPoint) {
      std::cout << std::atof(&data[i]) << std::endl;
    }

    other_.x = std::atof(&data[nullPoint[0]]);
    other_.y = std::atof(&data[nullPoint[1]]);

    isFinishReceive = true;
  });
}