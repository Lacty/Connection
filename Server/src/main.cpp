
#include <iostream>
#include "Udp/udp.hpp"


int main() {
  Udp udp;
  udp.init(12345);

  while (true) {
    std::cout << udp.recv() << std::endl;
  }
}
