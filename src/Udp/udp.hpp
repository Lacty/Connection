
#pragma once

#include <WinSock2.h>
#include <iostream>
#include <vector>
#include <assert.h>


class Udp {
private:
  WSAData     wsa_data_;
  SOCKET      sock_;
  sockaddr_in addr_;
  u_short     port_;
  std::string ip_;

  void createSocket();

public:
  Udp();
  ~Udp();

  void initAddr(u_short port, const std::string& ip);

  std::vector<char> recieve();

  void send(const std::vector<char>& data);
};