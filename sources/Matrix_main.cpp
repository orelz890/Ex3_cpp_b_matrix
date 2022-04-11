// #include "Matrix.hpp"
// #include <limits.h>


// // How to run: g++ -o a.out Matrix.cpp Matrix_main.cpp Matrix.hpp
// using namespace std;

// std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};

// std::string creat_mat_format(std::string data){
//     for (int i = 0; i < data.size(); i++){
//         if(data.at(i) == '|'){
//             data[i] = ' ';
//         }
//     }
//     return data;
// }
// namespace zich{
//     void action(int act, Matrix &mat, Matrix &mat2){
//         switch (act){
//         case 0:
//             exit(0);
//         case 1:

//             break;
//         case 2:

//             break;
//         case 3:

//             break;
//         case 4:

//             break;
//         case 5:

//             break;
//         case 6:

//             break;
//         case 7:

//             break;
//         case 8:

//             break;
//         case 9:

//             break;
//         case 10:

//             break;
//         case 11:

//             break;
//         case 12:

//             break;
//         case 13:

//             break;
//         case 14:

//             break;            
//         default:
//             break;
//         }
//     }
// }


// int main(){
//     // std::string data;
//     // std::string data2;

//     // cout << "Chose row & col size\n";
//     // int row = 0;
//     // int col = 0;
//     // cin >> row >> col;

//     // zich::Matrix a{row, col};

//     // cout << "Enter matrix data in this format\n"
//     //     <<"example 2x2 ==> [val1|val2],|[val3|val4]\n";
//     // cin >> data;
//     // data = creat_mat_format(data);
//     // std::stringstream is1;
//     // is1 << data;
//     // is1 >> a;

//     // zich::Matrix b{row, col};
//     // cout << "Enter the next matrix data\n";
//     // cin >> data2;
//     // data2 = creat_mat_format(data2);
//     // std::stringstream is2;
//     // is2 << data2;
//     // is2 >> b;

//     // cout << "Enter an action num:\n"
//     //     << "exit: 0,\n ==: 1, <=: 2, >=: 3, >: 4, <: 5\n"
//     //     << "mat*mat: 6, scalar*mat: 7, mat*=mat: 8, mat*=scalar\n"
//     //     << "mat-mat: 9, mat-=mat: 10, -mat=: 11\n"
//     //     << "mat++: 12, ++mat: 13, mat--: 14, --mat: 15\n";
    
//     // while (1){    
//     //     int act;
//     //     cin >> act;
//     //     zich::action(act,a ,b);
//     // }


//     vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
//     zich::Matrix mat_identity_3(identity_3,3,3);
//     vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
//     vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1

//     vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
//     vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
//     vector<double> _vec_ = {1,1,1,1,1,1,1,1,1,1,1,1};//4x3

//     zich::Matrix _mat_(_vec_, 4, 3);
//     zich::Matrix mat1(vec1, 3,3);
//     zich::Matrix mat_arr(arr,3,3);
//     zich::Matrix mat2(vec2,3,4);
//     zich::Matrix mat_identity_4(identity_4,4,4);

//     // cout << mat1*mat_identity_3;
//     // cout << mat_identity_3*mat1;

//     // cout<< mat2*_mat_;

//     // cout << _mat_*mat2;
//     // mat2*=_mat_;
//     // _mat_*=mat2;

//     // cout <<_mat_;
//     // std::vector<double> identity = {1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     // zich::Matrix mat20{3,4};

//     // istringstream is{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
//     // is >> mat20;
//     // // mat1==mat_cin;
//     // cout << mat20;
//     std::vector<double> twoX2 = {3, 3, 2, 2};

//     zich::Matrix m9{twoX2 , 2, 2};
//     std::stringstream os;
//     os << m9 << endl;
//     cout << os.str();

//     return 0;
// }
