//
// Created by Damir on 3/29/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_FILEREADER_H
#define TI_ASSIGNMENT_1_FILEREADER_H

#include <string>
#include <fstream>

using namespace std;

class FileReader {
public:
  explicit FileReader(const string& fileName);
  ~FileReader();

  string getText();
  void close();
private:
  ifstream _file;
};


#endif //TI_ASSIGNMENT_1_FILEREADER_H
