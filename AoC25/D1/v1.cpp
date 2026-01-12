#include <fstream>
#include <iostream>
#include <string>

int getPasswod() {
  std::string line;
  std::ifstream rfile;
  int rot = 50;
  int pass = 0;

  rfile.open("./code.txt");
  if (rfile.is_open()) {
    while (std::getline(rfile, line)) {

      std::cout << line << std::endl;

      // std::cout << rot << std::endl;

      if (!line.empty() && line[0] == 'R') {
        int dis = std::stoi(line.substr(1));

        for (int i = 0; i < dis; i++) {
          rot++;
          if (rot == 100)
            rot = 0;
          if (rot == -1)
            rot = 99;
        }

        std::cout << "Rotation = " << rot << std::endl;

      } else if (!line.empty() && line[0] == 'L') {
        int dis = std::stoi(line.substr(1));

        for (int i = 0; i < dis; i++) {
          rot--;
          if (rot == 100)
            rot = 0;
          if (rot == -1)
            rot = 99;
        }

        std::cout << "Rotation = " << rot << std::endl;
      }

      if (rot == 0)
        pass++;
    }
    rfile.close();
    return pass;
  }
  return 0;
}

int main() {

  // loadCodeToStack(&codeStack);
  int pass = getPasswod();
  std::cout << pass << std::endl;
}
