#include "units/angle.h"

namespace frc323 {
  namespace helpers {
    namespace swerveUtils {
      double degrees2SensorUnits(units::angle::degree_t degrees);
      units::angle::degree_t sensorUnits2Degrees(double units);
    }  // namespace swerveUtils
  }    // namespace helpers
};     // namespace frc323