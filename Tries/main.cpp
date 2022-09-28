#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str)
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void insertSubstringStartingAt(int index, std::string str)
    {
        for (int j = 0; j < str.length(); j++)
        {
            std::string substr = str.substr(j);
            // std::cout << substr << std::endl;
            auto node = this->root;

            for (auto i : substr)
            {
                if (!(node->children[i])) // Si no encuntra la llave
                {
                    auto newChildren = new TrieNode();
                    node->children[i] = newChildren;
                }
                node = node->children[i];
            }
            node->children[this->endSymbol] = nullptr;
        }
    }

    void populateSuffixTrieFrom(std::string str)
    {
        for (int i = 0; i < str.length(); i++)
            this->insertSubstringStartingAt(i, str);
    }

    bool contains(string str)
    {
        auto node = this->root;

        for (auto i : str)
        {

            if (!(node->children[i]))
                return false;
            node = node->children[i];
        }

        auto x = node->children;
        // std::cout << x.first << std::endl;

        for (auto x : node->children)
        {
            // std::cout << (x.first == this->endSymbol) << std::endl;
            if (x.first == this->endSymbol)
                return true;
        }

        return false;
    }
};

int main()
{
    std::vector<std::string> dictionary = {"hola", "mundo", "persona", "pasajero", "lechuga"};
    SuffixTrie myTrie("hola");
    for (auto i : dictionary)
        myTrie.populateSuffixTrieFrom(i);

    std::cout << "Contiene " << myTrie.contains("persona") << std::endl;

    return 0;
}
