#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State { Empty, Obstacle };
void PrintBoard(vector<vector<State>> board);
vector<vector<State>> ReadBoardFile(string filePath);
vector<State> ParseLine(string line);
string CellString(State boardPosition);

int main() {

  vector<vector<State>> newBoard = ReadBoardFile("1.board");
  cout << "Printing from file \n";
  PrintBoard(newBoard);
}

void PrintBoard(vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++)
      cout << CellString(board[i][j]);
    cout << "\n";
  }
}

vector<vector<State>> ReadBoardFile(string filePath) {
  vector<vector<State>> board;
  vector<State> row;
  vector<int>::iterator it;
  ifstream file(filePath);
  if (file) {
    string line;
    while (getline(file, line)) {
      row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

vector<State> ParseLine(string line) {
  int n;
  char c;
  vector<State> row;
  stringstream output;
  output.str(line);
  while (output >> n) {
    if (n == 0)
      row.push_back(State::Empty);
    else
      row.push_back(State::Obstacle);
    output >> c;
  }
  return row;
}

string CellString(State boardPosition) {
  switch (boardPosition) {
  case State::Obstacle:
    return "⛰️ ";
  default:
    return "0";
  }
}
