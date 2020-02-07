#include <iostream>
#include <fstream>
using namespace std;

void saveGame(){
    ofstream outFile;
    outFile.open("sample.txt");
    outFile << "This is a test.";
    outFile.close();
}

/*
int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}

*/
  