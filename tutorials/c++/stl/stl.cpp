#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
#include <array>
#include <random>

using namespace std;

struct dupa{
    int x;
    int y;
};

std::string toString( const std::pair< size_t, size_t >& data)
{
    std::ostringstream str;
    str << data.first << ", " << data.second;
    return str.str();
}

void heaps()
{
    std::vector<int> v{3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};
    std::vector<dupa> dv{{1, 2}, {3, 5}, {4, 6}, {1, 2}};
    std::cout << "initially v: " << std::endl;
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, ", " ));
    //std::for_each(v.cbegin(), v.cend(), [] (int x) {std::cout << x << ", ";} );
    std::cout << std::endl;

    /* make_heap
     *
     * Complexity
     *
     *  At most 3*std::distance(first, last) comparisons.
     *
     */

    std::make_heap(v.begin(), v.end());

    std::cout << "after make_heap" << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << std::endl;


    /* push_heap
     *
     * Complexity
     *
     *  At most log(N) comparisons where N=std::distance(first, last).
     */

    v.push_back(6);
    std::cout << "before push_heap: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<<std::endl;

    std::push_heap(v.begin(), v.end());
    std::cout << "after push_heap: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout<<std::endl;


    /* pop_heap
     *
     * Complexity
     *
     *  At most 2×log(N) comparisons where N=std::distance(first, last).
     */

    std::pop_heap(v.begin(), v.end());  //move the largest to the end

    std::cout << "after pop heap:" << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));

    int largest = v.back();
    std::cout << "largest element is at the end of vector: " << largest << std::endl;

    std::cout << "heap without largest element:" << std::endl;
    v.pop_back();
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    /* sort_heap
     *
     * Complexity
     *
     *  At most 2×N×log(N) comparisons where N=std::distance(first, last).
     *
     *  possible implementation:
        template< class RandomIt >
        void sort_heap( RandomIt first, RandomIt last )
        {
            while (first != last)
                std::pop_heap(first, last--);
        }

        template< class RandomIt, class Compare >
        void sort_heap( RandomIt first, RandomIt last, Compare comp )
        {
            while (first != last)
            std::pop_heap(first, last--, comp);
        }
    */

    std::sort_heap(v.begin(), v.end());

    std::cout << "after sort heap:" << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

}

void sorts()
{
    std::vector<int> v{3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};
    std::vector<dupa> dv{{1, 2}, {3, 5}, {4, 6}, {1, 2}};
    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));

    /* sort
     *
     * Complexity:
     *
     *  O(N·log(N)), where N = std::distance(first, last) comparisons. (since c++11)
     *
     *  possible implementation:
    */

    // sort using a standard library compare function object
    //std::sort(v.begin(), v.end(), std::greater<int>());
    //
    // sort using a custom function object
  //  struct {
  //      bool operator()(int a, int b) const
  //      {
  //          return a < b;
  //      }
  //  } customLess;
  //  std::sort(s.begin(), s.end(), customLess);

    // sort using a lambda expression
    //std::sort(s.begin(), s.end(), [](int a, int b) {
    //    return a > b;
    //});

    std::sort(v.begin(), v.end());

    std::cout << "after sort:" << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));

    /* partial_sort
     *
     * Complexity:
     *
     *  O(N·log(N)), where N = std::distance(first, last) comparisons. (since c++11)
     *
     *  possible implementation:
    */

    std::array<int, 10> arr{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::cout << "arr before partial_sort" << std::endl;
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::partial_sort(arr.begin(), arr.begin() + 3, arr.end());

    std::cout << "arr after partial_sort" << std::endl;
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    v = {3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};

    std::cout << "vec before partial_sort " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    std::partial_sort(v.begin(), v.begin()+5, v.end());


    std::cout << "vec after partial_sort " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    /* nth_element
     *
     * Complexity
     *
     *  1,3) Linear in std::distance(first, last) on average.
     *  2,4) O(N) applications of the predicate, and O(N log N) swaps, where N = last - first.     *
    */

    v = {3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};
    std::cout << "vector before nth_element" << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";

    std::nth_element(v.begin(), v.begin()+8, v.end());

    std::cout << "vector after nth_element: \n";
    std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << ", ";});
    std::cout << "\n";

    v = {3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());

    std::cout << "vector after nth_element: \n";
    std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << ", ";});
    std::cout << "\n";

    /* inplace_marge
     *
     * Complexity
     *
     * Given N = std::distance(first, last)},
     *
     *   1,3) Exactly N-1 comparisons if enough additional memory is available. If the memory is insufficient, O(N log N) comparisons.
     *   2,4) O(N log N) comparisons.
    */

    //std::inplace_merge(first, middle, last);
    // inplace_merge merges vector with two sorted parts {1,2,5,10,  2,4,6,7,8,11}
    v = {1,2,5,10,  2,4,6,7,8,11};
    std::inplace_merge(v.begin(), v.begin()+4, v.end());
    for(auto x : v) std::cout << x << ", ";
    std::cout << "\n";
}

void partitions()
{
    std::vector<int> v{3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};
    std::vector<dupa> dv{{1, 2}, {3, 5}, {4, 6}, {1, 2}};
    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";

    /* partition
     * 1) Reorders the elements in the range [first, last) in such a way that
     *    that all elements for which the predicate p returns true precede
     *    the elements for which predicate p returns false.
     *    Relative order of the elements is not preserved.
     * 2) Same as (1), but executed according to policy.
     *    This overload does not participate in overload resolution unless
     *    std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> is true
     * Complexity:
     *
     *
     *
     *  possible implementation:
    */

    /*
    template<class ForwardIt, class UnaryPredicate>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
    {
        first = std::find_if_not(first, last, p);
        if (first == last) return first;

        for (ForwardIt i = std::next(first); i != last; ++i) {
            if (p(*i)) {
                std::iter_swap(i, first);
                ++first;
            }
        }
        return first;
    }
    */

    auto it = std::partition(v.begin(), v.end(), [](int i){ return i % 2 == 0;});
    std::cout << "vector after partition" << std::endl;
    for(auto x : v) std::cout << x << ", "; std::cout << std::endl;

    std::cout << "partitioned vector" << std::endl;
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";

    /* partition_point
     *
     *  Examines the partitioned (as if by std::partition) range [first, last) and
     *  locates the end of the first partition, that is, the first element that
     *  does not satisfy p or last if all elements satisfy p.
     *
     * Complexity:
     *
     *  O(n).
     *
     *  Given N = std::distance(first, last), performs O(log N) applications of the predicate p.
     *  However, for non-RandomAccessIterators, the number of iterator increments is O(N).
     *
     *  possible implementation:
    */

    v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto is_even = [](int i){ return i % 2 == 0; };
    std::partition(v.begin(), v.end(), is_even);

    auto p = std::partition_point(v.begin(), v.end(), is_even);

    std::cout << "Before partition point:\n    ";
    std::copy(v.begin(), p, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nAfter partition point:\n    ";
    std::copy(p, v.end(), std::ostream_iterator<int>(std::cout, " "));
}

void parmutations()
{
    std::vector<int> v{3, 5, 2,  4, 7, 10, 5, 8, 9, 1, 7};
    std::vector<dupa> dv{{1, 2}, {3, 5}, {4, 6}, {1, 2}};
    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";

    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
    }

    std::cout << "after sort:\n";
    for (int n: v)  std::cout << n << ' ';
    std::cout << '\n';

    /* rotate
     *
     * Complexity
     *
     *  Linear in the distance between first and last
     *
     * Possible implementation:
     *
        template <class ForwardIt>
        ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
        {
            if(first == n_first) return last;
            if(n_first == last) return first;

            ForwardIt next = n_first;

            do {
                std::iter_swap(first++, next++);
                if (first == n_first) n_first = next;
            }
            while (next != last);

            ForwardIt ret = first;

            for(next = n_first; next != last; ) {
                std::iter_swap(first++, next++);
                if(first == n_first) n_first = next;
                else if(next == last) next = n_first;
            }

            return ret;
        }
     *
     */

    std::rotate(v.begin(), v.begin()+2, v.end());
    std::cout << "simple rotate left by two elements: " << "\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::rotate(v.begin(), v.begin()+4, v.end());
    std::cout << "simple next rotate left by four elements: " << "\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::cout << "simple rotate right by one element: " << "\n";
    std::rotate(v.rbegin(), v.rbegin()+1, v.rend());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    /* shuffle
     *
    * random_shuffle - deprecated
     *
     * Complexity
     *
     *  Linear in the distance between first and last
     *
     * Possible implementation:
     *
        template<class RandomIt, class URBG>
        void shuffle(RandomIt first, RandomIt last, URBG&& g)
        {
            typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
            typedef std::uniform_int_distribution<diff_t> distr_t;
            typedef typename distr_t::param_type param_t;

            distr_t D;
            diff_t n = last - first;
            for (diff_t i = n-1; i > 0; --i) {
                using std::swap;
                swap(first[i], first[D(g, param_t(0, i))]);
            }
        }
    */

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);
    std::cout << "after shuffle:\n";
    std::copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    /* reverse
     *
     * 1) Reverses the order of the elements in the range [first, last)
     *
     * Possible implementation:
     *
        template<class BidirIt>
        void reverse(BidirIt first, BidirIt last)
        {
            while ((first != last) && (first != --last)) {
                std::iter_swap(first++, last);
            }
        }
    */

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";

    std::reverse(v.begin(), v.end());

    std::cout << "after reverse\n";
    std::copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;


    //v = {3, 5, 2,  4, 7, 10, 5, 8, 9, 1, 7};
    v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "initialy v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";



    /* next_permutation
     *
     * Complexity
     *
     *  At most N/2 swaps, where N = std::distance(first, last).
     *  Averaged over the entire sequence of permutations, typical implementations
     *  use about 3 comparisons and 1.5 swaps per call.
     *
     * Possible implementation:

        template<class BidirIt>
        bool next_permutation(BidirIt first, BidirIt last)
        {
            if (first == last) return false;
            BidirIt i = last;
            if (first == --i) return false;

            while (true) {
                BidirIt i1, i2;

                i1 = i;
                if (*--i < *i1) {
                    i2 = last;
                    while (!(*i < *--i2))
                        ;
                    std::iter_swap(i, i2);
                    std::reverse(i1, last);
                    return true;
                }
                if (i == first) {
                    std::reverse(first, last);
                    return false;
                }
            }
        }

     *
     *
     *
    */

    std::next_permutation(v.begin(), v.end());

    std::cout << "after next_permutation:\n";
    std::copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::next_permutation(v.begin(), v.end());

    std::cout << "after next_permutation:\n";
    std::copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::string s = "aba";
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));

    /* prev_permutation
     *
     * Complexity
     *
     * At most (last-first)/2 swaps.
     * Averaged over the entire sequence of permutations,
     * typical implementations use about 3 comparisons and 1.5 swaps per call.
     *
     * Possible implementation:


        template<class BidirIt>
        bool prev_permutation(BidirIt first, BidirIt last)
        {
            if (first == last) return false;
            BidirIt i = last;
            if (first == --i) return false;

            while (1) {
                BidirIt i1, i2;

                i1 = i;
                if (*i1 < *--i) {
                    i2 = last;
                    while (!(*--i2 < *i))
                        ;
                    std::iter_swap(i, i2);
                    std::reverse(i1, last);
                    return true;
                }
                if (i == first) {
                    std::reverse(first, last);
                    return false;
                }
            }
        }

     *
     *
     *
    */

    std::prev_permutation(v.begin(), v.end());

    std::cout << "after prev_permutation:\n";
    std::copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    s="abc";
    std::sort(s.begin(), s.end(), std::greater<char>());
    do {
        std::cout << s << ' ';
    } while(std::prev_permutation(s.begin(), s.end()));
    std::cout << '\n';
}

void queries()
{
    std::vector<int> v{3, 5, 2,  4, 7, 10, 5, 8, 9, 1, 7};
    std::vector<dupa> dv{{1, 2}, {3, 5}, {4, 6}, {1, 2}};
    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";

    /* count
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    std::count(v.begin(), v.end(), 3);

    /* accumulate
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    /*auto result = */std::accumulate(v.begin(), v.end(), 1 , std::multiplies<int>());

    /* reduce    since c++17
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

 //   auto sum = std::reduce(v.begin(), v.end());

    /* partial_sum
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    /*auto result = */std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    /* inclusive_scan   since c++17
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    /* exclusive_scan since c++17
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    //std::exclusive_scan(v.begin(), v.end());

    /* inner_product
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    std::vector<int> a{0, 1, 2, 3, 4};
    std::vector<int> b{5, 4, 2, 3, 1};

    int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "Inner product of a and b: " << r1 << '\n';

    int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0,
                                std::plus<>(), std::equal_to<>());

    std::cout << "Number of pairwise matches between a and b: " <<  r2 << '\n';

    /* adjacent_difference()
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    std::adjacent_difference(v.begin(), v.end(), v.begin());

    /* sample since c++17
     *
     * Complexity
     *
     *
     *
     * Possible implementation:
     *
     */

    //std::sample();
}



int main()
{
//    heaps();
//    sorts();
//    partitions();
//    parmutations();
    queries();


    return 0;
}

