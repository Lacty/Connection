
#include "udp.hpp"


Udp::Udp() {
#if _WINDOWS
  int err = WSAStartup(MAKEWORD(2, 0), &wsa_data_);
  assert(err == 0);
#endif
}

Udp::~Udp() {
#if _WINDOWS
  WSACleanup();
  closesocket(sock_);
#else
  close(sock_);
#endif
}


void Udp::createSocket() {
  sock_ = socket(AF_INET, SOCK_DGRAM, 0);

  // err check
  if (sock_ < 0) {
    std::cout << "[CreateSocket] socket failed" << std::endl;
    perror("CreateSocket");
  }
}

void Udp::initAddr(u_short port, const std::string& ip) {
  createSocket();

  port_ = port;
  ip_ = ip;

  bool is_host = ip_.empty();

  addr_.sin_family = AF_INET;
  addr_.sin_port = htons(port_);
  
  addr_.sin_addr.s_addr
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


std::string Udp::recieve() {
  std::string data;
  data.clear();

  char buf[BUF_SIZE + 1];

  int nrecv = recv(sock_, buf, BUF_SIZE, 0);

  data = buf;
  data.resize(nrecv);

  // err check
  if (nrecv <= 0) {
    std::cout << "[Recv] Recv Failed:" << nrecv << std::endl;
    perror("Recv");
  }

  return std::move(data);
}

void Udp::send(const std::string& data) {
  int nwrite = sendto(sock_, data.c_str(), data.length(), 0, (sockaddr*)&addr_, sizeof(addr_));
  //std::cout << nwrite << std::endl;
  // err check
  if (nwrite <= 0) {
    std::cout << "[SendTo] SendTo Failed:" << nwrite << std::endl;
    perror("SendTo");
  }
}