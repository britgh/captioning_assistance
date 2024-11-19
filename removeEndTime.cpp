/// Program to remove timestamp from caption / transcript files
/// Britney Gonzalez Hernandez <gonzab21@unlv.nevada.edu>
/// Last Updated: 2024-11-19

#include <fstream>
#include <iostream>
using namespace std;

void removeTime(fstream &myfile); // function to remove ending time stamps
// function to remove consecutive repeat names in transcript
// function to insert speaker names into captions using transcript file

int main() {
    // retrieve file (for web c++ compiler)
    string filename;
    
    cout << "enter file name: ";
    cin >> filename;
    
    fstream myfile; 
    myfile.open(filename);

    
    // check if file opens successfully
    if (myfile.good()){
        cout << "file works." << endl;
        removeTime(myfile);
    } else {
        cout << "cannot open file." << endl;
    }
    
    myfile.close();
    return 0;
}

void removeTime(fstream &myfile) {
    string input;                       
    
    while (!(myfile.eof())) {           
        streampos prevline = myfile.tellg();    // store location in text prior to getline
        
        getline(myfile, input);                 // retrieve input (new line)
    
        // check if line begins with digit (is timestamp)
        if (isdigit(input[0])) {
            int owLength = input.size() - 11;   // amount to overwrite
            myfile.seekg(prevline);             // go to previous line
        
            myfile.ignore(11);                  // ignore start timestamp
        
            // overwrite remaining line in file
            for (int i = 0; i < owLength; i++) {
                myfile << ' ';
            }
        }
    }
}