#ifndef enigma_h
#define enigma_h

#include <string>
#include <vector>

class Enigma {
private:
  // 4 rotors, 26 positions each
  std::vector<std::vector<char>> rotors_;
  int numberOfRotors = 4;
  int numberOfChar = 26;
  int asciiOffset = 97;

  // 20 connections, 10 plugs
  std::vector<std::pair<char, char>> plugs_;
  int numberOfPlugs = 10;

  // for storing the message
  std::string text_;

public:
  // initialize neccessary components
  void create_rotors() {
    for (int i = 0; i < numberOfRotors; i++) {
      std::vector<char> rotor;
      for (int j = 0 + asciiOffset; j < 26 + asciiOffset; j++) {
        rotor.emplace_back(j);
      }
      rotors_.emplace_back(rotor);
    }
  }

  void create_plugs() {
    for (int i = 0; i < numberOfPlugs - 1; i++) {
      plugs_.emplace_back(i + asciiOffset, i + 1 + asciiOffset);
    }
  }

  // get components' setup
  std::vector<std::vector<char>> get_rotors() { return rotors_; }
  std::vector<std::pair<char, char>> get_plugs() { return plugs_; }

  // adjust components
  void set_rotors();
  void set_plugs();
  void reflector();
  void stepping_mechanism();
};

#endif
