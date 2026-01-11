#include <fstream>
#include <iostream>
#include <string>

int partOne() {
  std::string s;
  std::ifstream rfile;

  int dir = -1;
  int rot = 50;
  int pass = 0;

  rfile.open("./code.txt");
  // rfile.open("./test.txt");

  if (rfile.is_open()) {
    while (std::getline(rfile, s)) {

      std::cout << s << std::endl;
      int dis = std::stoi(s.substr(1));

      if (!s.empty() && s[0] == 'R') {
        dir = 0;
        rot = rot + dis;
      } else if (!s.empty() && s[0] == 'L') {
        dir = 1;
        rot = rot - dis;
      }

      std::cout << "Raw Rotation: " << rot << std::endl;

      rot = ((rot % 100) + 100) % 100;

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
