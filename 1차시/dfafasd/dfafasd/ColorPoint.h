#pragma once
#include "point.h"
class ColorPoint :public Point
{
private:
	string color;
public:
	string setColor(string c);
	void showColorPoint();
};
string ColorPoint::setColor(string c) {
	this->color= c;
	return color;
}
void ColorPoint::showColorPoint() {
	cout << this->color << endl;
	showPoint();
}