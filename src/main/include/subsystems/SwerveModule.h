#include <ctre/Phoenix.h>
#include <frc/geometry/Rotation2d.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class SwerveModule
{
public:
    SwerveModule(int kDriveMotorId, int kSteeringMotorId, units::radian_t kSteeringOffset);

private:
    // This section is static, so it is shared across all modules.

    // TODO (jdnovak): Update these constants as appropriate for the modules.
    // TODO (schreiaj): Ideally these could be read in and set via config files.
    constexpr static const double k_P = 1.0;
    constexpr static const double k_I = 0;
    constexpr static const double k_D = 0.5;

    // The ratio between the steering encoder and the actual wheel.
    constexpr static const double steeringRatio = 1.0;

    // The ratio between the drive encoder and the wheel.
    // TODO (jdnovak): Update this on actual numbers
    constexpr static const double driveRatio = 5.8;

    // This section is the start of module dependent fields.

    // TODO (schreiaj): The motor controller types will have to change if not using Neo drive/TalonSRX steer.
    // This will be an involved change. Ideally refactor to create a motor wrapper.
    const rev::CANSparkMax kDriveMotor;
    const ctre::phoenix::motorcontrol::can::WPI_TalonSRX kSteeringMotor;
    const frc::Rotation2d kSteeringOffset;
};
