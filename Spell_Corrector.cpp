#include <iostream>
#include <fstream>
#include <cstring>
#include "bst.h"
#include "PreProcessing.h"
#include "Distance.h"
#include <vector>
#include <cstring>
#include "LL.h"
#include <string>

using namespace std;
using namespace ::std;

class Spell_Corrector

{
public:
    node *temp;
    Linklist wordslist;
    ifstream read;
    ifstream read1;
    ifstream readx;
    vector<string> vector1;
    ifstream read3;

    BST St;
    Spell_Corrector(){
        wordlist();
    }

    void Print_BST(BST S)
    {
        S.InorderTraverse(S.root);
    }
    void wordlist()
    {
        string word;

        readx.open("dictionary.txt");
        if (read)
        {
            while (!readx.eof())
            {

                readx >> word;

                wordslist.insertH(word);
            }
        }
    }

    // dictionary loaded into BSt
    void Load_BST(string filename)
    {

        string word;
        read.open(filename);
        if (read)
        {
            while (!read.eof())
            {
                read >> word;
                // cout<<word;

                St.insert(word);
            }
        }

        // St.InorderTraverse(St.root);
    }

    // Reads words from "myfile.txt" &
    // Checks spellings...If correct appends to "CorrectedFile.txt "(compared with dictionary.txt)
    // if not correct: does preprsocessing or give alternate suggestions for the word from the "dictionary.txt
    // In the end appends all correct words to "CorrectedFile.txt"

    string Spell_Checker(string filename)
    {
        string temp;
        string newstring;
        Load_BST("dictionary.txt");
        string word; // users word
        read1.open(filename);
        if (read1)
        {
            while (!read1.eof())
            {
                read1 >> word;

                // cout << word << endl;

                if (St.search(word))
                {
                    temp += " " + word;
                    cout<<"Word found in 1st go"<<endl;
                }
                else
                {
                    // cout<<"word not found!"<<word<<endl;
                    newstring = Spellcorrector(word);
                    // cout << newstring << endl;
                    if (St.search(newstring))
                    {
                        cout << "word found : " << newstring << endl;
                        temp += " " + newstring;
                    }
                    else
                    {
                        cout << "word not found but here are some suggestions for the WORD : " << word << endl;
                        Linklist pp = GenerateList(word);
                        pp.print();
                        cout << "Kindly Select any of these : " << endl;
                        cin >> newstring;
                        temp += " " + newstring;
                        
                    }
                }
            }

            cout << temp << endl;
        }
        else
        {
            cout << "Nah bro nah" << endl;
        }
ofstream Myfile("CorrectedFile.txt");
                        Myfile << temp;
                        Myfile.close(); 

        return temp;
    }

    string Spellcorrector(string word)
    {
        string tempp;
        tempp = To_Lower_Case(word);

        return Remove_suffix(tempp);
    }

    void printVector()
    {

        for (string i : vector1)
            cout << i << ' ';
    }

    // void spellSuggestion(string str1, string filename)

    // {
    //     wordlist();
    //     Linklist *ptr;
    //     ptr = new Linklist;

    //     Linklist ll;

    //     string word;
    //     read3.open(filename);
    //     if (read3)
    //         int count1 = 0;
    //     {
    //         while (!read3.eof())
    //         {   read3 >> word;
    //             if (editDist(str1, word, str1.length(), word.length()) <= 2)
    //             {

    //                 ptr->insertT(word);
    //                 // cout<<word<<" ";
    //             }
    //         }
    //         ptr->print();

    //     }}

    Linklist GenerateList(string str1)
    {

        
        Linklist lls;
        
         temp= wordslist.head;

        while (temp->link != NULL)
        {

            if (editDist( str1,temp->data, temp->data.length(), str1.length()) <= 2)
            {
              // cout<<temp->data<<"->";
                 lls.insertT(temp->data);
               
            }
            temp = temp->link;

        }
        
        return lls;
        
    }

    //        Linklist lls;
    //         string word;
    //         read3.open(filename);
    //         if (read3)
    //             int count1 = 0;
    //         {
    //             while (!read3.eof())
    //             {   read3 >> word;
    //                 if (editDist(str1, word, str1.length(), word.length()) <= 2)
    //                 {

    //                     lls.insertT(word);}}}
    //         return lls;

    //    }
};

int main()
{
    Spell_Corrector Sc;
    Linklist ss, sss;
    // ss = Sc.GenerateList("ba");

    // // Sc.wordlist();
    // // Sc.wordslist.print();
    
    


    // ss.print();
    // cout<<"-----------------------------------------------------------"<<endl;
    // cout<<"-----------------------------------------------------------"<<endl;

    // sss = Sc.GenerateList("the");
    cout << Sc.Spell_Checker("myfile.txt");
    // Sc.wordlist();
}
