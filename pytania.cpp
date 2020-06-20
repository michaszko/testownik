#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  srand(time(NULL));

  ifstream infile("dudycz.txt");

  string tab[55][2];

  bool pytanie, odpowiedz;

  int licznik = 0, r;

  pytanie = 1;

  std::string line;
  while (getline(infile, line)) {
    if (!line.empty()) {
      if (pytanie) { 
        tab[licznik][0] += line;
        tab[licznik][0] += "\n";
      } else if (!pytanie) {
        tab[licznik][1] += line;
        tab[licznik][1] += "\n";
      }
    } else if (line.empty()) {
      pytanie = !pytanie;

      if (pytanie) {
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