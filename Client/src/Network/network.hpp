
#pragma once
#include <string>
#include <functional>
#include <thread>
#include <picojson.h>
#include "../Udp/udp.hpp"


class Network {
private:
  // connection protocol
  Udp udp_;

  // callback functions
  std::function<std::string()> send_callback_;
  std::function<void()>        recv_callback_;

public:
  Network() = delete;
  Network(const std::string& ip, int port);
  ~Network() = default;

  // setter for callback if connect
  void setSendCallback(std::function<std::string()> send_func);
  void setRecvCallback(std::function<void()> recv_func);

  // connect func
  void send(std::string& str);
  void recv(std::string& str);
};
