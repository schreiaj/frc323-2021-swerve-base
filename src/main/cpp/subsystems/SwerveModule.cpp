#include "subsystems/SwerveModule.h"
#include "Constants.h"
#include "Helpers.h"
#include <ctre/Phoenix.h>

using frc323::helpers::swerveUtils::degrees2SensorUnits;
using frc323::helpers::swerveUtils::sensorUnits2Degrees;
using frc323::robot::drivetrain::azimuth::k_steering_pid_idx;

SwerveModule::SwerveModule(int kDriveMotorId, int kSteeringMotorId, units::degree_t kSteeringOffset)
    : mDriveMotor(kDriveMotorId, rev::CANSparkMax::MotorType::kBrushless),
      mSteeringMotor(kSteeringMotorId),
      //   We invert the offset here so we can just take in what the module thinks is 0
      //   TODO (schreiaj): Verify this produces the correct results
      mSteeringOffset(-kSteeringOffset) {
  // Steering config, change specifics in appropriate section of Constants.h
  mSteeringMotor.ConfigFactoryDefault();
  mSteeringMotor.SetNeutralMode(frc323::robot::drivetrain::azimuth::k_idle_mode);
  mSteeringMotor.ConfigSupplyCurrentLimit(
      frc323::robot::drivetrain::azimuth::k_current_limit_config);
  mSteeringMotor.Config_kP(k_steering_pid_idx, frc323::robot::drivetrain::azimuth::k_P);
  mSteeringMotor.Config_kI(k_steering_pid_idx, frc323::robot::drivetrain::azimuth::k_I);
  mSteeringMotor.Config_kD(k_steering_pid_idx, frc323::robot::drivetrain::azimuth::k_D);
  mSteeringMotor.Config_kF(k_steering_pid_idx, frc323::robot::drivetrain::azimuth::k_F);
  mSteeringMotor.ConfigSelectedFeedbackSensor(frc323::robot::drivetrain::azimuth::k_feedback_device,
                                              k_steering_pid_idx);

  // TODO (jdnovak): If you want the drive motors to brake, change this to
  // kBrake
  mDriveMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  // mDriveMotor.GetEncoder()
}

// Set the module state to a given angle and wheel velocity
void SwerveModule::SetModuleState(units::degree_t kAngle,
                                  units::velocity::feet_per_second_t kWheelSpeed) {
  mSteeringMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::MotionMagic,
                     degrees2SensorUnits(kAngle + mSteeringOffset.Degrees()));
  // TODO (schreiaj): Compute how to make wheel move at commanded velocity.
}

// Gets the robot relative angle of the module bounded between 0 and 360
units::degree_t SwerveModule::GetModuleRelativeAngle() {
  return sensorUnits2Degrees(mSteeringMotor.GetSelectedSensorPosition()) +
         mSteeringOffset.Degrees();
}