
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

//Task A

int A[101][101];

//Task B

int count = 0;

int populateArray(int N) {


    //Generating random numbers to fill the lower triangular matrix
      for(int n = 0; n < N; n++){


          int i = rand()%100;
          int j = rand()%100;

          if(A[i][j] == 0){

              A[i][j] = 1;

          }

          else{

              A[i][j] += 1;
          }

      }
      return 0;
    }


//Task C

int searchValidEntries(int XL, int YL, int XH, int YH){
      for (int i = 0; i < 101; i++){
          for(int j = 0; j < 101; j++){
                if(j >= XL && j <= XH && i >= YL-1 && i <= YL + 1){
                  if(A[i][j] > 0){
                    cout<< i << ", "<< j <<"; "<< A[i][j]<<endl;
                  }

                }
          }
      }

return 0;
}


int main()
{
    srand(time(0));

    populateArray(2000);


// Program to read 5 bounding boxes
            cout<< "Printing out first bounding box values: "<< endl;
            searchValidEntries(1, 90, 100, 100);
              cout<< "\nPrinting out second bounding box values: "<< endl;
            searchValidEntries(80, 1, 100, 10);
              cout<< "\nPrinting out third bounding box values: "<< endl;
            searchValidEntries(10, 20, 40, 79);
              cout<< "\nPrinting out fourth bounding box values: "<< endl;
            searchValidEntries(40, 30, 70, 60);
              cout<< "\nPrinting out fifth bounding box values: "<< endl;
            searchValidEntries(50, 50, 70, 70);


}
