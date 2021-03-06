// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "RobotScissorLift.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RobotScissorLift::RobotScissorLift(double motorSpeed): frc::Command() {
    m_motorSpeed = motorSpeed;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::scissorLift.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RobotScissorLift::Initialize()
{
	if (m_motorSpeed > 1.0)
	{
		m_motorSpeed = 1.0;
	}

	if (m_motorSpeed < -1.0)
	{
		m_motorSpeed = -1.0;
	}
}

// Called repeatedly when this Command is scheduled to run
void RobotScissorLift::Execute()
{
	RobotMap::scissorLiftScissorLiftMotor->Set(m_motorSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool RobotScissorLift::IsFinished()
{
	bool finished = (m_motorSpeed > 0) ?
		RobotMap::scissorLiftDigitalInput1->Get() :
		RobotMap::scissorLiftDigitalInput0->Get();

	return finished;
}

// Called once after isFinished returns true
void RobotScissorLift::End()
{
	RobotMap::scissorLiftScissorLiftMotor->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotScissorLift::Interrupted() {

}
