//
// Created by Damir on 3/30/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT2_SHANNONFANODECODER_H
#define TI_ASSIGNMENT2_SHANNONFANODECODER_H

#include <string>
#include <vector>
#include "../NodesLoader/Node.h"

using namespace std;

class ShannonFanoDecoder {
public:
  explicit ShannonFanoDecoder(const string& encodedText);
  ~ShannonFanoDecoder();
  string decode(const vector<Node*> &characters);

private:
  string _encodedText;
  static void ReplaceAll(string &str, const string &from, const string &to);
};


#endif //TI_ASSIGNMENT2_SHANNONFANODECODER_H
