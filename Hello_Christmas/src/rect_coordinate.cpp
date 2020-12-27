#include "rect_coordinate.h"

Rect_co operator+(const Rect_co& p1, const Rect_co& p2) {
	return Rect_co(p1.xpos + p2.ypos, p1.ypos + p2.ypos);
}

Rect_co operator-(const Rect_co& p1, const Rect_co& p2) {
	return Rect_co(p1.xpos - p2.ypos, p1.ypos - p2.ypos);
}

Rect_co operator*(const Rect_co& p1, const Rect_co& p2) {
	return Rect_co(p1.xpos * p2.ypos, p1.ypos * p2.ypos);
}

Rect_co operator/(const Rect_co& p1, const Rect_co& p2) {
	return Rect_co(p1.xpos / p2.ypos, p1.ypos / p2.ypos);
}


Rect_co& Rect_co::operator=(const Rect_co& p) {
	this->xpos = p.xpos;
	this->ypos = p.ypos;
	return *this;
}

Rect_co& Rect_co::operator+=(const Rect_co& p) {
	this->xpos = this->xpos + p.xpos;
	this->ypos = this->ypos + p.ypos;
	return *this;
}

Rect_co& Rect_co::operator-=(const Rect_co& p) {
	this->xpos = this->xpos - p.xpos;
	this->ypos = this->ypos - p.ypos;
	return *this;
}

Rect_co& Rect_co::operator*=(const Rect_co& p) {
	this->xpos = this->xpos * p.xpos;
	this->ypos = this->ypos * p.ypos;
	return *this;
}

Rect_co& Rect_co::operator/=(const Rect_co& p) {
	this->xpos = this->xpos / p.xpos;
	this->ypos = this->ypos / p.ypos;
	return *this;
}

Rect_co& Rect_co::operator*(const double& i) {
	this->xpos = this->xpos * i;
	this->ypos = this->ypos * i;
	return *this;
}

Rect_co& Rect_co::restart(double x, double y) {
	this->xpos = x;
	this->ypos = y;
	return *this;
}