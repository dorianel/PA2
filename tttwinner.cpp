#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	ifstream input("tictactoeboards.txt");

	if (input.fail()){
		cout << "File does not exist - terminating" << endl;
		return 0;
	}

	bool valid = true;
	bool xWin = false;
	bool oWin = false;
	bool full = false;

	string row[200];
	string board[3][3];

	//Read rows
	int count=0;
	while (!input.eof()){
		input >> row[count];
		count++;
	}

	input.close();

	int numRows = count;

	ofstream output;
	output.open("tttstatus.txt");

	for(int i=0; i<numRows; i++){
		int numX = 0;
		int numO = 0;
		int numEmpty = 0;
		//Put into board
		for(int r=0; r<3; r++){
			for(int c=0; c<3; c++){
				board[r][c] = row[i][3*r+c];
				if(board[r][c] == "x"){
					numX++;
				}
				if(board[r][c] == "o"){
					numO++;
				}
				if(board[r][c] == "#"){
					numEmpty++;
				}
			}
		}
		if(numX > numO+1 || numX < numO){
			valid = false;
		}
		//Check rows
		for(int r=0; r<3; r++){
			if(board[r][0] == "x" && board[r][1] == "x" && board[r][2] == "x"){
				xWin = true;
			}
			if(board[r][0] == "o" && board[r][1] == "o" && board[r][2] == "o"){
				oWin = true;
			}
		}
		//Check columns
		for(int c=0; c<3; c++){
			if(board[0][c] == "x" && board[1][c] == "x" && board[2][c] == "x"){
				xWin = true;
			}
			if(board[0][c] == "o" && board[1][c] == "o" && board[2][c] == "o"){
				oWin = true;
			}
		}
		//Diagonals
		if(board[0][0] == "x" && board[1][1] == "x" && board[2][2] == "x"){
			xWin = true;
		}
		if(board[2][0] == "x" && board[1][1] == "x" && board[0][2] == "x"){
			xWin = true;
		}
		if(board[0][0] == "o" && board[1][1] == "o" && board[2][2] == "o"){
			oWin = true;
		}
		if(board[2][0] == "o" && board[1][1] == "o" && board[0][2] == "o"){
			oWin = true;
		}
		if(xWin && oWin){
			valid = false;
		}
		if(xWin && numX == numO){
			valid = false;
		}
		if(oWin && numX == numO+1){
			valid = false;
		}
		if(numEmpty == 0){
			full = true;
		}
		//Decision and output
		string tag = "c";

		if(valid){
			if(xWin){
				tag = "x";
			}
			if(oWin){
				tag = "o";
			}
			if(full){
				tag = "t";
			}
		}else{
			tag = "i";
		}

		output << row[i] << " " << tag << endl;
	}
	output.close();
	return 0;
}
