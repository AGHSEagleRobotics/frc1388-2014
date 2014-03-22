// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef CLAW_H
#define CLAW_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
//The below numbers are the number of degrees from the straight up position
#define POSITION_UP			0
#define POSITION_SHOOT 		40
#define POSITION_LOAD 		125
//this is how far we want to set the setpoint effectively setting the motor to go forward
#define SMALL_MOVEMENT  	.2
//Sets how far the claw is aloud to go in degrees
#define CLAW_RANGE_MIN 		0
#define CLAW_RANGE_MAX 		125
//Set max motor power this is default. SetOutputRange will change the max powers in specific instances
#define CLAW_MAX_POWER 		0.50
#define CLAW_MIN_POWER		-0.50
/**
 *
 *
 * @author ExampleAuthor
 */
class Claw: public PIDSubsystem {
 public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Encoder* quadClawEncoder;
	DigitalInput* backLimitSwitch;
	DigitalInput* frontLimitSwitch;
	SpeedController* armMotor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Claw();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void GoToSavedPosition();
	void GoToResetPosition();
	void Reset();
	void CheckLimits ();
	void SetOutputRange(float min, float max);
	double savePosition;
	bool initializedPosition;
	};
#endif
