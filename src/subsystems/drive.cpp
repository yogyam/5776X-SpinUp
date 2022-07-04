#incude "main.h"

using namespace okapi;

Motor rightFront( rightFrontPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

Motor rightBack ( rightBackPort, false, Abstractmotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

Motor leftBack ( leftBackPort, false, Abstractmotor::gearset::blue, Abstractmotor::encoderUnits::degrees);

Motor leftFront ( lefFrontPort, false, Abstractmotor::gearset::blue, Abstractmotor::encoderUnits::degrees);

typedef struct PID pid;
pid park;
pid rotate1;
pid translate1;
int timer1;

std::shared_ptr<ChassisController> drive = ChassisControllerBuilder().withMotors({leftBack, leftFront}, {rightFront, rightBack}).withDimensions(AbstractMotor::gearset::blue, {{4_in, 13.7_in}, okapi::imev5GreenTPR}).build();

void updateDrive() {
  if (controller.getDigital(ControllerDigital::left) == 1){
    leftFront.setBrakeMode(AbstractMotor::brakeMode::hold);
    leftBack.setBrakeMode(AbstractMotor::brakeMode::hold);

    rightFront.setBrakeMode(AbstractMotor::brakeMode::hold);
    rightBack.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
  else if (controller.getDigital(ControllerDigital::right) == 1){
    leftFront.setBrakeMode(AbstractMotor::brakeMode::coast);
    leftBack.setBrakeMode(AbstractMotor::brakeMode::coast);

    rightFront.setBrakeMode(AbstractMotor::brakeMode::coast1);
    rightBack.setBrakeMode(AbstractMotor::brakeMode::coast);
  }
}
