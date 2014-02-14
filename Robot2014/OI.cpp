// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AddedPowerDrive.h"
#include "Commands/ArcadeDrive.h"
#include "Commands/AutonDrive.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/CockShooter.h"
#include "Commands/CockShooterGroup.h"
#include "Commands/Drive.h"
#include "Commands/DriveStraight.h"
#include "Commands/FeedIn.h"
#include "Commands/FeedOff.h"
#include "Commands/FeedOut.h"
#include "Commands/GoToLoad.h"
#include "Commands/GoToShoot.h"
#include "Commands/GoToUp.h"
#include "Commands/HalfCockShooter.h"
#include "Commands/LoadShooter.h"
#include "Commands/PickUp.h"
#include "Commands/PositionDrive.h"
#include "Commands/RestorePosition.h"
#include "Commands/RotateClaw.h"
#include "Commands/SavePosition.h"
#include "Commands/Shoot.h"
#include "Commands/ShootAndCock.h"
#include "Commands/SpeedDrive.h"
#include "Commands/UnloadShooter.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/DriveForward.h"
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	opStick = new Joystick(3);
	
	cockShooterNow = new JoystickButton(opStick, 1);
	cockShooterNow->WhenPressed(new CockShooterGroup());
	feedInNow = new JoystickButton(opStick, 12);
	feedInNow->WhileHeld(new FeedIn());
	stopFeed = new JoystickButton(opStick, 10);
	stopFeed->WhileHeld(new FeedOff());
	feedOutNow = new JoystickButton(opStick, 8);
	feedOutNow->WhileHeld(new FeedOut());
	halfCock = new JoystickButton(opStick, 2);
	halfCock->WhenPressed(new HalfCockShooter());
	buttonPos4 = new JoystickButton(opStick, 5);
	buttonPos4->WhileHeld(new RestorePosition());
	buttonLoad = new JoystickButton(opStick, 4);
	buttonLoad->WhileHeld(new GoToLoad());
	buttonShoot = new JoystickButton(opStick, 3);
	buttonShoot->WhileHeld(new GoToShoot());
	buttonUp = new JoystickButton(opStick, 3);
	buttonUp->WhileHeld(new GoToUp());
	pickUpButton = new JoystickButton(opStick, 2);
	pickUpButton->WhenPressed(new PickUp());
	saveButton = new JoystickButton(opStick, 1);
	saveButton->WhenPressed(new SavePosition());
	rightDriverStick = new Joystick(2);
	
	shootButton2 = new JoystickButton(rightDriverStick, 1);
	shootButton2->WhenPressed(new Shoot());
	leftDriverStick = new Joystick(1);
	
	addDrivePower = new JoystickButton(leftDriverStick, 11);
	addDrivePower->WhenPressed(new AddedPowerDrive());
	positionDriveNow = new JoystickButton(leftDriverStick, 3);
	positionDriveNow->WhileHeld(new PositionDrive());
	speedDriveNow = new JoystickButton(leftDriverStick, 9);
	speedDriveNow->WhenPressed(new SpeedDrive());
	driveNow = new JoystickButton(leftDriverStick, 10);
	driveNow->WhenPressed(new Drive());
	shootButton1 = new JoystickButton(leftDriverStick, 1);
	shootButton1->WhenPressed(new Shoot());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("FeedIn", new FeedIn());
	SmartDashboard::PutData("PositionDrive", new PositionDrive());
	SmartDashboard::PutData("RotateClaw", new RotateClaw());
	SmartDashboard::PutData("Drive", new Drive());
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("SavePosition", new SavePosition());
	SmartDashboard::PutData("RestorePosition", new RestorePosition());
	SmartDashboard::PutData("PickUp", new PickUp());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("GoToUp", new GoToUp());
	SmartDashboard::PutData("GoToLoad", new GoToLoad());
	SmartDashboard::PutData("GoToShoot", new GoToShoot());
	SmartDashboard::PutData("AddedPowerDrive", new AddedPowerDrive());
	SmartDashboard::PutData("ArcadeDrive", new ArcadeDrive());
	SmartDashboard::PutData("LoadShooter", new LoadShooter());
	SmartDashboard::PutData("HalfCockShooter", new HalfCockShooter());
	SmartDashboard::PutData("FeedOut", new FeedOut());
	SmartDashboard::PutData("FeedOff", new FeedOff());
	SmartDashboard::PutData("CockShooterGroup", new CockShooterGroup());
	SmartDashboard::PutData("CockShooter", new CockShooter());
	SmartDashboard::PutData("ShootAndCock", new ShootAndCock());
	SmartDashboard::PutData("UnloadShooter", new UnloadShooter());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getOpStick() {
	return opStick;
}
Joystick* OI::getRightDriverStick() {
	return rightDriverStick;
}
Joystick* OI::getLeftDriverStick() {
	return leftDriverStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
float OI::getRightXAxis()
{
	return Robot::JoystickDeadband(rightDriverStick->GetAxis(Joystick::kXAxis));
}
float OI::getRightYAxis()
{
	return Robot::JoystickDeadband(rightDriverStick->GetAxis(Joystick::kYAxis));
}
float OI::getRightZAxis()
{
	return Robot::JoystickDeadband(rightDriverStick->GetAxis(Joystick::kZAxis));
}
float OI::getLeftYAxis()
{
	return Robot::JoystickDeadband(leftDriverStick->GetAxis(Joystick::kYAxis));
}
