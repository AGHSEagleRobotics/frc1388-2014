// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Claw.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/RotateClaw.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
Claw::Claw() : PIDSubsystem("Claw", 0.025, 0.0, 0.0) {
	SetAbsoluteTolerance(0.2);
	GetPIDController()->SetContinuous(false);
	LiveWindow::GetInstance()->AddActuator("Claw", "PIDSubsystem Controller", GetPIDController());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	quadClawEncoder = RobotMap::clawQuadClawEncoder;
	armMotor = RobotMap::clawArmMotor;
	backLimitSwitch = RobotMap::clawBackLimitSwitch;
	frontLimitSwitch = RobotMap::clawFrontLimitSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	
	//Set the intial position to false so we can reset later
	initializedPosition = false;
	savePosition = (POSITION_SHOOT);
	
}
double Claw::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return quadClawEncoder->PIDGet();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}
void Claw::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	
	//we need to invert the motor so it will run the correct direction
	output = -output;
	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
	armMotor->PIDWrite(output);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}
void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new RotateClaw());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Claw::GoToSavedPosition()
{
	SetSetpoint(savePosition);
}
void Claw::Reset()
{
	GetPIDController()->Reset();
}
void Claw::CheckLimits()
{
	//this command utilizes SetOutputRange to limit the motor based on limit switches 
	if(frontLimitSwitch->Get() == true)
	{
		// if front limit switch is hit this limits the motor from running forward
		SetOutputRange(CLAW_MIN_POWER,0.0);
	}
	else if(backLimitSwitch->Get() == true)
	{
		// if backlimitswitch is hit this limit the motor from running backwards
		SetOutputRange(0.0, CLAW_MAX_POWER);
	}
	else 
	{
		//if neither switch is hit this allows full movement of arm
		SetOutputRange(CLAW_MIN_POWER, CLAW_MAX_POWER);
	} 
}
void Claw::SetOutputRange(float min, float max)
{
	GetPIDController()->SetOutputRange(min , max);
}
