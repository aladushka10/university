#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  string name;
  cout << "Cin firm name: " << endl;
  cin >> name;
  int cntBranchesCountries;
  cout << "Cin count of Countries with branches: " << endl;
  cin >> cntBranchesCountries;
  vector <string> branchesCountries(cntBranchesCountries);
  vector < vector <double > > branchQualities(cntBranchesCountries);
  vector < vector <string> > branchNames(cntBranchesCountries);
  vector < vector <string> > u(cntBranchesCountries);
  vector < vector <string> > v(cntBranchesCountries);
  for (int i = 0; i < cntBranchesCountries; i++)
  {
      cout << "Cin country with Branches: " << endl;
      cin >> branchesCountries[i];
      cout << "Cin how many branches in this country: " << endl;
      int n;
      cin >> n;
      branchNames[i].resize(n);
      u.resize(n);
      v.resize(n);
      for (int j = 0; j < n; j++)
      {
          cout << "Cin branch name, u, v" << endl;
          cin >> branchNames[i][j];
          cin >> u[i][j];
          cin >> v[i][j];
          cout << "Cin d: " << endl;
          double d;
          cin >> d;
          if (d < 0.033)
          {
              cout << "AWARD " << branchesCountries[i] << " " << branchNames[i][j] << endl;
          }
          {
              if (d < 0.5)
                  cout << "OBSERVE " << branchesCountries[i] << " " << branchNames[i][j] << endl;
              else
                  if (d < 1.00)
                      cout << "CLOSE " << branchesCountries[i] << " " << branchNames[i][j] << endl;
          }
      }
  }

  return 0;
}