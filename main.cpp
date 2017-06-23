#include "hangman.h"

int main() {
	int mode = 1;

	printTitle();
	selectMode(mode);

	while (mode <= 3) {
		if (mode == 1) {
			cout << "* * * S I N G L E  M O D E * * *" << endl;
			
			ifstream list;
			string ans, copy, underbar, letter;
			string guess = " ";
			int count = 0;
			
			list.open("list.txt");
			srand(time(NULL));
			int r = rand() % LINE + 1;
			for (int i = 0; i < r; i++)
				list >> ans;
			toUpper(ans);

			playHangMan(ans, copy, underbar, letter, guess, count, mode);
		}
		else if (mode == 2) {
			cout << "* * * D U A L  M O D E * * *" << endl;
			
			string ans, copy, underbar, letter;
			string guess = " ";
			int count = 0;

			cout << "Enter a word for other player to guess: ";
			cin >> ans;
			toUpper(ans);
			system("clear");
			
			playHangMan(ans, copy, underbar, letter, guess, count, mode);
		}
		else if (mode == 3) {
			cout << "See you later!" << endl;
			break;
		}
		else {
			selectMode(mode);
		}
	}
	return 0;
}
