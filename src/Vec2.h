//
// Created by Lars on 08/06/2019.
//

#ifndef LENSESIM_VEC2_H
#define LENSESIM_VEC2_H

#include <cmath> // pow
#include <type_traits> // enable_if, is_arithmetic
#include "utils.h" // almost_equal

template<typename value_type = double>
struct Vec2 {

    /// Constructors ///
    Vec2() = default;
    Vec2(const Vec2& other) = default;
    Vec2(value_type mX, value_type mY) : x(mX), y(mY) {}

    /// Conversion Operator ///
    template<typename NewType>
    constexpr explicit operator Vec2<NewType>() const {
        return Vec2<NewType>(static_cast<NewType>(x), static_cast<NewType>(y));
    }

    /// Operators ///

    template<typename T>
    using enable_if_arithmetic = typename std::enable_if<std::is_arithmetic<T>::value, bool>::type;

    // henceforth: ovt = other value type
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator=(const Vec2<ovt>& other) {
        x = static_cast<value_type>(other.x);
        y = static_cast<value_type>(other.y);
        return *this;
    }

    Vec2<value_type> operator+() const {
        return *this;
    }

    Vec2<value_type> operator-() const {
        return Vec2<value_type>(-x, -y);
    }

    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator+=(const Vec2<ovt>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator-=(const Vec2<ovt>& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // vectorial multiplication never yields another vector
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator*=(const Vec2<ovt>& other) = delete;

    // scalar multiplication
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator*=(const ovt& other) {
        x *= other;
        y *= other;
        return *this;
    }

    // vectorial division does not exist
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator/=(const Vec2<ovt>& other) = delete;

    // scalar division
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type>& operator/=(const ovt& other) {
        x /= other;
        y /= other;
        return *this;
    }

    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type> operator+(const Vec2<ovt>& other) const {
        Vec2<value_type> result(*this);
        result += other;
        return result;
    }

    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type> operator-(const Vec2<ovt>& other) const {
        Vec2<value_type> result = *this;
        result -= other;
        return result;
    }

    // scalar multiplication
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type> operator*(const ovt& other) const {
        Vec2<value_type> result = *this;
        result *= other;
        return result;
    }

    // commutative
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    friend Vec2<value_type> operator*(const ovt& other, const Vec2& vec) {
        return vec * other;
    }

    // vectorial division does not exist
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type> operator/(const Vec2<ovt>& other) const = delete;

    // scalar division
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    Vec2<value_type> operator/(const ovt& other) const {
        Vec2<value_type> result = *this;
        result /= other;
        return result;
    }

    // dot product
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    friend value_type operator*(const Vec2<value_type>& v1, const Vec2<ovt>& v2) {
        return static_cast<value_type>(v1.x * v2.x + v1.y * v2.y);
    }


    /// Utility ///

    // 2-d cross product
    template<typename ovt, enable_if_arithmetic<ovt> = true>
    value_type cross_product(const Vec2<ovt>& other) const {
        return static_cast<value_type>(x * other.y - y * other.x);
    }

    template<typename ovt, enable_if_arithmetic<ovt> = true>
    value_type sq_distance_to(const Vec2<ovt>& other) const {
        return static_cast<value_type>(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    value_type sq_magnitude() {
        return static_cast<value_type>(std::pow(x, 2) + std::pow(y, 2));
    }

    Vec2<value_type> normalized() {
        value_type mag = std::sqrt(sq_magnitude());
        if (mag == 0) {

        }
        return (*this) / mag;
    }

    void zero() {
        x = 0;
        y = 0;
    }
    
    
    /// Member Data ///

    value_type x = 0;
    value_type y = 0;

};

#endif //LENSESIM_VEC2_H
