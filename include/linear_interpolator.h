#ifndef LINEAR_INTERPOLATOR_H
#define LINEAR_INTERPOLATOR_H


struct LinearInterpolator {
    LinearInterpolator(float input_min, float input_max, float output_min, float output_max);
    virtual ~LinearInterpolator();

    float map(float value) const;

    float x1;
    float x2;
    float y1;
    float y2;


};


#endif
