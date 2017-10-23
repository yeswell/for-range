#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#include "test.h"
#include "for_range.h"



using namespace std;



void time_test(int m, int n)
{
    cout << "Start time test." << endl;
    cout << endl;

    cout << "The test considers the ratio of time spent on a service operation" << endl;
    cout << "in a loop using range(a, b, step) to time in the usually cycle." << endl;
    cout << "Vars 'time_r' and 'time_u' is a service time (in ticks) for one" << endl;
    cout << "iteration of the loop using range(a, b, step) and usually cycle." <<endl;
    cout << endl;

    cout << "The average values are calculated on 1e+m starts." << endl;
    cout << "Number of iterations in each loop is 1e+n." << endl;
    cout << endl;

    cout << "(m, n): time_r / time_u" << endl;
    cout << "-----------------------" << endl;

    for (auto i: range(m))
    {
        for (auto j: range(n))
        {
            cout << "(" << i << ", " << j << "): ";
            cout << work_time_ratio(pow(10, i), pow(10, j));
            cout << endl;
        }
    }

    cout << endl;
    cout << "End time test." << endl;
}

double work_time_ratio(int M, int N)
{
    int sum = 0;
    double time_r = 0, time_u = 0;

    auto seed = chrono::system_clock::now().time_since_epoch();
    auto gen  = default_random_engine( seed.count() );
    auto rand = uniform_int_distribution <int> (1, M);

    for (auto i: range(M))
    {
        int begin = i + rand(gen);
        int end   = N + begin;

        time_r += time_range_for(begin, end, 1, &sum);
        time_u += time_usual_for(begin, end, 1, &sum);
    }

    return ( time_r / time_u );
}

double time_usual_for(int begin, int end, int step, int * ret)
{
    using namespace std::chrono;

    high_resolution_clock::time_point t_1, t_2;
    auto t_s = duration<double>::zero();

    *ret = 0;

    for ( auto i = begin; i != end; i += step )
    {
        t_1 = high_resolution_clock::now();
        *ret += i;
        t_2 = high_resolution_clock::now();

        t_s += (t_2 - t_1);
    }

    t_1 = high_resolution_clock::now();
    for ( auto i = begin; i != end; i += step )
    {
        *ret += i;
    }
    t_2 = high_resolution_clock::now();

    return (duration<double>(t_2 - t_1 - t_s)).count();
}

double time_range_for(int begin, int end, int step, int * ret)
{
    using namespace std::chrono;

    high_resolution_clock::time_point t_1, t_2;
    auto t_s = duration<double>::zero();

    *ret = 0;

    for ( auto i : range(begin, end, step) )
    {
        t_1 = high_resolution_clock::now();
        *ret += i;
        t_2 = high_resolution_clock::now();

        t_s += (t_2 - t_1);
    }

    t_1 = high_resolution_clock::now();
    for ( auto i : range(begin, end, step) )
    {
        *ret += i;
    }
    t_2 = high_resolution_clock::now();

    return (duration<double>(t_2 - t_1 - t_s)).count();
}
