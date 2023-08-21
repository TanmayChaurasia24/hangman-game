#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    // For Windows
    std::system("cls");
#else
    // For Unix-like systems (Linux, macOS)
    std::system("clear");
#endif
}
int main()
{
    int m = 0, num, v, attempt = 0;
    vector<string> words;
    vector<string> temp;
    cout << endl;
    cout << "\t\t\t WELCOME TO HANGMAN GAME " << endl;
    cout << "\t\t----------------------------------------- " << endl
         << endl;
    cout << "\t\t enter the words that you want in your game" << endl;

    while (m != 1)
    {
        string w;
        cout << "\t\t enter the word: ";
        cin >> w;
        words.push_back(w);
        cout << endl
             << endl;
        cout << "\t\t if you want to stop entering the words the press 1 else press 2 : ";
        cin >> v;
        m = v;
    }
    clearScreen();
    cout << "\t\t\tthe words that you entered are: " << endl;
    for (int i = 0; i < words.size(); i++)
    {
        int g = 0;
        cout << "\t\t\t" << g + 1 << ": " << words[i] << endl;
    }
    cout << endl
         << endl;
    string yn;
    cout << "\t\t\tDO YOU WANT TO START THE GAME YES/NO? ";
    cin >> yn;
     string word_guess;
    if (yn == "yes")
    {
        char letter;
        int random_index = rand() % words.size();

        string random_word = words[random_index];
        int length = random_word.length();
        char temp[length];
        char assign = '_';
        for (int l = 0; l < length; l++)
        {
            temp[l] = assign;
        }
        int count = 0;
        while (attempt <= 5)
        {
            bool found = false;

            cout << "\t\t\tenter the letter: ";
            cin >> letter;

            for (int i = 0; i < random_word.length(); i++)
            {

                if (letter == random_word[i])
                {
                    found = true;
                    temp[i] = letter;
                  
                }
                
            }
            cout << "\t\t\tcurrent progress: ";
            for(int i=0 ; i<length ; i++)
            {
                cout << temp[i];
            }
            cout << endl << endl;
           if(!found)
           {
            attempt++;
            cout << "\t\t\tattempt remaning: "<< 5-attempt << endl << endl;
           }
           bool all = true;
            for (int i = 0; i < length; i++)
            {
                if(temp[i] == assign)
                {
                    all = false;
                    break;
                }
            }
            if (all)
            {
                cout << "\t\t\t------------------------YOU WON--------------------------";
                break;
            }
        }
        if (attempt > 5)
        {

            cout << "\t\t\t-------------------------------HANGMAN CREATED---------------------------" << endl;
        }
    }
    else
    {
        cout << "\t\t\twrite yes to play the game" << endl;
    }
}