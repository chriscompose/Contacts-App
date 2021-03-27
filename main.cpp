//
//  main.cpp
//  Contacts-App
//
//  Created by Christian Cano Delgado on 22/02/2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

int menuOption;

void menu() {
    
    cout << "--------------------------------" << endl;
    cout << "              MENU              " << endl;
    cout << "1 - Create new contact." << endl;
    cout << "2 - Show Contacts." << endl;
    cout << "3 - Close app." << endl;
    cout << "--------------------------------" << endl;
    cout << "Introduce option: ";
    cin >> menuOption;
    
};

void createFile() {
    
    ofstream agenda;
    agenda.open("/Users/christian/Desktop/Agenda/Agenda.txt", ios::out);
    
    if (agenda.fail()){
        cout << "Failed to open file" << endl;
    }
    
    agenda << "--------------------------------" << endl;
    agenda << "            CONTACTS            " << endl;
    agenda << "--------------------------------" << endl;
    agenda << endl;
    
    agenda.close();
    
};

void addContact() {
    
    // Varibles used to create contacts 
    string name;
    string surname;
    string telNumber;
    string contact;
    
    ofstream agenda;
    agenda.open("/Users/christian/Desktop/Agenda/Agenda.txt", ios::app);
    
    if (agenda.fail()){
        cout << "Failed to open file" << endl;
    }
    
    cout << "Add contact's details: " << endl;
    cout << "NAME: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "SURNAME: ";
    getline(cin, surname);
    cout << "PHONE NUMBER: ";
    getline(cin, telNumber);
    contact = "* " + name + " " + surname + ", " + telNumber + ".";
    agenda << contact << endl;
    
    
    // Shows the contacts we saved in the file.
    cout << "Contact saved: " << endl;
    cout << contact << endl;
    
    agenda.close();
    
};

void showContacts() {
    
    string fileContents;
    ifstream agenda;
    agenda.open("/Users/christian/Desktop/Agenda/Agenda.txt", ios::in);
    
    if (agenda.fail()){
        cout << "Failed to open file" << endl;
    }
    
    cout << "--------------------------------" << endl;
    cout << "         SAVED CONTACTS         " << endl;
    cout << "--------------------------------" << endl;
    while (getline(agenda, fileContents)){
        cout << fileContents << endl;
    };
    
    agenda.close();
};

int main() {
    
    createFile();
    
    do {
        
        menu(); // Main menu of the app; we can select different options as user to interact with the app.
        
        switch(menuOption) {
            case 1:
                addContact();
                break;
            case 2:
                showContacts();
                break;
            case 3:
                cout << "--------------------------------" << endl;
                cout << "            APP CLOSED          " << endl;
                cout << "--------------------------------" << endl;
                break;
        };
        
    }
    while (menuOption != 3);
    cout << "--------------------------------" << endl;
    cout << "             THANKS!            " << endl;
    cout << "--------------------------------" << endl;
    
    return 0;
}
