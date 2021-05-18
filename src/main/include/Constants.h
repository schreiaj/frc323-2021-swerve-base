// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ctre/Phoenix.h";

using ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration;
using ctre::phoenix::motorcontrol::can::TalonSRXPIDSetConfiguration;

using ctre::phoenix::motorcontrol::can::SlotConfiguration;

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace frc323 {
  namespace robot {
    namespace drivetrain {
      namespace azimuth {
        // TODO (jdnovak): This is where you can set up current limiting for steering
        constexpr auto ENABLE_CURRENT_LIMIT = true;
        constexpr auto HOLDING_AMPS = 20.0;
        constexpr auto THRESHHOLD_AMPS = 25.0;
        constexpr auto TRIGGER_THRESHOLD_SECONDS = 0.25;

        SupplyCurrentLimitConfiguration k_current_limit_config = SupplyCurrentLimitConfiguration{
            ENABLE_CURRENT_LIMIT, HOLDING_AMPS, THRESHHOLD_AMPS, TRIGGER_THRESHOLD_SECONDS};

        // TODO (jdnovak): Config feedback sensor
        constexpr auto k_feedback_device =
            ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Absolute;

        // TODO (jdnovak): Update these constants as appropriate for the modules.
        // TODO (schreiaj): Ideally these could be read in and set via config files.
        constexpr double k_P = 1.0;
        constexpr double k_I = 0;
        constexpr double k_D = 0.5;
        constexpr double k_F = 0.0;

        // TODO (jdnovak): This sets up the index of the PID config.
        constexpr int k_steering_pid_idx = 0;

        // TODO (jdnovak):
        constexpr auto k_idle_mode = ctre::phoenix::motorcontrol::Brake;

      }  // namespace azimuth
      TalonSRXConfiguration k_azimuth_config;

    };  // namespace drivetrain
  };    // namespace robot
};      // namespace frc323