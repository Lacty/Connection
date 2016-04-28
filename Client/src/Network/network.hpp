
#pragma once
#include <thread>
#include "picojson.h"
#include "../Tcp/tcp.hpp"


class Network {
private:
  Tcp tcp_;

  std::string ip_;
  int port_;

  picojson::object send_data_;
  picojson::object recv_data_;

  std::thread send_th_;
  std::thread recv_th_;

  bool is_enable_;
  bool is_finish_;

public:
  Network() = default;
  Network(const std::string& ip, int port);
  ~Network() = default;

  template<typename T>
  T get(const std::string& key) {
    if (!recv_data_.count(key)) return 0;
    return recv_data_[key].get<T>();
  }

  template<typename T>
  void add(const std::string& key, T& val) {
    send_data_.emplace(std::make_pair(key.c_str(), picojson::value(val)));
  }

  void clearSendBuf();

  void connect();
  void disconnect();

  void setSendThread();
  void setRecvThread();

  void enable(bool enable);
};