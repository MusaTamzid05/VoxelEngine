#include "linear_interpolator.h"


LinearInterpolator::LinearInterpolator(double input_min, double input_max, double output_min, double output_max):
    x1(input_min),
    x2(input_max),
    y1(output_min),
    y2(output_max) {}



LinearInterpolator::~LinearInterpolator() {

}

double LinearInterpolator::map(double value) const {
    double a = (y2 - y1) / (x2 - x1);
    double b = value - x1;

    return y1 + a * b;
}
