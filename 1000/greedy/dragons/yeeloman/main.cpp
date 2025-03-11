#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;
int main() {
  int player_dmg, nb_loops;
  matrix_t dragons;

  std::cin >> player_dmg >> nb_loops;

  for (int i = 0; i < nb_loops; i++) {
    int dragon_dmg, defeat_bonus;

    std::cin >> dragon_dmg >> defeat_bonus;
    dragons.push_back(std::vector<int>{dragon_dmg, defeat_bonus});
  }
  return 0;
}
