#ifndef LINEAR_INTERPOLATOR_H
#define LINEAR_INTERPOLATOR_H


struct LinearInterpolator {
    LinearInterpolator(double input_min, double input_max, double output_min, double output_max);
    virtual ~LinearInterpolator();

    double map(double value) const;

    double x1;
    double x2;
    double y1;
    double y2;


};


#endif
