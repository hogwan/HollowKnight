#pragma once

class int2
{
public:
	// static이 되어야 합니다.
	static const int2 Left;
	static const int2 Right;
	static const int2 Up;
	static const int2 Down;
	static const int2 Zero;

	// 보통 이런 수학적 클래스는
	// public으로 맴버변수를 두는 편입니다.
public:
	int X = 0;
	int Y = 0;

	// 디폴트 대입연산자.
	void operator=(const int2& _Other)
	{
		X = _Other.X;
		Y = _Other.Y;
	}

	bool operator==(const int2& _Other) const
	{
		return X == _Other.X && Y == _Other.Y;
	}

	bool operator!=(const int2& _Other) const
	{
		return X != _Other.X || Y != _Other.Y;
	}

	int2 operator*(const int _Value) const
	{
		return int2{ X * _Value, Y * _Value };
	}

	int2& operator*=(const int _Value)
	{
		X *= _Value;
		Y *= _Value;
		return *this;
	}

	int2 operator+(const int2& _Other) const
	{
		return { X + _Other.X, Y + _Other.Y };
	}

	void operator+=(const int2& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
	}
};

