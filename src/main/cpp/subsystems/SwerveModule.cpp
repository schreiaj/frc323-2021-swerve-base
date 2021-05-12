#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule(int kDriveMotorId, int kSteeringMotorId, units::radian_t kSteeringOffset) : kDriveMotor(kDriveMotorId, rev::CANSparkMax::MotorType::kBrushless),
                                                                                                       kSteeringMotor(kSteeringMotorId),
                                                                                                       kSteeringOffset(kSteeringOffset)
{
}