#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class FileScanner {
    public:
    string rfile;
    fstream myFileIn, myFileOut;

    FileScanner(string file){
        rfile = file;
    }

    void read(){
        myFileIn.open("archivo.txt", ios::in);//Read
    if (myFileIn.is_open())
    {
        string line;
        while(getline(myFileIn, line)){
            cout << line << endl;
            myFileOut.open("archivoOut.txt", ios::out);//Write
            if (myFileOut.is_open()){
                myFileOut << line;//Write and go to next line on document
                myFileOut.close();
            }
        }
        myFileIn.close();
    }
    
    }
    
};

int main(){
    FileScanner file("archivo");
    file.read();


    
    system("pause>0");
}