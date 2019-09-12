#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    //creates the size of matrix
    const int row = 3;
    const int col = 3;
    //initialize the matrix, and resize it to a 3*3 matrix
    vector< vector<int> > matrix;
    matrix.resize( row , vector <int> (col , -1 ) ) ;
    //create random position
    int rand_place1;
    int rand_place2;
    //create user input
    int user_in1;
    int user_in2;
    //create count for guesses
    int count = 0;
    //create boolean type for checking the guess
    bool not_found = true;
    //create a random location
    srand(time(nullptr));
    rand_place1 = rand()%3;
    rand_place2 = rand()%3;

    for(int i = 0; i < row ; ++i){
        cout << endl;
        for(int j = 0; j < col; ++j) {
            matrix[i][j] = ' ';
        }
    }
    //fill the matrix with spaces
    for(int i = 0; i < row; ++i){
        cout << endl;
        for(int j = 0; j < col; ++j) {
            matrix[i][j] = ' ';
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
            matrix[user_in1][user_in2] = 'O';
        }
        else{
            count +=1;
            cout << "\nMiss, try again" << endl;
            matrix[user_in1][user_in2] = 'X';
        }

        for(int i = 0; i < row ; ++i){
            cout << endl;
            for(int j = 0; j < col  - 1;++j){
                cout << matrix[i][j] << '!';
            }
            cout << matrix[i][row - 1];
            if(i == col - 1) {
            }
            else{
                cout << "\n~~~~~";
            }
        }


    }
    return 0;
}