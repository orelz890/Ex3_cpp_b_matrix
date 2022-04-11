// ========================
// my test
// =======================

// #include "doctest.h"
// #include "Matrix.hpp"
// #include <string>
// #include <algorithm>

// using namespace std;
// using namespace zich;

// std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
// std::vector<double> negIdentity = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
// std::vector<double> arr3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
// std::vector<double> arr4 = {3, 1, 1, 3, 4, 0, 0, 1, 3, 2, 2, 0, 0, 0, 0, 0};
// std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};
// std::vector<double> mat_data_neg = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
// std::vector<double> mat_data2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
// std::vector<double> fourX3 = {3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1};
// std::vector<double> twoX2 = {3, 3, 2, 2};

// Matrix matId{identity, 3, 3};
// Matrix matNegId{negIdentity, 3, 3};
// Matrix mat2on2{twoX2, 2, 2};
// Matrix mat3on3{arr3, 3, 3};
// Matrix mat4on4{arr4, 4, 4};
// Matrix mat4on3{fourX3, 4, 3};


// TEST_CASE("Good tests"){


//     Matrix mat{mat_data, 3, 3};
//     Matrix mat2{mat_data2, 3, 3};
//     Matrix mat3{mat_data, 3, 3};
    

// /* ===================================
//     Both prefix & postfix funcs works
//    ===================================
// */

//     // Checking the ++ & -- operators
//     for (size_t i = 2; i < 10; i++){
//         CHECK(--mat2 == mat);
//         CHECK(++mat2 == mat*2);
//         // Checking that the position of the operator matters
//         CHECK(mat2++ == (mat+mat));
//         CHECK(mat2-- != (mat+mat));
//         CHECK(++mat3 == mat * i);
//     }

//     Matrix m = -mat;
//     Matrix m2{mat_data_neg, 3, 3};
//     CHECK(m2 == m);

//     Matrix temp = mat * 2;
//     CHECK(temp == mat2);

//     temp += temp;
//     CHECK(temp == mat2 * 2);

//     temp -= mat2;
//     CHECK(temp == mat2);

// /*
//    ======================
//     Matrix on matrix
//    ======================
// */
//     // Checking that + and += returns the same matrix
//     for (int i = -10; i < 10; i++){
//         Matrix temp2 = mat * (double)i;
//         Matrix temp3 = mat + temp2;
//         mat += temp2;
//         CHECK(temp3 == mat);
//     }


//     // Checking that - and -= returns the same matrix
//     for (int i = -10; i < 10; i++){
//         Matrix temp2 = mat * (double)i;
//         Matrix temp3 = mat - temp2;
//         mat -= temp2;
//         CHECK(temp3 == mat);
//     }
    
//     // Checking that * and *= returns the same matrix
//     for (int i = -10; i < 10; i++){
//         double scalar = (double)i;
//         Matrix temp = mat * scalar;   
//         mat *= scalar;
//         CHECK(temp == mat);
//         temp = mat * mat;
//         mat *= mat;
//         CHECK(temp == mat);
//     }

//     // Mat should be 0 matrix
//     CHECK((mat * 2) == mat);

// /*
//     ==========================
//     Matrix comparing tests
//     ==========================
// */
//     Matrix mat6{mat_data, 3, 3};
//     Matrix mat7{mat_data2, 3, 3};
//     Matrix mat8{mat_data, 3, 3};

//     CHECK(mat6 == mat8);
//     CHECK(mat6 <= mat8);
//     CHECK(mat6 >= mat8);
//     CHECK(mat6 < mat7);
//     CHECK(mat7 > mat6);
//     CHECK(mat6 != mat7);

//     mat8 *= 10;
//     for (int i = 0; i < 20; i++){
//         if (i < 10){
//             CHECK((mat6 * (double)i) < mat8);
//             CHECK((mat6 * (double)i) <= mat8);
//             CHECK((mat6 * (double)i) != mat8);
//         }
//         else if(i == 10){
//             CHECK((mat6 * (double)i) == mat8);
//             CHECK((mat6 + mat6) == (mat6 * 2));
//         }
//         else{
//             CHECK((mat6 * (double)i) >= mat8);
//             CHECK((mat6 * (double)i) > mat8);
//             CHECK((mat6 * (double)i) != mat8);
//         }      
//     }

// /*
//    =========================
//     Input/Output operations
//    =========================
// */
//     // Output:
//     Matrix m9{twoX2 , 2, 2};
//     std::stringstream os;
//     os << m9 << endl;
//     CHECK(os.str() == "[3 3]\n[2 2]\n\n");

//     Matrix m10{identity , 3, 3};
//     std::stringstream os1;
//     os1 << m10 << endl;
//     CHECK(os1.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]\n\n");

//     Matrix m11{fourX3 , 4, 3};
//     std::stringstream os2;
//     os2 << m11 << endl;
//     CHECK(os2.str() == "[3 2 1]\n[3 2 1]\n[3 2 1]\n[3 2 1]\n\n");

//     Matrix m12{mat_data_neg , 3, 3};
//     std::stringstream os3;
//     os3 << m12 << endl;
//     CHECK(os3.str() == "[-1 -1 -1]\n[-1 -1 -1]\n[-1 -1 -1]\n\n");

//     // Input:
//     Matrix m13{2, 2};
//     std::stringstream is;
//     is << "[3 3], [2, 2]";
//     is >> m13;
//     CHECK(m13 == m9);

//     Matrix m14{3, 3};
//     std::stringstream is1;
//     is1 << "[1 0 0], [0 1 0], [0 0 1]";
//     is1 >> m14;
//     CHECK(m14 == m10);

//     Matrix m15{4, 3};
//     std::stringstream is2;
//     is2 << "[3 2 1], [3 2 1], [3 2 1], [3 2 1]";
//     is2 >> m15;
//     CHECK(m15 == m11);

//     Matrix m16{3, 3};
//     std::stringstream is3;
//     is3 << "[-1 -1 -1], [-1 -1 -1], [-1 -1 -1]";
//     is3 >> m16;
//     CHECK(m16 == m12);


// }


// TEST_CASE("Bad input") {

//     Matrix mat{mat_data, 3, 3};
//     Matrix mat2{mat_data2, 3, 3};
//     Matrix mat3{mat_data, 3, 3};
//     std::vector<double> empty_data = {};

// /*
//    ==================
//     Negetive input
//    ==================
// */
        
//     for (int i = -50; i < 0; i++){
//         CHECK_THROWS((Matrix{mat_data, i, 3}));
//         CHECK_THROWS((Matrix{mat_data, 3, i}));
//         CHECK_THROWS((Matrix{mat_data, i, i}));
//         CHECK_THROWS((Matrix{mat_data, i*i, i}));
//         CHECK_THROWS((Matrix{mat_data, i, i*i}));
//     }

// /*
//    ====================
//     Illigal empty case
//    ====================
// */
//     for (int i = 0; i < 50; i++){
//         CHECK_THROWS((Matrix{mat_data, 0, i}));
//         CHECK_THROWS((Matrix{mat_data, i, 0}));  
//         CHECK_THROWS((Matrix{empty_data, i, i}));
//     }
    
// /*
//    ========================================
//     Matrix size not equels Row*Col == size
//    ========================================
// */
//     for (int i = 0; i < 50; i++){
//         CHECK_THROWS((Matrix{fourX3, i, i}));
//         CHECK_THROWS((Matrix{fourX3, i, i + 2}));
//         CHECK_THROWS((Matrix{fourX3, i, i + 3}));
//     }

// }

// TEST_CASE("Illigal operations"){


// /*
//    =======================
//     Diffrent matrix size
//    =======================
// */

//     for (int i = 0; i < 50; i++){
//         Matrix m4on3 = (mat4on3 * i);
//         Matrix m2on2 = (mat2on2 * i);
//         Matrix m3on3 = (mat3on3 * i);
//         Matrix m4on4 = (mat4on4 * i);
// /* 
//    ==================
//    Illigal compering
//    ==================
// */
//         bool t;
//         // Mix even & odd compering
//         CHECK_THROWS(t = (m2on2 < mat3on3));
//         CHECK_THROWS(t = (m3on3 <= mat4on3));
//         CHECK_THROWS(t =(m2on2 != mat3on3));
//         CHECK_THROWS(t = (m3on3 > mat2on2));
//         CHECK_THROWS(t = (m4on3 >= mat3on3));
//         CHECK_THROWS(t = (m2on2 == mat3on3));

//         // Even & even compering
//         CHECK_THROWS(t = (m4on4 >= mat2on2));
//         CHECK_THROWS(t = (m2on2 < mat4on4));
//         CHECK_THROWS(t = (m2on2 > mat4on4));
//         CHECK_THROWS(t = (m4on4 <= mat2on2));
//         CHECK_THROWS(t = (m2on2 != mat4on4));
//         CHECK_THROWS(t = (m4on4 == mat2on2));

// /*
//    =====================
//     Illigal aritmetics:
//    =====================
// */  
//         CHECK_THROWS(m2on2 + mat3on3);
//         CHECK_THROWS(m3on3 - mat4on3);
//         CHECK_THROWS(m2on2 * mat3on3);

//         CHECK_THROWS(m4on4 += mat2on2);
//         CHECK_THROWS(m2on2 -= mat4on4);
//         CHECK_THROWS(m2on2 *= mat4on4);

//         CHECK_THROWS(m3on3 + mat2on2);
//         CHECK_THROWS(m4on3 * mat3on3);
//         CHECK_THROWS(m2on2 - mat3on3);
        
//         CHECK_THROWS(m4on4 -= mat2on2);
//         CHECK_THROWS(m2on2 += mat4on4);
//         CHECK_THROWS(m4on4 *= mat2on2);                
//     }

// /*
//    =========================
//     Input/Output operations
//    =========================
// */

//     // Matrix size < data size

//     // Input:
//     Matrix m13{1, 2};
//     std::stringstream is;
//     is << "[3 3], [2, 2]";
//     CHECK_THROWS(is >> m13);

//     Matrix m14{3, 2};
//     std::stringstream is1;
//     is1 << "[1 0 0], [0 1 0], [0 0 1]";
//     CHECK_THROWS(is1 >> m14);

//     // // Matrix size > data size

//     // Matrix m15{4, 4};
//     // std::stringstream is2;
//     // is2 << "[3 2 1], [3 2 1], [3 2 1], [3 2 1]";
//     // CHECK_THROWS(is2 >> m15);

//     // Matrix m16{10, 10};
//     // std::stringstream is3;
//     // is3 << "[-1 -1 -1], [-1 -1 -1], [-1 -1 -1]";
//     // CHECK_THROWS(is3 >> m16);
// }


// =====================
// student 1
// =====================

// #include <iostream>
// #include <stdlib.h>
// #include <string>
// #include "doctest.h"
// #include <vector>
// #include "Matrix.hpp"
// #include <cmath>

// using namespace std;
// namespace zich{ 

// const int ten = 10;

// TEST_CASE("Case: Invalid multiplication and amount"){
//     vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
//     vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
//     vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1
//     vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
//     vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
//     Matrix mat1(identity_3,3,3);
//     Matrix mat2(vec2,3,4);
//     Matrix mat3(identity_4,4,4);
//     Matrix mat4_arr(arr,3,3);
//     CHECK_THROWS((mat2*mat1));
//     CHECK_THROWS(mat3*mat2);

//     CHECK_THROWS(mat2*mat2);                                       /////////////////////////////////////////

//     CHECK_THROWS(mat4_arr*mat3);
//     CHECK_THROWS(mat2*mat4_arr);
//     for (double i = 0; i < 500; i++)
//     {
//     vector<double> arr1 = {i, i+1, i+2, i+3};//2x2
//     vector<double> arr2 = {i,i,i,i,i,i,i,i,i};//3x3
//     vector<double> arr = {i};//1x1
//     Matrix mat1(arr1,2,2);
//     Matrix mat2(arr2,3,3);
//     Matrix mat(arr,1,1);
//     CHECK_THROWS(mat1*mat2);
//     CHECK_THROWS(mat2*mat1);
//     CHECK_THROWS(mat2+mat1);  
//     CHECK_THROWS(mat1+mat2);
//     CHECK_THROWS(mat+mat2);
//     CHECK_THROWS(mat1+mat);
//     CHECK_THROWS(mat2*mat);      
//     }

//     for (double i = 0; i < ten; i++)
//     {
//     vector<double> arr1 = {i, i+1, i+2, i+3};//2x2
//     for(double j=0; j<ten; j++){
//     vector<double> arr2 = {j};//1x1
//     Matrix mat1(arr1,2,2);
//     Matrix mat2(arr2,1,1);
//     CHECK_THROWS(mat2*mat1);
//     CHECK_THROWS(mat1*mat2);
//     }     
//     }
// }
// TEST_CASE("Case: Invalid Subtraction matrix"){
//     for (double i = 0; i < 500; i++)
//     {
//     vector<double> arr1 = {i, i+1, i+2, i+3};//2x2
//     vector<double> arr2 = {i,i,i,i,i,i,i,i,i};//3x3
//     Matrix mat1(arr1,2,2);
//     Matrix mat2(arr2,3,3);
//     CHECK_THROWS(mat1-mat2);
//     CHECK_THROWS(mat2-mat1);  
//     }
// }

// TEST_CASE("matrix multiplication"){
//     vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
//     Matrix mat_identity_3(identity_3,3,3);
//     vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
//     vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1
//     vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
//     vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
//     vector<double> _vec_ = {1,1,1,1,1,1,1,1,1,1,1,1};//4x3
//     Matrix _mat_(_vec_, 4, 3);
//     Matrix mat1(vec1, 3,3);
//     Matrix mat_arr(arr,3,3);
//     Matrix mat2(vec2,3,4);
//     Matrix mat_identity_4(identity_4,4,4);

//     CHECK(((mat1*mat_identity_3) == mat1));

//     CHECK(((mat_identity_3*mat1) == mat1));               ////////////////////////////////
    
//     CHECK(((mat2*mat_identity_4) == mat2));              /////////////////////////////////
//     CHECK(((mat1+mat_identity_3) == mat_arr));
//     CHECK(((mat2*_mat_) == mat1));                       ///////////////////////

//     for (double i = 1; i < 500; i++)
//     {
//         int random = rand() % 1000;
//         vector<double> vec1 = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
//         Matrix matrix(vec1, 3, 3);
//         CHECK(((matrix * mat_identity_3) == matrix));

//         vector<double> arr1 = {i,i,i,i,i,i,i,i,i};//3x3

//         vector<double> arr = {pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2)};//3x3
//         Matrix mat1(arr1, 3, 3);
//         Matrix mat(arr, 3, 3);
//         CHECK(((mat1*mat1) != mat));
//         CHECK(((mat_identity_3*mat_identity_3) == mat_identity_3));
//     }
// }


// TEST_CASE("Comparisons between matrices"){

//     for (double i = 1; i < 500; i++)
//     {
//         vector<double> vec1 = {i,i,i,i};//2x2
//         vector<double> identity_2 = {i,0,0,i};//2x2
//         vector<double> vec_ = {i,i,i,i,i,i,i,i,i};//3x3
//         Matrix mat(vec1,2,2);
//         Matrix mat_identity_2(identity_2,2,2);
//         Matrix mat_(vec_,3,3);
//         CHECK((mat > mat_identity_2));
//         CHECK((mat >= mat_identity_2));
//         CHECK((mat != mat_identity_2));
//         CHECK((mat_identity_2 < mat));
//         CHECK((mat_identity_2 <= mat));

//         CHECK_THROWS(bool ans = (mat < mat_));
//         CHECK_THROWS(bool ans = (mat <= mat_));
//         CHECK_THROWS(bool ans = (mat == mat_));
//         CHECK_THROWS(bool ans = (mat >= mat_));
//         CHECK_THROWS(bool ans = (mat > mat_));
//         CHECK_THROWS(bool ans = (mat != mat_));

//     }
// }
// TEST_CASE("Subtraction and amount"){
//     int k=1;
//     vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
//     Matrix mat_identity_3(identity_3,3,3);
//     int random = rand() % 1000;
//     for (double i = 0; i < 500; i++)
//     {
//         vector<double> vec1 = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
//         Matrix matrix(vec1, 3, 3);

//         vector<double> vec = {i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k};
//         Matrix mat(vec, 3, 3);

//         vector<double> vec1_minus = {-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random};
//         Matrix matrix_minus(vec1_minus, 3, 3);
        
//         vector<double> vec_sub = {i*random-k,i*random,i*random,i*random,i*random-k,i*random,i*random,i*random,i*random-k};
//         Matrix matrix_sub(vec_sub, 3, 3);

//         vector<double> vec_ = {i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k};
//         Matrix matrix_(vec_, 3, 3);

//         CHECK(((+matrix) != matrix_sub));
//         CHECK(((matrix - mat_identity_3) == matrix_sub));
//     }
// }
// TEST_CASE("CHECK ++ and -- operators"){
//     int k=1;
//     int random = rand() % 1000;
//     for (double i = 0; i < 500; i++)
//     {
//         vector<double> vec1 = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
//         Matrix matrix(vec1, 3, 3);

//         vector<double> v = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
//         Matrix matrix_v(v, 3, 3);

//         vector<double> vec = {i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k,i*random+k};
//         Matrix mat(vec, 3, 3);

//         vector<double> vec1_minus = {-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random,-i*random};
//         Matrix matrix_minus(vec1_minus, 3, 3);
        
//         vector<double> vec_sub = {i*random-k,i*random,i*random,i*random,i*random-k,i*random,i*random,i*random,i*random-k};
//         Matrix matrix_sub(vec_sub, 3, 3);

//         vector<double> vec_ = {i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k,i*random-k};
//         Matrix matrix_(vec_, 3, 3);
//         CHECK(((matrix++) == matrix_v));
//         CHECK(((matrix--) == mat));
//         CHECK(((++matrix) == mat));
//         ++matrix;
//         CHECK(((--matrix) == mat));
//     }
// }
// }


// =================
// student 2
// =================

#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
using namespace zich;

std::vector<double> arr1 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> arr_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};
std::vector<double> arr_c = {2, 0, 0, 0, 2, 0, 0, 0, 2};
std::vector<double> arr_d= {4, 0, 0, 0, 4, 0, 0, 0, 4};
std::vector<double> arr_e= {4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0};
std::vector<double> arr_f= {5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0};
std::vector<double> arr_h= {9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0};

std::vector<double> arr1_1 = {0, 1, 1, 1, 0, 1, 1, 1,0};
std::vector<double> unit_matrix_1 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
std::vector<double> arr_b_1 = {4, 1, 1, 1, 4, 1, 1, 1, 4};
std::vector<double> arr_c_1 = {3, 1, 1, 1, 3, 1, 1, 1, 3};
std::vector<double> arr_d_1= {5, 1, 1, 1, 5, 1, 1, 1, 5};
std::vector<double> arr_e_1= {5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1};
std::vector<double> arr_f_1= {6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1};
std::vector<double> arr_h_1= {10, 1, 1,1, 10, 1, 1, 1, 10, 1, 1, 1};

Matrix mat_un{arr1,3,3};
Matrix mat1{unit_matrix,3,3};
Matrix mat2{arr_b,3,3};
Matrix mat3{arr_c,3,3};
Matrix mat4{arr_d,3,3};
Matrix mat5{arr_e,4,3};
Matrix mat6{arr_f,4,3};
Matrix mat7{arr_h,4,3};

Matrix mat_un_1{arr1_1,3,3};
Matrix mat1_1{unit_matrix_1,3,3};
Matrix mat2_2{arr_b_1,3,3};
Matrix mat3_3{arr_c_1,3,3};
Matrix mat4_4{arr_d_1,3,3};
Matrix mat5_5{arr_e_1,4,3};
Matrix mat6_6{arr_f_1,4,3};
Matrix mat7_7{arr_h_1,4,3};

std::vector<double> arr_cin = {1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1};
Matrix mat_cin{arr_cin,3,4};

bool equalto = false;

TEST_CASE("function + binary matrix and matrix"){

    CHECK_EQ(mat2,mat1+mat3);
    CHECK_EQ(mat3,mat1+mat1);
    CHECK_EQ(mat2,mat1+mat1+mat1);
    CHECK_EQ(mat4,mat1+mat1+mat1+mat1);
    CHECK_EQ(mat4,mat1+mat1+mat3);
    CHECK_EQ(mat4,mat1+mat2);
    CHECK_EQ(mat4,mat3+mat3);

    CHECK_THROWS(mat1+mat5);
    CHECK_THROWS(mat2+mat6);
    CHECK_THROWS(mat3+mat5);
    CHECK_THROWS(mat4+mat6);

    CHECK_NOTHROW(mat5+mat6);
}

TEST_CASE("function += binary matrix and matrix"){
    mat1+=mat3;
    CHECK_EQ(mat2,mat1);
    mat2+=mat1;
    mat4+=mat3;
    CHECK_EQ(mat4,mat2);
    mat1+=mat1;
    CHECK_EQ(mat1,mat2);
    mat1+= mat3;
    mat3+= mat2;
    CHECK_EQ(mat3,mat1);
    mat5+=mat6;
    CHECK_EQ(mat5,mat7);

    CHECK_THROWS(mat5+=mat4);
    CHECK_THROWS(mat6+=mat4);
    CHECK_THROWS(mat7+=mat4);
    CHECK_THROWS(mat5+=mat3);
    CHECK_THROWS(mat6+=mat3);
}

TEST_CASE("function + unary"){
    CHECK_EQ(mat1,+mat1);
}

TEST_CASE("function - binary matrix and matrix"){
    CHECK_EQ(mat2-mat4,mat1-mat3);
    CHECK_EQ(mat4,mat1-mat3+mat2);
    CHECK_EQ(mat3,mat1-mat2+mat4);
    CHECK_EQ(mat5-mat6,mat7-mat6);
    
    CHECK_THROWS(mat1-mat5);
    CHECK_THROWS(mat2-mat6);
    CHECK_THROWS(mat3-mat7);
    CHECK_THROWS(mat4-mat5-mat7);
}

TEST_CASE("function -= binary matrix and matrix"){
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    mat3-=mat1;
    CHECK_EQ(mat1,mat3);
    mat2-=mat3;
    mat1+=mat3;
    CHECK_EQ(mat1,mat2);
    mat4-=mat2;
    CHECK_EQ(mat4,mat2);
    mat4+=mat1;
    mat4-=mat3;
    mat3+=mat1;
    CHECK_EQ(mat4,mat3);
    mat7-=mat6;
    CHECK_EQ(mat7,mat5);

    CHECK_THROWS(mat5-=mat4);
    CHECK_THROWS(mat6-=mat4);
    CHECK_THROWS(mat7-=mat4);
    CHECK_THROWS(mat5-=mat1);
    CHECK_THROWS(mat5-=mat2);
    CHECK_THROWS(mat3-=mat7);

}

TEST_CASE("function - unary"){
    Matrix mat1{unit_matrix,3,3};
    CHECK_EQ(-mat1,mat_un);
}

TEST_CASE("function < binary"){
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK_EQ(true,mat1<mat2);
    CHECK_EQ(true,mat1<mat3);
    CHECK_EQ(true,mat1<mat4);
    CHECK_EQ(true,mat2<mat4);
    CHECK_EQ(true,mat3<mat2);
    CHECK_EQ(true,mat3<mat4);

    CHECK_EQ(true,mat5<mat6);
    CHECK_EQ(true,mat6<mat7);
    CHECK_EQ(true,mat5<mat7);

    CHECK_EQ(false,mat2<mat1);
    CHECK_EQ(false,mat3<mat1);
    CHECK_EQ(false,mat4<mat1);
    CHECK_EQ(false,mat4<mat2);
    CHECK_EQ(false,mat2<mat3);
    CHECK_EQ(false,mat4<mat3);

    CHECK_EQ(false,mat6<mat5);
    CHECK_EQ(false,mat7<mat6);
    CHECK_EQ(false,mat7<mat5);

    CHECK_EQ(false,mat1<mat1);
    CHECK_EQ(false,mat2<mat2);
    CHECK_EQ(false,mat3<mat3);
    CHECK_EQ(false,mat4<mat4);
    CHECK_EQ(false,mat5<mat5);
    CHECK_EQ(false,mat6<mat6);
    CHECK_EQ(false,mat7<mat7);

    CHECK_THROWS(equalto =(mat4<mat7));
    CHECK_THROWS(equalto =(mat4<mat5));
    CHECK_THROWS(equalto =(mat4<mat6));
    CHECK_THROWS(equalto =(mat1<mat7));
    CHECK_THROWS(equalto =(mat2<mat7));
    CHECK_THROWS(equalto =(mat3<mat7));
    CHECK_THROWS(equalto =(mat4<mat5));
}

TEST_CASE("function <= binary"){
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK_EQ(true,mat1<=mat2);
    CHECK_EQ(true,mat1<=mat3);
    CHECK_EQ(true,mat1<=mat4);
    CHECK_EQ(true,mat2<=mat4);
    CHECK_EQ(true,mat3<=mat2);
    CHECK_EQ(true,mat3<=mat4);

    CHECK_EQ(true,mat5<=mat6);
    CHECK_EQ(true,mat6<=mat7);
    CHECK_EQ(true,mat5<=mat7);

    CHECK_EQ(false,mat2<=mat1);
    CHECK_EQ(false,mat3<=mat1);
    CHECK_EQ(false,mat4<=mat1);
    CHECK_EQ(false,mat4<=mat2);
    CHECK_EQ(false,mat2<=mat3);
    CHECK_EQ(false,mat4<=mat3);

    CHECK_EQ(false,mat6<=mat5);
    CHECK_EQ(false,mat7<=mat6);
    CHECK_EQ(false,mat7<=mat5);

    CHECK_EQ(true,mat1<=mat1);
    CHECK_EQ(true,mat2<=mat2);
    CHECK_EQ(true,mat3<=mat3);
    CHECK_EQ(true,mat4<=mat4);
    CHECK_EQ(true,mat5<=mat5);
    CHECK_EQ(true,mat6<=mat6);
    CHECK_EQ(true,mat7<=mat7);

    CHECK_THROWS(equalto =(mat4<=mat7));
    CHECK_THROWS(equalto =(mat4<=mat5));
    CHECK_THROWS(equalto =(mat4<=mat6));
    CHECK_THROWS(equalto =(mat1<=mat7));
    CHECK_THROWS(equalto =(mat2<=mat7));
    CHECK_THROWS(equalto =(mat3<=mat7));
    CHECK_THROWS(equalto =(mat4<=mat5));

}

TEST_CASE("function > binary"){
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK_EQ(true,mat2>mat1);
    CHECK_EQ(true,mat3>mat1);
    CHECK_EQ(true,mat4>mat1);
    CHECK_EQ(true,mat4>mat2);
    CHECK_EQ(true,mat2>mat3);
    CHECK_EQ(true,mat4>mat3);

    CHECK_EQ(true,mat6>mat5);
    CHECK_EQ(true,mat7>mat6);
    CHECK_EQ(true,mat7>mat5);

    CHECK_EQ(false,mat1>mat2);
    CHECK_EQ(false,mat1>mat3);
    CHECK_EQ(false,mat1>mat4);
    CHECK_EQ(false,mat2>mat4);
    CHECK_EQ(false,mat3>mat2);
    CHECK_EQ(false,mat3>mat4);

    CHECK_EQ(false,mat5>mat6);
    CHECK_EQ(false,mat6>mat7);
    CHECK_EQ(false,mat5>mat7);

    CHECK_EQ(false,mat1>mat1);
    CHECK_EQ(false,mat2>mat2);
    CHECK_EQ(false,mat3>mat3);
    CHECK_EQ(false,mat4>mat4);
    CHECK_EQ(false,mat5>mat5);
    CHECK_EQ(false,mat6>mat6);
    CHECK_EQ(false,mat7>mat7);

    CHECK_THROWS(equalto =(mat4>mat7));
    CHECK_THROWS(equalto =(mat4>mat5));
    CHECK_THROWS(equalto =(mat4>mat6));
    CHECK_THROWS(equalto =(mat1>mat7));
    CHECK_THROWS(equalto =(mat2>mat7));
    CHECK_THROWS(equalto =(mat3>mat7));
    CHECK_THROWS(equalto =(mat4>mat5));

}

TEST_CASE("function >= binary"){
Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK_EQ(true,mat2>=mat1);
    CHECK_EQ(true,mat3>=mat1);
    CHECK_EQ(true,mat4>=mat1);
    CHECK_EQ(true,mat4>=mat2);
    CHECK_EQ(true,mat2>=mat3);
    CHECK_EQ(true,mat4>=mat3);

    CHECK_EQ(true,mat6>=mat5);
    CHECK_EQ(true,mat7>=mat6);
    CHECK_EQ(true,mat7>=mat5);

    CHECK_EQ(false,mat1>=mat2);
    CHECK_EQ(false,mat1>=mat3);
    CHECK_EQ(false,mat1>=mat4);
    CHECK_EQ(false,mat2>=mat4);
    CHECK_EQ(false,mat3>=mat2);
    CHECK_EQ(false,mat3>=mat4);

    CHECK_EQ(false,mat5>=mat6);
    CHECK_EQ(false,mat6>=mat7);
    CHECK_EQ(false,mat5>=mat7);

    CHECK_EQ(true,mat1>=mat1);
    CHECK_EQ(true,mat2>=mat2);
    CHECK_EQ(true,mat3>=mat3);
    CHECK_EQ(true,mat4>=mat4);
    CHECK_EQ(true,mat5>=mat5);
    CHECK_EQ(true,mat6>=mat6);
    CHECK_EQ(true,mat7>=mat7);

    CHECK_THROWS(equalto =(mat4>=mat7));
    CHECK_THROWS(equalto =(mat4>=mat5));
    CHECK_THROWS(equalto =(mat4>=mat6));
    CHECK_THROWS(equalto =(mat1>=mat7));
    CHECK_THROWS(equalto =(mat2>=mat7));
    CHECK_THROWS(equalto =(mat3>=mat7));
    CHECK_THROWS(equalto =(mat4>=mat5));
}

TEST_CASE("function == binary"){
    CHECK_EQ(false,mat1==mat2);
    CHECK_EQ(false,mat1==mat4);
    CHECK_EQ(false,mat3==mat2);
    CHECK_EQ(false,mat3==mat4);

    CHECK_EQ(true,mat1==mat1);
    CHECK_EQ(true,mat2==mat2);
    CHECK_EQ(true,mat3==mat3);
    CHECK_EQ(true,mat4==mat4);
    CHECK_EQ(true,mat5==mat5);
    CHECK_EQ(true,mat6==mat6);
    CHECK_EQ(true,mat7==mat7);

    CHECK_EQ(true,mat1==mat3);
    CHECK_EQ(true,mat2==mat4);
    CHECK_EQ(true,mat5==mat7);

    mat6++;
    CHECK_EQ(false,mat6==mat7);

    CHECK_THROWS(equalto =(mat4==mat7));
    CHECK_THROWS(equalto =(mat4==mat5));
    CHECK_THROWS(equalto =(mat4==mat6));
    CHECK_THROWS(equalto =(mat1==mat7));
    CHECK_THROWS(equalto =(mat2==mat7));
    CHECK_THROWS(equalto =(mat3==mat7));
    CHECK_THROWS(equalto =(mat4==mat5));
}

TEST_CASE("function != binary"){

    CHECK_EQ(true,mat1!=mat2);
    CHECK_EQ(true,mat1!=mat4);
    CHECK_EQ(true,mat3!=mat2);
    CHECK_EQ(true,mat3!=mat4);

    CHECK_EQ(false,mat1!=mat1);
    CHECK_EQ(false,mat2!=mat2);
    CHECK_EQ(false,mat3!=mat3);
    CHECK_EQ(false,mat4!=mat4);
    CHECK_EQ(false,mat5!=mat5);
    CHECK_EQ(false,mat6!=mat6);
    CHECK_EQ(false,mat7!=mat7);

    CHECK_EQ(false,mat1!=mat3);
    CHECK_EQ(false,mat2!=mat4);
    CHECK_EQ(false,mat5!=mat7);

    mat6++;
    CHECK_EQ(true,mat6!=mat7);

    CHECK_THROWS(equalto =(mat4!=mat7));
    CHECK_THROWS(equalto =(mat4!=mat5));
    CHECK_THROWS(equalto =(mat4!=mat6));
    CHECK_THROWS(equalto =(mat1!=mat7));
    CHECK_THROWS(equalto =(mat2!=mat7));
    CHECK_THROWS(equalto =(mat3!=mat7));
    CHECK_THROWS(equalto =(mat4!=mat5));
}

TEST_CASE("function ++ before"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    ++mat_un;
    ++mat1;
    ++mat2;
    ++mat3;
    ++mat4;
    ++mat5;
    ++mat6;
    ++mat7;

    CHECK(mat_un_1 == mat_un);
    CHECK(mat1 == mat1_1);
    CHECK(mat2 == mat2_2);
    CHECK(mat3 == mat3_3);
    CHECK(mat4 == mat4_4);
    CHECK(mat5 == mat5_5);
    CHECK(mat6 == mat6_6);
    CHECK(mat7 == mat7_7);


}

TEST_CASE("function ++ after"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    mat_un++;
    mat1++;
    mat2++;
    mat3++;
    mat4++;
    mat5++;
    mat6++;
    mat7++;

    CHECK(mat_un_1 == mat_un);
    CHECK(mat1 == mat1_1);
    CHECK(mat2 == mat2_2);
    CHECK(mat3 == mat3_3);
    CHECK(mat4 == mat4_4);
    CHECK(mat5 == mat5_5);
    CHECK(mat6 == mat6_6);
    CHECK(mat7 == mat7_7);
}

TEST_CASE("function -- before"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    --mat_un_1;
    --mat1_1;
    --mat2_2;
    --mat3_3;
    --mat4_4;
    --mat5_5;
    --mat6_6;
    --mat7_7;

    CHECK(mat_un_1 == mat_un);
    CHECK(mat1 == mat1_1);
    CHECK(mat2 == mat2_2);
    CHECK(mat3 == mat3_3);
    CHECK(mat4 == mat4_4);
    CHECK(mat5 == mat5_5);
    CHECK(mat6 == mat6_6);
    CHECK(mat7 == mat7_7);
}

TEST_CASE("function -- after"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};
    Matrix mat_un_1{arr1_1,3,3};
    Matrix mat1_1{unit_matrix_1,3,3};
    Matrix mat2_2{arr_b_1,3,3};
    Matrix mat3_3{arr_c_1,3,3};
    Matrix mat4_4{arr_d_1,3,3};
    Matrix mat5_5{arr_e_1,4,3};
    Matrix mat6_6{arr_f_1,4,3};
    Matrix mat7_7{arr_h_1,4,3};

    --mat_un_1;
    --mat1_1;
    --mat2_2;
    --mat3_3;
    --mat4_4;
    --mat5_5;
    --mat6_6;
    --mat7_7;

    CHECK(mat_un_1 == mat_un);
    CHECK(mat1 == mat1_1);
    CHECK(mat2 == mat2_2);
    CHECK(mat3 == mat3_3);
    CHECK(mat4 == mat4_4);
    CHECK(mat5 == mat5_5);
    CHECK(mat6 == mat6_6);
    CHECK(mat7 == mat7_7);
}

TEST_CASE("function *= matrix and than int"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};
    mat1*=3;
    CHECK(mat1 == mat2);
    mat1-=mat3;
    mat1*=4;
    CHECK(mat4 == mat1);
    mat1-=mat2;
    mat1*=2;
    CHECK(mat3 == mat1);
    mat5*= 9;
    mat7*=4;
    CHECK(mat5 == mat7);
    mat4*=9;
    CHECK_THROWS( equalto=(mat4*5 == mat5*4));    
}

TEST_CASE("function * matrix and than int"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK(mat1*3 == mat2);
    CHECK(mat1*4 == mat4);
    CHECK(mat1*2 == mat3);

    CHECK(mat5*9 == mat7*4);
    CHECK(mat6*9 == mat7*5);
    CHECK(mat5*5 == mat6*4);

    CHECK_THROWS( equalto=(mat4*45 == mat5)); 

    
}

TEST_CASE("function * matrix and matrix"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK(mat2*mat1 == mat2);
    CHECK(mat4*mat1 == mat4);
    CHECK(mat3*mat1 == mat3);
    CHECK(mat3*mat2 == mat3+mat4);

    CHECK_NOTHROW(mat7*mat1);
    CHECK_NOTHROW(mat7*mat2);
    CHECK_NOTHROW(mat7*mat3);
    CHECK_NOTHROW(mat7*mat4);
    CHECK_NOTHROW(mat6*mat1);
    CHECK_NOTHROW(mat6*mat2);
    CHECK_NOTHROW(mat6*mat3);
    CHECK_NOTHROW(mat6*mat4);
    CHECK_NOTHROW(mat5*mat1);
    CHECK_NOTHROW(mat5*mat2);
    CHECK_NOTHROW(mat5*mat3);
    CHECK_NOTHROW(mat5*mat4);

    CHECK_THROWS(mat7*mat5);
    CHECK_THROWS(mat7*mat6);
    CHECK_THROWS(mat6*mat5); 
}

TEST_CASE("function *= matrix and matrix"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};
    Matrix mat_un_1{arr1_1,3,3};
    Matrix mat1_1{unit_matrix_1,3,3};
    Matrix mat2_2{arr_b_1,3,3};
    Matrix mat3_3{arr_c_1,3,3};
    Matrix mat4_4{arr_d_1,3,3};
    Matrix mat5_5{arr_e_1,4,3};
    Matrix mat6_6{arr_f_1,4,3};
    Matrix mat7_7{arr_h_1,4,3};
    --mat_un_1;
    --mat1_1;
    --mat2_2;
    --mat3_3;
    --mat4_4;
    --mat5_5;
    --mat6_6;
    --mat7_7;
    
    mat2*=mat1;
    CHECK(mat2== mat2_2);
    mat4*=mat1;
    CHECK(mat4 == mat4_4);
    mat3*=mat1;
    CHECK(mat3 == mat3_3);
    mat2*=mat3;
    CHECK(mat2 == mat3+mat4);

    CHECK_THROWS(mat7*=mat5);
    CHECK_THROWS(mat7*=mat6);
    CHECK_THROWS(mat6*=mat5); 

    CHECK_NOTHROW(mat7*=mat1);
    CHECK_NOTHROW(mat7*=mat2);
    CHECK_NOTHROW(mat7*=mat3);
    CHECK_NOTHROW(mat7*=mat4);
    CHECK_NOTHROW(mat6*=mat1);
    CHECK_NOTHROW(mat6*=mat2);
    CHECK_NOTHROW(mat6*=mat3);
    CHECK_NOTHROW(mat6*=mat4);
    CHECK_NOTHROW(mat5*=mat1);
    CHECK_NOTHROW(mat5*=mat2);
    CHECK_NOTHROW(mat5*=mat3);
    CHECK_NOTHROW(mat5*=mat4);
}

TEST_CASE("function * int and than matrix"){
    Matrix mat_un{arr1,3,3};
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
    Matrix mat5{arr_e,4,3};
    Matrix mat6{arr_f,4,3};
    Matrix mat7{arr_h,4,3};

    CHECK(3*mat1 == mat2);
    CHECK(4*mat1 == mat4);
    CHECK(2*mat1 == mat3);

    CHECK(9*mat5 == 4*mat7);
    CHECK(9*mat6 == 5*mat7);
    CHECK(5*mat5 == 4*mat6);

    CHECK_THROWS( equalto=(45*mat4 == mat5));
}

TEST_CASE("function <<"){
    Matrix mat1{unit_matrix,3,3};
    Matrix mat2{arr_b,3,3};
    Matrix mat3{arr_c,3,3};
    Matrix mat4{arr_d,3,3};
 
    ostringstream os1;
    os1 << mat1;
    CHECK(os1.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]");

    ostringstream os2;
    os2 << mat2;
    CHECK(os2.str() == "[3 0 0]\n[0 3 0]\n[0 0 3]");

    ostringstream os3;
    os3 << mat3;
    CHECK(os3.str() == "[2 0 0]\n[0 2 0]\n[0 0 2]");

    ostringstream os4;
    os4 << mat4;
    CHECK(os4.str() == "[4 0 0]\n[0 4 0]\n[0 0 4]");

    ostringstream os5;
    os5 << mat_un;
    CHECK(os5.str() == "[-1 0 0]\n[0 -1 0]\n[0 0 -1]");

}
TEST_CASE("function >>"){
    istringstream is1{"[1 1 1 1],[1 1 1 1], [1 1 1 1]\n"};
    CHECK_THROWS(is1 >> mat1);
    istringstream is2{"[1 1 1 1], [1 1 1 1] [1 1 1 1],\n"};
    CHECK_THROWS(is2 >> mat1);
    istringstream is3{"[1 11 1]  [1 1 1 1], [1 1 1 1]\n"};
    CHECK_THROWS(is3 >> mat1);
    istringstream is4{",[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
    CHECK_THROWS(is4 >> mat1);
    istringstream is5{",,[1 1 1 1] [1 1 1 1] [1 1 1 1]\n"};
    CHECK_THROWS(is5 >> mat1);
    istringstream is6{"[ 1 1 1 1 ], [ 1 1 1 1 , [ 1 1 1 1 ]]\n"};
    CHECK_THROWS(is6 >> mat1);
    istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
    CHECK_NOTHROW(is7 >> mat1);
}
































































