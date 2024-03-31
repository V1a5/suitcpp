#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

string choices(){
    string list[] = {"rock", "paper", "scissors"};
    srand(time(0));
    int randomIndex = rand() % 3; // Menggunakan modulus 3 karena ada 3 pilihan
    string computerGuess = list[randomIndex];
    return computerGuess;
}

int checkWinning(string user, string computer, int point){
    cout << "\nYou choose " << user << " and computer choose " << computer << endl;
    if (user == computer) {
        cout << "It's a tie!" << endl;
    } else if ((user == "rock" && computer == "scissors")||
                (user == "paper" && computer == "rock")||
                (user == "scissors" && computer == "paper")){
        cout << "You win!" << endl;
        point++;
    } else {
        cout << "Computer wins!" << endl;
    }
    return point;
}


int main(){
    cout << "WELCOME TO ROCK, PAPER, SCISSROS GAME!!!" << endl;
    int pointUser = 0;
    string play;
    cout << "Do ready to play?(yes/no) "<< endl;
    cin >> play;
    if (play != "yes"){
        exit(0);
    }
    cout << "\nLET'S PLAYY!!!" << endl;
    while (true){
        string computer = choices();
        string user;
        cout << "Enter your choices (rock, paper, or scissors) or quit? " << endl;
        cin >> user;
        if (user == "quit"){
            cout << "You win " << pointUser << " game" << endl;
            exit(0);
        }
        pointUser = checkWinning(user,computer,pointUser);
    }
    return 0;
}