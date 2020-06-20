#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
  srand(time(NULL));

  ifstream infile("test.txt");

  string tab[50][2];

  bool pytanie, odpowiedz;

  int licznik = 0, r;

  pytanie = 1;

  std::string line;
  while (getline(infile, line)) {
    if (!line.empty()) {
      if (pytanie) {
          tab[licznik][0] += "\x1b[1m" + line + "\x1b[0m";
          tab[licznik][0] += "\n";
      }

      else if (!pytanie) {
        tab[licznik][1] += "\x1b[36m" + line + "\x1b[0m";
        tab[licznik][1] += "\n";
    	}
    }
    else if(line.empty()) {
    	pytanie = !pytanie;

    	if(pytanie){
          licznik++;
        }
    }
  }

  while (1) {
    r = rand() % (licznik + 1);

    cin.ignore();
    cout << tab[r][0] << endl;

    cin.ignore();
    cout << tab[r][1];

    cin.ignore();
    system("clear");
  }

  return 0;
}