
#include <iostream>
#include "Udp/udp.hpp"


int main() {
  Udp recv;
  recv.init(12345);

  Udp send;
  send.init(54321, "127.0.0.1");

  while (true) {
    std::string data(recv.recv());
    send << data;
  }
}
