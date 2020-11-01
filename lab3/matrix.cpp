#include <iostream>

using namespace std;

class Matrix
{
private:
    class Grid
    {
    private:
        int size;
        float *data;

    public:
        Grid(int _size) : size{_size}, data{new float[size * size]} {}

        Grid() : size{10}, data{new float[100]} {}

        float *operator[](size_t row) { return row * size + data; }

        float &operator()(size_t row, size_t column)
        {
            return data[row * size + column];
        }
    };

    int size;
    Grid values;

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
                cout << values[i][j] << " ";
            }
            cout << endl;
        }
    }

public:
    Matrix()
    {
        size = 10;
        values = Grid(size);

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

    Matrix(int _size)
    {
        size = _size;
        values = Grid(size);

        void AssignIdentityMatrix();
    }

    Matrix(const Matrix &_matrix)
    {
        size = _matrix.size;
        values = Grid(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                values[i][j] = _matrix.values[i][j];
            }
        }
    }

    Matrix(const Matrix &_matrix, int x, int y)
    {
        size = _matrix.size - 1;
        values = Grid(size);

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

    float Determinant() const
    {
        if (size == 1)
        {
            return values[1][1];
        }
        else if (size == 2)
        {
            return values[1][1] * values[2][2] - values[1][2] * values[2][1];
        }
        else
        {
        }
    }

    float Determinant(Matrix matrix) const
    {
        if (size == 1)
        {
            return values[1][1];
        }
        else if (size == 2)
        {
            return values[1][1] * values[2][2] - values[1][2] * values[2][1];
        }
        else
        {
        }
    }

    Matrix &operator--() //matrix--
    {
        for (int i = 0; i < size; i++)
        {
            values[i][i]--;
        }

        return *this;
    }

    // Matrix &operator--(int) //--matrix
    // {
    //     Matrix temp(*this);
    //     operator--();
    //     return temp;
    // }

    Matrix &operator=(const Matrix &a) // matrix = matrix2
    {
        if (this == &a) //check matrix = matrix
            return *this;

        size = a.size;

        for (int i = 0; i < size; i++)
        {
            values[i] = new float[size];

            for (int j = 0; j < size; j++)
            {
                values[i][j] = a.values[i][j];
            }
        }

        return *this;
    }
};

int main()
{
    Matrix x = Matrix(3);
}