
#include "network.hpp"
#include <vector>
#include <string>


Network::Network(const std::string& ip, int port) :
ip_(ip),
port_(port) {
  enable();
}

Network::~Network() {}


void Network::connect() {
  if (!is_enable_ && is_fin_) return;

  // join thread if finished
  if (th_.joinable() && is_fin_) th_.join();

  if (!is_enable_) return;

  send_.clear();
  if (!is_fin_) return;

  if (th_.joinable()) th_.join();

  // set thread
  th_ = std::thread([&] {
    is_fin_ = false;
    std::string data;
    picojson::value val(send_);

    // connect to server
    tcp_.connect(ip_, port_);
    //tcp_ << val.serialize();
    tcp_ >> data;

    picojson::parse(val, data);
    recv_ = val.get<picojson::object>();

    std::cout << recv_["name"].get<std::string>().c_str() << std::endl;

    is_fin_ = true;
  });
}

void Network::enable()  { is_enable_ = true; }
void Network::disable() { is_enable_ = false; }