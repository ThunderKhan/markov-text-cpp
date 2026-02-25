#include <markov/tokenizer.hpp>

#include <sstream>
#include <vector>

namespace markov {
  std::vector<Token> tokenize (const std::string& text) {
    std::vector<Token> tokens;

    std::istringstream iss(text);
    Token token;

    while (iss >> token) {
      tokens.push_back(token);
    }

    return tokens;
  }
}
