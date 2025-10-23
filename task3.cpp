#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// class for a matrix, stores a vector of vectors of strings as the matrix so it is resizeable
class matrix
{
public:
    vector<vector<string>> matx; // main matrix

    void print()
    { // method to print the matrix
        for (auto i : matx)
        { // iterates across rows
            for (auto j : i)
            {                     // iterates across columns
                cout << j << ' '; // outputs value
            }
            cout << endl;
        }
        return;
    }
};

// function to get a matrix from a file that has trhe number of matrices followed by the two matrices
int getMatrices(string fileName, matrix &matx1, matrix &matx2)
{
    ifstream matxFile(fileName); // gets file stream
    string line;                 // creates a line to read each line of the file

    if (matxFile.is_open()) // checks is the file can be opened or is available
    {
        getline(matxFile, line);               // gets the first line for the size of the matrix
        int matxNum = stoi(line), lineNum = 0; // stores the size of the matrix as a number and a number to determine which line of the matrices it's on

        while (getline(matxFile, line)) // while loop for the whole file
        {
            vector<string> splitLine;      // creates a vector for the row
            size_t pos_start = 0, pos_end; // initializes a start and end to get the next value
            string token;                  // initializes a token to stor ehte next value
            if (!line.empty())
            { // checks that the line is not empty
                while ((pos_end = line.find(' ', pos_start)) != string::npos)
                {                                                        // finds the position of the next space and set is to the end position and checks the string has not ended
                    token = line.substr(pos_start, pos_end - pos_start); // gets the substring starting at the current start position and ending at the found delimiter
                    pos_start = pos_end + 1;                             // changes the start positon to right after the end
                    splitLine.push_back(token);                          // adds value to the splitLine vector
                }

                splitLine.push_back(line.substr(pos_start)); // adds final value of the line

                if (lineNum < matxNum)
                {                                    // checks which matrix should be used using the lineNum value
                    matx1.matx.push_back(splitLine); // adds line to matx1
                }
                else
                {
                    matx2.matx.push_back(splitLine); // adds line to matx2
                }

                lineNum++; // advances lineNum to make sure proper matrix is being added to
            }
        }
    }
    else
    {
        throw std::invalid_argument("file not available"); // throws error if file not found
    }
    return 0;
}

// function to multiply two matrices and return the result
matrix multMatcs(matrix matx1, matrix matx2)
{
    matrix outMatx; // creates the matrix to output

    for (int i = 0; i < matx1.matx.size(); ++i)
    {                        // loops across matx1 rows
        vector<string> line; // creates a line for the new matrix

        for (int j = 0; j < matx2.matx[0].size(); ++j)
        {                // loops across matx2 columns
            int sum = 0; // creates a variable to store sum of rows and columns
            for (int k = 0; k < matx1.matx[0].size(); ++k)
            {                                   // loops across matx1 columns and matx2 rows
                int a = stod(matx1.matx[i][k]); // gets value from matx1
                int b = stod(matx2.matx[k][j]); // gets value from matx2
                sum += a * b;                   // adds values to sum int
            }

            line.push_back(to_string(sum)); // adds sum value to line
        }
        outMatx.matx.push_back(line); // adds line to new matrix
    }
    return outMatx;
}

int main()
{
    string file; // creates a string for the file name

    cout << "Input file name: "; // prompt for file name
    cin >> file;                 // gets file name

    matrix matx1, matx2; // creates two matrices
    try
    {
        getMatrices(file, matx1, matx2); // runs getMatrices with the file name and two blank matrices already instantiated
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what(); // prints if an error is thrown
        return 0;
    }

    matrix multMatx = multMatcs(matx1, matx2); // gets multiplication of matrixes
    multMatx.print();                          // prints multiplied matrix

    return 0;
}