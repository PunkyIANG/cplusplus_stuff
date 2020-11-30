#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//exp >= 0, specifically for matrix calc
template <typename T>
T powInt(const T base, const int exp) {
    T result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

template <typename T>
class Matrix
{
public:
    int size;
    vector<vector<T>> values;

    void AssignIdentityMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    values[i][j] = 1;
                }
                else
                {
                    values[i][j] = 0;
                }
            }
        }
    }

    Matrix() //size = 10; generating identity matrix
    {
        size = 10;
        values = vector<vector<T>>(size, vector<T>(size));

        AssignIdentityMatrix();
    }

    Matrix(int _size) //size as parameter; generating identity matrix
    {
        size = _size;
        values = vector<vector<T>>(size, vector<T>(size));

        AssignIdentityMatrix();
    }

    Matrix(const Matrix &_matrix) //copying constructor
    {
        size = _matrix.size;
        values = vector<vector<T>>(size, vector<T>(size));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                values[i][j] = _matrix.values[i][j];
            }
        }
    }

    Matrix(const Matrix &_matrix, int x, int y) //copying constructor specifically for determinant calc
    {
        size = _matrix.size - 1;
        values = vector<vector<T>>(size, vector<T>(size));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int tempI = (i < x) ? i : i + 1;
                int tempJ = (j < y) ? j : j + 1;
                values[i][j] = _matrix.values[tempI][tempJ];
            }
        }
    }

    ~Matrix()
    {
    }

    T Value(int x, int y)
    {
        if ((x < size) & (y < size) & (x >= 0) & (y >= 0))
        {
            return values[x][y];
        }
        else
        {
            throw "ERROR: id out of bounds";
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << values[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    T Determinant()
    {
        if (size < 1)
        {
            throw "ERROR: bad input matrix for determinant";
        }
        if (size == 1)
        {
            return values[0][0];
        }
        else if (size == 2)
        {
            return values[0][0] * values[1][1] - values[0][1] * values[1][0];
        }
        else
        {
            T result = 0;
            for (int i = 0; i < size; i++)
            {
                result += powInt((T)-1, i) * values[i][0] * Matrix(*this, i, 0).Determinant();
            }
            return result;
        }
    }

    Matrix MinorMatrix()
    {
        Matrix result(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.values[i][j] = Matrix(*this, i, j).Determinant();
            }
        }

        return result;
    }

    Matrix CofactorMatrix()
    { //schimbam semnul la fiecare cifra cu suma id-urilor impara
        Matrix result(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (((i + j) % 2 == 1) & (values[i][j] != 0))
                {
                    result.values[i][j] = -values[i][j];
                }
                else
                {
                    result.values[i][j] = values[i][j];
                }
            }
        }

        return result;
    }

    Matrix AdjointMatrix() //matricea transpusa, mirror dupa diagonala principala
    {
        Matrix result(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.values[i][j] = values[j][i];
            }
        }

        return result;
    }

    Matrix Inverse()
    {
        if (Determinant() != 0)
        {
            return MinorMatrix().CofactorMatrix().AdjointMatrix() * (1 / Determinant());
        }
        else
        {
            return *this;
        }
    }

    Matrix &operator--() //--matrix
    {
        for (int i = 0; i < size; i++)
        {
            values[i][i]--;
        }

        return *this;
    }

    Matrix operator--(int) //matrix--
    {

        Matrix temp(*this);
        operator--();
        return temp;
    }

    Matrix operator-(const Matrix &a)
    {
        if (size != a.size)
        {
            throw "ERROR: subtraction of matrices of different size";
        }

        Matrix result(*this);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.values[i][j] -= a.values[i][j];
            }
        }

        return result;
    }

    Matrix operator-(T a)
    {
        return *this - Matrix(size) * a;
    }

    Matrix operator*(T a)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                values[i][j] = a * values[i][j];
            }
        }

        return *this;
    }

    Matrix operator*(const Matrix &a)
    {
        if (size != a.size)
        {
            throw "ERROR: multiplied matrix size differs";
        }

        Matrix result(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.values[i][j] = 0;
                for (int k = 0; k < size; k++)
                {
                    result.values[i][j] += values[i][k] * a.values[k][j];
                }
            }
        }

        return result;
    }

    Matrix &operator=(const Matrix &a) // matrix = matrix2
    {
        if (this == &a) //check matrix = matrix
            return *this;

        size = a.size;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                values[i][j] = a.values[i][j];
            }
        }

        return *this;
    }

    Matrix operator/=(Matrix a)
    { //division is basically multiplying with inverse
        *this = *this * a.Inverse();
        return (*this * a.Inverse());
    }

    bool operator<=(Matrix a)
    {
        if (Determinant() <= a.Determinant())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename U>
    friend ostream &operator<<(ostream &out, const Matrix<U> &matrix);
    template <typename U>
    friend istream &operator>>(istream &in, Matrix<U> &matrix);
};

template <typename T>
Matrix<T> operator-(T a, Matrix<T> b)
{
    return ((Matrix<T>(b.size) * a) - b);
}

template <typename T>
Matrix<T> operator*(T a, Matrix<T> b)
{
    for (int i = 0; i < b.size; i++)
    {
        for (int j = 0; j < b.size; j++)
        {
            b.values[i][j] = a * b.values[i][j];
        }
    }

    return b;
}

template <typename T>
ostream &operator<<(ostream &out, const Matrix<T> &matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++)
        {
            out << matrix.values[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

template <typename T>
istream &operator>>(std::istream &in, Matrix<T> &matrix)
{
    cout << "Size: ";
    in >> matrix.size;

    cout << "Matrix: ";
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++)
        {
            in >> matrix.values[i][j];
        }
    }
    return in;
}

int main()
{
    Matrix<float> x(3), y(2);

    try {
        x = x * y;
    } catch (const char *excptn) {
        cout << excptn << endl;
    }

    // cout << "1)" << endl;
    // cin >> y;
    // cout << y << endl; //1
    // //x.Print();

    // cout << "2) " << y.Value(0, 0) << endl
    //      << endl; //2

    // Matrix<int> z(3), w(3);
    // z = z * 4;
    // w = w * 2;
    // z /= w; //3
    // cout << "3)" << endl
    //      << z << endl;

    // Matrix<float> a(3), b(3);
    // cout << "4)" << endl
    //      << (--a) << endl
    //      << (b--) << endl; //4

    // cout << "5) " << (x <= a) << endl
    //      << endl; //5

    // cout << "6)" << endl
    //      << (x - 2) << endl; //6
    // cout << ((float)2 - x) << endl;

    // cout << "7)" << endl
    //      << a << endl;
    // a = x;
    // cout << endl
    //      << a << endl;
}