// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "LoadShooter.h"
LoadShooter::LoadShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void LoadShooter::Initialize() {
	printf("Loading the Shooter! \r\n");
	
	loadingTimer.Reset();
	
	isTimerRunning = false;
	
	if(Robot::shooter->latchingLimitSwitch->Get() == false)
	{
//		TODO: Check the sign of the value being set
		Robot::shooter->loadingMotor->Set(0.3);
	}
}
// Called repeatedly when this Command is scheduled to run
void LoadShooter::Execute() {
	
	printf("Motor Power: %f Time: %f \r\n", Robot::shooter->loadingMotor->Get(), loadingTimer.Get());
		
	if(Robot::shooter->latchingLimitSwitch->Get() && !(isTimerRunning))
	{
		loadingTimer.Start();
		isTimerRunning = true;
//		TODO: Check if kOff is the right call
		Robot::shooter->latch->Set(Relay::kOff);
		Robot::shooter->loadingMotor->Set(0);
	}
	
}
// Make this return true when this Command no longer needs to run execute()
bool LoadShooter::IsFinished() {
	return loadingTimer.Get() > 0.2;
}
// Called once after isFinished returns true
void LoadShooter::End() {
	Robot::shooter->loadingMotor->Set(0);
	loadingTimer.Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoadShooter::Interrupted() {
	End();
}
