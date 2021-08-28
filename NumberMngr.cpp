#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


/// Writes the arrays it recives on the output file
class PagedArray{
    public:
    fstream myFileOut;
    
    /// Writes on the output file the array it recives
    ///
    /// This method recives an array from the FileScanner class
    /// @see readNOrganize()
    void createPages(vector<int>intArray){
        
        myFileOut.open("archivoOut.txt", ios::app);//Write  
        if (myFileOut.is_open()){
            for (int i = 0; i < intArray.size(); i++) 
            {
                myFileOut << intArray.at(i) << ",";
                //std::cout << intArray.at(i) << ' ';
            }
            myFileOut << 0;
            myFileOut << "\n";
            myFileOut.close();
        }
    }

    
};

/// Deploys quicksort to organize the numbers introduced
/// 
/// 
class ToQuickSort{
    public:

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

    void begin(){
        fstream pagedFile;
        vector<int> toOrganize;

        pagedFile.open("archivoOut.txt", ios::in);//Read
        if (pagedFile.is_open()){
            string line, value;
            int intValue;
            int counter = 0;
            while(getline(pagedFile, line)){
                while(getline(pagedFile, value, ',')){
                    toOrganize.push_back(stoi(value));
                }
            }
            pagedFile.close();
            quickSort(toOrganize,0,toOrganize.size()-1);
            printArray(toOrganize);
        }
    }

};

/// Recieves the incoming file, reads, scans and organizes the numbers from the file.  
/// 
/// This class recives a file with numbers from main(), this class will read the numbers from the file, organizes the number into pages and speaks with the PagedArray class to temporaly implement them on the output file.
/// @see createPages()
class FileScanner {
    public:
    string rfile;
    fstream myFileIn;
    vector<int> numberArray;
    PagedArray pArray;

    FileScanner(string file){
        rfile = file;
    }

    ///Reads and organaizes numbers and tells PageArray to write them.
    ///
    ///This method is in charge of recieving a file with numbers, it manages the numbers on arrays and spak with the PageArray class to write them on the output file
    void readNOrganize(){
        myFileIn.open("archivo.txt", ios::in);//Read
        if (myFileIn.is_open())
        {
            string line, value;
            int intValue;
            int counter = 0;
            while(getline(myFileIn, line)){
                while(getline(myFileIn, value, ',')){
                    //---------------------
                    if (counter < 256) {
                        counter++;
                        numberArray.push_back(stoi(value));
                    }
                    if (counter == 256){
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
    string inFile;
    ToQuickSort tQS;

    cout << "mainRunning" << "\n";
    cout << "Por favor introducir el nombre del archivo a leer: " << "\n"; 
    cin >> inFile;
    FileScanner file(inFile);
    file.readNOrganize();

    tQS.begin();
    

    
    system("pause>0");
}