/*********************************************************************
 ** Program Filename: Text Adventure
 ** Author: Magee
 ** Date: 01/16/19
 ** Description: Text adventure with 2 choices and 3 levels. Contains
 ** chance section
 ** Input: 1 and 2 to choose path of adventure
 ** Output: User prompts and adventure events
 *********************************************************************/

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
/*********************************************************************
 ** Function: user_prompt
 ** Description:  Prints out user prompts and checks if user input is
 ** a 1 or 2
 ** Parameters: A string array
 ** Pre-Conditions: A string array exists
 ** Post-Conditions: None
 *********************************************************************/

int user_prompt ( std::string array[] ) {
    
    int i = 0;
    std:: string response;
    int error_handle = 1;
    for ( i = 0; i < 2; i++) {
        
        std::cout << i+1 << " :" << array[i] << std::endl;
        
    }
    while ( error_handle == 1) {
        // if a character is not 1 and 2, rerun user input
        int count = 0;
        std::cin >> response;
        int response_length = response.length();
        char response_array [ response_length + 1 ];
        strcpy (response_array, response.c_str());
        
        for ( i = 0; i < response_length; i++) {
            
            if ( int (response_array[i]) < 49 || int (response_array[i]) > 50 ) {
                
                count++;
                
            }
        }
        
        if ( count == 0 && response_length == 1) {
            // if character is 1 or 2, continue with adventure
            error_handle = 0;
            
        }
        
        else {
            
            std::cout << "Enter valid input" << std::endl;
        }
        
        std::stringstream convert(response);
        convert >> i;
        std::cin.ignore();
        
    }
    
    return i;
    
}



int main(int argc, const char * argv[]) {
    
    int replay = 1;
    srand(time(NULL));
    std::string again[2] = { "Play again" , "Quit" };
    
    while ( replay == 1 ) {
        // user_input() will return into conditions: while and if, to progress through the story
        std::cout << "You are in your room" << std::endl;
        std::string first_prompt[2] ={"Play video games", "Study for your quiz"};
        int first_response = user_prompt ( first_prompt );
        std::cout << "It is now bedtime" << std::endl << "\n";
        
        if ( first_response == 1) {
            
            std::string second_prompt[2] ={"Play more video games", "Make a cheatsheet"};
            int second_response = user_prompt ( second_prompt );
            std::cout << "You realize its time for class" << std::endl << "\n";
            
            if ( second_response == 1) {
                
                std::string third_prompt[2] ={"Take the test", "Peek at your friends paper"};
                int third_response = user_prompt ( third_prompt );
                std::cout << "\n";

                if ( third_response == 1 ) {
                    
                    std::cout << "You get a C-" << std::endl;
                    std::cout << "\n";
                    replay = user_prompt ( again );
                }
                
                else if (third_response == 2) {
                    int randNum = rand() % 10;
                    if (randNum < 2) {
                        std::cout << "You got a few answers and the teacher didn't notice" << std::endl;
                        std::cout << "You got a C" << std::endl << "\n";
                        std::cout << "\n";
                        replay = user_prompt ( again );
                    
                    }
                    
                    else {
                        std::cout << "You got a few answers and but the teacher noticed" << std::endl;
                        std::cout << "You got a F" << std::endl;
                        std::cout << "\n";
                        replay = user_prompt ( again );
                    }

                }

            }
            
            else if ( second_response == 2) {
                
                std::string third_prompt[2] ={"Take the test", "Use your cheatsheet"};
                int third_response = user_prompt ( third_prompt );
                
                if ( third_response == 1 ) {
                    
                    std::cout << "You get a C+" << std::endl;
                    std::cout << "\n";
                    replay = user_prompt ( again );
                }
                
                else if (third_response == 2) {
                    
                    int randNum = rand() % 10;
                    if (randNum < 2) {
                        std::cout << "There are a few answers on your cheatsheet" << std::endl;
                        std::cout << "You got a C" << std::endl;
                        std::cout << "\n";
                        replay = user_prompt ( again );
                        
                    }
                    
                    else {
                        std::cout << "The teacher found your cheatsheet" << std::endl;
                        std::cout << "You got a F" << std::endl;
                        std::cout << "\n";
                        replay = user_prompt ( again );
                    }
                }
            }
        }
        else if ( first_response == 2) {
            
            std::string second_prompt[2] ={"Go to sleep", "Prepare a healthy breakfast and pack your things for tommorow morning"};
            int second_response = user_prompt ( second_prompt );
            std::cout << "You realize its time for class" << std::endl << "\n";
            
            if (second_response == 1) {
                
                std::string third_prompt[2] ={"Finish your test as fast as possible", "Triple check your answers"};
                int third_response = user_prompt ( third_prompt );
                std::cout << "\n";
                
                if (third_response == 1 ) {
                    
                    std::cout << "You got a B-" << std::endl;
                    std::cout << "\n";
                    replay = user_prompt ( again );

                }
                
                else if (third_response == 2 ) {
                    
                    std::cout << "You got a B+" << std::endl;
                    std::cout << "\n";
                    replay = user_prompt ( again );

                }
            }
            
            else if (second_response == 2) {
                
                std::string third_prompt[2] ={"Finish your test as fast as possible", "Triple check your answers"};
                int third_response = user_prompt ( third_prompt );
                
                if ( third_response == 1 ) {
                    std::cout << "You got an A-" << std::endl;
                    std::cout << "\n";
                    replay = user_prompt ( again );
                }
                
                else if ( third_response == 2) {
                    std::cout << "You got an A+" << std::endl;
                    std::cout << "\n";
                    replay = user_prompt ( again );
                }
            }
            
        }
    }
    
    return 0;
}
