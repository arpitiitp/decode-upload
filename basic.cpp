#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimum(vector<int> v, int i, int j)
  {
    int min = v[i], index;
    for (int k = i; k <= j; k++)
    {
      if (v[k] < min)
      {
        min = v[k];
        index = k;
      }
    }

    return index;
  }
  void sort(vector<int> &v, int i, int j)
  {
    for (int k = i; k < j; k++)
    {
      for (int l = k + 1; l <= j; l++)
      {
        if (v[k] > v[l])
        {
          int temp = v[k];
          v[k] = v[l];
          v[l] = temp;
        }
      }
    }
  }
  void nextPermutation(vector<int> &v)
  {
    int n = v.size();
    bool flag = true;
    int c = 0;
    for (int i = n - 1; i > 0; i--)
    {
      if ((i - 1) == 0 && v[i - 1] < v[i])
      {
        int index = minimum(v, 2, n - 1);
        int temp = v[i - 1];
        v[i - 1] = v[index];
        v[index] = temp;
        c = i;
        flag = false;
        break;
      }
      if (v[i - 1] < v[i])
      {
        int temp = v[i - 1];
        v[i - 1] = v[i];
        v[i] = temp;
        flag = false;
        c = i;
        break;
      }
    }

    if (c < (n - 1) && flag == false)
    {
      sort(v, c, n - 1);
    }
    if (flag)
    {
      for (int i = 0, j = n - 1; i < j; i++, j--)
      {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
    for (int i = 0; i < v.size(); i++)
    {
      cout << v[i] << " ";
    }
  }
};

int main()
{
  vector<int> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }

  class Solution s1;
  s1.nextPermutation(v);
  return 0;
}