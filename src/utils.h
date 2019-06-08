//
// Created by Lars on 08/06/2019.
//

#ifndef LENSESIM_UTILS_H
#define LENSESIM_UTILS_H

#include <type_traits> // enable_if
#include <limits> // is_integer

template<typename T, typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type = true>
bool almost_equal(T x, T y, int ulp = 1) {
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::abs(x-y) <= std::numeric_limits<T>::epsilon() * std::abs(x+y) * ulp
           // unless the result is subnormal
           || std::abs(x-y) < std::numeric_limits<T>::min();
}



#endif //LENSESIM_UTILS_H
