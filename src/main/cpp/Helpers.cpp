#include "Helpers.h"
#include <cmath>

// This is a simple function that handles converting from degrees to raw sensor units.
double frc323::helpers::swerveUtils::degrees2SensorUnits(units::angle::degree_t degrees) {
  return degrees.to<double>() / 360.0 * 4096.0;
}
// Returns the angle that a corresponding number of sensor ticks responds to (sensor relative)
units::angle::degree_t frc323::helpers::swerveUtils::sensorUnits2Degrees(double units) {
  return units::angle::degree_t{fmod(units, 4096.0) / 4096.0 * 360.0};
}