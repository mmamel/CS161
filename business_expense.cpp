/*********************************************************************
 ** Program Filename: Business_expense.cpp
 ** Author: Doyen
 ** Date: 02/17/2019
 ** Description: User will be prompted for all financial transactions
 **during their business trip and the total cost and total reimbursement
 **value will be calcualted at the end.
 ** Input: User will input number of days, departure time, arrival time,
 ** cost of airfare, cost of conference fee, transportation cost, and
 ** food costs.
 ** Output: Total expense for the trip and total reimbursment amount
 *********************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

/*********************************************************************
 ** Function: period_checker(string *user_input)
 ** Description: Finds the period in a string input and checks if
 ** there are less than 2 digits after it i.e. is the monetary value
 ** for cents a possible value.
 ** Parameters:pointer to a string
 ** Pre-Conditions: input must be a read using a pointer to a string
 ** containing only 0-9 or . chars
 ** Post-Conditions: input will be in the form ---.XX i.e. value of
 ** cents will be between 0 - 99.
 *********************************************************************/
int period_checker(string *user_input){
    int valid = 0;
    int index = user_input -> find('.');
    if(index+3 == user_input->size() || index+2 == user_input->size()){
        valid = 1;
    }
    else{
        cout << "Enter valid input" << endl;
    }
    return valid;
}

/*********************************************************************
 ** Function: currency_checker
 ** Description: checks if user input only contains chars betweeon 0-9
 ** or '.'
 ** Parameters: pointer to a string
 ** Pre-Conditions: pointer to an empty string must be initialized
 ** Post-Conditions: user_input will only contain chars between 0-9 or .
 *********************************************************************/
double currency_checker(string *user_input){
    int good_input = 0;
    while(good_input == 0){
        int counter = 0;
        int period_counter = 0;
        getline(cin, *user_input);
        if(user_input->size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
            for(int i = 0; i < user_input->size(); i++){
                //checks for numbers between 0-9
                if(int(user_input->at(i)) < 48 || int(user_input->at(i)) > 57){
                    counter++;
                }
                //accounts for '.' char
                if(user_input->at(i) == '.'){
                    counter--;
                    period_counter++;
                }
            }
            if(counter == 0){
                if(period_counter == 1){
                    good_input = period_checker(user_input);
                }
                else{
                    good_input = 1;
                }
            }
            
            else{
                cout << "Enter valid input" << endl;
            }
        }
    }
    return atof(user_input->c_str());
}
/*********************************************************************
 ** Function: reimburse_checker
 ** Description: calculates the maximum reimbursement for a given cost
 ** Parameters: pointer to running total of reimbursement value, pointer
 ** to a string, and the maximum reimbursement for a given cost
 ** Pre-Conditions: user input must be a valid monetary value
 ** Post-Conditions: value added to total will be between 0 - max
 *********************************************************************/
void reimburse_checker(float *reimburse_total, string *user_input, float max){
    float convert = atof(user_input->c_str());
    if (convert >= max){
        *reimburse_total += max;
    }
    else{
        *reimburse_total += convert;
    }
}

/*********************************************************************
 ** Function: reimburse_checker
 ** Description: calculates the maximum reimbursement for a given cost
 ** Parameters: pointer to running total of reimbursement value, 1-4
 ** indicating car type, duration of trip, miles driven during trip
 ** total cost of transportation
 ** Pre-Conditions: user must enter 1-4 to specificy car type, total
 ** cost can't be negative, days must be > 0.
 ** Post-Conditions: value added to total will be between 0 - max
 *********************************************************************/
void reimburse_checker(float *reimburse_total, int car_type, int days, float miles_total, float total){
    float max = 0;
    if (car_type == 1){
        max = (20 * days) + (miles_total * 0.24);
    }
    else if (car_type == 2){
        max = (25 * days) + (miles_total * 0.27);
    }
    else if (car_type == 3){
        max = (30 * days) + (miles_total * 0.32);
    }
    else if (car_type == 4){
        max = (50 * days) + (miles_total * 0.45);
    }
    if (total >= max){
        *reimburse_total += max;
    }
    else{
        *reimburse_total += total;
    }
}
/*********************************************************************
 ** Function: days_input
 ** Description: checks if input contains a range of chars
 ** Parameters: ints that represent range of acceptable ascii values
 ** Pre-Conditions: n/a
 ** Post-Conditions: input will be a range of specified chars
 *********************************************************************/
int days_input(int min, int max){
    int good_input = 0;
    string user_input;
    while (good_input == 0){
        int counter = 0;
        getline(cin, user_input);
        if(user_input.size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
        //checks if each character inputed is between 0-9
        for (int i = 0; i < user_input.size(); i++){
            if (int(user_input.at(i)) <min|| int(user_input.at(i)) > max){
                counter++;
            }
        }
            //checks edge case of first number being 0
        if (counter > 0 || user_input.at(0) == '0'){
            cout << "Enter valid input" << endl;
        }
        else
        {
            good_input = 1;
        }
        }
    }
    return atoi(user_input.c_str());
}

/*********************************************************************
 ** Function: time_input
 ** Description: checks if input is a valid time value in form 00.00
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: first number is between 0-2, second is 0-9, third
 ** is '.', 4th is 0-6, 5th is 0-9.
 *********************************************************************/
float time_input(){
    int good_input = 0;
    string user_input;
    while (good_input == 0){
        getline(cin, user_input);
        if (user_input.size() == 5 && int(user_input.at(0)) > 47 && int(user_input.at(0)) < 51 && int(user_input.at(1)) > 47 && int(user_input.at(1)) < 58 && int(user_input.at(2)) == '.' && int(user_input.at(3)) > 47 && int(user_input.at(3)) < 54 && int(user_input.at(4)) > 47 && int(user_input.at(4)) < 58){
            //checks edge case where first number is 2 so the second must be 0-4.
            if(user_input.at(0) == '2' && (int(user_input.at(1)) < 48 || int(user_input.at(1)) >52)){
                cout << "Enter valid input" << endl;
            }
            else{
                good_input = 1;            }
        }
        else{
            cout << "Enter valid input" << endl;
        }
    }
    return atof(user_input.c_str());
}

/*********************************************************************
 ** Function: air_input
 ** Description: checks if user input is valid and adds to running total
 ** Parameters: pointer to total expense and total reimbursment, and
 ** pointer to string
 ** Pre-Conditions: pointers must hold address to different variables
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void air_input(float *total_expense, float *total_reimburse, string *user_input){
    int good_input = 0;
    cout << "How much was the airfare in US $?" << endl;
    while(good_input == 0){
        int counter = 0;
        int period_counter = 0;
        getline(cin, *user_input);
        if(user_input->size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
            // checks if value is between 0-9
            for(int i = 0; i < user_input->size(); i++){
                if(int(user_input->at(i)) < 48 || int(user_input->at(i)) > 57){
                    counter++;
                }
                if(user_input->at(i) == '.'){
                    counter--;
                    period_counter++;
                }
            }
            if(counter == 0){
                if(period_counter == 1){
                    //checks if cents value is between 0-99
                    good_input = period_checker(user_input);
                }
            else{
                    good_input = 1;
                }
            }
            
            else{
                cout << "Enter valid input" << endl;
            }
        }
    }
    *total_expense += atof(user_input->c_str());
    *total_reimburse += atof(user_input->c_str());
}

/*********************************************************************
 ** Function: conference_input
 ** Description: checks if input is valid dollar amount and adds to total
 ** Parameters: pointer to total expense and total reimbursment, and
 ** pointer to string
 ** Pre-Conditions: pointers must hold address to different variables
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void conference_input(float *total_expense, float *total_reimburse, string *user_input){
    int good_input = 0;
    cout << "What was the cost of conference fees?" << endl;
    while(good_input == 0){
        int counter = 0;
        int period_counter = 0;
        getline(cin, *user_input);
        if(user_input->size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
            for(int i = 0; i < user_input->size(); i++){
                if(int(user_input->at(i)) < 48 || int(user_input->at(i)) > 57){
                    counter++;
                }
                if(user_input->at(i) == '.'){
                    counter--;
                    period_counter++;
                }
            }
            if(counter == 0){
                if(period_counter == 1){
                    good_input = period_checker(user_input);
                }
                else{
                    good_input = 1;
                }
            }
            
            else{
                cout << "Enter valid input" << endl;
            }
        }
    }
    *total_expense += atof(user_input->c_str());
    *total_reimburse += atof(user_input->c_str());
}
/*********************************************************************
 ** Function: if_taxi
 ** Description: checks if user input is valid and adds to running total
 ** Parameters: pointer to total expense and total reimbursment,
 ** pointer to string, and days spent on trip
 ** Pre-Conditions: pointers must hold address to different variables,
 ** and days must be initialized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void if_taxi(float *total_expense, float *total_reimburse, string *user_input, int days){
    for(int i = 1; i < days+1; i++){
        int good_input = 0;
        cout << "Enter taxi cost for day " << i << endl;
        while(good_input == 0){
            int counter = 0;
            int period_counter = 0;
            getline(cin, *user_input);
            if(user_input->size() == 0){
                cout << "Enter valid input" << endl;
            }
            else{
                for(int i = 0; i < user_input->size(); i++){
                    if(int(user_input->at(i)) < 48 || int(user_input->at(i)) > 57){
                        counter++;
                    }
                    if(user_input->at(i) == '.'){
                        counter--;
                        period_counter++;
                    }
                }
                if(counter == 0){
                    if(period_counter == 1){
                        good_input = period_checker(user_input);
                    }
                    else{
                        good_input = 1;
                    }
                }
                
                else{
                    cout << "Enter valid input" << endl;
                }
            }
        }
        *total_expense += atof(user_input->c_str());
        reimburse_checker(total_reimburse, user_input, 6);
    }
}

/*********************************************************************
 ** Function: if_rental
 ** Description: calculates total expense and total reimbursment
 ** based on expenditures, type of car and miles driven
 ** Parameters: pointer to total expense and total reimbursment, and
 ** pointer to string, and days spent on trip
 ** Pre-Conditions: pointers must hold address to different variables
 ** days must be initialized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void if_rental(float *total_expense, float *total_reimburse, string *user_input, int days){
    cout << "How much did you spend in total for the rental car?" << endl;
    float rental_total = currency_checker(user_input);
    cout << "How much did you spend on gas?" << endl;
    float gas_total = currency_checker(user_input);
    cout << "What type of car did you rent? \n 1-Sedan \n2-SUV \n3-Van \n4-Convertible" << endl;
    int car_type = days_input(49, 52);
    cout << "What was the total amount of miles driven?";
    float miles_total = currency_checker(user_input);
    float total_car_cost = (rental_total + gas_total);
    *total_expense += total_car_cost;
    reimburse_checker(total_reimburse, car_type, days, miles_total, total_car_cost);
    
}

/*********************************************************************
 ** Function: parking_input
 ** Description: checks if user input is valid and adds to running total
 ** by iterating through days and asking for parking fees
 ** Parameters: pointer to total expense and total reimbursment, and
 ** pointer to string, number of days spent on trip
 ** Pre-Conditions: pointers must hold address to different variables
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void parking_input(float *total_expense, float *total_reimburse, string *user_input, int days){
    float parking_cost = 0;
    for(int i = 0; i < days; i++){
        cout << "Enter parking cost for day " << i+1 << endl;
        parking_cost = currency_checker(user_input);
        cout << "This is parking cost" << parking_cost << endl;
        *total_expense += parking_cost;
        reimburse_checker(total_reimburse, user_input, 6);
        
    }
}

/*********************************************************************
 ** Function: vehicle_input
 ** Description: checks if user input is one or two, then calls on
 ** the appropriate function to handle expenditures for taxi or rental
 ** Parameters: pointer to total expense and total reimbursment, and
 ** pointer to string, and numbe of days spent
 ** Pre-Conditions: pointers must hold address to different variables
 ** days must be initialized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void vehicle_input(float *total_expense, float *total_reimburse, string *user_input, int days){
    int good_input = 0;
    cout << "What vehicle did you use \n 1-Rental \n 2-Taxi" << endl;
    while(good_input == 0){
        int counter = 0;
        getline(cin, *user_input);
        if(user_input->size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
            //checks if each character inputed is between 0-9
            for (int i = 0; i < user_input->size(); i++){
                if (int(user_input->at(i)) < 49 || int(user_input->at(i)) > 50){
                    counter++;
                }
            }
            if (counter > 0 || user_input->at(0) == '0'){
                cout << "Enter valid input" << endl;
            }
            else
            {
                good_input = 1;
            }
        }
    }
    if(*user_input == "1"){
        if_rental(total_expense, total_reimburse, user_input, days);
        parking_input(total_expense, total_reimburse, user_input, days);
}
    else if(*user_input == "2"){
        if_taxi(total_expense, total_reimburse, user_input, days);
    }
}

/*********************************************************************
 ** Function: hotel_input
 ** Description: checks if user input is valid and adds to running total
 ** by iterating through nights and asking for hotel fee
 ** Parameters: pointer to total expense and total reimbursment
 ** pointer to string, and number of days
 ** Pre-Conditions: pointers must hold address to different variables,
 ** and days must be initalized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void hotel_input(float *total_expense, float *total_reimburse, string *user_input, int days){
    float hotel_Cost = 0;
    for(int i = 0; i < days-1; i++){
        cout << "Enter hotel fee for night " << i+1 << endl;
        hotel_Cost = currency_checker(user_input);
        *total_expense += hotel_Cost;
        reimburse_checker(total_reimburse, user_input, 90);
    }
}
/*********************************************************************
 ** Function: first_food
 ** Description: determines which meals for the first day are allowed
 ** to be counted as an expense, then adds to running totals
 ** Parameters: pointer to total expense and total reimbursment
 ** pointer to string, and time of departure
 ** Pre-Conditions: pointers must hold address to different variables,
 ** and time must be initalized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void first_food(float *total_expense, float *total_reimburse, string *user_input, float time){
    if (time < 7){
        cout << "Enter breakfast fee" << endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 9);
    }
    else{
        cout << "Your breakfast for day 1 is not allowed as an expense" << endl;
    }
    if (time < 12){
        cout << "Enter lunch fee" << endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 12);
    }
    else{
        cout << "Your Lunch for day 1 is not allowed as an expense" << endl;

    }
    if (time < 18){
        cout << "Enter dinner fee" << endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 16);
    }
    else{
        cout << "Your Dinner for day 1 is not allowed as an expense" << endl;
    }
    
}

/*********************************************************************
 ** Function: last_food
 ** Description: determines which meals for the last day are allowed
 ** to be counted as an expense, then adds to running totals
 ** Parameters: pointer to total expense and total reimbursment
 ** pointer to string, and time of arrival
 ** Pre-Conditions: pointers must hold address to different variables,
 ** and time must be initalized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void last_food (float *total_expense, float *total_reimburse, string *user_input, float time, int days){
    if (time > 8){
        cout << "Enter breakfast fee" << endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 9);
    }
    else{
        cout << "Enter breakfast fee" << endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 9);
        cout << "Your breakfast for " << days <<  "is not allowed as an expense" << endl;
    }
    if (time > 13){
        cout << "Enter lunch fee"<< endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 12);    }
    else{
        cout << "Your lunch for " << days <<  "is not allowed as an expense" << endl;
    }
    if (time > 19){
        cout << "Enter dinner fee" << endl;
        float fee = currency_checker(user_input);
        *total_expense += fee;
        reimburse_checker(total_reimburse, user_input, 16);    }
    else{
        cout << "Your dinner for " << days <<  "is not allowed as an expense" << endl;
    }
    
}
/*********************************************************************
 ** Function: food_input
 ** Description: prompts user for each meal between first and last day
 ** and adds cost to running totals
 ** Parameters: pointer to total expense and total reimbursment
 ** pointer to string, number of days, time of departure and arrival
 ** Pre-Conditions: pointers must hold address to different variables,
 ** time and days must be initalized
 ** Post-Conditions: input will be a valid dollar amount
 *********************************************************************/
void food_input(float *total_expense, float *total_reimburse, string *user_input, int days, float depart, float arrive){
    first_food(total_expense, total_reimburse, user_input, depart);
    for(int i = 2; i < days; i++){
        cout << "Enter breakfast fee for day " << i << endl;
        float cost1 = currency_checker(user_input);
        reimburse_checker(total_reimburse, user_input, 9);
        cout << "Enter lunch fee for day " << i << endl;
        float cost2 = currency_checker(user_input);
        reimburse_checker(total_reimburse, user_input, 12);
        cout << "Enter dinner fee for day " << i << endl;
        float cost3 = currency_checker(user_input);
        reimburse_checker(total_reimburse, user_input, 16);
        *total_expense += (cost1 + cost2 +cost3);
        }
    last_food(total_expense, total_reimburse, user_input, arrive, days);
    }



int main(){
    int replay = 1;
    while (replay == 1){
    float total_expense = 0;
    float *splat_expense = &total_expense;
    float total_reimburse = 0;
    float *splat_reimburse = &total_reimburse;
    string user_input = "";
    string *splat_input = &user_input;
    cout << "How many days was the trip?" << endl;
    int days = days_input(48, 57);
    cout << "What time did you depart? Enter in military time i.e. 00.00" << endl;
    float depart_time = time_input();
    cout << "What time did you arrive? Enter in military time i.e. 00.00" << endl;
    float arrival_time = time_input();
    air_input(splat_expense, splat_reimburse, splat_input);
    conference_input(splat_expense,splat_reimburse, splat_input);
    vehicle_input(splat_expense, splat_reimburse, splat_input, days);
    hotel_input(splat_expense, splat_reimburse, splat_input, days);
    food_input(splat_expense, splat_reimburse, splat_input, days, depart_time, arrival_time);
    cout<< "Total expense: " << *splat_expense <<endl;
    cout<< "Total reimbursement: " << *splat_reimburse<<endl;
    cout << "1-Calculate another expense\n2-Quit" << endl;
    replay = days_input(49, 50);
    }
    return 0;
}
