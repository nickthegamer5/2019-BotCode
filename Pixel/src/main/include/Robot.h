// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "frc/WPILib.h"
#include "frc/commands/Command.h"
#include "frc/livewindow/LiveWindow.h"

// General functions

// return +-1 based on whether a number > or < 0
inline double SignOf(double value)
{
	return (value < 0.0 ? -1.0 : 1.0);
}

// return equality of floating point numbers to a given tolerance
inline bool Equals (double value1, double value2, double tolerance)
{
	return (fabs(value1 - value2) < tolerance);
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/DriveSubSystem.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

// UI for robot
#include "ControllerState.h"

// manually defined commands
#include "Commands/Teleop.h"


class Robot : public frc::TimedRobot {
public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<DriveSubSystem> driveSubSystem;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // Xbox controller(s)
    static std::unique_ptr<ControllerState> controllerState;

    // Command Groups
    static std::unique_ptr<Teleop> teleop;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif
