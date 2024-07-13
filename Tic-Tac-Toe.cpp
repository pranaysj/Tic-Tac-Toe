#include <iostream>
using namespace std;\

char fieldCell[3][3] =
{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};

void Field() {
	system("cls");
	cout << "		|		|		" << endl;
	cout << "	" << fieldCell[0][0] << "	|	" << fieldCell[0][1] << "	|	" << fieldCell[0][2] << "	" << endl;
	cout << "		|		|		" << endl;
	cout << "- - - - - - - - |- - - - - - - -|- - - - - - - - " << endl;
	cout << "		|		|		" << endl;
	cout << "	" << fieldCell[1][0] << "	|	" << fieldCell[1][1] << "	|	" << fieldCell[1][2] << "	" << endl;
	cout << "		|		|		" << endl;
	cout << "- - - - - - - - |- - - - - - - -|- - - - - - - - " << endl;
	cout << "		|		|		" << endl;
	cout << "	" << fieldCell[2][0] << "	|	" << fieldCell[2][1] << "	|	" << fieldCell[2][2] << "	" << endl;
	cout << "		|		|		" << endl;
}

void CheckXorO(int _player, int _input) {
	//If player 1st turn then draw X and 
	//If player 2st turn then draw O and 
	char playerSign = (_player == 1) ? 'X' : 'O';

	//Replace the X or O according to the input with playerSign
	switch (_input) {
	case 1: fieldCell[0][0] = playerSign;
		break;
	case 2: fieldCell[0][1] = playerSign;
		break;
	case 3: fieldCell[0][2] = playerSign;
		break;
	case 4: fieldCell[1][0] = playerSign;
		break;
	case 5: fieldCell[1][1] = playerSign;
		break;
	case 6: fieldCell[1][2] = playerSign;
		break;
	case 7: fieldCell[2][0] = playerSign;
		break;
	case 8: fieldCell[2][1] = playerSign;
		break;
	case 9: fieldCell[2][2] = playerSign;
		break;
	}
}

//Check the winning condiiton
bool CheckWin(char _playerSign) {
	return ((fieldCell[0][0] == _playerSign && fieldCell[0][1] == _playerSign && fieldCell[0][2] == _playerSign) ||
		(fieldCell[1][0] == _playerSign && fieldCell[1][1] == _playerSign && fieldCell[1][2] == _playerSign) ||
		(fieldCell[2][0] == _playerSign && fieldCell[2][1] == _playerSign && fieldCell[2][2] == _playerSign) ||
		(fieldCell[0][0] == _playerSign && fieldCell[1][0] == _playerSign && fieldCell[2][0] == _playerSign) ||
		(fieldCell[0][1] == _playerSign && fieldCell[1][1] == _playerSign && fieldCell[2][1] == _playerSign) ||
		(fieldCell[0][2] == _playerSign && fieldCell[1][2] == _playerSign && fieldCell[2][2] == _playerSign) ||
		(fieldCell[0][0] == _playerSign && fieldCell[1][1] == _playerSign && fieldCell[2][2] == _playerSign) ||
		(fieldCell[0][2] == _playerSign && fieldCell[1][1] == _playerSign && fieldCell[2][0] == _playerSign)
		);
}

int main()
{

	//Input
	int player = 2; //player one start
	int input = 0;
	bool inputCorrect = true;

	while (true) {
		//Drawing the field
		Field();

		//Players turn
		if (player == 2) {
			player = 1;
			CheckXorO(player, input);
		}
		else
		{
			player = 2;
			CheckXorO(player, input);
		}

		Field();

		if (CheckWin('X')) {
			cout << "\nPlayer 2 has won!" << endl;
		}
		else if (CheckWin('O')) {
			cout << "\nPlayer 1 has won!" << endl;
		}

		// Test if field is already taken
		do {
			cout << endl;
			cout << "Player " << player << ": Choose your field! ";
			cin >> input;


			//Checking the input and the cell positon arre the same
			if ((input == 1 && fieldCell[0][0] == '1') ||
				(input == 2 && fieldCell[0][1] == '2') ||
				(input == 3 && fieldCell[0][2] == '3') ||
				(input == 4 && fieldCell[1][0] == '4') ||
				(input == 5 && fieldCell[1][1] == '5') ||
				(input == 6 && fieldCell[1][2] == '6') ||
				(input == 7 && fieldCell[2][0] == '7') ||
				(input == 8 && fieldCell[2][1] == '8') ||
				(input == 9 && fieldCell[2][2] == '9')) {
				inputCorrect = true;
			}
			else {
				cout << "\nIncorrect input! Please use another field!" << endl;
				inputCorrect = false;
			}
		} while (!inputCorrect);

	}
	

}


