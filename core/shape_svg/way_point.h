#include <string>
#include "critical_point.h"
#ifndef __LZ_WAY_POINT__
#define __LZ_WAY_POINT__

namespace Lewzen {
    class WayPoint: public Point2D {
    private:
        std::string _el_id;
        double _el_num;
        bool _is_candidate;
        CriticalPoint (* on_elected) (const shared_ptr<WayPoint> &p);
    public:

    }
}