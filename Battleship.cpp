#include <iostream>
using namespace std;

int main() {
    const int board_side = 3;
    char board[board_side][board_side];  //creates 2D array as a "game board"
    int rand_place1;
    int rand_place2;
    int user_in1;
    int user_in2;
    int count = 1;
    bool not_found = true;
    //srand(1);   seed used for testing
    rand_place1 = rand()%3;
    rand_place2 = rand()%3;

    for(int i = 0; i < board_side; ++i){
        cout << endl;
        for(int j = 0; j < board_side; ++j) {
            board[i][j] = ' ';
        }
    }

    while(not_found){
        cout << "\nGuess a row and a column. ";
        cin >> user_in1;
        cin >> user_in2;
        user_in1 -= 1;
        user_in2 -= 1;
        if(user_in1 == rand_place1 && user_in2 == rand_place2){
            not_found = false;
            cout << "\nYou sunk my battleship after " << count << " trys!" << endl;
            board[user_in1][user_in2] = 'O';
        }
        else{
            count +=1;
            cout << "\nMiss, try again" << endl;
            board[user_in1][user_in2] = 'X';
        }

        for(int i = 0; i < board_side ; ++i){
            cout << endl;
            for(int j = 0; j < board_side  - 1; ++j){
                cout << board[i][j] << '!';
            }
            cout << board[i][board_side - 1];
            if(i == board_side - 1) {
            }
            else{
                cout << "\n~~~~~";
            }
        }


    }
    return 0;
}