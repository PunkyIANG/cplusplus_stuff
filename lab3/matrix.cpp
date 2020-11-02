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
        } else {
            return *this;
        }
    }

    Matrix operator--() //matrix--
    {
        for (int i = 0; i < size; i++)
        {
            values[i][i]--;
        }

        return *this;
    }

    Matrix operator--(int) //--matrix
    {

        Matrix temp(*this);
        operator--();
        return temp;
    }

    Matrix &operator*(float a)
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

    Matrix operator*(const Matrix &a) {
        if (size != a.size) {
            cout << "ERROR: multiplied matrix size differs" << endl;
            return *this;
        }

        Matrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.values[i][j] = 0;
                for (int k = 0; k < size; k++) {
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

    Matrix operator/=(Matrix a) {   //division is basically multiplying with inverse
        return *this * a.Inverse();
    }
};

int main()
{
    Matrix x(3), y(3);
    x /= y;
    x.Print();
}