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

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/AircontrolModule.h"
#include "Subsystems/CubeIntake.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/ScissorLift.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"
#include "ControllerState.h"
#include "Commands/Teleoperation.h"

// This is a enum that's going to be scale or switch
enum
{
	AUTO_SWITCH,	// = 0
	AUTO_SCALE		// = 1
};

// What side of the field we are lined up on
enum
{
	AUTO_START_LEFT,		// = 0
	AUTO_START_RIGHT		// = 1
};

enum
{
	TURN_LEFT,
	TURN_RIGHT
};

// return +-1 based on whether a number > or < 0
inline double SignOf(double value)
{
	return (value < 0.0 ? -1.0 : 1.0);
}

//this is a method that will give you the absolute value whenever you need it
//(used multiple times in the program)
inline bool Equals (double value1, double value2, double tolerance)
{
	return (fabs(value1 - value2) < tolerance);
}

class Robot : public frc::TimedRobot {
public:
	static double autoLength;
	static double autoWidth;
	static double autoStraightMotorSpeed;
	static double autoTurnMotorSpeed;
	static double autoDwellTime;
	static double autoScissorMotorSpeed;

	// longDistance is the distance before the first turn.
	// shortDistance is the distance to the device after the turn.
	// 1st array value is switch, 2nd array value is scale.
	static std::vector<double> longDistance;	// from field measurements!
	static std::vector<double> shortDistance;	// from field measurements!

	static std::vector<double> autoTurnAngle;
	static std::vector<double> startSideTurnFactor;

	frc::Command* autonomousCommand = nullptr;
	Teleoperation* teleopCommand = nullptr;
	//std::unique_ptr<DriveGoStraight> pDriveGoStraight;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<ControllerState> controllerState1;	// use this instead of OI
	static std::unique_ptr<ControllerState> controllerState2;	// use this instead of OI
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;
	frc::SendableChooser<std::string> positionChooser; //Selection for starting position
	frc::SendableChooser<std::string> objectiveChooser; //Selection for what we want to get to
	frc::SendableChooser<double> dwellChooser; //Dwell time chooser

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<DriveTrain> driveTrain;
	static std::shared_ptr<AircontrolModule> aircontrolModule;
	static std::shared_ptr<CubeIntake> cubeIntake;
	static std::shared_ptr<ScissorLift> scissorLift;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void tankDrive();
	void drive();
	void alexAsked();
	void PCMod();
};
#endif
