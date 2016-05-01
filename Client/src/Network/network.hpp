
#pragma once
#include <string>
#include <functional>
#include "../Udp/udp.hpp"


class Network {
private:
  Udp udp;

public:
  Network() = delete;
  Network(const std::string& ip, int port);
  ~Network() = default;

  void setSendCallback();
  void setRecvCallback();
};
