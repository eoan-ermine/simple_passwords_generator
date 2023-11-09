#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include <vector>

class PassGen {
public:
  PassGen() : r_device(), gen(r_device()) {}

  std::string generate(std::string_view ident) {
    static const auto gen = [](char from, char to) {
      std::vector<char> res;
      for (char c = from; c != to; ++c)
        res.push_back(c);
      return res;
    };

    static const std::vector uppers = gen('A', 'Z');
    static const std::vector lowers = gen('a', 'z');
    static const std::vector digits = gen('0', '9');
    static const std::vector symbols = {'!', '"',  '#', '$', '%',
                                        '&', '\'', '(', ')', '*'};

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
  char getRandomFromSet(const std::vector<char> &set) {
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