//the find method is implemented with KMP
#include <iostream>
#include <cstdlib>
#include "string.h"
#include <fstream>

using namespace std;

int main()
{

    ifstream f("input1.txt");
    ofstream o("output.txt");
    int db = 1;
    char yn[2];

   

    STRING target, target_copy;
    for (int game = 1; game <= db; game++)
    {
        target.clear();
        target_copy.clear();
        getline(f, target);
        target_copy = target;
        int len = target.length();
        STRING guess;
        for (int i = 0; i < len; i++)
        {
            if (target[i] != ' ')
                guess.push_back('-');
            else
            {
                guess.push_back(' ');
            }
        }
        guess.push_back('\0');
        // game
        int numGuesses = 0;
        bool gameOver = false;

        while (!gameOver)
        {
            std::cout << "Current guess: " << guess << std::endl;
            o << "Current guess: " << guess << std::endl;
            // actual
            STRING input;
            std::cout << "Enter a letter or the full word guess: ";
            o << "Enter a letter or the full word guess: ";
            cin >> input;

            if (input == target_copy || guess == target)
            { // full word guess
                std::cout << "Congratulations, you won! The word was \"" << target_copy << "\"." << std::endl;
                o << "Congratulations, you won! The word was \"" << target_copy << "\"." << std::endl;
                gameOver = true;
            }
            else if (input.length() > 0)
            { // single letter guess
                // search
                size_t pos = find(target, input);
                if (pos != -1)
                {
                    while (find(target, input) != -1)
                    {
                        pos = find(target, input);
                        STRING temp;
                        temp = guess.substr(0, pos);
                        temp += input;
                        temp += guess.substr(pos + input.length(), len - 1);
                        guess.clear();
                        for (size_t i = 0; i < temp.size(); i++)
                        {
                            guess.push_back(temp[i]);
                        }

                        STRING temmp;
                        temmp = target.substr(0, pos);
                        for (int u = 0; u < input.length(); u++)
                        {
                            temmp.push_back('-');
                        }
                        temmp += target.substr(pos + input.length(), len - 1);
                        target.clear();
                        for (size_t i = 0; i < temmp.size(); i++)
                        {
                            target.push_back(temmp[i]);
                        }
                    }

                    std::cout << "Correct! The letter(s) \"" << input << "\" is in the word." << std::endl;
                    o << "Correct! The letter \"" << input << "\" is in the word." << std::endl;
                    if (guess == target_copy || guess == target)
                    { // full word guess
                        std::cout << "Congratulations, you won! The word was \"" << target_copy << "\"." << std::endl;
                        o << "Congratulations, you won! The word was \"" << target_copy << "\"." << std::endl;
                        gameOver = true;
                    }
                }
                else
                {
                    std::cout << "Sorry, the letter \"" << input << "\" is not in the word." << std::endl;
                    o << "Sorry, the letter \"" << input << "\" is not in the word." << std::endl;
                }
                numGuesses++;
            }
            else
            { // invalid input
                cout << input;
                std::cout << "Invalid input. Please enter a single letter or the full word guess." << std::endl;
                o << "Invalid input. Please enter a single letter or the full word guess." << std::endl;
            }
        }

        std::cout << "You made " << numGuesses << " guesses." << std::endl;
        o << "You made " << numGuesses << " guesses." << std::endl;
    }
    return 0;
}
