#include <fstream>
#include <iostream>
#include <string>

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

      std::cout << s << std::endl;
      int dis = std::stoi(s.substr(1));

      if (s[0] == 'R') {
        rot = rot + dis;
      } else {
        rot = rot - dis;
      }

      std::cout << "Raw Rotation: " << rot << std::endl;

      rot = ((rot % POSITIONS) + POSITIONS) % POSITIONS;

      std::cout << "Final Rotation: " << rot << std::endl;

      if (rot == 0)
        pass++;
    }
    rfile.close();
    return pass;
  }
  return 0;
}

int main() {
  int pass;
  pass = partOne();
  std::cout << pass << std::endl;
}
