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
#define LOADING_SPEED 1
#define COCKING_SPEED -1
#define STOPPING_SPEED 0
// TODO: Do we want to have the motor fight the backdrive with power or will it heat up?
#define HOLD_SPEED -0.15
CockShooter::CockShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void CockShooter::Initialize() {
	state = unload;
}
// Called repeatedly when this Command is scheduled to run
void CockShooter::Execute() {
	isLoaded = Robot::shooter->latchingLimitSwitch->Get();
	isCocked = Robot::shooter->cockedLimitSwitch->Get();
//	isBacked = Robot::shooter->backLimitSwitch->Get();
	
	switch(state)
	{
		case unload:
			Robot::shooter->SetLoadingMotor(LOADING_SPEED);
			if(isLoaded)
			{
				state = cock;	
				printf("State is Cock! \r\n");
			}
		break;
		case cock:
			Robot::shooter->SetLoadingMotor(COCKING_SPEED);
			if(isCocked)
			{
				state = hold;
				printf("State is Hold! \r\n");
			}
		break;
//		case end:
//			Robot::shooter->SetLoadingMotor(STOPPING_SPEED);
//			if(isBacked)
//			{
//				state = unload;
//			}
		case hold:
			Robot::shooter->SetLoadingMotor(HOLD_SPEED);
			if(isCocked == false)
			{
				printf("State is Cock! \r\n");
				state = cock;
			}
		break;
	}
}
// Make this return true when this Command no longer needs to run execute()
bool CockShooter::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void CockShooter::End() {
	Robot::shooter->SetLoadingMotor(0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CockShooter::Interrupted() {
	End();
}
