//============================================================================
// Name        : project3_VandeVijvere_ccv0004.cpp
// Author      : Colin Vande Vijvere
// AU UserID   : ccv0004
// Description : COMP2710 Software Construction Project 3
// Compile     : g++ project3_VandeVijvere_ccv0004.cpp -std=c++11
// Run         : ./a.out
// Help        : No help received
//============================================================================


#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// fuction to see if a file exists
bool check_file(string file) {
    ifstream stream;

    // check if file exists
    stream.open(file.c_str());
    if (stream.fail()) {
        stream.close();
        return false;
    }
    stream.close();

    return true;
}




//function for reading in file
vector<int> read_file(string file) {
    ifstream stream;
    vector<int> output;
    int i = 0;

    stream.open(file.c_str());
    while (stream >> i) {
        output.insert(output.end(), i);
    }
    //closing file
    stream.close();

    return output;
}




// Merges the two vectors into one vector and sorts
vector<int> merge_and_sort(vector<int> vector1, vector<int> vector2) {
    //creating a vector to return
    vector<int> vector3 = vector1;

    //add vector 2 to the output vector
    vector3.insert(vector3.end(), vector2.begin(), vector2.end());
    
    //sort vector
    sort(vector3.begin(), vector3.end());

    return vector3;
}




// function that creates an output file and writes the output vector to it.
void write_file(string file, vector<int> v) {
    ofstream stream;

    stream.open(file.c_str());
    for (unsigned int i=0; i < v.size(); i++) {
        stream << v.at(i) << endl;
    }
    //closing file
    stream.close();
}




//printing method for the vector
void print_vector(vector<int> v) {
    for (unsigned int i=0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    cout << endl;
}





// ------ MAIN ------ //
int main() {

    //variables

    vector<int> list1;
    vector<int> list2;
    vector<int> outputList;
    string file1;
    string file2;
    string file3;
    

    cout << "*** Welcome to Colin's sorting program ***" << endl;

    // reading in first
    do {
        cout << "Enter the first input file name: ";
        cin >> file1;
    } while (cin.fail() || !check_file(file1));

    list1 = read_file(file1);
    cout << "The list of " << list1.size()
         << " numbers in the file " + file1 + " is:\n";
    print_vector(list1);





    // reading in second file
    do {
        cout << "Enter the second input file name: ";
        cin >> file2;
    } while (cin.fail() || !check_file(file2));

    list2 = read_file(file2);
    cout << "The list of " << list2.size()
         << " numbers in file " + file2 + " is:\n";
    print_vector(list2);





    //calls merge vector to combine and sort the 2 input files
    outputList = merge_and_sort(list1, list2);
    cout << "The sorted list of " << outputList.size() << " numbers is: ";
    for (unsigned int i=0; i < outputList.size(); i++) {
        cout << outputList.at(i) << " ";
    }
    cout << endl;




    //ask for the output file 
    do {
        cout << "Enter the output file name: ";
        cin >> file3;
    } while (cin.fail());

    write_file(file3, outputList);

    cout << "*** Please check the new file - " + file3 + " ***" << endl
         << "*** Goodbye. ***\n";

    return 0;
}