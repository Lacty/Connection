
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
#include <cassert>


const int BUF_SIZE = 126;

class Udp {
private:

#if defined(WIN32) || defined(_WINDOWS)
  WSAData     wsa_;
  SOCKET      sock_;
#else
  int sock_;
#endif

  sockaddr_in addr_;

  void createSock();
  void closeSock();

public:
  Udp();
  ~Udp();

  void init(const int port, const std::string& ip);
  void init(const int port);

  void recv(std::string& data);
  void send(const std::string& data);
  std::string recv();

  // operators
  void operator >> (std::string& data);
  void operator << (const std::string& data);
};