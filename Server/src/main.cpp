
#include <iostream>
#include "Udp/udp.hpp"


int main() {
  Udp udp;
  udp.init(12345, "192.168.10.179");
  udp << "hoge";
}
