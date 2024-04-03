#include "enigma.h"
#include <iostream>

int main() {
  Enigma enigma;

  enigma.create_rotors();

  for (auto &r : enigma.get_rotors()) {
    for (auto &ch : r) {
      std::cout << ch;
    }
  }

  return 0;
}
