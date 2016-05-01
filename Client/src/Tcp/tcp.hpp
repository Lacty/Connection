
#pragma once


// Windows or Other
#if defined(WIN32) || defined(_WINDOWS)
#include <WinSock2.h>
#else
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#endif

#include <iostream>

const int LISTEN_NUM = 5;
const int BUFFER_SIZE = 1024;


class Tcp {
private:
#if defined(WIN32) || defined(_WINDOWS)
  WSAData wsa_;
  SOCKET  sock_;
#else
  int sock_;
#endif
  sockaddr_in addr_;

/*
  close Socket func
*/
#if defined(WIN32) || defined(_WINDOWS)
  void closeSock(SOCKET sock) {
    WSACleanup();
    ::closesocket(sock_);
  }
#else
  void closeSock(int sock) {
    // close sock
    ::close(sock_);
  }
#endif
  
public:
  Tcp();
  ~Tcp();
  
  // clear 'sock_' and 'addr_'
  void clear();

  // server func
  bool create();
  bool bind(const int port);
  bool listen();
  bool accept(Tcp& src);
  
  // client func
  bool connect(const std::string& address, const int port);
  
  // data transmission
  bool recv(std::string& data);
  bool send(const std::string data);
  std::string recv();
  
  // check if socket is valid
  bool is_valid();
  
  // operators
  void operator >> (std::string& data);
  void operator << (const std::string data);
};