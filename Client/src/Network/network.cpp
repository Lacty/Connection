
#include "network.hpp"
#include <vector>
#include <string>


Network::Network(const std::string& ip, int port) {
  // inisialize udp
  udp_.init(port, ip);
}


void Network::setSendCallback(std::function<std::string()> send_func) {
  send_callback_ = send_func;
}

void Network::setRecvCallback(std::function<void()> recv_func) {
  recv_callback_ = recv_func;
}


void Network::send(std::string& str) {
  udp_ << str;
}

void Network::recv(std::string& str) {
  udp_ >> str;
}