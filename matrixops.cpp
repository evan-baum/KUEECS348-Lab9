#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int printMatrix(string fileName)
{
    ifstream matxFile(fileName);
    string line;

    if (matxFile.is_open())
    {
        getline(matxFile, line);
        int matxNum = stoi(line), matxLineNum = 0;
        string matx[matxNum + 1][matxNum + 1];

        while (getline(matxFile, line))
        {
            size_t pos_start = 0, arr_pos = 0, pos_end;
            string token;

            while ((pos_end = line.find(' ', pos_start)) != std::string::npos)
            {
                token = line.substr(pos_start, pos_end - pos_start);
                pos_start = pos_end + 1;
                matx[matxLineNum][arr_pos] = token;
                arr_pos++;
            }

            matx[matxLineNum][arr_pos] = line.substr(pos_start);
            matxLineNum++;
        }

        for(int i; i < matxNum; i++) {
            for(int j; j < matxNum; j++) {
                cout << matx[i][j];
            }
            cout << '\n';
        }
    }
    return 1;
}

int main() {
    printMatrix("matx.txt");
}