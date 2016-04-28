
#include "network.hpp"
#include <vector>
#include <string>


Network::Network(const std::string& ip, int port) :
  ip_(ip),
  port_(port) {
  is_finish_ = false;
  is_enable_ = true;
}


void Network::clearSendBuf() {
  send_data_.clear();
}

void Network::connect() {
  is_enable_ = true;
  tcp_.connect(ip_, port_);
}

void Network::disconnect() {
  is_finish_ = false;
  //if (send_th_.joinable()) send_th_.join();
  if (recv_th_.joinable()) recv_th_.join();
}

void Network::setSendThread() {
  send_th_ = std::thread([&] {
    while (1) {
      if (!is_enable_) continue;

      tcp_.clear();
      tcp_.connect(ip_, port_);
      
      picojson::value val(send_data_);
      tcp_ << val.serialize();
      //tcp_ << "hoge";

      if (is_finish_) break;
    }
  });
}

void Network::setRecvThread() {
  recv_th_ = std::thread([&] {
    //while (1) {
      std::string data;
      tcp_ >> data;

      picojson::value val;
      picojson::parse(val, data);

      recv_data_ = val.get<picojson::object>();

      //if (!is_enable_) break;
    //}
  });
}

void Network::enable(bool enable) {
  is_enable_ = enable;
}