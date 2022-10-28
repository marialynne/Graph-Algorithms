#include <iostream>
#include <cmath>
#include <regex>
#include <vector>

using namespace std;

float abstand(float x1, float y1, float x2, float y2)
{
    float d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}

void findDistances(vector<vector<float>> centrales, vector<vector<float>> colonias)
{
    for(int i = 0; i < colonias.size(); i++)
    {
        float menor = abstand(colonias[i][0], colonias[i][1], centrales[0][0], centrales[0][1]);
        int index = 0;

        for(int j = 0; j < centrales.size(); j++)
        {
            if(to_string(colonias[i][0]) == to_string(centrales[j][0]) && to_string(colonias[i][1]) == to_string(centrales[j][1]))
            {
                cout<<"Posicion de la colonia ("<<i + 1<<") igual a la de la central ("<<char(j + 65)<<")! \n";
                menor = 0;
                index = j;
                break;
            }
            else
            {
                float dActual = abstand(colonias[i][0], colonias[i][1], centrales[j][0], centrales[j][1]);

                if(dActual < menor)
                {
                    menor = dActual;
                    index = j;
                }
            }
        }
        if(menor > 0)
        {
            cout<<"Colonia ("<<i + 1<<") -> Central mas cercana: ("<<char(index + 65)<<"), distancia: "<<menor<<"km. \n";

        }
    }
}

bool regexNumber(string numb)
{ 
     const regex expReg("^[0-9]+$");
     return regex_match(numb, expReg);
}

bool regexFloat(string numb)
{
     const regex expReg("^[+-]?([0-9]*[.])?[0-9]+$"); 
     return regex_match(numb, expReg);
}

bool regexCoordinate(string coor)
{
     const regex expReg("^\\(([+-]?([0-9]*[.])?[0-9]+)[,]([+-]?([0-9]*[.])?[0-9]+)\\)+$"); 
     return regex_match(coor, expReg);
}

void entradasCoordenadas()
{
    cout<<"\n----------------------PARTE 4----------------------\n";
    cout<<"\n";
    cout<<"Introduzca las coordenadas de las centrales a continuacion... \n";
    cout<<"El formato valido para coordenadas es (X,Y) sin espacios.\n";
    cout<<"Ejemplos: (2,3) -> (-1,-5) -> (-3.5,2.7) etc.\n";
    cout<<"Para salir escriba el caracter e .\n";
    cout<<"\n";

    vector<vector<float>> centrales;

    while(true)
    {
        string coordenada;
        vector<float> coor;

        cin >> coordenada;

        if(regexCoordinate(coordenada))
        {
            coordenada.erase(0, 1);
            coordenada.erase(coordenada.size() - 1);

            string delimiter = ",";

            coor.push_back(stof(coordenada.substr(0, coordenada.find(delimiter))));
            coordenada.erase(0, coordenada.find(delimiter) + delimiter.length());
            coor.push_back(stof(coordenada));

            centrales.push_back(coor);

        }else if(coordenada == "e" || coordenada == "E")
        {
            if(!coordenada.empty())
            {
                cout<<"\n";
                break;
            }
            else
            {
                cout<<"\nERROR: Se debe agregar al menos una central.\n";
            }   
        }else
        {
            cout<<"\nEntrada no valida. \n";
            cout<<"El formato valido para coordenadas es (X,Y) sin espacios.\n";
            cout<<"Ejemplos: (2,3) -> (-1,-5) -> (-3.5,2.7) etc.\n";
            cout<<"Para salir escriba el caracter e .\n";
        }
    }

    cout<<"Introduzca las coordenadas de las colonias a continuacion... \n";
    cout<<"El formato valido para coordenadas es (X,Y) sin espacios.\n";
    cout<<"Ejemplos: (2,3) -> (-1,-5) -> (-3.5,2.7) etc.\n";
    cout<<"Para salir escriba el caracter e .\n";
    cout<<"\n";
    
    vector<vector<float>> colonias;

    while(true)
    {
        string colonia;
        vector<float> coor;

        cin >> colonia;

        if(regexCoordinate(colonia))
        {
            colonia.erase(0, 1);
            colonia.erase(colonia.size() - 1);

            string delimiter = ",";

            coor.push_back(stof(colonia.substr(0, colonia.find(delimiter))));
            colonia.erase(0, colonia.find(delimiter) + delimiter.length());
            coor.push_back(stof(colonia));

            colonias.push_back(coor);

        }else if(colonia == "e" || colonia == "E")
        {
            if(!colonia.empty())
            {
                cout<<"\n";
                break;
            }
            else
            {
                cout<<"\nERROR: Se debe agregar al menos una colonia.\n";
            }   
        }else
        {
            cout<<"\nEntrada no valida. \n";
            cout<<"El formato valido para coordenadas es (X,Y) sin espacios.\n";
            cout<<"Ejemplos: (2,3) -> (-1,-5) -> (-3.5,2.7) etc.\n";
            cout<<"Para salir escriba el caracter e .\n";
        }
    }

    findDistances(centrales, colonias);

}

int main()
{
    entradasCoordenadas();
    return 0;
}