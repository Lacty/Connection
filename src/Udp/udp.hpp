
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

  void createSocket() {
    sock_ = socket(AF_INET, SOCK_DGRAM, 0);

    // err check
    if (sock_ < 0) {
      std::cout << "[CreateSocket] socket failed" << std::endl;
      perror("CreateSocket");
    }
  }

public:
  Udp() {
    int err = WSAStartup(MAKEWORD(2, 0), &wsa_data_);
    assert(err == 0);
    createSocket();
  }

  ~Udp() {
    WSACleanup();
    closesocket(sock_);
  }

  void initAddr(u_short port, const std::string& ip) {
    port_ = port;
    ip_ = ip;

    bool is_host = ip_.size() <= 0;

    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port_);
    addr_.sin_addr.S_un.S_addr
      = is_host
      ? INADDR_ANY
      : inet_addr(ip_.c_str());

    // named the socket(bind)
    if (is_host) {
      int res = bind(sock_, (sockaddr*)&addr_, sizeof(addr_));
      if (res < 0) {
        std::cout << "err bind" << std::endl;
      }
    }
  }

  std::vector<char> recieve() {
    std::vector<char> data(1024, NULL);
    int nrecv = recv(sock_, &data[0], sizeof(data), 0);

    data.resize(nrecv);

    // err check
    if (nrecv <= 0) {
      std::cout << "[Recv] Recv Failed:" << nrecv << std::endl;
      perror("Recv");
    }

    return std::move(data);
  }

  void send(const std::vector<char>& data) {
    int nwrite = sendto(sock_, &data[0], (int)data.size(), 0, (sockaddr*)&addr_, sizeof(addr_));

    // err check
    if (nwrite <= 0) {
      std::cout << "[SendTo] SendTo Failed:" << nwrite << std::endl;
      perror("SendTo");
    }
  }
};