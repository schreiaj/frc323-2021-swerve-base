#include "Constants.h"
#include <ctre/Phoenix.h>
#include <frc/geometry/Rotation2d.h>
#include <rev/CANSparkMax.h>
#include <units/velocity.h>

class SwerveModule {
 public:
  SwerveModule(int kDriveMotorId, int kSteeringMotorId, units::degree_t kSteeringOffset);

  void SetModuleState(units::degree_t kAngle, units::velocity::feet_per_second_t kWheelSpeed);

  units::degree_t GetModuleRelativeAngle();

 private:
  // This section is static, so it is shared across all modules.

  // The ratio between the steering encoder and the actual wheel.
  constexpr static const double kSteeringRatio = 1.0;

  // The ratio between the drive encoder and the wheel.
  // TODO (jdnovak): Update this on actual numbers
  constexpr static const double kDriveRatio = 5.8;

  // This section is the start of module dependent fields.

  // TODO (schreiaj): The motor controller types will have to change if not
  // using Neo drive/TalonSRX steer. This will be an involved change. Ideally
  // refactor to create a motor wrapper.
  rev::CANSparkMax mDriveMotor;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX mSteeringMotor;
  const frc::Rotation2d mSteeringOffset;
};
