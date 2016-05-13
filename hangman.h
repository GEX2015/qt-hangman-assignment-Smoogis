#pragma once
#include <map>
#include <set>
#include <vector>
class Hangman
{
public:
    Hangman();
    ~Hangman();

    std::string displayGallows() const;
    void play();

    std::string displayMove();
    void guess(char guess);

    std::string getPhrase() { return _phrase; }
    bool won();
    bool lost();

private:
    std::vector<std::string> words;
    std::string _phrase;
    std::set<char> _correctGuesses;
    std::set<char> _missedGuesses;
};

