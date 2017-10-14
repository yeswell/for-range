#include <iostream>
#include <cstdlib>
#include <ctime>

#include "test.h"
#include "for_range.h"



void test()
{
    int begin, end, sum, M, N;
    double t, t_u_mean, t_r_mean;

    srand( time(NULL) );

    M = 1e+6;
    N = 1e+3;

    t_u_mean = t_r_mean = 0;

    for ( auto i: range(1, M) )
    {
        begin = rand() % M;
        end = begin + N;

        t = test_usual_for(begin, end, 1, &sum);
        t_u_mean += (t - t_u_mean) / i;

        t = test_range_for(begin, end, 1, &sum);
        t_r_mean += (t - t_r_mean) / i;
    }

    cout << endl;
    cout << "The average time of execution of the usual FOR: " << (t_u_mean / M) << " seconds" << endl;
    cout << "The average time of execution of the range FOR: " << (t_r_mean / M) << " seconds" << endl;
    cout << endl;
}

double time_for_sum(int begin, int end, int step, int * ret)
{
    long long sum, clocks;
    clock_t clk_1, clk_2;

    sum = 0;
    clocks = 0;

    for ( auto i : range(begin, end, step) )
    {
        clk_1 = clock();
        sum += i;
        clk_2 = clock();

        clocks += (clk_2 - clk_1);
    }

    *ret = sum;

    return ( clocks / CLOCKS_PER_SEC );
}

double test_usual_for(int begin, int end, int step, int * ret)
{
    long long sum;
    double t_for_sum;
    clock_t clk_1, clk_2;

    sum = 0;

    clk_1 = clock();
    for ( auto i = begin; i <= end; i += step )
    {
        sum += i;
    }
    clk_2 = clock();

    t_for_sum = time_for_sum(begin, end, step, ret);

    *ret = sum;

    return ( (double(clk_2 - clk_1) / CLOCKS_PER_SEC) - t_for_sum );
}

double test_range_for(int begin, int end, int step, int * ret)
{
    long long sum;
    double t_for_sum;
    clock_t clk_1, clk_2;

    sum = 0;

    clk_1 = clock();
    for ( auto i : range(begin, end, step) )
    {
        sum += i;
    }
    clk_2 = clock();

    t_for_sum = time_for_sum(begin, end, step, ret);

    *ret = sum;

    return ( (double(clk_2 - clk_1) / CLOCKS_PER_SEC) - t_for_sum );
}
