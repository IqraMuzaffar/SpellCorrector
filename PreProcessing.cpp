
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string To_Lower_Case(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        string1[i] = tolower(string1[i]);
    }

    return string1;
}

bool isSuffix(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2)
        return false;
    for (int i = 0; i < n1; i++)
        if (s1[n1 - i - 1] != s2[n2 - i - 1])
            return false;
    return true;
}


string Remove_suffix(string &string1)
{
  if (isSuffix("s", string1) )
    {
        string1 = string1.substr(0, string1.length() - 1);
    }
 
    else if (isSuffix("ing", string1))
    {
        string1 = string1.substr(0, string1.length() - 3);
        string1.append("e");
    }

    else if (isSuffix("ies", string1))
    {
        string1 = string1.substr(0, string1.length() - 3);
        string1.append("y");
    }

   
   else if (isSuffix("ly", string1) || isSuffix("ed", string1) || isSuffix("es", string1))
    {
        string1 = string1.substr(0, string1.length() - 2);
    }
    return string1;

}


int main()
{
    string s1 = "caring";
    cout<<Remove_suffix(s1)<<endl;
    cout<<To_Lower_Case("IQRA");
}