#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream input("sudokuboard.txt");

	if (input.fail()){
		cout << "File does not exist - terminating" << endl;
		return 0;
	}

	int board[9][9];
	string row[9];

	//Read rows into array
	for(int i=0; i<9; i++){
		input >> row[i];
	}

	input.close();

	//Separate into individual elements
	for(int r=0; r<9; r++){
		for(int c=0; c<9; c++){
			board[r][c] = row[r][c]-48;
		}
	}

	//Check validity
	bool valid = true;
	//Rows
	for(int r=0; r<9; r++){
		int count[9] = {0};
		for(int c=0; c<9; c++){
			int ind = board[r][c];
			count[ind]++;
		}
		for(int i=0; i<9; i++){
			if (count[i] != 1){
				valid = false;
			}
		}
	}
	//Columns
	for(int c=0; c<9; c++){
		int count[9] = {0};
		for(int r=0; r<9; r++){
			int ind = board[r][c];
			count[ind]++;
		}
		for(int i=0; i<9; i++){
			if (count[i] != 1){
				valid = false;
			}
		}
	}
	//3x3 groups
	for(int x=0; x<3; x++){
		for (int y=0; y<3; y++){
			int count[9] = {0};
			for(int r=3*x; r<3+3*x; r++){
				for(int c=3*y; c<3+3*y; c++){
					int ind = board[r][c];
					count[ind]++;
				}
			}
			for(int i=0; i<9; i++){
				if (count[i] != 1){
					valid = false;
				}
			}
		}
	}

	if(valid){
		cout << "Valid" << endl;
	}else{
		cout << "Invalid" << endl;
	}
	return 0;
}
