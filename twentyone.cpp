/*********************************************************************
 ** Program Filename: Blackjack
 ** Author:
 ** Date: 01/25/19
 ** Description: Betting game for 1-4 players against 1 dealer. Winner
 ** is determined by whoever can score a hand closest to 21 without
 ** going over.
 ** Input: Number of players, starting bank amount, bet amount, draw
 ** another card, and replay
 ** Output: Players bank value and card value
 *********************************************************************/
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*********************************************************************
 ** Function: playerNumber()
 ** Description: Checks if user input is valid ie 1-4
 ** Parameters: None
 ** Pre-Conditions: Variable to store user input must be intialized
 ** Post-Conditions: User input is all valid
 *********************************************************************/
int playerNumber () {
    int i = 0;
    std::string response;
    int error_handle = 1;
    
    while (error_handle == 1) {
        int count = 0;
        getline(cin, response);
        int response_length = response.length();
        if(response_length == 0){
            cout << "Enter valid input" << endl;
        }
        else {
        char response_array [ response_length + 1 ];
        strcpy (response_array, response.c_str());
        
        for ( i = 0; i < response_length; i++) {
            if ( int (response_array[i]) < 49 || int (response_array[i]) > 52 ) {
                count++;
            }
        }
        
        if (count == 0) {
            error_handle = 0;
        }
        else {
            cout << "Enter valid input" << std::endl;
        }
        
        std::stringstream convert(response);
        convert >> i;
        }
        
    }
    return i;
}
/*********************************************************************
 ** Function: user_input()
 ** Description: Checks if user input is valid ie 0-9
 ** Parameters: None
 ** Pre-Conditions: 2 dimensional array to store input must be initialized
 ** Post-Conditions: User input is all valid
 *********************************************************************/
int user_input () {
    int i = 0;
    std::string response;
    int error_handle = 1;
    
    while (error_handle == 1) {
        int count = 0;
        getline(cin, response);
        int response_length = response.length();
        if (response_length == 0) {
            cout << "Enter valid input" << endl;
        }
        else{
        char response_array [ response_length + 1 ];
        strcpy (response_array, response.c_str());
        
        for (i = 0; i < response_length; i++) {
            if ( int (response_array[i]) < 48 || int (response_array[i]) > 57 ) {
                count++;
            }
        }
        
        if (count == 0) { //valid input
            error_handle = 0;
        }
        else if (response_array[0] == 0) {
            cout << "Enter valid input" << std::endl;
        }
        else {
            cout << "Enter valid input" << std::endl;
        }
        
        std::stringstream convert(response);
        convert >> i;
        }
        
    }
    return i;
}
/*********************************************************************
 ** Function: hitCard()
 ** Description: Checks if user input is valid ie 1-2. This either reruns
 ** a loop or ends the loop and moves on to the next player
 ** Parameters: Int entry is a value used to control a while loop
 ** Pre-Conditions: Int entry must be set to 1 to start the loop
 ** Post-Conditions: User input has all valid inputs
 *********************************************************************/
int hitCard (int *entry){
    int i = 0;
    std::string response;
    int error_handle = 1;
    
    while ( error_handle == 1) {
        // if a character is not 1 and 2, rerun user input
        int count = 0;
        getline(cin, response);
        int response_length = response.length();
        if (response_length == 0){
            cout << "Enter valid input" << endl;
        }
        else {
        char response_array [ response_length + 1 ];
        strcpy (response_array, response.c_str());
        
        for ( i = 0; i < response_length; i++) {
            if ( int (response_array[i]) < 49 || int (response_array[i]) > 50 ) {
                count++;
            }
        }
        
        if (count == 0) {
            // if character is 1 or 2, continue with adventure
            error_handle = 0;
        }
        else if (response_array[0] == 0) {
            cout << "Enter valid input" << std::endl;
        }
        else {
            cout << "Enter valid input" << std::endl;
        }
        
        std::stringstream convert(response);
        convert >> *entry;
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int gameOver = 1; //if the dealer is bankrupt or not
    while (gameOver == 1){
        int bankruptPlayers = 0; //if the number of bankrupt Players == number of players, game is over
        int cardValue = 0; //temporary value to store the card value dealt in a round
        int dealerCardValue = 0; //temporary value to store the card value dealt in a round
        int dealerHit = 1; //used to track if the dealer should continue to hit
        srand(time(NULL));
        int playerData[5][3]= {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}; // each row is a distinct player and the dealer is the first row. each column is the bank total, betting amount, and hand total
        cout << "How many players are playing?" << endl;
        int numOfPlayer = playerNumber(); //lets the for loop know when to stop
        
        for (int i = 1; i < numOfPlayer+1; i++){ //Stores player bank amounts in first column of playerData[]
            cout << "How much does Player " << i << " start off with?" << endl;
            playerData[i][0] = user_input();
        }
        cout << "How much does the dealer start out with?" << endl;
        playerData[0][0] = user_input();
        //ensuring all betting rules are maintained
    for (int i = 1; i < numOfPlayer+1; i++){ //Tracks how much a player is willing to bet in a
        //round in second coloumn of playerData[]
        bool validInput = false;
        cout << "Player " << i << " has " << playerData[i][0] << " in the bank" << endl;
        if (playerData[i][0] != 0){ //makes sure player is not bankrupt
        cout << "How much does Player " << i << " bet this round?" << endl;
            while (validInput == false){
                playerData[i][1] = user_input();
                if (playerData[i][1] > playerData[i][0]){ //makes sure player is not betting more
                    //than they have
                    cout << "You don't own that much" << endl;
                }
                else{
                    validInput = true;
                }
            }
        }
    }
    //dealing out the hand for player
    for (int i = 1; i < numOfPlayer+1; i++){ //Tracks the curent hand total of each player
        int hitAgain = 1;
        
        while (hitAgain == 1) {
        cardValue = rand() % 10 + 1;
        cout << "Player " << i << " got a card value of " << cardValue << endl;
        playerData[i][2] += cardValue;
        cout << "Their hand total is " << playerData[i][2] << endl;
            if (playerData[i][2] > 21){
                cout << "Player " << i << " busted" << endl;
                hitAgain = 2;
            }
            else{
        cout << "1-Hit \n" << "2-Stop" << endl;
        hitCard(&hitAgain);
            }
            
        }
    }
    
    //dealers hand
    while (dealerHit == 1){
        dealerCardValue = rand() % 10 + 1;
        cout << "Dealer got a card value of " << cardValue << endl;
        playerData[0][2] += dealerCardValue;
        cout << "The Dealers hand total is " << playerData[0][2] << endl;
        if (playerData[0][2] > 16){
            dealerHit = 0;
        }
        if (playerData[0][2] > 21){
            cout << "Dealer busted" << endl;
            dealerHit = 0;
        }
    }
    
    //comparing card value
    for (int i = 1; i < numOfPlayer+1; i++){
        //if player busted, they automatically lose
        if (playerData[i][2] > 21){
            playerData[i][0] -= playerData[i][1];
            playerData[0][0] += playerData[i][1];
        }
        //if the dealer busts, all players win
        else if (playerData[0][2] > 21){
            playerData[i][0] += playerData[i][1];
            playerData[0][0] -= playerData[i][1];
        }
        //if player has higher number, player wins the bet (playerData[i][2])
        else if (playerData[i][2] > playerData[0][2]){
            playerData[i][0] += playerData[i][1];
            playerData[0][0] -= playerData[i][1];
        }
        //if player has lower number, dealer wins the bet (playerData[0][0])
        else if (playerData[i][2] < playerData[0][2]){
            playerData[i][0] -= playerData[i][1];
            playerData[0][0] += playerData[i][1];
        }
    }
    //end the game if the dealer is bankrupt
    if (playerData[0][0] <= 0){
        cout << "The dealer is bankrupt" << endl;
        gameOver = true;
    }
    for (int i = 1; i < numOfPlayer+1; i++){
        if (playerData[i][0] == 0){
            bankruptPlayers++;
        }
    }
        if (bankruptPlayers == numOfPlayer){
            gameOver = true;
        }

        for (int e = 1; e < numOfPlayer+1; e++){
            cout << "Player" << e << " had" << playerData[e][0] << endl;
        }
        cout << "Dealer had" << playerData[0][0]<<endl;
        cout << "Would you like to play again? \n" << "1-Play Again \n" << "2-Quit" << endl;
        hitCard(&gameOver);
    }
    return 0;
}
