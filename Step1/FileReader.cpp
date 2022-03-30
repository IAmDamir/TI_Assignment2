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

int FileReader::getFileSize() {
  // position the pointer to the end
  _file.seekg(0, ios::end);

  return _file.tellg();
}

void FileReader::close() {
  _file.close();
}
