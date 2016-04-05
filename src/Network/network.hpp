
#pragma once
#include <thread>
#include "picojson.h"
#include "../Tcp/tcp.hpp"


class Network {
private:
  std::string ip_;
  int port_;
  Tcp tcp_;

  picojson::object recv_;
  picojson::object send_;

  std::thread th_;

  bool is_enable_;
  bool is_fin_;

public:
  Network() = default;
  Network(const std::string& ip, int port);
  ~Network();

  template<typename T>
  T get(const std::string& key) {
    return recv_[key].get<T>();
  }

  template<typename T>
  void add(const std::string& key, T val) {
    send_.emplace(std::make_pair(key.c_str(), picojson::value(val)));
  }
  
  void connect();

  void enable();
  void disable();
}; 