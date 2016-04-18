
#include "network.hpp"
#include <vector>
#include <string>


Network::Network(const std::string& ip, int port) :
  ip_(ip),
  port_(port),
  is_enable_(true),
  is_fin_send_(true),
  is_fin_recv_(true) {}

Network::~Network() {}


void Network::clearSendBuf() {
  send_.clear();
}

void Network::setSendThread() {
  if (!is_enable_) return;

  if (!is_fin_send_) return;

  if (th_send_.joinable()) th_send_.join();

  th_send_ = std::thread([&] {
    is_fin_send_ = false;
    if (send_.empty()) return;

    udp_send_.initAddr((u_short)port_, ip_);

    picojson::value val(send_);
    udp_send_.send(val.serialize());
 
    is_fin_send_ = true;
  });
}

void Network::setRecvThread() {
  if (!is_enable_) return;

  if (!is_fin_recv_) return;

  if (th_recv_.joinable()) th_recv_.join();

  th_recv_ = std::thread([&] {
    is_fin_recv_ = false;

    udp_recv_.initAddr(12345, "");

    std::string data = udp_recv_.recieve();
    picojson::value val;
    picojson::parse(val, data);
    recv_ = val.get<picojson::object>();

    is_fin_recv_ = true;
  });
}

void Network::enable() { is_enable_ = true; }
void Network::disable() { is_enable_ = false; }

void Network::exit() {
  is_enable_ = false;
  if (th_send_.joinable()) th_send_.join();
  if (th_recv_.joinable()) th_recv_.join();
}