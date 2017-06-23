#include "hangman.h"

void printTitle() {
	cout << "##     ##    ###    ##    ##  ######   ##     ##    ###    ##    ## " << endl;
	cout << "##     ##   ## ##   ###   ## ##    ##  ###   ###   ## ##   ###   ## " << endl;
	cout << "##     ##  ##   ##  ####  ## ##        #### ####  ##   ##  ####  ## " << endl;
	cout << "######### ##     ## ## ## ## ##   #### ## ### ## ##     ## ## ## ## " << endl;
	cout << "##     ## ######### ##  #### ##    ##  ##     ## ######### ##  #### " << endl;
	cout << "##     ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##   ### " << endl;
	cout << "##     ## ##     ## ##    ##  ######   ##     ## ##     ## ##    ## " << endl;
}

void toUpper(string &word) {
	transform(word.begin(), word.end(), word.begin(), ::toupper);
}

void selectMode(int &mode) {
	cout << endl << "* * * M E N U * * *" << endl;
	cout << "1. SINGLE MODE" << endl;
	cout << "2. DUAL MODE" << endl;
	cout << "3. QUIT" << endl;
	char c;	
	cout << "Enter Option: ";
	cin >> c;
	while (!isdigit(c) || c < '1' || c > '3') {
		cout << "Please enter option between 1 to 3: ";
		cin >> c;
	}
	mode = c - '0';
	cout << endl;
}

void guessWord(string ans, string &copy, string &underbar, string &letter, string &guess, int &count) {
	cout << underbar << endl;
	cout << "You have " << count << " chances to guess" << endl;
	if (guess != " ")
		cout << "Guessed letters:" << guess << endl;
	cout << "Enter a letter or word to guess: ";
	cin >> letter;
	toUpper(letter);
	while (guess.find(letter) != -1) {
		cout << "You have already guessed '" << letter << "'" << endl;
		cout << "Enter a letter or word to guess: ";
		cin >> letter;
		toUpper(letter);
	}
	if (letter == ans) {
		cout << endl;
		return;
	}

	if (copy.find(letter) != -1) {
		while (copy.find(letter) != -1) {
			underbar.replace(copy.find(letter), 1, letter);
			copy.replace(copy.find(letter), 1, "_");
		}
		guess += letter;
		guess += " ";
		count--;
	}
	else {
		cout << "That's wrong. :(" << endl;
		guess += letter;
		guess += " ";
		count--;
	}
	cout << endl;
}

bool checkAns(string ans, string underbar, string letter, int count) {
	char input = ' ';
	if (underbar == ans || letter == ans) {
		cout << ans << endl;
		cout << "THAT'S CORRECT! YOU WIN!!" << endl;
		return true;
	}
	if (count == 0) {
		cout << "GAME OVER!" << endl;
		cout << "The answer was: " << ans << endl;
		return true;
	}
	return false;
}

void endGame(int &mode) {
	char c;
	while (true) {
		cout << "Do you want to play again? (Y/N): ";
		cin >> c;
		if (c == 'Y' || c == 'y') {
			selectMode(mode);
			return;
		}			
		else if (c == 'N' || c == 'n') {
			mode = 3;
			return;
		}
		else {
			cout << "Please enter 'Y' or 'N'" << endl;
		}
	}
}

void playHangMan(string ans, string &copy, string &underbar, string &letter, string &guess, int &count, int &mode) {
	copy = ans;

	for (int i = 0; i != ans.length(); i++)
		underbar += '_';

	count = ans.length() + 3;

	while (true) {
		guessWord(ans, copy, underbar, letter, guess, count);
		if (checkAns(ans, underbar, letter, count) == true) {
			endGame(mode);
			break;
		}
	}
}
