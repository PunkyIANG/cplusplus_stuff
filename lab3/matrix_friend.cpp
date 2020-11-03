#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Matrix
{
public:
    int size;
    vector<vector<float>> values;

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

public:
    Matrix() //size = 10; generating identity matrix
    {
        size = 10;
        values = vector<vector<float>>(size, vector<float>(size));

        AssignIdentityMatrix();
    }

    Matrix(int _size) //size as parameter; generating identity matrix
    {
        size = _size;
        values = vector<vector<float>>(size, vector<float>(size));

        AssignIdentityMatrix();
    }

    Matrix(const Matrix &_matrix) //copying constructor
    {
        size = _matrix.size;
        values = vector<vector<float>>(size, vector<float>(size));

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
        values = vector<vector<float>>(size, vector<float>(size));

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

public:
    float Value(int x, int y)
    {
        if ((x < size) & (y < size) & (x >= 0) & (y >= 0))
        {
            return values[x][y];
        }
        else
        {
            cout << "ERROR: id out of bounds" << endl;
            return 0;
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

    float Determinant()
    {
        if (size < 1)
        {
            cout << "ERROR: bad input matrix for determinant" << endl;
            return 0;
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
            float result = 0;
            for (int i = 0; i < size; i++)
            {
                result += pow(-1, i + 0) * values[i][0] * Matrix(*this, i, 0).Determinant();
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

    friend Matrix operator--(Matrix a); //--matrix

    friend Matrix operator--(Matrix &a, int x); //matrix--

    friend Matrix operator-(Matrix a, const Matrix &b);

    friend Matrix operator-(Matrix a, float b);

    friend Matrix operator*(Matrix, float);

    friend Matrix operator*(Matrix, const Matrix &);

    Matrix &operator=(const Matrix &a) // matrix = matrix2
    {
        if (this == &a) //check matrix = matrix
        {
            return *this;
        }

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

    friend Matrix operator/=(const Matrix &, Matrix);

    friend bool operator<=(Matrix, Matrix);

    friend ostream &operator<<(ostream &out, const Matrix &matrix);

    friend istream &operator>>(std::istream &in, Matrix &matrix);
};

Matrix operator--(Matrix a) //--matrix
{
    for (int i = 0; i < a.size; i++)
    {
        a.values[i][i]--;
    }

    return a;
}

Matrix operator--(Matrix &a, int x) //matrix--
{
    Matrix temp(a);
    --a;
    return temp;
}

Matrix operator-(Matrix a, const Matrix &b)
{
    if (a.size != b.size)
    {
        cout << "ERROR: subtraction of matrices of different size" << endl;
        return a;
    }

    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size; j++)
        {
            a.values[i][j] -= b.values[i][j];
        }
    }

    return a;
}

Matrix operator-(Matrix a, float b)
{
    return a - Matrix(a.size) * b;
}

Matrix operator-(float a, Matrix b) //
{
    return ((Matrix(b.size) * a) - b);
}

Matrix operator/=(Matrix &a, Matrix b)
{ //division is basically multiplying with inverse
    a = a * b.Inverse();
    return a * b.Inverse();
}

Matrix operator*(Matrix a, const Matrix &b)
{
    if (a.size != b.size)
    {
        cout << "ERROR: multiplied matrix size differs" << endl;
        return a;
    }

    Matrix result(a.size);

    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size; j++)
        {
            result.values[i][j] = 0;
            for (int k = 0; k < a.size; k++)
            {
                result.values[i][j] += a.values[i][k] * b.values[k][j];
            }
        }
    }

    return result;
}

Matrix operator*(Matrix a, float b)
{
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size; j++)
        {
            a.values[i][j] = b * a.values[i][j];
        }
    }

    return a;
}

Matrix operator*(float a, Matrix b)
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

bool operator<=(Matrix a, Matrix b)
{
    if (a.Determinant() <= b.Determinant())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream &operator<<(ostream &out, const Matrix &matrix)
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

istream &operator>>(std::istream &in, Matrix &matrix)
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
    Matrix x(3), y(3);
    x = x * 2;

    cout << "1)" << endl;
    cin >> y;
    cout << y << endl; //1
    //y.Print();

    cout << "2) " << y.Value(0, 0) << endl
         << endl; //2

    Matrix z(3), w(3);
    z = z * 3;
    w = w * 2;
    z /= w; //3
    cout << "3)" << endl
         << z << endl;

    Matrix a(3), b(3);
    cout << "4)" << endl
         << (--a) << endl
         << (b--) << endl; //4

    cout << "5) " << (x <= a) << endl
         << endl; //5

    cout << "6)" << endl
         << (x - 2) << endl; //6
    cout << (2 - x) << endl;

    cout << "7)" << endl
         << a << endl;
    a = x;
    cout << endl
         << a << endl;
}