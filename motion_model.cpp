#include "motion_model.h"

#include <cmath>

namespace pfilter
{
    MotionModel::MotionModel(int resolution)
        : map_resolution(resolution)
        , alpha_1(0.0)
        , alpha_2(0.0)
        , alpha_3(0.0)
        , alpha_4(0.0)
        , motion_threshold(0.5) // 5cm
    {

    }

    MotionModel::~MotionModel()
    {
        //TODO: Delete allocated memory
    }

    bool MotionModel::isMoving(cv::Vec3d u_t0, cv::Vec3d u_t1)
    {
        double x0 = u_t0[0] / map_resolution;
        double y0 = u_t0[1] / map_resolution;
        double theta0 = u_t0[2];

        double x1 = u_t1[0] / map_resolution;
        double y1 = u_t1[1] / map_resolution;
        double theta1 = u_t1[2];

        double translation_delta = std::sqrt(std::pow(x1 - x0, 2) + std::pow(y1 - y0, 2));
        if(translation_delta < motion_threshold)
            return false;
        return true;
    }

} /* namespace pfilter */