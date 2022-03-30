//
// Created by Damir on 3/16/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_NODE_H
#define TI_ASSIGNMENT_1_NODE_H

#include <string>

using namespace std;

class Node {
public:
  Node();
  explicit Node(float frequency, char character, const std::string& code = "");
  ~Node();

  float getFrequency() const;
  void setFrequency(float frequency);

  char getCharacter() const;
  void setCharacter(char character);

  const std::string &getCode() const;
  void setCode(const std::string &code);

  static void ReplaceAll(string &str, const string &from, const string &to);
  static string specialCharToNotation(string ch);
  static char notationToSpecialChar(const string& ch);

  friend ostream& operator<<(ostream& os, const Node& node);

private:
  float _frequency;
  char _character;
  std::string _code;
};

#endif //TI_ASSIGNMENT_1_NODE_H
