
#include "AppNative/appNative.hpp"
#include "Scene/sceneManager.hpp"

int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());
  
  SceneManager game(&app);

  while (app.isOpen()) {
    game.run();
  }
}
