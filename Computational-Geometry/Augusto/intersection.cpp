#include <iostream>
#include <regex>

using namespace std;

bool todoEnUno(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{ // O(1)
    float a = ((y2 - y1) / (x2 - x1));
    float b = ((((y2 - y1) / (x2 - x1)) * (x1 * -1)) + y1);

    float c = ((y4 - y3) / (x4 - x3));
    float d = ((((y4 - y3) / (x4 - x3)) * (x3 * -1)) + y3);

    float x = ((d - b) / (a - c));

    float xTemp = a * x + b;
    float yTemp = c * x + d;

    string uno = to_string(xTemp);
    string dos = to_string(yTemp);

    if (uno == dos)
    {

        float y = a * x + b;

        if (((x1 <= x && x <= x2) || (x2 <= x && x <= x1)) && ((x3 <= x && x <= x4) || (x4 <= x && x <= x3)))
        {
            if (((y1 <= y && y <= y2) || (y2 <= y && y <= y1)) && ((y3 <= y && y <= y4) || (y4 <= y && y <= y3)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool regexNumber(string numb)
{                                   // Funcion que regresa un booleano referente a si la entrada recibida es o no un entero.
    const regex expReg("^[0-9]+$"); // Regex que checa la presencia de uno o mas digitos del 0 al 9.
    return regex_match(numb, expReg);
}

bool regexFloat(string numb)
{                                                    // Funcion que regresa un booleano referente a si la entrada recibida es o no un entero.
    const regex expReg("^[+-]?([0-9]*[.])?[0-9]+$"); // Regex que checa la presencia de uno o mas digitos del 0 al 9.
    return regex_match(numb, expReg);
}

void initializer()
{

    cout << "Bienvenido al calculador de intersecciones.\n";

    string N = "0"; // No. de eleemntos

    while (true)
    { // Mientras el numero de elementos introducido no sea correcto.

        cout << "Ingresa el numero de segmentos a ingresar: ";
        getline(cin, N);
        cin.clear();
        fflush(stdin);

        if (!regexNumber(N))
        { // Si se introduce un caracter erroneo.
            cout << "ERROR: Solo se aceptan caracteres numericos del 0 al 9, sin espacios.\n";
        }
        else if (stoi(N) < 2)
        { // Si se introduce un valor menor a 3 elementos.
            cout << "ERROR: Se requiere de un minimo de 2 segmentos.\n";
        }
        else
        { // Si la entrada es correcta.
            break;
        }
    }

    int n = stoi(N); // No. de elementos, convertido a Int.
    float puntos[n][4];

    for (int g = 0; g < n; g++)
    {
        for (int h = 0; h < 4; h++)
        {
            cout << "Ingresa el valor de (" << char(g + 65) << ") - ";

            if (h == 0)
            {
                cout << "X1: ";
            }
            else if (h == 1)
            {
                cout << "Y1: ";
            }
            else if (h == 2)
            {
                cout << "X2: ";
            }
            else
            {
                cout << "Y2: ";
            }

            while (true)
            { // Mientras no se hayan agreagdo todos los pesos.

                string currentN; // Entrada actual.
                getline(cin, currentN);
                cin.clear();
                fflush(stdin);

                if (!regexFloat(currentN))
                { // Si la entrada no es valida.
                    cout << "ERROR: Entrada invalida. Solo se aceptan numeros enteros o decimales, positivos o negativos y sin espacios.\n";
                }
                else
                {
                    puntos[g][h] = stof(currentN);
                    break;
                }
            }
        }
    }

    cout << "\n";
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Segmentos (" << char(i + 65) << ") y (" << char(j + 65) << ") tienen interseccion: ";

            if (todoEnUno(puntos[i][0], puntos[i][1], puntos[i][2], puntos[i][3], puntos[j][0], puntos[j][1], puntos[j][2], puntos[j][3]))
            {
                cout << "true. \n";
            }
            else
            {
                cout << "false. \n";
            }
        }
    }
}

int main()
{
    initializer();
    return 0;
}