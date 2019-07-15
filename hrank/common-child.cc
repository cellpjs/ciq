#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  int** ccMemo = new int*[len1+1];
  for(int i = 0; i < len1+1; i++) {
    ccMemo[i] = new int[len2+1];
  }

  for (int i=1; i<len1+1; i++) {
    for (int j=1; j<len2+1; j++) {
      if (s1[i-1] == s2[j-1]){
        ccMemo[i][j] = 1 + ccMemo[i-1][j-1];
      } 
      else {
        ccMemo[i][j] = max(ccMemo[i-1][j], ccMemo[i][j-1]);
      }
    }
  }
  int result = ccMemo[len1][len2];
  for(int i = 0; i < len1+1; i++) {
    delete [] ccMemo[i];
  }
  delete [] ccMemo;
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}


