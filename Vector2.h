#pragma once

#include <cmath> // sqrt関数のために必要

class Vector2 {
public:
	float x, y; // xとyをpublicにして直接アクセス可能にする

	Vector2() : x(0), y(0) {}
	Vector2(const float x, const float y) : x(x), y(y) {}

	~Vector2() {}

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2& operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 operator*(float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}

	Vector2& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2 operator/(float scalar) const {
		return Vector2(x / scalar, y / scalar);
	}

	Vector2& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	bool operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const {
		return x != other.x || y != other.y;
	}

	void Normalize() {
		float length = sqrt(x * x + y * y);
		if (length != 0) { // 0で割ることを避ける
			x /= length;
			y /= length;
		}
	}
};
