#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <random>
using namespace std;

namespace {
static std::mt19937 &random_engine() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return gen;
}

template <typename T> static T rand_int(const T &a, const T &b) {
  std::uniform_int_distribution<T> dis(a, b);
  return dis(random_engine());
}

template <typename Container>
static auto rand_elem(const Container &container) ->
    typename Container::value_type {
  assert(container.size() > 0);
  return container[rand_int(0, (int)container.size() - 1)];
}

static string rand_string(const string &charset, int size) {
  string s(size, '0');
  for (int i = 0; i < size; ++i)
    s[i] = rand_elem(charset);
  return s;
}
} // namespace

int main(int argc, char *argv[]) {
  string arg = argv[2];
  // cout << argc << endl;
  // cout << argv[0] << endl;
  // cout << argv[1] << endl;
  // cout << argv[2] << endl;
  int instance = stoi(arg);
  // cout << instance << endl;
  int n;
  if (instance <= 20) {
    n = 25;
  } else if (instance <= 30) {
    n = 50;
  } else if (instance <= 40) {
    n = 75;
  } else if (instance <= 60) {
    n = 100;
  } else if (instance <= 80) {
    n = 250;
  } else if (instance <= 100) {
    n = 500;
  }


  cout << n << endl;
  for (int i = 0; i < n; i++) {
    int collectionTimeInSeconds = rand_int(60 * 10, 60 * 20);
    int dendeInMililiters = rand_int(5000, 10000);
    cout << collectionTimeInSeconds << " " << dendeInMililiters << endl;
  }

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int distanceMeters = (i == j ? 0 : rand_int(100, 30000));
        int durationSeconds = distanceMeters / 13;
        cout << i << " " << j << " " << distanceMeters << " " << durationSeconds << endl;
      }
  }
}
