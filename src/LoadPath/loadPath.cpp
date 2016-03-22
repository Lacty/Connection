
#include "loadPath.hpp"


std::string loadAsset(const std::string& src) {
#if _WINDOWS
  std::string path("../../assets/");
#elif __APPLE__
  std::string path("../../../assets/");
#endif
  path += src;
  return path;
}
