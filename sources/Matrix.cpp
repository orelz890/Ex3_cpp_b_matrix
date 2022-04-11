#include "Matrix.hpp"

const int MIN_NUM_CHAR = 0;
const int MAX_NUM_CHAR = 9;


namespace zich{

    Matrix Matrix:: operator+(const Matrix &mat) const{
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }        
        std::vector<double> new_data;
        new_data.resize((unsigned long)mat.mat_size);
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
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        std::vector<double> new_data;
        new_data.resize((unsigned long)mat.mat_size);
        for (int i = 0; i < this->mat_size; i++){
            new_data[(unsigned long)i] = (this->get_val_at(i) - mat.get_val_at(i));
        }
        return Matrix(new_data, this->rows, this->columns);
    }

    Matrix Matrix:: operator-() const{
        Matrix a{this->matrix, this->rows, this->columns};
        return  a*(-1);
    }

    Matrix Matrix::operator+() const{
        Matrix a{this->matrix, this->rows, this->columns};
        return a;
    }

    Matrix Matrix:: operator*(const Matrix &mat) const{
        if (this->columns != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        // Create new matrix
        std::vector<double> new_data;
        new_data.resize((unsigned long)this->rows*mat.columns);
        Matrix ans(new_data, this->rows, mat.columns);

        // Multiplication calculation
        int ans_col = 0;
        int col = 0;
        int mat_col = 0;
        for (int i = 0; i < this->rows; i++){
            for (int row = 0; row < this->rows; row++){
                double sum_val = 0;
                for (col = 0; col < this->columns; col++){
                    sum_val += this->get_val_at(i, col)*mat.get_val_at(col,mat_col%(mat.columns));
                }
                ans.set_val_at(i,mat_col++%(mat.columns), sum_val);
            }
        }
        return ans;
    }

    Matrix Matrix:: operator*(const double scalar) const{
        std::vector<double> new_data;
        new_data.resize((unsigned long)this->mat_size);
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
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        for (int i = 0; i < this->mat_size; i++){
            this->matrix[(unsigned long)i] += mat.get_val_at(i);
        }
        return *this;
    }

    Matrix& Matrix:: operator-=(const Matrix &mat){
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        for (int i = 0; i < this->matrix.size(); i++){
            this->matrix[(unsigned long)i] -= mat.get_val_at(i);
        }
        return *this;
    }

    Matrix& Matrix:: operator*=(const Matrix &mat){
        if (this->columns != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        *this = (*this)*mat;
        return *this;
    }

    Matrix& Matrix:: operator*=(const double scalar){
        for (int i = 0; i < this->matrix.size(); i++){
            this->matrix[(unsigned long)i] *= scalar;
        }
        return *this;
    }

    bool Matrix:: operator>(const Matrix &mat) const{
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        return sum_all_vals(*this) > sum_all_vals(mat);
    }

    bool Matrix:: operator>=(const Matrix &mat) const{
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        return ( (sum_all_vals(*this) > sum_all_vals(mat)) || ((*this) == mat) );
    }

    bool Matrix:: operator<(const Matrix &mat) const{
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }        
        return (sum_all_vals(*this) < sum_all_vals(mat));
    }

    bool Matrix:: operator<=(const Matrix &mat) const{
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
            throw std::runtime_error("Both matrixs should be the same size");
        }
        return ( (sum_all_vals(*this) < sum_all_vals(mat) ) || ((*this) == mat));
    }

    bool Matrix:: operator==(const Matrix &mat) const{
        if (this->mat_size != mat.mat_size || this->columns != mat.columns || this->rows != mat.rows){
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
                os << '[' << mat.get_val_at(i) << ' ';
            }
            else if((i+1) % mat.columns == 0){
                os << mat.get_val_at(i) << ']';
                if ((i+1) != mat.mat_size){
                    os << '\n';
                }
            }
            else{
                os << mat.get_val_at(i) << ' ';
            }
        }
        return os;
    }


// First part taken from:
// https://stackoverflow.com/questions/3203452/how-to-read-entire-stream-into-a-stdstring
    std::istream& operator>> (std::istream &is, Matrix& mat){

        // Extracting the data to a string
        std::string data;
        // remember where we are    
        std::streampos p = is.tellg();
        // go to the end
        is.seekg(0, std::ios_base::end);
        // work out the size
        std::streamoff str_size = (long)(is.tellg() - p);
        // restore the position
        is.seekg(p);
        data.resize((unsigned long)str_size);
        // and finally, read in the data
        is.read(&data[0], str_size);

        // Find the size of the new matrix
        unsigned long row = 0;
        unsigned long col = 1;
        int curr_row_col = 1;
        bool first_row = true;
        bool begin = false;
        for (int i = 0; i < str_size; i++){
            
            char curr_data = data.at((unsigned long)i);
            bool is_num = (curr_data - '0') >= MIN_NUM_CHAR && (curr_data - '0') <= MAX_NUM_CHAR;
            bool is_legal = is_num || curr_data == ',' || curr_data == '[' || curr_data == ']' || curr_data == ' ' || curr_data == '\n'; 
            
            if (!is_legal || (i == 0 && curr_data != '[') 
                || ((i < str_size -1) && ( curr_data == ',' && data.at((unsigned long)i+1) != ' ') )
                || ((i < str_size -2) && ((curr_data == ']') && (data.at((unsigned long)i+1) != ','))) 
                || ((i < str_size -2) && ((curr_data == ' ') && ( (data.at((unsigned long)i+1) != '[') 
                && ((data.at((unsigned long)i+1) - '0' > MAX_NUM_CHAR) || (data.at((unsigned long)i+1) - '0' < MIN_NUM_CHAR)))))
                || ((i == str_size -2) && ((data.at((unsigned long)i) != ']') || (data.at((unsigned long)i+1) != '\n'))))
            {
                throw std::runtime_error("Wrong input values!");
            }
            
            if (curr_data == '['){
                row++;
                curr_row_col = 1;
                begin = true;
            }
            if (curr_data == ']'){
                first_row = false;
                begin = false;
                if (col != curr_row_col){
                    throw std::runtime_error("Wrong input values!");
                }    
            }
            if(begin && curr_data == ' '){
                curr_row_col++;
                if (first_row){
                    col = curr_row_col;
                }     
            }
        }
        mat.matrix.resize(row*col);
        mat.mat_size = row*col;
        mat.columns = col;
        mat.rows = row;

        // Converting the string to vector<double>
        int pos = 0;
        std::string curr_val_str;
        for (int i = 0; i < str_size; i++){

            char curr_data = data.at((unsigned long)i);
            bool is_num = (curr_data - '0') >= MIN_NUM_CHAR && (curr_data - '0') <= MAX_NUM_CHAR;

            if (is_num){
                curr_val_str += curr_data;
            }
            else if(!(curr_val_str.empty())){

                double curr_val = std::stod(curr_val_str);
                mat.matrix[(unsigned long)pos++] = curr_val;
                curr_val_str = "";
            } 
        }
        return is;
    }

}
