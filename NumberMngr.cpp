#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class ToQuickSort{
    public:
    vector<int>numberArray;

    ToQuickSort(vector<int>lnArray){
        numberArray = lnArray;
    }

    int partition(vector<int>&array,int inicio, int fin){
    int pivote = array[inicio];
    int i = inicio + 1;
    for(int j = i; j <= fin; j++){
        if(array[j] < pivote){
            swap(array[i],array[j]);
            i++;
        }
    }
    swap(array[inicio],array[i-1]);
    return i-1;
    }

    void quickSort(vector<int>&array, int inicio, int fin){
        if(inicio < fin){
            int pivote = partition(array,inicio,fin);
            quickSort(array,inicio,pivote-1);
            quickSort(array,pivote+1,fin);
        }
        
    }

    void printArray(vector<int>array){  
        for(int i = 0; i < array.size(); i++){
            cout << array[i] << " ";
        }
        cout << endl;
    } 

    };


class FileScanner {
    public:
    string rfile;
    fstream myFileIn, myFileOut;
    vector<int> numberArray;

    FileScanner(string file){
        rfile = file;
    }

    void read(){
        myFileIn.open("archivo.txt", ios::in);//Read
        if (myFileIn.is_open())
        {
            string line, value;
            int intValue;
            while(getline(myFileIn, line)){
                while(getline(myFileIn, value, ',')){
                    //---------------------
                    //cout << value << endl;
                    numberArray.push_back(stoi(value));
                    

                    /*myFileOut.open("archivoOut.txt", ios::app);//Write
                    if (myFileOut.is_open()){
                        myFileOut << value << "\n";
                        myFileOut.close();
                    }*/
                    //-------------------------
                }
                for (int i = 0; i < numberArray.size(); i++) {
                    std::cout << numberArray.at(i) << ' ';
                }
                cout << "\n";
                ToQuickSort(numberArray).quickSort(numberArray,0,numberArray.size()-1);
                for (int i = 0; i < numberArray.size(); i++) {
                    std::cout << numberArray.at(i) << ' ';
                }
                myFileOut.open("archivoOut.txt", ios::app);//Write
                    if (myFileOut.is_open()){
                        for (int i = 0; i < numberArray.size(); i++) 
                        {
                            myFileOut << numberArray.at(i) << ",";
                            //std::cout << numberArray.at(i) << ' ';
                        }
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