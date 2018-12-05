#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
#include <array>

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

    std::vector<int> v{3, 5, 2, 1, 4, 3, 3, 10, 5, 8, 9, 1, 2, 3};
    std::vector<dupa> dv{{1, 2}, {3, 5}, {4, 6}, {1, 2}};
    std::cout << "initially v: " << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
    std::cout << "\n";


}

int main()
{
//    heaps();
//    sorts();
//    partitions();
    parmutations();


    return 0;
}

