#include "Matrix.hpp"

namespace zich{

    Matrix Matrix:: operator+(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        
        // std::vector<double> new_data = {};
        // auto it = new_data.insert(new_data.begin(),mat.matrix.size());
        // new_data.insert(it, 0);
        // for (int i = 0; i < this->matrix.size(); i++){
        //     new_data[(unsigned long)i] = (this->matrix[(unsigned long)i] + mat.matrix[(unsigned long)i]);
        // }
        // return Matrix(new_data, this->rows, this->columns);
        return *this;
    }

    double sum_all_vals(Matrix &mat){
        double ans = 0;
        for (int i = 0; i < mat.matrix.size(); i++){
            ans += mat.matrix[(unsigned long)i];
        }
        return ans;
    }
    double sum_all_vals(const Matrix &mat){
        double ans = 0;
        for (int i = 0; i < mat.matrix.size(); i++){
            ans += mat.matrix[(unsigned long)i];
        }
        return ans;
    }
    
    Matrix Matrix:: operator-(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // std::vector<double> new_data = {};
        // auto it = new_data.insert(new_data.begin(),mat.matrix.size());
        // new_data.insert(it, 0);
        // for (int i = 0; i < this->matrix.size(); i++){
        //     new_data[(unsigned long)i] = (this->matrix[(unsigned long)i] - mat.matrix[(unsigned long)i]);
        // }
        // return Matrix(new_data, this->rows, this->columns);
        return *this;
    }

    Matrix Matrix:: operator-() const{
        // Matrix a{this->matrix, this->rows, this->columns};
        // return  a*(-1);
        return *this;
    }

    Matrix Matrix:: operator*(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // std::vector<double> new_data = {};
        // auto it = new_data.insert(new_data.begin(),mat.matrix.size());
        // new_data.insert(it, 0);
        // for (int i = 0; i < this->matrix.size(); i++){
        //     new_data[(unsigned long)i] = (this->matrix[(unsigned long)i] * mat.matrix[(unsigned long)i]);
        // }
        // return Matrix(new_data, this->rows, this->columns);
        return *this;
    }

    Matrix Matrix:: operator*(const double scalar) const{
        // std::vector<double> new_data = {};
        // auto it = new_data.insert(new_data.begin(),this->matrix.size());
        // new_data.insert(it, 0);
        // for (int i = 0; i < this->matrix.size(); i++){
        //     new_data[(unsigned long)i] = (this->matrix[(unsigned long)i] * scalar);
        // }
        // return Matrix(new_data, this->rows, this->columns);
        return *this;
    }

    Matrix& Matrix:: operator++(){
        // Matrix & ans = *this;
        // for (int i = 0; i < this->matrix.size(); i++){
        //     this->matrix[(unsigned long)i]++;
        // }
        // return ans;
        return *this;
    }

    Matrix Matrix:: operator++(const int num){
        // (*this)++;
        return *this;
    }

    Matrix& Matrix:: operator--(){
        // Matrix &ans = *this;
        // for (int i = 0; i < this->matrix.size(); i++){
        //     this->matrix[(unsigned long)i]--;
        // }
        // return ans;
        return *this;
    }

    Matrix Matrix:: operator--(const int num){
        // (*this)--;
        return *this;
    }

    Matrix& Matrix:: operator+=(const Matrix &mat){
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // for (int i = 0; i < this->matrix.size(); i++){
        //     this->matrix[(unsigned long)i] += mat.matrix[(unsigned long)i];
        // }
        return *this;

    }

    Matrix& Matrix:: operator-=(const Matrix &mat){
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // for (int i = 0; i < this->matrix.size(); i++){
        //     this->matrix[(unsigned long)i] -= mat.matrix[(unsigned long)i];
        // }
        return *this;
    }

    Matrix& Matrix:: operator*=(const Matrix &mat){
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // for (int i = 0; i < this->matrix.size(); i++){
        //     this->matrix[(unsigned long)i] *= mat.matrix[(unsigned long)i];
        // }
        return *this;

    }

    Matrix& Matrix:: operator*=(const double scalar){
        // for (int i = 0; i < this->matrix.size(); i++){
        //     this->matrix[(unsigned long)i] *= scalar;
        // }
        return *this;

    }

    bool Matrix:: operator>(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }        
        // return sum_all_vals(*this) > sum_all_vals(mat);
        return false;

    }

    bool Matrix:: operator>=(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // return sum_all_vals(*this) >= sum_all_vals(mat);
        return false;

    }

    bool Matrix:: operator<(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }        
        // return sum_all_vals(*this) < sum_all_vals(mat);
        return false;

    }

    bool Matrix:: operator<=(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // return sum_all_vals(*this) <= sum_all_vals(mat);
        return false;
    }

    bool Matrix:: operator==(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // for (int i = 0; i < this->matrix.size(); i++){
        //     if(this->matrix[(unsigned long)i] != mat.matrix[(unsigned long)i]){
        //         return false;
        //     }
        // }
        // return true;
        return false;
    }

    bool Matrix:: operator!=(const Matrix &mat) const{
        // if (mat_size != mat.mat_size){
        //     throw std::runtime_error("Both matrixs should be the same size");
        // }
        // return !((*this) == mat);
        return false;
    }

    Matrix operator*(const double scalar, const Matrix &mat){
        // std::vector<double> new_data = {};
        // for (int i = 0; i < mat.matrix.size(); i++){
        //     new_data[(unsigned long)i] = (mat.matrix[(unsigned long)i] / (-1));
        // }
        // return Matrix(new_data, mat.rows, mat.columns);
        return mat*scalar;
    }

    std::ostream& operator<<(std::ostream& os , const Matrix& mat){

        for (int i = 0; i < mat.mat_size; i++){
            if (i % mat.columns == 0){
                os << '[' << mat.matrix.at((unsigned long)i) << ' ';
            }
            else if((i+1) % mat.columns == 0){
                os << mat.matrix.at((unsigned long)i) << ']' << '\n';
            }
            else{
                os << mat.matrix.at((unsigned long)i) << ' ';
            }
        }
        return os;
    }

    std::istream& operator>> (std::istream &is, Matrix& mat){
        int size = mat.rows * mat.columns;
        for (int i = 0; i <= size; i++){
            double temp;
            is >> temp;
            mat.matrix[(unsigned long)i] = temp;
        }
        is >> mat.rows >> mat.columns;
        return is;
    }

}

