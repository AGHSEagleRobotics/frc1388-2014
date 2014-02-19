// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.



#include "AutonomousGroup.h"
#include "GoToShoot.h"
#include "DriveForward.h"
#include "Shoot.h"
#include "CockShooterGroup.h"
#include "AutonDrive.h"
AutonomousGroup::AutonomousGroup() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
	//We found out that you must add the parameters to get the sequential to work
	// 3 sec to zero out
	//Don't cock the shooter because the shooter will be pre-cocked
	//TODO: make sure this is set to the default autonomous commmand 
	//We have to wait for the claw to zero out before we call GoToShoot()
	AddSequential(new WaitCommand(3)); 
	AddSequential(new GoToShoot());
	//Drive to shooting position
	//parameter is feet to drive forward. 11.5 is our current estimate for optimal range
	AddSequential(new AutonDrive(11.5, 0.6));
	AddSequential(new Shoot());
	

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
