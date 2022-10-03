#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <regex>
bool stringVerification(std::string word);
std::vector<std::string> inputData(int num);

class TrieNode
{
public:
    std::unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie()
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
    }

    void populateSuffixTrieFrom(std::string str)
    {
        int level = 0;
        auto node = this->root;

        for (auto i : str)
        {
            if (!(node->children[i])) // Si no encuntra la llave
            {
                auto newChildren = new TrieNode();
                node->children[i] = newChildren;
                level++;
            }

            node = node->children[i]; // Nos movemos a newChildren
        }
        node->children[this->endSymbol] = nullptr;
    }

    bool contains(std::string str)
    {
        auto node = this->root;
        for (auto i : str)
        {
            if (!(node->children[i]))
                return false;
            node = node->children[i];
        }

        for (auto x : node->children)
        {
            if (x.first == this->endSymbol)
                return true;
        }

        return false;
    }

    void print(TrieNode *node, std::string prefix)
    {
        for (auto itr : node->children)
        {
            std::cout << itr.first << "";
            if (itr.second != nullptr)
            {
                print(itr.second, prefix + "|");

                // std::cout << "|";
                std::cout << "\n";
                std::cout << prefix;
            }
        }
    }
};

int main()
{
    std::vector<std::string> dictionary, toSearch;
    SuffixTrie myTrie;
    int n, m;

    std::cout << "\nIngrese n: ";
    std::cin >> n;
    while (n < 0)
    {
        std::cout << "Por favor, ingrese un numero entero positivo" << std::endl;
        std::cout << "\nIngrese n: ";
        std::cin >> n;
    }
    dictionary = inputData(n);

    std::cout << "\nIngrese m: ";
    std::cin >> m;
    while (m < 0)
    {
        std::cout << "Por favor, ingrese un numero entero positivo" << std::endl;
        std::cout << "\nIngrese m: ";
        std::cin >> n;
    }
    toSearch = inputData(m);

    for (auto i : dictionary)
        myTrie.populateSuffixTrieFrom(i);

    for (auto i : toSearch)
        (myTrie.contains(i)) ? std::cout << "\nTRUE:\tSi contiene palabra: " + i : std::cout << "\nFALSE:\tNo contiene palabra: " + i;

    std::cout << "\n\n-----Trie-----\n";
    myTrie.print(myTrie.root, "");

    return 0;
}

bool stringVerification(std::string word)
{
    std::string available = "^[A-Za-z]+";
    std::regex pattern(available);
    return (regex_match(word, pattern));
}

std::vector<std::string> inputData(int num)
{
    std::vector<std::string> temp(num, "");

    getline(std::cin, temp[0]); // Un mamada

    for (int i = 0; i < num; i++)
    {
        std::cout << "Palabra (" << i + 1 << "/" << num << "): ";
        getline(std::cin, temp[i]);

        if (!stringVerification(temp[i]))
        {
            std::cout << "Por favor ingrese una palabra de la a-z o A-Z, sin espacios.\n";
            i--;
        }
        if (temp[i].length() == 0)
        {
            std::cout << "\nPor favor no ingrese una palabra vacia.\n";
            i--;
        }
    }

    return temp;
}