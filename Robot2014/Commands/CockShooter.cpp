// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "CockShooter.h"
bool isCocked = Robot::shooter->cockedLimitSwitch;
bool isLatchable = Robot::shooter->latchingLimitSwitch;
CockShooter::CockShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	
}
// Called just before this Command runs the first time
void CockShooter::Initialize() {
	if(isLatchable == false)
	{
		Robot::shooter->loadingMotor->Set(-0.5);
	}
	
	if(isLatchable == true)
	{
		Robot::shooter->latch->Set(Relay::kOff);
		Robot::shooter->loadingMotor->Set(0.5);
	}
}
// Called repeatedly when this Command is scheduled to run
void CockShooter::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool CockShooter::IsFinished() {
	if(isCocked == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Called once after isFinished returns true
void CockShooter::End() {
	Robot::shooter->loadingMotor->Set(0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CockShooter::Interrupted() {
	End();
}