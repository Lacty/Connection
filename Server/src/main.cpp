
#include <iostream>
#include "Udp/udp.hpp"


int main() {
  Udp udp;
  udp.init(12345, "127.0.0.1");
  udp << "hoge";
}
