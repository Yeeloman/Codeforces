#include <iostream>
#include <vector>

bool includes(std::vector<int> interval_x, std::vector<int> interval_y) {
  return interval_x[0] >= interval_y[0] && interval_x[1] <= interval_y[1];
}

int main() {
  int test_num, a, b, c, d;
  std::vector<int> interval_y, interval_x, resp;
  std::cin >> test_num;

  for (int i = 0; i < test_num; i++) {
    int drs_to_lck = 0;
    std::cin >> a >> b;
    interval_x.push_back(a);
    interval_x.push_back(b);
    std::cin >> c >> d;
    interval_y.push_back(c);
    interval_y.push_back(d);

    if (includes(interval_x, interval_y)) {
      if (interval_x[0] == interval_y[0] && interval_x[1] == interval_y[1]) {
        drs_to_lck = interval_x[1] - interval_x[0];
      } else if (interval_x[0] == interval_y[0] ||
                 interval_x[1] == interval_y[1]) {
        drs_to_lck = interval_x[1] - interval_x[0] + 1;
      } else {
        drs_to_lck = interval_x[1] - interval_x[0] + 2;
      }
    } else if (includes(interval_y, interval_x)) {
      if (interval_y[0] == interval_x[0] && interval_y[1] == interval_x[1]) {
        drs_to_lck = interval_y[1] - interval_y[0];
      } else if (interval_y[0] == interval_x[0] ||
                 interval_y[1] == interval_x[1]) {
        drs_to_lck = interval_y[1] - interval_y[0] + 1;
      } else {
        drs_to_lck = interval_y[1] - interval_y[0] + 2;
      }
    } else {
      if (interval_x[0] < interval_y[0] && interval_x[1] > interval_y[1]) {
        drs_to_lck = interval_x[1] - interval_x[0] + 2;
      } else {
        drs_to_lck = interval_y[1] - interval_y[0] + 2;
      }
    }

    resp.push_back(drs_to_lck);
  }

  for (auto i : resp) {
    std::cout << i << "\n";
  }

  return 0;
}
