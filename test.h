#ifndef TEST_H
#define TEST_H



void test(int m, int n);

double work_time_ratio(int M, int N, double * t_r_mean, double * t_u_mean);

double time_for_sum(int begin, int end, int step, int * ret);

double time_range_for(int begin, int end, int step, int * ret);
double time_usual_for(int begin, int end, int step, int * ret);



#endif // TEST_H
