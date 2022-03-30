//
// Created by Damir on 3/16/2022.
//

#include <iostream>
#include <iomanip>
#include "Node.h"

Node::Node(float frequency, char character, const std::string& code) {
  _frequency = frequency;
  _character = character;
  _code = code;
}

Node::Node() {
  _frequency = 0;
  _character = '\0';
  _code = "";
}

Node::~Node() = default;


float Node::getFrequency() const {
  return _frequency;
}


void Node::setFrequency(float frequency) {
  Node::_frequency = frequency;
}

char Node::getCharacter() const {
  return _character;
}

void Node::setCharacter(char character) {
  Node::_character = character;
}

const std::string &Node::getCode() const {
  return _code;
}

void Node::setCode(const std::string &code)  {
  Node::_code = code;
}

ostream &operator<<(ostream &os, const Node &node) {
  string out;
  out.push_back(node._character);
  out = Node::specialCharToNotation(out);
  os << left << setprecision(3) << fixed;
  os << setw(2) << Node::specialCharToNotation(out) << " "
     << node._frequency << " "
     << node._code << endl;
  return os;
}

void Node::ReplaceAll(string &str, const string &from, const string &to) {
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }
}

string Node::specialCharToNotation(string ch) {
  // checking if last char is whitespace, if so assigning different value to our string
  // let's use sp instead whitespace, because 2 chars looks better than the whole word
  if (ch.at(ch.length()-1) == ' ') {
    ch.pop_back();
    ch += "sp";
  }
  // nl is for
  // newline
  ReplaceAll(ch, "\r", "nl");
  ReplaceAll(ch, "\n", "nl");
  // ht is for   horizontal tab
  ReplaceAll(ch, "\t", "ht");
  // vt is for
  //           vertical tab
  ReplaceAll(ch, "\v", "vt");

  return ch;
}

char Node::notationToSpecialChar(const string &ch)  {
  if(ch == "sp")
    return ' ';
  if(ch == "nl")
    return '\n';
  if(ch == "ht")
    return '\t';
  if(ch == "vt")
    return '\v';
  return ch[0];
}