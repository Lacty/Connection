
#include "udp.hpp"


Udp::Udp() {
#if defined(WIN32) || defined(_WINDOWS)
  if (WSAStartup(MAKEWORD(2, 0), &wsa_)) assert(!"error: WSAStart");
  // reset sock var
  sock_ = 0;
  // clean addr array
  memset(&addr_, 0, sizeof(addr_));
#else
  // reset sock var
  sock_ = 0;
  // clean addr array
  memset(&addr_, 0, sizeof(addr_));
#endif
}

Udp::~Udp() {
  closeSock();
  WSACleanup();
}


void Udp::createSock() {
  closeSock();

  sock_ = ::socket(AF_INET, SOCK_DGRAM, 0);
  assert(sock_ != 0);
}

void Udp::closeSock() {
#if defined(WIN32) || defined(_WINDOWS)
  closesocket(sock_);
#else
  close(sock_);
#endif
}


void Udp::init(const int port, const std::string& ip) {
  createSock();

  addr_.sin_family = AF_INET;
  addr_.sin_port = htons(port);
  addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}

void Udp::init(const int port) {
  createSock();

  addr_.sin_family = AF_INET;
  addr_.sin_port = htons(port);
  addr_.sin_addr.s_addr = INADDR_ANY;

  int res = ::bind(sock_, (sockaddr*)&addr_, sizeof(addr_));

  // err check if Bind Failed
  assert(res == 0);
}


void Udp::recv(std::string& data) {
  char buf[BUF_SIZE + 1];
  memset(buf, 0, sizeof(buf));

  int nrecv = ::recv(sock_, buf, BUF_SIZE, 0);

  std::cout << buf << " : " << nrecv << std::endl;

  data = buf;
  data.resize(nrecv);

  // err check if Recv Failed
  assert (nrecv != 0);
}

void Udp::send(const std::string& data) {
  int nwrite = ::sendto(sock_, data.c_str(), data.length(), 0, (sockaddr*)&addr_, sizeof(addr_));

  // err check if Sendto Failed
  assert(nwrite != 0);
}

std::string Udp::recv() {
  std::string data;
  this->recv(data);
  return std::move(data);
}

// operators
void Udp::operator >> (std::string& data) {
  recv(data);
}

void Udp::operator << (const std::string& data) {
  send(std::move(data));
}