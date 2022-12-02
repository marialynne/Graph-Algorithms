#include <iostream>
#include <stack>
#include <stdlib.h>
#include <tuple>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
string residue = "";

vector<string> dictionary = {"perro",
                             "helado",
                             "cuchara",
                             "serpiente",
                             "cucaracha"};

string getRandomWord()
{
    srand(time(NULL));
    int random = rand() % dictionary.size();
    string sel_elem = dictionary[random];
    return sel_elem;
}

void printLines(string word, string input)
{
    string line = "";
    residue = "";

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] != input[i])
        {
            line += "-";
            residue += word[i];
        }
        else if (word[i] == input[i])
        {
            line += word[i];
        }
    }
    cout << line << endl;
}

string getClueCesar(string res)
{
    string clue = "";
    for (int i = 0; i < res.length(); i++)
    {
        char key = res[i];
        key = key + 1;
        clue += key;
    }
    return clue;
}

void hangmanGame()
{
    cout << "Hola! Este es el juego del ahorcado, ten cuidado pues solo tendras 10 intentos para resolverlo." << endl;
    cout << "Las pistas te las dare con una tecnica de encriptacion... ah, Cesar suena bien.. no lo conoces?" << endl;
    cout << "Pues mira bien el patron y encontraras la solucion, buena suerte" << endl;

    int chances = 10;
    string input = "";

    cout << "______" << endl;
    cout << "|/   |" << endl;
    cout << "|   (_)" << endl;
    cout << "|   /|"
         << char(92) << endl;
    cout << "|    |" << endl;
    cout << "|   | |" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|_____" << endl;

    string word = getRandomWord();
    cout << endl
         << endl;
    while (chances > 0 && input != word)
    {
        cout << "Numero de intentos: " << chances << endl;
        cout << endl;
        printLines(word, input);
        cout << "Pista Cesar: " << getClueCesar(residue) << endl;
        input = "";
        cout << "\nDame la palabra: ";
        cin >> input;
        chances--;
        cout << endl;
    }
    if (word == input)
    {
        cout << "Ganaste!!!" << endl;
    }
    else
    {
        cout << "Se te acabaron los intentos..." << endl;
        cout << "______" << endl;
        cout << "|/   |" << endl;
        cout << "|   " << endl;
        cout << "|  " << endl;
        cout << "|    " << endl;
        cout << "|   " << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|_____" << endl;
    }
}

int main()
{
    hangmanGame();
    return 0;
}