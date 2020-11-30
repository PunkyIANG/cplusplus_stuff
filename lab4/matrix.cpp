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
private:
    int size;
    T *values;

public:
    int GetSize() {
        return size;
    }

    void SetSize(int _size) {
        size = _size;
    }

    T GetValue(int x, int y) const
    {
        if ((x < size) & (y < size) & (x >= 0) & (y >= 0))
        {
            return values[x * size + y];
        }
        else
        {
            throw "ERROR: id out of bounds";
        }
    }

    void SetValue(int x, int y, T value) {
        if ((x < size) & (y < size) & (x >= 0) & (y >= 0))
        {
            values[x * size + y] = value;
        }
        else
        {
            throw "ERROR: id out of bounds";
        }
    }

    void AssignIdentityMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    SetValue(i, j, 1);
                }
                else
                {
                    SetValue(i, j, 0);
                }
            }
        }
    }

    Matrix() //size = 10; generating identity matrix
    {
        size = 3;
        values = new T[size * size];

        AssignIdentityMatrix();
    }

    Matrix(int _size) //size as parameter; generating identity matrix
    {
        size = _size;
        values = new T[size * size];

        AssignIdentityMatrix();
    }

    Matrix(const Matrix &_matrix) //copying constructor
    {
        size = _matrix.size;
        values = new T[size * size];

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                SetValue(i, j, _matrix.GetValue(i, j));
            }
        }
    }

    Matrix(const Matrix &_matrix, int x, int y) //copying constructor specifically for determinant calc
    {
        size = _matrix.size - 1;
        values = new T[size * size];

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int tempI = (i < x) ? i : i + 1;
                int tempJ = (j < y) ? j : j + 1;
                SetValue(i, j, _matrix.GetValue(tempI, tempJ));
            }
        }
    }

    ~Matrix()
    {
    }

    T Determinant()
    {
        if (size < 1)
        {
            throw "ERROR: bad input matrix for determinant";
        }
        if (size == 1)
        {
            return GetValue(0, 0);
        }
        else if (size == 2)
        {
            return GetValue(0,0) * GetValue(1,1) - GetValue(0,1) * GetValue(1,0);
        }
        else
        {
            T result = 0;
            for (int i = 0; i < size; i++)
            {
                result += powInt((T)-1, i) * GetValue(i, 0) * Matrix(*this, i, 0).Determinant();
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
                //result.values[i][j] = Matrix(*this, i, j).Determinant();
                result.SetValue(i, j, Matrix(*this, i, j).Determinant());
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
                result.SetValue(i, j, GetValue(i, j) * powInt(-1, i + j));
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
                result.SetValue(i, j, GetValue(j, i));
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
            SetValue(i, i, GetValue(i, i) - 1);
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
                result.SetValue(i, j, result.GetValue(i, j) - a.GetValue(i, j));
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
                SetValue(i, j, a * GetValue(i, j));
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
                result.SetValue(i, j, 0);
                for (int k = 0; k < size; k++)
                {
                    result.SetValue(i, j, GetValue(i, k) * a.GetValue(k, j));
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
                SetValue(i, j, a.GetValue(i, j));
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
    return ((Matrix<T>(b.GetSize()) * a) - b);
}

template <typename T>
Matrix<T> operator*(T a, Matrix<T> b)
{
    for (int i = 0; i < b.size; i++)
    {
        for (int j = 0; j < b.size; j++)
        {
            //b.values[i][j] = a * b.values[i][j];
            b.SetValue(i, j, a * b.GetValue(i, j));
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
            out << matrix.GetValue(i, j) << " ";
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
            // in >> matrix.values[i][j];
            T temp;
            in >> temp;
            matrix.SetValue(i, j, temp);
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

    cout << "1)" << endl;
    cin >> y;
    cout << y << endl; //1

    cout << "2) " << y.GetValue(0, 0) << endl
         << endl; //2

    cout << "3)" << endl;
    Matrix<int> z(3), w(3);
    z = z * 4;
    w = w * 2;
    z /= w; //3
    cout << z << endl;

    Matrix<float> a(3), b(3);
    cout << "4)" << endl
         << (--a) << endl
         << (b--) << endl; //4

    cout << "5) " << (x <= a) << endl
         << endl; //5

    cout << "6)" << endl
         << (x - 2) << endl; //6
    cout << ((float)2 - x) << endl;

    cout << "7)" << endl
         << a << endl;
    a = x;
    cout << endl
         << a << endl;

    cout << "Extra" << endl;
    // set matrix as
    // 1 3 3
    // 1 4 3
    // 1 3 4

    Matrix<int> h;

    cin >> h;

    cout << h.Inverse();

    // result should be
    // 7 -3 -3
    // -1 1 0
    // -1 0 1
}