#include <iostream>
#include <vector>

bool includes(std::vector<int> interval_x, std::vector<int> interval_y) {
  /*std::cout << "Checking if Interval [" << interval_x[0] << ", "*/
  /*          << interval_x[1] << "] includes Interval [" << interval_y[0] << ", "*/
  /*          << interval_y[1] << "]\n";*/
  bool result = interval_x[0] <= interval_y[0] && interval_x[1] >= interval_y[1];
  /*std::cout << "Result of includes check: " << result << "\n";*/
  return result;
}

bool intersect(std::vector<int> interval_x, std::vector<int> interval_y) {
  /*std::cout << "Checking if Interval [" << interval_x[0]*/
  /*          << ", " << interval_x[1] << "] intersects with Interval [" << interval_y[0] << ", "*/
  /*          << interval_y[1] << "]\n";*/
  bool result = std::max(interval_x[0], interval_y[0]) <=
                std::min(interval_x[1], interval_y[1]);
  /*std::cout << "Result of intersection check: " << result << "\n";*/
  return result;
}

int main() {
  int test_num, a, b, c, d;
  std::vector<int> interval_y, interval_x, resp;
  std::cin >> test_num;

  /*std::cout << "Test cases: " << test_num << "\n";*/

  for (int i = 0; i < test_num; i++) {
    int drs_to_lck = 0;
    std::cin >> a >> b;
    interval_x.push_back(a);
    interval_x.push_back(b);
    std::cin >> c >> d;
    interval_y.push_back(c);
    interval_y.push_back(d);

    /*std::cout << "\nTest " << i + 1 << ": Interval X = [" << interval_x[0] << ", "*/
    /*          << interval_x[1] << "], Interval Y = [" << interval_y[0] << ", "*/
    /*          << interval_y[1] << "]\n";*/
    /**/
    if (includes(interval_x, interval_y)) {
      /*std::cout << "Entered 'includes' check: Interval X includes Interval Y\n";*/
      if (interval_x[0] == interval_y[0] && interval_x[1] == interval_y[1]) {
        /*std::cout << "Intervals are exactly the same. Result: " << interval_x[1] - interval_x[0] << "\n";*/
        drs_to_lck = interval_x[1] - interval_x[0];
      } else if (interval_x[0] == interval_y[0] || interval_x[1] == interval_y[1]) {
        /*std::cout << "One boundary is the same for both intervals. Result: " << interval_x[1] - interval_x[0] + 1 << "\n";*/
        drs_to_lck = interval_y[1] - interval_y[0] + 1;
      } else {
        /*std::cout << "Interval X contains Interval Y. Result: " << interval_x[1] - interval_x[0] + 2 << "\n";*/
        drs_to_lck = interval_y[1] - interval_y[0] + 2;
      }
    } else if (includes(interval_y, interval_x)) {
      /*std::cout << "Entered 'includes' check: Interval Y includes Interval X\n";*/
      if (interval_y[0] == interval_x[0] && interval_y[1] == interval_x[1]) {
        /*std::cout << "Intervals are exactly the same. Result: " << interval_y[1] - interval_y[0] << "\n";*/
        drs_to_lck = interval_y[1] - interval_y[0];
      } else if (interval_y[0] == interval_x[0] || interval_y[1] == interval_x[1]) {
        /*std::cout << "One boundary is the same for both intervals. Result: " << interval_y[1] - interval_y[0] + 1 << "\n";*/
        drs_to_lck = interval_x[1] - interval_x[0] + 1;
      } else {
        /*std::cout << "Interval Y contains Interval X. Result: " << interval_y[1] - interval_y[0] + 2 << "\n";*/
        drs_to_lck = interval_x[1] - interval_x[0] + 2;
      }
    } else if (intersect(interval_x, interval_y)) {
      /*std::cout << "Entered 'intersect' check: Intervals intersect, but neither includes the other\n";*/
      drs_to_lck = std::min(interval_x[1], interval_y[1]) - std::max(interval_x[0], interval_y[0]) + 2;
    } else {
      /*std::cout << "Entered 'else' block: Intervals do not intersect or include each other\n";*/
        drs_to_lck = 1;
    }

    /*std::cout << "Result for test " << i + 1 << ": " << drs_to_lck << "\n";*/
    resp.push_back(drs_to_lck);
    interval_x.clear(); // Clear the vectors for the next test case
    interval_y.clear();
  }

  /*std::cout << "\nFinal Results:\n";*/
  for (auto i : resp) {
    std::cout << i << "\n";
  }

  return 0;
}

