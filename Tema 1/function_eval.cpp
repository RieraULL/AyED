#include <cstdio>

#include <cmath>
#include <cassert>

#include <iostream>
#include <fstream>
#include <iomanip>

namespace AyED
{
    typedef double (*funtion_ptr)(double);

    class function_evaluation
    {
    private:
        double left_limit_;
        double right_limit_; 
        double tol_;

        int n_;
   
        double *x_;
        double *y_;

    public:
        function_evaluation(double left, double right, double tol = 1E-2);
        ~function_evaluation(void);

        void evaluate(funtion_ptr f);

        void set_limits(double left, double right, double tol = 1E-2);

        std::ostream &write(std::ostream &os) const;

    private:
        void create_vectors(void);
        void free_vectors(void);
    };

    function_evaluation::function_evaluation(double left, double right, double tol) : left_limit_(left), right_limit_(right), tol_(tol), n_(0), x_(NULL), y_(NULL)
    {
        assert(left_limit_ < right_limit_);

        create_vectors();
    }

    function_evaluation::~function_evaluation(void)
    {
        free_vectors();
    }

    void function_evaluation::create_vectors(void)
    {
        free_vectors();

        n_ = ceil((right_limit_ - left_limit_) / tol_);

        x_ = new double[n_];
        y_ = new double[n_];

        assert(x_ != NULL);
        assert(y_ != NULL);
    }

    void function_evaluation::free_vectors(void)
    {
        if (x_ != NULL)
        {
            delete[] x_;
            x_ = NULL;
        }

        if (y_ != NULL)
        {
            delete[] y_;
            y_ = NULL;
        }
    }

    void function_evaluation::set_limits(double left, double right, double tol)
    {
        assert(left < right);

        tol_ = tol;

        left_limit_ = left;
        right_limit_ = right;

        create_vectors();
    }

    void function_evaluation::evaluate(funtion_ptr f)
    {
        assert(f != NULL);

        for (int i = 0; i < n_; i++)
        {
            x_[i] = left_limit_ + i * tol_;
            y_[i] = f(x_[i]);
        }
    }

    std::ostream &function_evaluation::write(std::ostream &os) const
    {
        os << "#" << std::setw(11) << "x" << std::setw(11) << "y" << std::endl;

        for (int i = 0; i < n_; i++)
        {
            os << " " << std::setw(11) << std::fixed << std::setprecision(7) << x_[i] << std::setw(11) << std::fixed << std::setprecision(7) << y_[i] << std::endl;
        }

        return os;
    }

}

int main(void)
{
    AyED::function_evaluation f(-2 * M_1_PI, 2 * M_PI, 1E-3);

    f.evaluate(sin);

    {
        std::ofstream output_file("sin.dat");
        f.write(output_file);
        output_file.close();
    }
 
    f.evaluate(cos);

    {
        std::ofstream output_file("cos.dat");
        f.write(output_file);
        output_file.close();
    }    

    f.evaluate(tan);

    {
        std::ofstream output_file("tan.dat");
        f.write(output_file);
        output_file.close();
    }       

    return 0;
}