//
// Created by Damir on 3/29/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_NODESSAVER_H
#define TI_ASSIGNMENT_1_NODESSAVER_H


#include <vector>
#include <fstream>
#include <ranges>
#include <sstream>
#include "Node.h"

using namespace std;

class NodesLoader {
public:
  static inline void LoadNodesFromFile(vector<Node*>& characters, const string& fileName) {
    ifstream file(fileName);
    string line;

    while (getline(file, line)) {
      vector<string> data = split(line);
      char ch = Node::notationToSpecialChar(data[0]);
      float frequency = stof(data[1]);
      string code = data[2];

      characters.push_back(new Node(frequency, ch, code));
    }

    file.close();
  }
private:
  static inline vector<string> split(string x, char delim = ' ') {
    //includes a delimiter at the end so last word is also read
    x += delim;
    vector<string> splitted;
    string temp = "";
    for (int i = 0; i < x.length(); i++) {
      if (x[i] == delim) {
        //store words in "splitted" vector
        if (!temp.empty())
          splitted.push_back(temp);
        temp = "";
        i++;
      }
      temp += x[i];
    }
    return splitted;
  }
};


#endif //TI_ASSIGNMENT_1_NODESSAVER_H
