#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "test.h"
#include "for_range.h"



void test(int m, int n)
{
    double t_r, t_u;

    cout << "Test start." << endl;
    cout << endl;

    cout << "The test considers the ratio of time spent on a service operation" << endl;
    cout << "in a loop using range(a, b, step) to time in the usually cycle." << endl;
    cout << "Vars time_r and time_u is a service time (in milliseconds) for one" << endl;
    cout << "iteration of the loop using the range(a, b, step) and the usually cycle." <<endl;
    cout << "Var x is the ratio of the time_r to the time_u." << endl;
    cout << endl;

    cout << "The average values are calculated on 10^m starts." << endl;
    cout << "Number of iterations in each loop is 10^n." << endl;
    cout << endl;

    cout << "(m, n): x = time_r / time_u" << endl;
    cout << "---------------------------" << endl;

    for (auto i: range(1, m))
    {
        for (auto j: range(1, n))
        {
            cout << "(" << i << ", " << j << "): ";
            cout << work_time_ratio(pow(10, i), pow(10, j), &t_r, &t_u) << " = ";
            cout << t_r << " / ";
            cout << t_u << endl;
        }
    }

    cout << endl;
    cout << "Test end." << endl;
}


double work_time_ratio(int M, int N, double * t_r_mean, double * t_u_mean)
{
    int begin, end, sum;

    *t_r_mean = *t_u_mean = 0;

    srand( time(NULL) );

    for ( auto i: range(1, M) )
    {
        begin = (i + rand()) % M;
        end = begin + N;

        double t = time_for_sum(begin, end, 1, &sum);

        *t_r_mean += time_range_for(begin, end, 1, &sum) - t;
        *t_u_mean += time_usual_for(begin, end, 1, &sum) - t;
    }

    *t_r_mean /= M;
    *t_u_mean /= M;

    return ( *t_r_mean / *t_u_mean );
}

double time_for_sum(int begin, int end, int step, int * ret)
{
    long long clocks = 0;
    clock_t clk_1, clk_2;

    *ret = 0;

    for ( auto i : range(begin, end, step) )
    {
        clk_1 = clock();
        *ret += i;
        clk_2 = clock();

        clocks += (clk_2 - clk_1);
    }

    return ( clocks / CLOCKS_PER_SEC );
}

double time_usual_for(int begin, int end, int step, int * ret)
{
    clock_t clk_1, clk_2;

    *ret = 0;

    clk_1 = clock();
    for ( auto i = begin; i <= end; i += step )
    {
        *ret += i;
    }
    clk_2 = clock();

    return ( double(clk_2 - clk_1) / CLOCKS_PER_SEC );
}

double time_range_for(int begin, int end, int step, int * ret)
{
    clock_t clk_1, clk_2;

    *ret = 0;

    clk_1 = clock();
    for ( auto i : range(begin, end, step) )
    {
        *ret += i;
    }
    clk_2 = clock();

    return ( double(clk_2 - clk_1) / CLOCKS_PER_SEC );
}
