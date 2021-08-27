#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class PagedArray{
    public:
    fstream myFileOut;
    
    void createPages(vector<int>intArray){
        
        cout << "bruhpage" << "\n";
        myFileOut.open("archivoOut.txt", ios::app);//Write  
        if (myFileOut.is_open()){
            for (int i = 0; i < intArray.size(); i++) 
            {
                myFileOut << intArray.at(i) << ",";
                //std::cout << intArray.at(i) << ' ';
            }
            myFileOut << "\n";
            myFileOut.close();
        }
    }

    
};


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
    fstream myFileIn/*, myFileOut*/;
    vector<int> numberArray;
    PagedArray pArray;

    FileScanner(string file){
        rfile = file;
    }

    void read(){
        cout << "bruhread" << "\n";
        myFileIn.open("archivo.txt", ios::in);//Read
        if (myFileIn.is_open())
        {
            string line, value;
            int intValue;
            int counter = 0;
            while(getline(myFileIn, line)){
                while(getline(myFileIn, value, ',')){
                    //---------------------
                    if (counter < 5) {
                        counter++;
                        cout << "\n" << counter << "\n";
                        cout << "bruhif1" << "\n";
                        numberArray.push_back(stoi(value));
                        for (int i = 0; i < numberArray.size(); i++) 
                        {
                            cout << numberArray.at(i) << ",";
                        }
                        
                    }
                    if (counter == 5){
                        cout << "bruhif2" << "\n";
                        pArray.createPages(numberArray);
                        counter = 0;
                        numberArray.clear();
                    }
                    //-------------------------
                }
                
            }
            pArray.createPages(numberArray);
            myFileIn.close();
        }
        
    }

};


int main(){
    cout << "bruhmain" << "\n";
    FileScanner file("archivo");
    file.read();


    
    system("pause>0");
}