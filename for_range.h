#ifndef FOR_RANGE_H
#define FOR_RANGE_H



#include <iterator>



using namespace std;



class range : public iterator <forward_iterator_tag, long long>
{

    private:

        long long i_current, i_end, i_step;



    public:

        range(long long begin, long long end, long long step = 1)
        {
            i_current = begin;
            i_end     = end;
            i_step    = step;
        }

        range(const range & iter)
        {
            i_current = iter.i_current;
            i_end     = iter.i_end;
            i_step    = iter.i_step;
        }

        range begin()
        {
            return range(i_current, 0, i_step);
        }

        range end()
        {
            return range(i_end, 0, i_step);
        }

        range & operator ++ ()
        {
            i_current += i_step;

            return *this;
        }

        bool operator != (const range & iter)
        {
            if ( i_step == 0 )
            {
                return false;
            };

            if ( i_step > 0 )
            {
                return ( i_current <= iter.i_current );
            }
            else
            {
                return ( i_current >= iter.i_current );
            }
        }

        typename range::reference operator * ()
        {
            return ( i_current );
        }
};



#endif // FOR_RANGE_H
