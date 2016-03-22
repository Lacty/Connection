
#include "game.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Title/title.hpp"


Game::Game(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font_(loadAsset("rounded-l-mplus-1c-regular.ttf")) {
  font_.setSize(50);
  std::cout << "start game" << std::endl;
}

Game::~Game() {
  std::cout << "end game" << std::endl;
}


void Game::update() {
  if (app_->isPushKey(GLFW_KEY_N)) { is_finish_ = true; }
}

void Game::draw() {
  font_.draw("Game", Vec2f(app_->windowCenter()));
}


std::shared_ptr<SceneBase> Game::nextScene(AppNative *app) {
  return sceneCreate<Title>(app);
}