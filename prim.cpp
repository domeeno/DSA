#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int adjacencyMatrix[50][50];
int i, j;

struct Matrix
{
    string MatrixName;
    short MatrixLength;
};

short Matrices;
Matrix Idx[5]; // maximum Matrices that can be stored

//void Ascii();
void requireEnter();
void printMatrix()

//void createMatrix();
//void loadMatrix();
//void editMatrix();
//void showMatrices();
//void saveMatrices();
//void loadMatrices();
//void deleteMatrix();
//void executePrim();

int main()
{
    char key;
    loadMatrices();
    do
    {

        //Ascii();
        //cout << "Number of matrices: " << Matrices << endl;
        cout << "MENU: " << endl;

        cout << "1. Create Matrix" << endl;
        cout << "2. Load Matrix" << endl;
        cout << "3. Edit Current Loaded Matrix" << endl;
        cout << "4. Show all Matrices" << endl;
        cout << "5. Save Matrices in Database" << endl;
        cout << "6. Load Matrices from Database" << endl;
        cout << "7. Remove Matrice from DataBase" << endl;
        //printMatrix

        cout << endl;

        key = getch();

        /*switch(key)
        {
            case '1':
                createMatrix();
                break;
            case '2':
                editMatrix();
                break;
            case '3':
                showMatrices();
                break;
            case '4':
                loadMatrix();
                break;
            case '5':
                deleteMatrix();
                break;
            case '6':
                executePrim();
                break;
        }
        */

        requireEnter();
        system("cls");

    }while(key != 27);

    return 0;
}

//void Ascii() {   };

void requireEnter()
{
    cout << "Click Enter to continue... " << endl;
    while(getch() != 13);
}

void printMatrix()
{
    for(i = 0; i < Matrix[Matrices].MatrixLength; i++)
    {
        for(j = 0; i < Matrix[Matrices].MatrixLength; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void createMatrix()
{
    cout << "The Matrix Requires a name: " << endl << endl << "Matrix: ";
    cin >> Matrix[Matrices].MatrixName;

    cout << "Insert the number of Vertices: " << endl << endl << "Vertices: ";
    cin >> Matrix[Matrices].MatrixLength;

    char key;
    int command;
    do
    {
        i = 0;
        j = 0;

        command = getch();
        switch(command)
        {
            case '37':
                j--;
                break;
            case '39':
                j++;
                break;
            case '38':
                i--;
                break;
            case '40':
                i++;
                break;
        }

        requireEnter();

    }while(key != 27);

    Matrices++;
}

void loadMatrix()
{
    ofstream file("database.txt");


}

//void editMatrix() {   }

//void

void showMatrices()
{
    if(Matrices > 0)
    {
        for (int i = 0; i < Matrices; i++)
        {
            cout << "Matrice index: " << (i+1) << endl;
            cout << "Matrice Name: " << Matrix[i].MatrixName << endl;
            cout << "Vertices: " << Matrix[i].MatrixLength << endl;
        }
    }
    else
        cout << "There is nobody in database."  << endl;
}

void saveMatrices()
{
    ofstream file("database.txt");

    if (file.is_open())
    {
        file << Matrices << endl;

        for (int i = 0; i < Matrices; i++)
        {
            file << Matrix[i].MatrixName << endl;
            file << people[i].MatrixLength << endl;
        }

        file.close();
    }
    else
        cout << "I couldnt save to database" << endl;
}

void loadMatrices()
{
    ifstream file("database.txt");

    if (file.is_open())
    {
        file >> Matrices;

        if (Matrices > 0)
        {
            do
            {
                file >> Matrix[i].MatrixName;
                file >> Matrix[i].MatrixLength;

                i++;
            }while(!file.eof());

            cout << "Matrices have been loaded properly. " << endl;
        }
        else
            cout << "Databse is Empty" << endl;
    }
    else
        cout << "The file database.txt doesnt exist" << endl;
}

void deleteMatrix()
{
    if (Matrices > 0)
    {
        short index;
        cout << "What matrix do you want to remove? Type index: " << endl;
        cin >> index;

        if (Matrices >= index)
        {
            for (short k = index; k < Matrices; k++)
            {
                Matrix[k-1].MatrixName = Matrix[k].MatrixName;
                Matrix[k-1].MatrixLength = Matrix[k].MatrixLength;
            }

            Matrices--;
            saveMatrices();
        }
        else
            cout << "There is nobody like that" << endl;
    }
    else
        cout << "There is nothing to remove" << endl;
}
