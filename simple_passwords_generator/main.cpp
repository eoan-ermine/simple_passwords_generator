#include <iostream>
#include <random>
#include <span>
#include <string>
#include <string_view>

class PassGen {
public:
  PassGen() : r_device(), gen(r_device()) {}

  std::string generate(std::string_view ident) {
    std::string res;
    res.push_back(getRandomFromSet(uppers));
    res.push_back(getRandomFromSet(uppers));
    res.push_back(((ident.size() * ident.size()) % 10) + '0');
    res.push_back(getRandomFromSet(digits));
    res.push_back(getRandomFromSet(symbols));
    res.push_back(getRandomFromSet(lowers));
    return res;
  }

private:
  static std::vector<char> genSetFromRange(char from, char to) {
    std::vector<char> res;
    for (char c = from; c != to; ++c)
      res.push_back(c);
    return res;
  }

  const std::vector<char> uppers = genSetFromRange('A', 'Z');
  const std::vector<char> lowers = genSetFromRange('a', 'z');
  const std::vector<char> digits = genSetFromRange('0', '9');
  const std::vector<char> symbols = {'!', '"',  '#', '$', '%',
                                     '&', '\'', '(', ')', '*'};

  char getRandomFromSet(std::span<const char> set) {
    std::uniform_int_distribution<int> dist(0, set.size() - 1);
    return set[dist(gen)];
  }

  std::random_device r_device;
  std::mt19937 gen;
};

int main() {
  PassGen passGen;

  std::string ident;
  std::cin >> ident;
  std::cout << passGen.generate(ident) << '\n';
}