
#include "game.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Title/title.hpp"


Game::Game(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font_(loadAsset("rounded-l-mplus-1c-regular.ttf")),
media_(loadAsset("sound.wav")),
vis_(&media_) {
  font_size_ = 150;
  font_.setSize(font_size_);
  vis_.setPos(Vec2f(0, -100));
  vis_.setSize((Vec2f)app_->windowSize());

  index_ = 0;
  data_.push_back("Hi XD");
  data_.push_back("my name is Yanai");
  data_.push_back("i'm C++er");
  data_.push_back("");
  data_.push_back("Tw @Lost206");
  data_.push_back("Git /Lacty");
  data_.push_back("Sound Visualizer");
  data_.push_back("Sound = sin(x) + 2*sin(2x)...");
  data_.push_back("m(_._)m");

  std::cout << "start game" << std::endl;
}

Game::~Game() {
  std::cout << "end game" << std::endl;
}


void Game::update() {
  if (app_->isPushKey(GLFW_KEY_N)) { is_finish_ = true; }
  if (app_->isPushKey(GLFW_KEY_P)) { media_.play(); }
  if (app_->isPushKey(GLFW_KEY_S)) { media_.stop(); }
  if (app_->isPushKey(GLFW_KEY_O)) { media_.pause(); }

  if (app_->isPushKey(GLFW_KEY_A)) { if (index_ > 0) index_--; }
  if (app_->isPushKey(GLFW_KEY_D)) { if (index_ < data_.size() - 1) index_++; }

  if (app_->isPressKey(GLFW_KEY_W)) { font_size_++; font_.setSize(font_size_); }
  if (app_->isPressKey(GLFW_KEY_S)) { font_size_--; font_.setSize(font_size_); }

  std::cout << app_->windowSize().x << std::endl;
}

void Game::draw() {
  //font_.draw("Game", Vec2f(app_->windowCenter()));

  font_.drawCenter(data_[index_].c_str(), (Vec2f)app_->windowSize() / 2);

  vis_.drawTest(Vec2f(0, 0), Vec2f(app_->windowSize().x, 0));
}


std::shared_ptr<SceneBase> Game::nextScene(AppNative *app) {
  return sceneCreate<Title>(app);
}