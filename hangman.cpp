#include "Hangman.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

static const int ALLOWED_MISSES = 6;

Hangman::Hangman()
{
    srand(static_cast<unsigned int>(time(0)));
    std::fstream ifile;
    ifile.open("C:\\Users\\Douglas\\Documents\\build-Hangman-Desktop_Qt_5_6_0_MinGW_32bit-Debug\\debug\\hangman.txt");
    if (ifile.fail())
    {
        std::cerr << "Cannot open file. Does not exist." << std::endl;
    }

    std::string word;
    while (!ifile.eof())
    {
        getline(ifile, word);
        words.push_back(word);
    }

    _phrase = words[rand() % words.size()];

    _missedGuesses.clear();
    _correctGuesses.clear();
}

Hangman::~Hangman()
{
}

std::string Hangman::displayGallows() const
{
    if (_missedGuesses.size() == 0)
    {
        return "border-image:url(:/media/gallows0.png)";
    }

    if (_missedGuesses.size() == 1)
    {
        return "border-image:url(:/media/gallows1.png)";
    }

    if (_missedGuesses.size() == 2)
    {
        return "border-image:url(:/media/gallows2.png)";
    }

    if (_missedGuesses.size() == 3)
    {
        return "border-image:url(:/media/gallows3.png)";
    }

    if (_missedGuesses.size() == 4)
    {
        return "border-image:url(:/media/gallows4.png)";
    }

    if (_missedGuesses.size() == 5)
    {
        return "border-image:url(:/media/gallows5.png)";
    }

    if (_missedGuesses.size() == 6)
    {
        return "border-image:url(:/media/gallows6.png)";
    }
}

void Hangman::play()
{
    while (!won())
    {
        displayMove();
        system("cls");
        if (lost())
            break;
    }
}

std::string Hangman::displayMove()
{
    std::string workingPhrase;
    for (char c : _phrase)
    {
        auto itr = std::find(_correctGuesses.begin(), _correctGuesses.end(), c);
        if (itr == _correctGuesses.end())
            workingPhrase += "_ ";
        else
            workingPhrase += c;
    }
    return workingPhrase;

//        std::cout << "\nUsed guesses (Max is 6): ";
//        for (auto e : _missedGuesses)
//            std::cout << e << " ";

//        std::cout << "\nMisses left: " << ALLOWED_MISSES - _missedGuesses.size() << "\n";
}

void Hangman::guess(char guess)
{

    // 1 already guessed
    //   find  correct or bad guess
    //   return
    //
    // 2. find _phrase
    //    yes -> insert good
    //    no -> inser bad

    for (int i = 0; i < _phrase.length();i++)
    {
        if (guess == _phrase[i])
        {
            _correctGuesses.insert(guess);
            return;
        }
    }
    _missedGuesses.insert(guess);

}

bool Hangman::won()
{

    for (auto e : _phrase)
    {
        if (std::find(_correctGuesses.begin(), _correctGuesses.end(), e) == _correctGuesses.end())
            return false;
    }
    return true;
}

bool Hangman::lost()
{
    if (_missedGuesses.size() == 6)
        return true;
    else
        return false;
}
