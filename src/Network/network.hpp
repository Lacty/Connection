
#pragma once
#include <thread>
#include "picojson.h"
#include "../Udp/udp.hpp"


class Network {
private:
  std::string ip_;
  int port_;
  Udp udp_send_;
  Udp udp_recv_;

  picojson::object recv_;
  picojson::object send_;

  std::thread th_send_;
  std::thread th_recv_;

  bool is_enable_;
  bool is_fin_send_;
  bool is_fin_recv_;

  bool lock_;

public:
  Network() = default;
  Network(const std::string& ip, int port);
  ~Network();

  template<typename T>
  T get(const std::string& key) {
    if (recv_.empty()) return 0;
    return recv_[key].get<T>();
  }

  template<typename T>
  void add(const std::string& key, T val) {
    send_.emplace(std::make_pair(key.c_str(), picojson::value(val)));
  }

  void clearSendBuf();

  void setSendThread();
  void setRecvThread();

  void enable();
  void disable();
  void exit();

  void lock() { lock_ = true; }
  void unLock() { lock_ = false; }
}; 