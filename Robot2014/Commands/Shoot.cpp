// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shoot.h"
#define TIMEOUT 3
//#define HALFTIME 1
Shoot::Shoot() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Shoot::Initialize() {
	shootTimer.Reset();
	shootTimer.Start();
	Robot::tusks->SetTusks(false);
	Robot::shooter->SetLoadingMotor(-1);
	printf("Shoot has started \r\n");
}
// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
//	printf("Time = %f", shootTimer.Get());
//	if(shootTimer.Get() > HALFTIME)
//		Robot::shooter->SetLoadingMotor(0.7);
	bool backLimitSwitch = Robot::shooter->backLimitSwitch->Get();
	if(backLimitSwitch)
	{
	printf("Back Limit Switch is TRUE! \r\n");
	}
	else
	{
		printf("Back Limit Switch is FALSE! \r\n");
	}
}
// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
//	if(shootTimer.Get() > TIMEOUT)
	bool backLimitSwitch = Robot::shooter->backLimitSwitch->Get();
	if(backLimitSwitch == true || shootTimer.Get() > TIMEOUT)
		return true;
	else
		return false;
}
// Called once after isFinished returns true
void Shoot::End() {
	Robot::shooter->SetLoadingMotor(0);
	printf("Shoot has ended \r\n");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	End();
}
