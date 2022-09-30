#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <regex>
#include <cctype>

using namespace std;

/*********************VALIDACIONES*********************/
bool regexWord(string word){
     const regex expReg("^[a-zA-Z]+$");
     return regex_match(word, expReg);
}

bool regexNumber(string numb){
     const regex expReg("^[0-9]+$");
     return regex_match(numb, expReg);
}
/*********************VALIDACIONES*********************/

struct node{

	int counter;
	bool isEnd;
	struct node *next[26];
}
*head;

void initNode(){

	head = new node();
	head -> isEnd = false;
	head -> counter = 0;
}

void insert(string word){

	node *current = head;
	current -> counter += 1;
	
	for(int i = 0 ; i < word.length(); i++){

		int letter;

        if(!isupper(word[i])){
            letter = int(word[i]) - int('a');
        }else{
            letter = int(word[i]) - int('A');
        }	

		if(current->next[letter] == NULL){
           current->next[letter] = new node(); 
        }

		current -> next[letter] -> counter += 1;
		current = current -> next[letter];		
	}
	current -> isEnd = true;
}

bool search(string word){

	node *current = head;

    int letter;

	for(int i = 0 ; i < word.length(); i++){

        if(!isupper(word[i])){
            letter = int(word[i]) - int('a');
        }else{
            letter = int(word[i]) - int('A');
        }

		if(current->next[letter] == NULL){
            return false;
        }else{
          current = current->next[letter];  
        }
	}

	return current->isEnd;
}

void path(string word){

	node *current = head;

    cout<<"Camino: ";

    int letter;

	for(int i = 0 ; i < word.length(); i++){

		if(!isupper(word[i])){
            letter = int(word[i]) - int('a');
        }else{
            letter = int(word[i]) - int('A');
        }

        cout<<"Nodo("<<letter<<") -> ";

        current = current -> next[letter];  
        
	}
}

/*
void tree(string word){

}
*/

void trie(int n, string words[]){

    initNode();

    for(int i = 0; i < n; i ++){
        insert(words[i]);
    }

    cout<<"\n";

    string word;

    while(true){
        cout<<"Buscar Palabra: ";
        cin>>word;
        //cin.ignore();
        //getline(cin, word);

        if(regexWord(word)
        ){
            
            cout<<"Encontrado?: "<<search(word)<<"\n";

            if(search(word) == true){
                path(word);
            }
        }else{
            cout<<"ERROR: Solo se aceptan caracteres de la a - z. \n";
        }
        cout<<"\n";
    }
}

void init() {

    int i = 0;
    int n;

    cout<<"\nBienvenido a TRIE. \n";
    cout<<"Ingresa el numero de palabras a insertar: \n";
    cin >> n;

	cin.ignore(10000, '\n');
	fflush(stdin);

    string words[n];

    while(i < n){
        string word;
        cout<<"Ingresa la palabra ("<<(i + 1)<<"): \n";
        
        getline(cin, word);
        //cin>>ws;
        cout<<word << "\n";

        cin.clear();
	    fflush(stdin);
        
        if(regexWord(word) == true)
        {
            words[i] = word;
            i += 1;
        }
        else{
            cout<<"ERROR: Solo se aceptan caracteres de la a - z, minusculas y sin espacios.\n";
        
        }
    }

    
    trie(n, words);

}

int main(){

	init();
	
	return 0;
}