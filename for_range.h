#ifndef FOR_RANGE_H
#define FOR_RANGE_H



#include <iterator>



class range : public std::iterator <std::forward_iterator_tag, long long>
{
    private:

        long long i_curr, i_end, i_step;

        inline void init()
        {
            long long diff = i_curr - i_end;

            if ( (i_step != 0) and (((i_step ^ diff) < 0) or (diff == 0)) )
            {
                i_end += i_step + (diff % i_step);
            }
            else
            {
                i_curr = i_end = i_step = 0;
            }
        }



    public:

        range(long long begin, long long end, long long step)
            : i_curr(begin), i_end(end), i_step(step)
        {}

        range(long long begin, long long end)
            : range(begin, end, 1)
        {}

        range(long long N)
            : range(1, N, 1)
        {}

        range begin()
        {
            return init(), range(i_curr, 0, i_step);
        }

        range end()
        {
            return range(i_end, 0, i_step);
        }

        range & operator ++ ()
        {
            return (i_curr += i_step), *this;
        }

        bool operator != (const range & iter)
        {
            return (i_curr != iter.i_curr);
        }

        typename range::reference operator * ()
        {
            return i_curr;
        }
};



#endif // FOR_RANGE_H
