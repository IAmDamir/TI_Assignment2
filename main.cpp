#include <iostream>
#include "NodesLoader/NodesLoader.h"
#include "Step1/FileReader.h"
#include "Step2/ShannonFanoDecoder.h"

using namespace std;

int main() {
  const string inputFile = "../new.txt";
  vector<Node*> characters;
  // Loads nodes from previous assignment
  NodesLoader::LoadNodesFromFile(characters, "../Nodes.txt");

  FileReader fileReader(inputFile);
  string encodedText = fileReader.getText();
  cout << encodedText << endl;
  fileReader.close();

  ShannonFanoDecoder decoder(encodedText);
  string decodedText = decoder.decode(characters);

  cout << decodedText << endl;

  for (auto& node:characters) {
    delete(node);
  }
  return 0;
}
