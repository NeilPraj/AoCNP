#include <fstream>
#include <iostream>
#include <string>

// #define DEBUG

void debugPrint(const std::string &message) {
#ifdef DEBUG
  std::cout << message << std::endl;
#endif
}

const int POSITIONS = 100;
const int START_POS = 50;

int partOne() {
  std::string s;
  std::ifstream rfile;

  int rot = START_POS;
  int pass = 0;

  rfile.open("./code.txt");
  // rfile.open("./test.txt");

  if (rfile.is_open()) {
    while (std::getline(rfile, s)) {
      if (s.empty())
        return 0;

      // debugPrint(s);
      int dis = std::stoi(s.substr(1));

      if (s[0] == 'R') {
        rot = rot + dis;
      } else {
        rot = rot - dis;
      }

      // debugPrint("Raw rotation: " + std::to_string(rot));

      rot = ((rot % POSITIONS) + POSITIONS) % POSITIONS;

      // debugPrint("Scaled rotation: " + std::to_string(rot));

      if (rot == 0)
        pass++;
    }
    rfile.close();
    return pass;
  }
  return 0;
}

int partTwo() {
  std::string s;
  std::ifstream rfile;

  int rot = START_POS;
  int pass = 0;

  rfile.open("./code.txt");
  // rfile.open("./test.txt");

  if (rfile.is_open()) {
    while (std::getline(rfile, s)) {
      if (s.empty())
        return 0;
      debugPrint(s);
      int dis = std::stoi(s.substr(1));

      if (s[0] == 'R') {
        for (int i = 0; i < dis; i++) {
          rot++;
          if (rot == 100)
            rot = 0;
          if (rot == 0)
            pass++;
          debugPrint("R increment: " + std::to_string(rot));
        }
      } else {
        for (int i = 0; i < dis; i++) {
          rot--;
          if (rot == -1)
            rot = 99;
          if (rot == 0)
            pass++;
          debugPrint("L decrement: " + std::to_string(rot));
        }
      }
    }
    rfile.close();
    return pass;
  }

  return 0;
}

int main() {
  int pass;
  pass = partOne();
  std::cout << "Part 1: " << pass << std::endl;
  pass = partTwo();
  std::cout << "Part 2: " << pass << std::endl;
}
