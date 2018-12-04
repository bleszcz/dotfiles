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
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", " ));
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
     *  O(N·log(N)), where N = std::distance(first, last) comparisons. (since c++11)
     *
    */

    std::nth_element(v.begin(), v.end());

}

int main()
{
    heaps();
    sorts();

    return 0;
}

