#pragma once

class Vector2 {
public:
	Vector2() : _x(0), _y(0) {}
	Vector2(float x, float y) : _x(x), _y(y) {}
	~Vector2() {}

	float getX() const { return _x; }
	float getY() const { return _y; }

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	Vector2 operator+(const Vector2& other) const {
		return Vector2(_x + other._x, _y + other._y);
	}

	Vector2& operator+=(const Vector2& other) {
		_x += other._x;
		_y += other._y;
		return *this;
	}


	Vector2 operator-(const Vector2& other) const {
		return Vector2(_x - other._x, _y - other._y);
	}


	Vector2& operator-=(const Vector2& other) {
		_x -= other._x;
		_y -= other._y;
		return *this;
	}


	Vector2 operator*(float scalar) const {
		return Vector2(_x * scalar, _y * scalar);
	}


	Vector2& operator*=(float scalar) {
		_x *= scalar;
		_y *= scalar;
		return *this;
	}


	Vector2 operator/(float scalar) const {
		return Vector2(_x / scalar, _y / scalar);
	}


	Vector2& operator/=(float scalar) {
		_x /= scalar;
		_y /= scalar;
		return *this;
	}


	bool operator==(const Vector2& other) const {
		return _x == other._x && _y == other._y;
	}


	bool operator!=(const Vector2& other) const {
		return _x != other._x || _y != other._y;
	}

	void Normalize() {
		float length = sqrt(_x * _x + _y * _y);
		_x /= length;
		_y /= length;
	}

private:
	float _x, _y;
};
