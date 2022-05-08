// #include "Matrix.hpp"
// #include <limits.h>


// // How to run: 
// // g++ -o a.out Matrix.cpp Matrix_main.cpp Matrix.hpp
// using namespace std;
// using namespace zich;

// // [1 1 1], [2 2 2]
// std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};
// Matrix mat{2,2};
// Matrix mat2{1,1};

// string data;
// stringstream is1;
// stringstream is2;
// string data2;
// bool temp;
// double scalar;

// void action(int act){

//     switch (act){
//     case 0:
//         exit(0);
//     case 1:
//         temp = (mat == mat2);
//         if (temp){
//             cout << "Left matrix == right one? True\n";
//         }
//         else{
//             cout << "Left matrix != right one? False\n";
//         }
//         break;
//     case 2:
//         temp = (mat <= mat2);
//         if (temp){
//             cout << "Left matrix <= right one? True\n";
//         }
//         else{
//             cout << "Left matrix <= right one? False\n";
//         }
//         break;
//     case 3:
//         temp = (mat >= mat2);
//         if (temp){
//             cout << "Left matrix >= right one? True\n";
//         }
//         else{
//             cout << "Left matrix >= right one? False\n";
//         }
//         break;
//     case 4:
//         temp = (mat > mat2);
//         if (temp){
//             cout << "Left matrix > right one? True\n";
//         }
//         else{
//             cout << "Left matrix > right one? False\n";
//         }
//         break;
//     case 5:
//         temp = (mat < mat2);
//         if (temp){
//             cout << "Left matrix < right one? True\n";
//         }
//         else{
//             cout << "Left matrix < right one? False\n";
//         }
//         break;
//     case 6:
//         cout << (mat * mat2) << "\n";
//         break;
//     case 7:
//         cout << "Left matrix = \n" << (mat*= mat2) <<'\n';
//         break;
//     case 8:
//         cout << (mat-mat) << '\n';
//         break;
//     case 9:
//         cout << (mat-=mat2) << '\n';
//         break;
//     case 10:
//         cout<< "Chose scalar\n";
//         cin >> scalar;
//         cout << (mat*= scalar) << '\n';
//         break;
//     case 11:
//         cout<< "Chose scalar\n";
//         cin >> scalar;
//         cout << (scalar*mat) << '\n';
//         break;
//     case 12:
//         cout << (-mat) << '\n';
//         break;
//     case 13:
//         cout << mat++ << '\n';
//         break;
//     case 14:
//         cout << ++mat << '\n';
//         break;
//     case 15:
//         cout << mat-- << '\n';
//         break; 
//     case 16:
//         cout << --mat << '\n';
//         break;         
//     default:
//         cout << "Chose a num between 0 - 16\n";
//         break;
//     }
// }


// int main(){
    
//     int act;
//     while (1){    
//         // Get the first matrix from the user
//         try{

//             cout << "Enter matrix data in this format\n example 2x2 ==> [val1 val2], [val3 val4]\n";
//             data.clear();
//             getline(cin, data);
//             data += '\n';
//             is1 << data;
//             is1 >> mat;
//             cout << "The mat u entered is:\n" << mat << '\n';
//             fflush(stdout);
//             break;
//         }
//         catch(const std::exception& e){
//             cout<< "The data you entered is not in the correct format.. please read the instructions\n";
//             fflush(stdout);
//         }
//     }

//     while (1)
//     {
//         // Get the desired operation
//         cout << "========================================================";
//         cout << "\nEnter an action num:\n"
//         << "0: exit ,\n 1: == , 2: <= , 3: >= , 4: > , 5: < \n"
//         << "6: mat*mat, 7: mat*=mat ,8: mat-mat , 9: mat-=mat\n"
//         << "10: mat*=scalar , 11: scalar*mat, 12: -mat\n"
//         << "13: mat++, 14: ++mat, 15: mat--, 16: --mat\n";

//         cin >> act;
//         fflush(stdin);

//         // If needed a second matrix get it too
//         try{
//             if (act < 9 ){
//                 cout << "Enter matrix data in this format\n example 2x2 ==> [val1 val2], [val3 val4]\n";
//                 data2.clear();
//                 // Clear the cin 
//                 getline(cin, data2);
//                 fflush(stdin);
//                 // Get the next matrix
//                 getline(cin, data2);
//                 fflush(stdin);                
//                 data2 += '\n';
//                 is2 << data2;
//                 is2 >> mat2;
//                 cout << "The mat u entered is:\n" << mat2 << '\n';
//                 fflush(stdout);
//             }
//             // Do the operation
//             action(act);
//         }
//         catch(const std::exception& e){
//             cout<< "Function " << act <<  " throw us out! " << e.what() << " Try something else..\n";
//             fflush(stdout);
//         }
//     }

//     return 0;
// }
