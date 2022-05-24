#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void To_Lower_Case(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        string1[i] = tolower(string1[i]);
    }

    cout << string1 << endl;
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

void Remove_ing(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        if (isSuffix("ing", string1))
        {
            string1 = string1.substr(0, string1.length() - 3);
        }
    }
    cout << string1 << endl;
}

void Remove_s_d(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        if (isSuffix("s", string1) || isSuffix("es", string1) || isSuffix("ed", string1))
        {
            string1 = string1.substr(0, string1.length() - 1);
        }
    }
    cout << string1 << endl;
}

void Remove_2(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        if (isSuffix("ly", string1) || isSuffix("ed", string1) || isSuffix("es", string1))
        {
            string1 = string1.substr(0, string1.length() - 2);
        }
    }
    cout << string1 << endl;
}

//...do later

void Remove_ing2(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        if (isSuffix("ing", string1))
        {
            string1 = string1.substr(0, string1.length() - 3);
        }
    }
    string1.append("e");
    cout << string1 << endl;
}

void Remove_ies(string string1)
{
    for (int i = 0; i < string1.length(); i++)
    {
        if (isSuffix("ies", string1))
        {
            string1 = string1.substr(0, string1.length() - 3);
        }
    }
    string1.append("y");
    cout << string1 << endl;
}

void Remove_suffix(string string1)
{

    if (isSuffix("ly", string1) || isSuffix("ed", string1) || isSuffix("es", string1))
    {
        string1 = string1.substr(0, string1.length() - 2);
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

    else if (isSuffix("s", string1) )
    {
        string1 = string1.substr(0, string1.length() - 1);
    }
    cout<<string1<<endl;

}


int main()
{
    string s1 = "caring";
    Remove_suffix(s1);
}