#pragma once

class Rect_co {
private:
	double xpos;
	double ypos;
public:

	Rect_co() : xpos(0), ypos(0) {};
	Rect_co(double x, double y) : xpos(x), ypos(y) {};
	Rect_co(const Rect_co& copy) : xpos(copy.xpos), ypos(copy.ypos) {};
	Rect_co& operator=(const Rect_co& p);

	friend Rect_co operator+(const Rect_co& p1, const Rect_co& p2);
	friend Rect_co operator-(const Rect_co& p1, const Rect_co& p2);
	friend Rect_co operator*(const Rect_co& p1, const Rect_co& p2);
	friend Rect_co operator/(const Rect_co& p1, const Rect_co& p2);


	Rect_co& operator+=(const Rect_co& p);
	Rect_co& operator-=(const Rect_co& p);
	Rect_co& operator*=(const Rect_co& p);
	Rect_co& operator/=(const Rect_co& p);

	Rect_co& operator*(const double& i);
	Rect_co& restart(double x = 0.0, double y = 0.0);

	void setY(double i) {
		this->ypos = i;
	}

	double getY() {
		return this->ypos;
	}

	void setX(double i) {
		this->xpos = i;
	}

	double getX() {
		return this->xpos;
	}
};

