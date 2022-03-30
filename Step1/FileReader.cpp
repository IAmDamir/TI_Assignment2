//
// Created by Damir on 3/29/2022.
//

#include "FileReader.h"

FileReader::FileReader(const string& fileName) {
  _file.open(fileName);
}

FileReader::~FileReader() {
  _file.close();
}

string FileReader::getText() {
  _file.seekg(ios_base::beg);

  string str((istreambuf_iterator<char>(_file)),
             istreambuf_iterator<char>());

  return str;
}

void FileReader::close() {
  _file.close();
}