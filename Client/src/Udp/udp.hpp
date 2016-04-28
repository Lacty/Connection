
#pragma once

#if _WINDOWS
  #include <WinSock2.h>
#else
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
#endif

#include <iostream>
#include <string>
#include <assert.h>


const int BUF_SIZE = 256;

class Udp {
private:
#if _WINDOWS
  WSAData     wsa_data_;
  SOCKET      sock_;
#else
  int sock_;
#endif

  sockaddr_in addr_;
  u_short     port_;
  std::string ip_;

  void createSocket();

public:
  Udp();
  ~Udp();

  void initAddr(u_short port, const std::string& ip);

  std::string recieve();

  void send(const std::string& data);
};