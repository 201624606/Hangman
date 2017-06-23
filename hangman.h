#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <time.h>
#define LINE 269
using namespace std;

void printTitle();
void toUpper(string &word);
void selectMode(int &mode);
void guessWord(string ans, string &copy, string &underbar, string &letter, string &guess, int &count);
bool checkAns(string ans, string underbar, string letter, int count);
void endGame(int &mode);
void playHangMan(string ans, string &copy, string &underbar, string &letter, string &guess, int &count, int &mode);
