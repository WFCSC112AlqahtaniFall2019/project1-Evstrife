#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {

    //creates the size of matrix
    const int size = 3;

    //initialize the matrix, and resize it to a 3*3 matrix
    vector< vector<char> > matrix;
    matrix.resize( size , vector <char> (size , -1 ) ) ;

    //initiate random position
    int rand_place1;
    int rand_place2;

    //initiate user input
    int user_in1;
    int user_in2;

    //initiate count for guesses
    int count = 1;

    //initiate boolean type for checking the guess
    bool not_found = true;

    //create a random location
    srand(time(nullptr));
    rand_place1 = rand()%3;
    rand_place2 = rand()%3;

    //fill the matrix with spaces
    for(int i = 0; i < size; ++i){
        cout << endl;
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = ' ';
        }
    }
    //print an initial empty game board
    for(int i = 0; i < size ; ++i){
        cout << endl;
        for(int j = 0; j < size  - 1;++j){
            cout << matrix[i][j] << '!';
        }
        cout << matrix[i][size - 1];
        if(i == size - 1) {
        }
        else{
            cout << "\n～～～～～～";
        }
    }
    while(not_found){
        //ask user for input
        cout << "\nGuess a row and a column. ";
        cin >> user_in1;
        cin >> user_in2;
        //convert the vector index
        user_in1 -= 1;
        user_in2 -= 1;
        //check whether the guess is correct
        if(user_in1 == rand_place1 && user_in2 == rand_place2){
            not_found = false;
            cout << "\nYou sunk my battleship after " << count << " trys!" << endl;
            matrix[user_in1][user_in2] = 'O';

        }
        //if wrong, increase count by 1, and try again
        else{
            count ++;
            cout << "\nMiss, try again" << endl;
            matrix[user_in1][user_in2] = 'X';
        }

        //print the updated game board for each guess
        for(int i = 0; i < size ; ++i){
            cout << endl;
            for(int j = 0; j < size  - 1;++j){
                cout << matrix[i][j] << '!';
            }
            cout << matrix[i][size - 1];
            if(i == size - 1) {
            }
            else{
                cout << "\n～～～～～～";
            }
        }
    }


    return 0;
}