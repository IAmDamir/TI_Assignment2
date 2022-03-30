//
// Created by Damir on 3/30/2022.
//

#include <iostream>
#include "ShannonFanoDecoder.h"

ShannonFanoDecoder::ShannonFanoDecoder(const string& encodedText) {
  _encodedText = encodedText;
}

ShannonFanoDecoder::~ShannonFanoDecoder() = default;

string ShannonFanoDecoder::decode(const vector<Node*> &characters) {
  // encodedCharacter is a sequence of binary digits that could have a code for a char in our Node array
  string encodedCharacter, decodedText;
  //// this int is used only for output, is not required by the algorithm
  // firstNodeWithMatchingCodeidx is the first character that has the same code prefix
  int firstNodeWithMatchingCodeidx;
  for (auto &ch:_encodedText) {
    encodedCharacter.push_back(ch);
    //// is not required by the algorithm
    // duplicates encodedCharacter so that when encodedCharacter is empty we can still output it
    string encodedCharacterForOut = encodedCharacter;
    //// is not required by the algorithm
    // detects if this is the first node that has the same code prefix
    bool isFirstNodeWithMatchingCode = true;
    //// is not required by the algorithm
    // characters with the same code prefix that we need
    string chars;

    for (int i = 0; i < characters.size(); ++i) {
      Node node = *characters[i];
      // isPrefix checks if characters[i] has encodedCharacter as prefix
      //// if you don't want the explanation of how I check it you can skip following comments
      // mismatch returns a pair of iterators to the first non-equal element from each string
      // if no mismatches found then it returns iterator pointing to the end of the string
      // so if mismatch(...).first == firstString.end() then secondString has firstString as prefix
      bool isPrefix = std::mismatch(encodedCharacter.begin(), encodedCharacter.end(),
                                    node.getCode().begin(), node.getCode().end()).first == encodedCharacter.end();
      if (isPrefix) {
        // specialChar will contain character that we decoded
        // if decoded char is special char it will turn it to the notation that we can read
        string specialChar;
        specialChar.push_back(node.getCharacter());
        chars += Node::specialCharToNotation(specialChar) + " ";
        if (isFirstNodeWithMatchingCode) {
          firstNodeWithMatchingCodeidx = i + 1;
        }
        isFirstNodeWithMatchingCode = false;
      }

      if (node.getCode() == encodedCharacter) {
        decodedText.push_back(node.getCharacter());
        encodedCharacter.clear();
        break;
      }
    }

    //// producing output
    // deletes last whitespace
    chars.pop_back();
    // turns all whitespaces into ", " /* not the best solution, I know */
    ReplaceAll(chars, " ", ", ");
    printf("%s: Node%i: (%s) %s\n",
           encodedCharacterForOut.c_str(),
           firstNodeWithMatchingCodeidx,
           encodedCharacterForOut.c_str(),
           chars.c_str());
  }

  return decodedText;
}

void ShannonFanoDecoder::ReplaceAll(string &str, const string &from, const string &to)  {
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }
}