#ifndef CLARENSMATHMATRIX
#define CLARENSMATHMATRIX

#include <vector>
#include <stdexcept>

namespace ClarensMath {

    struct Cell {
        int row;
        int col;
    };

    template<typename T>
    class Matrix {
    public:
        using value_type        = typename std::vector<T>::value_type;
        using iterator          = typename std::vector<T>::iterator;
        using const_iterator    = typename std::vector<T>::const_iterator;
        using reference         = typename std::vector<T>::reference;
        using const_reference   = typename std::vector<T>::const_reference;

        Matrix(int rowCount, int colCount);
        Matrix(int rowCount, int colCount, const value_type& val);

        int rows() const;
        int cols() const;
        reference       operator()(int row, int col);
        const_reference operator()(int row, int col) const;
        iterator        begin();
        iterator        end();
        const_iterator  begin() const;
        const_iterator  end()   const;
        void resize(int rowCount, int colCount);
        void resize(int rowCount, int colCount, const value_type& val);

    private:
        reference       index(int row, int col);
        const_reference index(int row, int col) const;
        void            checkRange(int row, int col) const;
        void            checkLength(int rowCount, int colCount) const;
        std::vector<T>  data;
        int r;
        int c;
    };

    template<typename T>
    Matrix<T>::Matrix(int rowCount, int colCount)
    {
        resize(rowCount, colCount);
    }

    template<typename T>
    inline Matrix<T>::Matrix(int rowCount, int colCount, const value_type &val)
    {
        resize(rowCount, colCount, val);
    }

    template<typename T>
    inline int Matrix<T>::rows() const
    {
        return r;
    }

    template<typename T>
    inline int Matrix<T>::cols() const
    {
        return c;
    }

    template<typename T>
    inline typename Matrix<T>::reference Matrix<T>::operator()(int row, int col)
    {
        return index(row, col);
    }

    template<typename T>
    inline typename Matrix<T>::const_reference Matrix<T>::operator()(int row, int col) const
    {
        return index(row, col);
    }

    template<typename T>
    inline typename Matrix<T>::iterator Matrix<T>::begin()
    {
        return data.begin();
    }

    template<typename T>
    inline typename Matrix<T>::iterator Matrix<T>::end()
    {
        return data.end();
    }

    template<typename T>
    inline typename Matrix<T>::const_iterator Matrix<T>::begin() const
    {
        return data.begin();
    }

    template<typename T>
    inline typename Matrix<T>::const_iterator Matrix<T>::end() const
    {
        return data.end();
    }

    template<typename T>
    inline void Matrix<T>::resize(int rowCount, int colCount)
    {
        checkLength(rowCount, colCount);
        r = rowCount;
        c = colCount;
        data.resize(rowCount * colCount);
    }

    template<typename T>
    inline void Matrix<T>::resize(int rowCount, int colCount, const Matrix::value_type &val)
    {
        checkLength(rowCount, colCount);
        r = rowCount;
        c = colCount;
        data.resize(rowCount * colCount, val);
    }

    template<typename T>
    inline typename Matrix<T>::reference Matrix<T>::index(int row, int col)
    {
        checkRange(row, col);

        return data[row * cols() + col];
    }

    template<typename T>
    inline typename Matrix<T>::const_reference Matrix<T>::index(int row, int col) const
    {
        checkRange(row, col);

        return data[row * cols() + col];
    }

    template<typename T>
    inline void Matrix<T>::checkRange(int row, int col) const
    {
        if (row < 0 || row >= rows())
            throw std::out_of_range{"Row index is out of valid range"};

        if (col < 0 || col >= cols())
            throw std::out_of_range{"Column index is out of valid range"};
    }

    template<typename T>
    inline void Matrix<T>::checkLength(int rowCount, int colCount) const
    {
        if(rowCount <= 0)
            throw std::length_error{"Matrix row number must be positive value"};

        if(colCount <= 0)
            throw std::length_error{"Matrix column number must be positive value"};

    }

}

#endif // CLARENSMATHMATRIX

