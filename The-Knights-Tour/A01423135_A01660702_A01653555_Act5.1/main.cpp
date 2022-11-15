#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <regex>

using namespace std;


bool regexNumber(string numb) // Time: O(1)
{
    const regex expReg("^[0-9]+$");
    return regex_match(numb, expReg);
}

void last5Steps (vector<pair<int, int> > steps) {
  cout << "Steps " << steps.size() - 6 << " - " << steps.size() - 1 << ": ";
  for (int i = steps.size() - 6; i < steps.size(); i++) {
    cout << "(" << steps[i].first << ", " << steps[i].second << ")  " ;
  }
  cout << "\n";
}

void showSolution (vector<vector<int>> board, vector<pair<int, int>> steps) {
  for (int index = 0; index < steps.size(); index++) {
    pair<int, int> step = steps[index];
    board[step.first][step.second] = index + 1;
  }

  cout << "Steps taken: " << "\n";
  for (auto row : board) {
    for (auto value : row) {
      cout << value << " ";
    }
    cout << "\n";
  }
}

bool positionValid (int row, int column, vector<vector<int> > board) {
  // Out of bounds
  if (row < 0 || row > board.size() - 1) return false;
  if (column < 0 || column > board[0].size() - 1) return false;
  // Has been to that position before
  if (board[row][column] == 1) return false;
  // None of the above are true
  return true;
}

pair<int, int> moveKnight(int movement, int row, int col) {
  // Move without caring if inside bounds or valid
  switch(movement) {
    case 1:
      // uppermost right movement 
      return make_pair(row - 2, col + 1);
      break;
    case 2:
      // upper right movement
      return make_pair(row - 1, col + 2);
      break;
    case 3:
      // lower right movement
      return make_pair(row + 1, col + 2);
      break;
    case 4:
      // lowermost right movement
      return make_pair(row + 2, col + 1);
      break;
    case 5:
      // uppermost left movement
      return make_pair(row - 2, col - 1);
      break;
    case 6:
      // upper left movement
      return make_pair(row - 1, col - 2);
      break;
    case 7:
      // lower left movement
      return make_pair(row + 1, col - 2);
      break;
    case 8:
      // lowermost left movement
      return make_pair(row + 2, col - 1);
      break;
    default:
      return make_pair(-1, -1);
  }
}

bool knigthsProblem(vector<vector<int> > &board, pair<int, int> position, vector<pair<int, int> > &steps) {
  // base case
  if (steps.size() == board.size() * board[0].size()) {
    return true;
  }

  // if current pos is valid
  if (positionValid(position.first, position.second, board)) {
    board[position.first][position.second] = 1;
    steps.push_back(position);
  } else {
    return false;
  }

  // Check if movement returns true
  int movement = 1;
  while (movement <= 8) {
    pair<int, int> newPos = moveKnight(movement, position.first, position.second);
    if (!knigthsProblem(board, newPos, steps)) {
      movement++;
    } else {
      return true;
    }
  }

  return false;
}

int main () {
  string sizeBoard;

  cout << "Input size of board: ";
  cin >> sizeBoard;

  if (!regexNumber(sizeBoard)) {
    cout << "Input must be an integer\n";
    exit(0);
  }

  vector<vector<int> > board (stoi(sizeBoard), vector<int> (stoi(sizeBoard)));
  vector<pair<int, int> > steps;

/*   for (int i = 0; i < board.size(); i++) {
    for (int k = 0; k < board.size(); k++) {
      cout << board[i][k] << " ";
    }
    cout << "\n";
  }
 */
  bool result = knigthsProblem (board, {0, 0}, steps);

  if (result) {
    cout << " -- SOLUTION FOUND -- \n";
    showSolution(board, steps);
  } else {
    cout << "-- SOLUTION NOT FOUND -- \n";
    showSolution(board, steps);
  }
}