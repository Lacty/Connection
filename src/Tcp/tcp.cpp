
#include "tcp.hpp"
#include <assert.h>


Tcp::Tcp() {
#if defined(WIN32) || defined(_WINDOWS)
  if (WSAStartup(MAKEWORD(2, 0), &wsa_)) assert(!"WSAStartup failed");
  // reset sock var
  sock_ = 0;
#else
  // reset sock var
  sock_ = 0;
  // clean addr array
  memset(&addr_, 0, sizeof(addr_));
#endif
}

Tcp::~Tcp() {
  if (is_valid()) {
    closeSock(sock_);
  }
}


/*
  server func
*/

bool Tcp::create() {
  // init sock
  sock_ = socket(AF_INET, SOCK_STREAM, 0);
  
  // report err if faild
  if (!is_valid()) {
    assert(!"Socket::create() err");
    return false;
  }
  
  return true;
}

bool Tcp::bind(const int port) {
  if (!is_valid()) {
    std::cout << "plz init sock";
    return false;
  }
  
  addr_.sin_family      = AF_INET;
  addr_.sin_port        = htons(port);
  addr_.sin_addr.s_addr = INADDR_ANY;
  
  // report err is can not bind sock
  if (-1 == ::bind(sock_, (sockaddr*)&addr_, sizeof(addr_))) {
    assert(!"Socket::bin() err");
    closeSock(sock_);
    return false;
  }
  
  return true;
}

bool Tcp::listen() {
  if (!is_valid()) {
    return false;
  }
  
  // report err if can not listen on sock
  if (-1 == ::listen(sock_, LISTEN_NUM)) {
    assert(!"Socket::listen() err");
    closeSock(sock_);
    return false;
  }
  
  return true;
}

bool Tcp::accept(Tcp& connect) {
  connect.sock_ = ::accept(sock_, 0, 0);
  
  // report err if accept is failed
  if (0 > connect.sock_) {
    assert(!"Socket::accept() err");
    closeSock(connect.sock_);
    return false;
  }
  
  return true;
}


/*
  client func
*/

bool Tcp::connect(const std::string &address, const int port) {
  sock_ = ::socket(AF_INET, SOCK_STREAM, 0);
  
  // report err if failed
  if(!is_valid())
  {
    perror("Socket::socket() err");
    return false;
  }
  
  addr_.sin_family      = AF_INET;
  addr_.sin_port        = htons(port);
  addr_.sin_addr.s_addr = inet_addr(address.c_str());
  
  // try to connect throught sock
  if (-1 == ::connect(sock_, (sockaddr*)&addr_, sizeof(addr_))) {
    assert(!"Socket::connect() err");
    closeSock(sock_);
    return false;
  }
  
  return true;
}


/*
  data transmission
*/

bool Tcp::recv(std::string &data) {
  if (!is_valid()) {
    return false;
  }

  int result;
  
  // clear data
  data.clear();
  
  // create buffer char table
  char buf[BUFFER_SIZE + 1];
  
  result = (int)::recv(sock_, buf, BUFFER_SIZE, 0);
  
  if (result < 0) {
    std::cout << "Socket::recv() ::recv() failed" << std::endl;
    return false;
  }
  
  // copy buf to data
  data = buf;

  if ((int)data.size() <= 0) {
    std::cout << "Socket::recv() no data" << std::endl;
    data.clear();
    return false;
  }

  data.resize(result);
  
  return true;
}

bool Tcp::send(const std::string &data) {
  if (!is_valid()) {
    return false;
  }
  
  int result;
  
  result = (int)::send(sock_, data.c_str(), data.length(), 0);
  
  if (result == -1) {
    std::cout << "Socket::send() ::send() failed" << std::endl;
    return false;
  }
  
  return true;
}


// recv data
// return std::string
std::string Tcp::recv() {
  std::string data;
  recv(data);
  return std::move(data);
}


// check if sock is valid
bool Tcp::is_valid() {
  return sock_ != -1;
}


/*
  operators
*/

// recv data
void Tcp::operator >> (std::string &data) {
  recv(data);
}

// send data
void Tcp::operator << (const std::string &data) {
  send(data);
}