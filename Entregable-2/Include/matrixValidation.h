#include <regex>
#include <cmath>

// IMPORATAR - MAYBE ESTA REPETIDA
/* bool regexFloat(string numb)
{                                                  // Funcion que regresa un booleano referente a si la entrada recibida es o no un entero.
  const regex expReg("^[+-]?([0-9]*[.])?[0-9]+$"); // Regex que checa la presencia de uno o mas digitos del 0 al 9.
  return regex_match(numb, expReg);
} */
/*
 *  Propiedades correctas de las matrices
- Tamaño correcto n = 4; (4x4)  ---- YA
- '0' en donde sea mismo nodo i == j -> 0 ---- YA
- Validar número decimales negativos o positivos (no caracteres raros o palabras)
- Primera matriz:
  - Que donde no haya conexiones valide que sea -1 y no otro número ----- REVIS QUE SOLO SEA -1 O POSITIVO, REVISAR QUE CONCUERDE
  - Que no haya '0' en donde no es i==j ---- YA
- Segunda matriz:
  - Que donde no haya conexiones sea '0' y no otro número
  - Los valores negativos se pueden pero se le tiene que sumar al flujo contrario
  - COMO MOSTRAR EN CASO DE NODOS NO ESTEN CONECTADOS


- Ambas matrices en común:
  - Donde en matriz1 haya un -1, en la matriz2 debe de haber un 0
 */

vector<vector<float>> clearMatrix(vector<vector<float>> matrix) // Time: O(1)
{
  matrix.clear();
  return matrix;
}

vector<vector<float>> generalValidations(vector<vector<string>> adjMatrix, int matrixNumber) // Time: O(n²)
{
  vector<vector<float>> validatedMatrix(adjMatrix.size(), vector<float>(adjMatrix.size(), 0));

  if (adjMatrix.size() != adjMatrix[0].size())
    return clearMatrix(validatedMatrix);

  for (int index = 0; index < adjMatrix.size(); index++)
  {
    if (adjMatrix[index][index] != "0")
    {
      cout << "entre" << endl;
      return clearMatrix(validatedMatrix); // Check same node connections 0,0 1,1 ...
    }

    for (int number = 0; number < adjMatrix.size(); number++)
    { // Check that text entered is float
      if (!regexFloat(adjMatrix[index][number]))
        return clearMatrix(validatedMatrix);

      float numberToCheck = stof(adjMatrix[index][number]);
      // Check that matrix 1 only has -1 as negative numbers
      if (index != number)
        if (matrixNumber == 1 && (numberToCheck < -1 || numberToCheck == 0))
          return clearMatrix(validatedMatrix);

      validatedMatrix[index][number] = numberToCheck;
    }
  }
  return validatedMatrix;
}

void adjustFlowMatrix(int index, int element, vector<vector<float>> &matrix2) // Time: O(1)
{
  float forwardFlow = matrix2[index][element];
  float backwardFlow = matrix2[element][index];

  cout << "\n\t<< Adjusting flow >>\n";

  if (forwardFlow < 0 && backwardFlow < 0)
  {
    matrix2[index][element] = abs(matrix2[element][index]);
    matrix2[element][index] = abs(matrix2[index][element]);
    return;
  }
  if (forwardFlow < 0)
  {
    matrix2[index][element] = 0;
    matrix2[element][index] += abs(forwardFlow);
    return;
  }
  if (backwardFlow < 0)
  {
    matrix2[index][element] += abs(backwardFlow);
    matrix2[element][index] = 0;
    return;
  }
}

bool matrixCorrespondence(vector<vector<float>> &matrix1, vector<vector<float>> &matrix2) // Time: O(n²)
{
  for (int index = 0; index < matrix1.size(); index++)
  {
    for (int element = 0; element < matrix1.size(); element++)
    {
      float elementMatrix_1 = matrix1[index][element];
      float elementMatrix_2 = matrix2[index][element];

      cout << "Matrix correspondence:\t" << elementMatrix_1 << "\t" << elementMatrix_2 << "\n";

      if (elementMatrix_1 == -1 && elementMatrix_2 != 0)
        return false;
      if (index != element)
        if (elementMatrix_2 == 0 && elementMatrix_1 != -1)
          return false;

      if (elementMatrix_2 < 0)
        adjustFlowMatrix(index, element, matrix2);
    }
  }
  return true;
}
