#ifndef enigma_h
#define enigma_h

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Enigma {
private:
  int asciiOffset = 97;

  // 4 rotors, 26 positions each
  std::vector<std::vector<char>> rotors_;
  int numberOfRotors = 4;
  int numberOfChar = 26;
  int rotorPosition;

  // 20 connections, 10 plugs
  std::vector<std::pair<char, char>> plugs_;
  int numberOfPlugs = 10;
  std::vector<char> matchedChar;

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
  // rotors
  void set_rotors(int rot = 0) {
    if (rot != 0) {
      rotorPosition = rot;
    } else {
      int offset;
      std::cout << "set rotor offset -> ";
      std::cin >> offset;
      set_rotors(offset);
    }
  }

  // plugs
  int random_pair_for_plugs() {
    timespec ts;
    for (int i = 0; i < 10; i++) {
      srand(ts.tv_nsec);
      int randNum = rand() % 26;
      char ch1 = randNum + asciiOffset;
      while (std::find(matchedChar.begin(), matchedChar.end(), ch1) !=
             matchedChar.end()) {
        // test
      }
      matchedChar.emplace_back(ch1);
      int randNum2 = rand() % 26;
      char ch2 = randNum2 + asciiOffset;
      matchedChar.emplace_back(ch2);
    }
  }

  void set_plugs() {
    std::string opt;
    std::cout << "manual | semi-automatic | automatic -> ";
    std::cin >> opt;
    switch (opt[0]) {
    case 'm':
      // manual
      break;
    case 's':
      // semi auto
      break;
    case 'a':
      // auto
      break;
    }
  }

  // automatic adjustments
  void advance_rotor() { // stepping mechanism
    set_rotors(1);
  }

  void reflector();
};

#endif
