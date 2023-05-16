#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  int p = 3, q = 11;
  int n, phi, d, k = 2;
  string m, c;
  int m1[] = {2,1,3,3,4}, c1[5], de[5];
  n = p * q;
  phi = (p - 1) * (q - 1);
  int e = 7; // 1+ (rand() % phi);

  for (d = 1; d < phi; d++)
  {
    if (((d * e) % phi) == 1)
      break;
  }

  cout << "Enter the value to be encrypted" << endl;
  cin >> m;
  cout << endl;
  cout << "h:2,e:1,l:3,o:4" << endl;
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    c1[i] = pow(m1[i], e);
    c1[i] = c1[i] % n;
  }
  cout << "Encrypted message:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << c1[i] << ",";
  }
  cout << endl;
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    de[i] = pow(c1[i], d);
    de[i] = de[i] % n;
  }
  cout << "Decrypted message:" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << de[i] << ",";
  }
  cout << endl;
  cout << endl;
  cout << "Decrypted message:" << endl;
  for (int i = 0; i < 5; i++)
  {
    if (de[i] == 1)
    {
      cout << "e";
    }
    else if (de[i] == 2)
    {
      cout << "h";
    }
    else if (de[i] == 3)
    {
      cout << "l";
    }
    else if (de[i] == 4)
    {
      cout << "o";
    }
  }
  cout << endl;
  cout << endl;
}