/*
* Complexity: O(2^n)
*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int accum[] = {0, 0};

bool regexNumber(string numb){
     const regex expReg("^[0-9]+$");
     return regex_match(numb, expReg);
}

void knapsack(int w[], int v[], int key, int capacity, int items, int value){
    if(value > accum[1]){
        accum[0] = items;
        accum[1] = value;
    }

    if(key == 0 || capacity == 0){
        return;
    }else if(w[key] > capacity){
        knapsack(w, v, key - 1, capacity, items, value);
    }else{
        knapsack(w, v, key - 1, capacity, items, value);
        knapsack(w, v, key - 1, capacity - w[key], items + 1, value + v[key]);
    }
}

void init(){

    cout<<"Bienvenido a Knapsack.\n";

    string N = "0";

    while(true){

        
        cout<<"Ingresa el numero de elementos: ";
        getline(cin, N);
        cin.clear();
	    fflush(stdin);

        if(!regexNumber(N)){
            cout<<"ERROR: Solo se aceptan caracteres numericos del 0 al 9, sin espacios.\n";
        }else if(stoi(N) < 3){
            cout<<"ERROR: Se requiere de un valor de n >= 3.\n";
        }else{
            break;
        }
    }

    int n = stoi(N);

    int value[n + 1];
    value[0] = 0;

    int i = 1;

    cout<<"\n";
    cout<<"Valores de elementos:\n";
    while(i <= n){

        string currentN;

        cout<<"("<<i<<"): ";
        getline(cin, currentN);
        cin.clear();
	    fflush(stdin);

        if(!regexNumber(currentN)){
            cout<<"ERROR: Solo se aceptan caracteres numericos del 0 al 9, sin espacios.\n";
        }else if(stoi(currentN) < 1){
            cout<<"ERROR: Se requiere de un valor de n >= 1.\n";
        }else{
            value[i] = stoi(currentN);
            i++;
        }
    }

    int weight[n + 1];
    weight[0] = 0;

    i = 1;

    cout<<"\n";
    cout<<"Pesos de elementos:\n";
    while(i <= n){

        string currentN;

        cout<<"("<<i<<"): ";
        getline(cin, currentN);
        cin.clear();
	    fflush(stdin);

        if(!regexNumber(currentN)){
            cout<<"ERROR: Solo se aceptan caracteres numericos del 0 al 9, sin espacios.\n";
        }else if(stoi(currentN) < 1){
            cout<<"ERROR: Se requiere de un valor de n >= 1.\n";
        }else{
            weight[i] = stoi(currentN);
            i++;
        }
    }

    string maxWeight ="0";

    cout<<"\n";
    cout<<"Pesos maximo de mochila:\n";

    while(true){

        getline(cin, maxWeight);
        cin.clear();
	    fflush(stdin);

        if(!regexNumber(maxWeight)){
            cout<<"ERROR: Solo se aceptan caracteres numericos del 0 al 9, sin espacios.\n";
        }else if(stoi( maxWeight) < 1){
            cout<<"ERROR: El valor de Peso Max debe ser >= 1.\n";
        }else{
            break;
        }
    }

    knapsack(weight, value, n, stoi(maxWeight), 0, 0);

    cout<<"\n";
    cout<<"Punto optimo encontrado: \n";
    cout<<"Valor: "<<accum[1]<<", con "<<accum[0]<<" elementos.\n";
}

int main(){

    init();

    return 0;
}