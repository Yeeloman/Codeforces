#include <iostream>
#include <ostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;

void answer(matrix_t matrix, int &hp) {
  for (size_t i = 0; i < matrix.size(); i++) {
    if (matrix[i][0] >= hp) {
      std::cout << "NO" << '\n';
      return;
    } else {
      hp += matrix[i][1];
    }
  }
  std::cout << "YES" << '\n';
}

void merge(matrix_t &matrix, matrix_t &left, matrix_t &right) {
  int i = 0, j = 0, k = 0;

  while (i < left.size() && j < right.size()) {
    if (left[i][0] < right[j][0]) {
      matrix[k++] = left[i++];
    } else {
      matrix[k++] = right[j++];
    }
  }

  while (i < left.size()) {
    matrix[k++] = left[i++];
  }

  while (j < right.size()) {
    matrix[k++] = right[j++];
  }
}

void mergeSort(matrix_t &matrix) {
  int length = matrix.size();
  if (length <= 1) {
    return;
  }
  int middle = length / 2;
  matrix_t left(matrix.begin(), matrix.begin() + middle);
  matrix_t right(matrix.begin() + middle, matrix.end());

  mergeSort(left);
  mergeSort(right);

  merge(matrix, left, right);
}

int main() {
  int hp, nb_loops;
  matrix_t dragons;

  std::cin >> hp >> nb_loops;

  for (int i = 0; i < nb_loops; i++) {
    int dragon_dmg, defeat_bonus;

    std::cin >> dragon_dmg >> defeat_bonus;
    dragons.push_back({dragon_dmg, defeat_bonus});
  }

  mergeSort(dragons);

  answer(dragons, hp);

  return 0;
}

