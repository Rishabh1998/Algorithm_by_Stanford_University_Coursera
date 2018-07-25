// Author : Nishant Panwar
#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";

    vector<int> result(n1 + n2, 0);

    int x = 0;
    int y = 0;

    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        y = 0;
        for (int j=n2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[x + y] + carry;

            carry = sum/10;

            result[x + y] = sum % 10;

            y++;
        }

        if (carry > 0)
            result[x + y] += carry;

        x++;
    }

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;

    if (i == -1)
       return "0";

    string s = "";
    while (i >= 0)
        s = s + to_string(result[i--]);

    return s;
}

int main()
{
    string str1 ;
    string str2 ;
    cin>>str1;
    cin>>str2;
    cout << multiply(str1, str2);
    return 0;
}

