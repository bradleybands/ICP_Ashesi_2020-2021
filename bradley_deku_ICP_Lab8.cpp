// Example program
#include <iostream>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

int N = 6;
int D[6][6];
int C[36];

int temp_array[2];


//Task A
int LinearIndx(int i, int j){

    int index_1D = ((i*i) + i)/2 + j;
    return index_1D;  //Returns 1D index from the given 2D indices
    }


//Task B
tuple<int, int> InverseIdx(int D[6][6], int index_1dB, int C[36]){
      for(int i = 0; i <6; i++ ){
          for(int j = 0; j < 6; j++){
            if (j<=i){
                    int index_1dC = (((pow(i,2))+i)/2) + j;
                    if (index_1dC == index_1dB){
                        temp_array[0] = i;
                        temp_array[1] = j;

                          return {temp_array[0], temp_array[1]};
                    }
            }
          }
      }
      return {temp_array[0], temp_array[1]};  //Returns the two 2D indices as a tuple
 }












int main() {

    //Main For loop which increments the N value by 2
    //To obtain values of 8, 32 and 128
    //Entire loop generates three lower triangular matrices

    for(int i = 3; i < 8; i +=2){


        int powVal = pow(2,i);

        int A[powVal][powVal];  //A[][]
        int B[powVal*powVal];   //B[]
        int temp = 0;   //Temporary value that represents the index of B[]


        //Generating random numbers to fill the lower triangular matrix
        for(int m = 0; m < (powVal); m++){
            for(int n = 0; n < powVal; n++){

                if(n <= m){

                    A[m][n] = rand()%1000;


                    }
                else{

                  A[m][n] = 0;

                    }

                }

            }

        //Print first 20 elements of A[][]

        cout<< "FIRST 20 ELEMENTS ARE\n\n: "<< endl;
        for(int p = 0; p < powVal; p++ ){

            for(int q = 0; q < powVal; q++){

                if(A[p][q] != 0  ){
                    B[temp]= A[p][q];
                    temp++;
                }

                if(A[p][q] != 0 && p < 6 && q < 5 ){
                cout<< A[p][q] << "              Indices = (" << p<< "," << q << ")" <<endl;
                }
            }

            }

        cout<< "\n\n\nMAT 2 VALUES\n\n"  << endl;


        //Print the first 20 elements of B[]
        for(int s = 0; s < powVal; s++){

            if (powVal > 20){
            cout<< B[LinearIndx(0,s)]<<endl;
            }
            else{
                for(int t = 0; t < 6; t++) {

                        cout<< B[LinearIndx(t,s)] << "              Indices =  "<< LinearIndx(t,s) << endl;

                }
                }

        }

        //Shows completion of main loop
          cout<< "MATRIX A[" << powVal << "][" << powVal << "] COMPLETE \n\n\n\n" << endl;

    }
}
