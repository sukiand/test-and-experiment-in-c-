#include <iostream>
#include <vector>
#include <malloc.h>

//#define LEN(arr) (sizeof(arr) / sizeof(typeof((arr)[0])))

using namespace std;

int main(int argc, char const* argv[])
{
  //int a1[] = {1, 3, 5, 7, 9};
  //int a2[] = {2, 4, 6, 8, 10};

  vector<int> v1 = {1,3,5,7,9};
  vector<int> v2 = {2,4,6,8,10};

  vector<int> result;

  vector<int>::iterator it1 = v1.begin();
  vector<int>::iterator it2 = v2.begin();

  while (it1 != v1.end() && it2 != v2.end()) {
    if (*it1 < *it2) {
      result.push_back(*it1);
      ++it1;
    } else {
      result.push_back(*it2);
      ++it2;
    }
  }

  while (it1 != v1.end()) {
    result.push_back(*it1);
    ++it1;
  }

  while (it2 != v2.end()) {
    result.push_back(*it2);
    ++it2;
  }

  for (it1 = result.begin(); it1 != result.end(); ++it1) {
    cout << *it1 << " ";
  }
  cout << endl;
  getchar();
  return 0;
}

