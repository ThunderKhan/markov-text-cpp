#pragma once

#include <string>
#include <vector>

#include "types.hpp"

namespace markov {
  // Tokenize raw text into sequence of tokens.
  //
  // Rules(simeplified):
  // - split on whitesapces
  // - punctuation is treated as part of the tokens
  // - no lowercasing here

  std::vector<Token> tokenize ( const std::string& text );
}
