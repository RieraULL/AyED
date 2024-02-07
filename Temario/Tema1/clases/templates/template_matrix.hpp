#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

namespace AyED
{

    template <class T>
    class matrix
    {

    public:
        matrix(void) : m_(0),
                       n_(0),
                       v_(NULL) {}

        matrix(int m, int n) : m_(m),
                               n_(n),
                               v_(NULL)
        {
            build();
        }

        ~matrix(void)
        {
            destroy();
        }

        void resize(int m, int n)
        {
            destroy();
            m_ = m;
            n_ = n_;

            build();
        }

        T &at(int i, int j)
        {
            return v_[pos(i, j)];
        }

        T at(int i, int j) const
        {
            return v_[pos(i, j)];
        }

        int get_m(void) const
        {
            return m_;
        }

        int get_n(void) const
        {
            return n_;
        }

        std::ostream &write(std::ostream &os) const
        {

            os << std::setw(4) << m_ << std::endl;
            os << std::setw(4) << n_ << std::endl;
            os << std::endl;

            for (int i = 1; i <= m_; i++)
            {
                for (int j = 1; j <= n_; j++)
                    os << v_[pos(i, j)] << " ";

                os << std::endl;
            }

            return os;
        }

        std::istream &read(std::istream &is)
        {
            destroy();

            is >> m_;
            is >> n_;

            build();

            for (int i = 1; i <= m_; i++)
                for (int j = 1; j <= n_; j++)
                    is >> v_[pos(i, j)];

            return is;
        }

        int pos(int i, int j) const
        {
            return (i - 1) * n_ + j - 1;
        }

    private:
        void build(void)
        {
            v_ = new T[m_ * n_];
        }

        void destroy(void)
        {
            if (v_)
                delete[] v_;
        }

    private:
        int m_;
        int n_;

        T *v_;
    };

    template <>
    std::ostream &matrix<int>::write(std::ostream &os) const
    {

        os << std::setw(4) << m_ << std::endl;
        os << std::setw(4) << n_ << std::endl;
        os << std::endl;

        for (int i = 1; i <= m_; i++)
        {
            for (int j = 1; j <= n_; j++)
                os << std::setw(5) << v_[pos(i, j)] << " ";

            os << std::endl;
        }

        return os;
    }

    template <>
    std::ostream &matrix<double>::write(std::ostream &os) const
    {

        os << std::setw(4) << m_ << std::endl;
        os << std::setw(4) << n_ << std::endl;
        os << std::endl;

        for (int i = 1; i <= m_; i++)
        {
            for (int j = 1; j <= n_; j++)
                os << std::setw(10) << std::fixed << std::setprecision(4) << v_[pos(i, j)] << " ";

            os << std::endl;
        }

        return os;
    }

}
