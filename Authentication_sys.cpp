// ofstream - Creates and writes to files
// ifstream - Reads from files
// fstream	- A combination of ofstream and ifstream: creates, reads, and writes to files


#include <iostream>
#include <fstream> // used for file handling operations, allows us to work with files
#include <sstream> // enables interopertion btw stream buffer and string object
#include <string>

using namespace std;

int main(){
    int a;
    int i = 0;
    string text, old, username, password0, password1, password2, pass, user, word, word1;
    string creds[2], cp[2];
    cout << "********** User Information Authentication System **********" << endl << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Change Password" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "************************************************************" << endl << endl;

    do{
        cout << "Chose an option from the menu - ";
        cin >> a;
        switch(a)
        {
            case 1:
            {
                cout << "********** Register **********" << endl << endl;
                cout << "Enter username: " << endl;
                cin >> username;
                cout << "Enter password: " << endl;
                cin >> password0;

                // ofstream is used to open a file to write something in it
                // storing username, password and age in the file
                ofstream of1; // creating an object of ofstream class
                of1.open("user_profile.txt");
                if(of1.is_open()){
                    of1 << username << "\n";
                    of1 << password0;
                    cout << "Registration successful!" << endl << endl;
                }
            break;
            }

            case 2:
            {
                cout << "********** Login **********" << endl << endl;

                // ifstream is used to open a file to read something from it
                ifstream of2;
                of2.open("user_profile.txt");
                
                cout << "Enter username: " << endl;
                cin >> user;
                cout << "Enter password: " << endl;
                cin >> pass;

                if(of2.is_open()){
                    while(!of2.eof()){ // eof - end of file function
                        while(getline(of2, text)){  // used to read file line by line
                            istringstream iss(text); // used to stream the string and store using the extraction operator
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        if(user == creds[0] && pass == creds[1]){
                            cout << "Welcome, you are now logged in!" << endl << endl;

                            cout << "Your profile - " << endl;
                            cout << "Username: " + username << endl;
                            cout << "Password: " + password0 << endl << endl;
                        }
                        else{
                            cout << "Invalid credentials" << endl << endl;
                            cout << "Press 2 to try again" << endl;
                            cout << "Press 3 to change password" << endl;
                            break;
                        }
                    }
                }

            break;
            }
            
            case 3:
            {
                i = 0;

                cout << "********** Change Password **********" << endl << endl; 

                cout << "Enter old password: " << endl;
                cin >> old;

                ifstream of0;
                of0.open("user_profile.txt");

                if (of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss >> word1;   // storing data in word1
                            cp[i] = word1;
                            i++;
                        }

                        if (old == cp[1]){
                            of0.close();

                            ofstream of1;
                            if(of1.is_open()){
                                cout << "Enter new password: " << endl;
                                cin >> password1;
                                cout << "Enter new password again: " << endl;
                                cin >> password2;

                                if (password1 == password2){
                                    of1 << cp[0] << "\n";
                                    of1 << password1;
                                    cout << "Password changed successfully!";
                                }
                                else{
                                    of1 << cp[0] << "\n";
                                    of1 << old;
                                    cout << "Password do not match" << endl;
                                }
                            }
                        }
                        else{
                            cout << "Please enter valid password" << endl;
                            break;
                        }
                    }
                }

            break;
            }
            
            case 4:
            {
                cout << "********** Thank you! **********";
            
            break;
            }
            
            default:
            cout << "Enter valid option from the menu";
        }
    } 
    while (a != 4);
    return 0;
}