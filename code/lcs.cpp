#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lcs_len(string s1, string s2)
{

	 int len1 = s1.size(), len2 = s2.size();
	if (len2 > len1)
	{
		string tmp;
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
    if (len1==0 || len2==0)return 0;
    vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));

    for (int i = 1; i <=len1; i++){
        for (int j = 1; j <=len2; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    }
    return dp[len1][len2];
}

int main()
{
	int n, na, nb;
	string s1, s2, tmps;
	char tmp;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		s1 ="";
		s2 ="";
		cin>>na>>nb;
		for(int j=0; j<na; j++)
		{
			cin>>tmp;
			tmps=tmp;
			s1.append(tmps);
		}

		for(int j=0; j<nb; j++)
		{
			cin>>tmp;
			tmps=tmp;
			s2.append(tmps);
		}
		s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
		s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
		cout<<"Case "<<i+1<<endl;
		cout<<lcs_len(s1, s2)<<endl;
	}
	return 0;
}
