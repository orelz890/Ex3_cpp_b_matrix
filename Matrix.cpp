#include "Matrix.hpp"

namespace zich{

    Matrix Matrix:: operator+(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }        
        std::vector<double> new_data;
        new_data.resize(mat.mat_size);
        for (int i = 0; i < this->matrix.size(); i++){
            new_data[(unsigned long)i] = (this->matrix[(unsigned long)i] + mat.matrix[(unsigned long)i]);
        }
        Matrix ans{new_data, this->rows, mat.get_cols()};
        return ans;
    }

    double sum_all_vals(Matrix &mat){
        double ans = 0;
        const int matrix_size = mat.get_rows() * mat.get_cols();
        for (int i = 0; i < matrix_size; i++){
            ans += mat.get_val_at(i);
        }
        return ans;
    }

    double sum_all_vals(const Matrix &mat){
        double ans = 0;
        const int matrix_size = mat.get_rows() * mat.get_cols();
        for (int i = 0; i < matrix_size; i++){
            ans += mat.get_val_at(i);
        }
        return ans;
    }
    
    Matrix Matrix:: operator-(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        std::vector<double> new_data;
        new_data.resize(mat.mat_size);
        for (int i = 0; i < this->mat_size; i++){
            new_data[(unsigned long)i] = (this->get_val_at(i) - mat.get_val_at(i));
        }
        return Matrix(new_data, this->rows, this->columns);
    }

    Matrix Matrix:: operator-() const{
        Matrix a{this->matrix, this->rows, this->columns};
        return  a*(-1);
    }

    Matrix Matrix:: operator*(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        std::vector<double> new_data;
        new_data.resize(mat.mat_size);
        for (int i = 0; i < this->mat_size; i++){
            new_data[(unsigned long)i] = (this->get_val_at(i) * mat.get_val_at(i));
        }
        return Matrix(new_data, this->rows, this->columns);
    }

    Matrix Matrix:: operator*(const double scalar) const{
        std::vector<double> new_data;
        new_data.resize(this->mat_size);
        for (int i = 0; i < this->mat_size; i++){
            new_data[(unsigned long)i] = (this->matrix[(unsigned long)i] * scalar);
        }
        return Matrix(new_data, this->rows, this->columns);
    }

    Matrix& Matrix:: operator++(){
        (*this)++;
        return *this;
    }

    Matrix Matrix:: operator++(const int num){
        Matrix ans = *this;
        for (int i = 0; i < this->matrix.size(); i++){
            this->matrix[(unsigned long)i]++;
        }
        return ans;
    }

    Matrix& Matrix:: operator--(){
        (*this)--;
        return *this;
    }

    Matrix Matrix:: operator--(const int num){
        Matrix ans = *this;
        for (int i = 0; i < this->matrix.size(); i++){
            this->matrix[(unsigned long)i]--;
        }
        return ans;
    }

    Matrix& Matrix:: operator+=(const Matrix &mat){
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        for (int i = 0; i < this->mat_size; i++){
            this->matrix[(unsigned long)i] += mat.get_val_at(i);
        }
        return *this;
    }

    Matrix& Matrix:: operator-=(const Matrix &mat){
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        for (int i = 0; i < this->matrix.size(); i++){
            this->matrix[(unsigned long)i] -= mat.get_val_at(i);
        }
        return *this;
    }

    Matrix& Matrix:: operator*=(const Matrix &mat){
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        for (int i = 0; i < this->mat_size; i++){
            this->matrix[(unsigned long)i] *= mat.get_val_at(i);
        }
        return *this;

    }

    Matrix& Matrix:: operator*=(const double scalar){
        for (int i = 0; i < this->matrix.size(); i++){
            this->matrix[(unsigned long)i] *= scalar;
        }
        return *this;
    }

    bool Matrix:: operator>(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        return sum_all_vals(*this) > sum_all_vals(mat);
    }

    bool Matrix:: operator>=(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        return ( (sum_all_vals(*this) > sum_all_vals(mat)) || ((*this) == mat) );
    }

    bool Matrix:: operator<(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }        
        return (sum_all_vals(*this) < sum_all_vals(mat));
    }

    bool Matrix:: operator<=(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        return ( (sum_all_vals(*this) < sum_all_vals(mat) ) || ((*this) == mat));
    }

    bool Matrix:: operator==(const Matrix &mat) const{
        if (mat_size != mat.mat_size){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        for (int i = 0; i < this->mat_size; i++){
            if(this->get_val_at(i) != mat.get_val_at(i)){
                return false;
            }
        }
        return true;
    }

    bool Matrix:: operator!=(const Matrix &mat) const{
        return !((*this) == mat);
    }

    Matrix operator*(const double scalar, const Matrix &mat){
        return mat * scalar;
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
