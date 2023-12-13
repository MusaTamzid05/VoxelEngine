#include "linear_interpolator.h"


LinearInterpolator::LinearInterpolator(float input_min, float input_max, float output_min, float output_max):
    x1(input_min),
    x2(input_max),
    y1(output_min),
    y2(output_max) {}



LinearInterpolator::~LinearInterpolator() {

}

float LinearInterpolator::map(float value) const {
    float a = (y2 - y1) / (x2 - x1);
    float b = value - x1;

    return y1 + a * b;
}
