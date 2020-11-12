#include <towr/models/robot_model.h>

#include <towr/models/examples/monoped_model.h>
#include <towr/models/examples/biped_model.h>
#include <towr/models/examples/hyq_model.h>
#include <towr/models/examples/anymal_model.h>
#include "towr/models/my_models/mini_cheetah_model.h"

namespace towr {


NewRobotModel::NewRobotModel(Robot robot)
{
  switch (robot) {
    case Monoped:
      dynamic_model_   = std::make_shared<MonopedDynamicModel>();
      kinematic_model_ = std::make_shared<MonopedKinematicModel>();
      break;
    case Biped:
      dynamic_model_   = std::make_shared<BipedDynamicModel>();
      kinematic_model_ = std::make_shared<BipedKinematicModel>();
      break;
    case Hyq:
      dynamic_model_   = std::make_shared<HyqDynamicModel>();
      kinematic_model_ = std::make_shared<HyqKinematicModel>();
      break;
    case Anymal:
      dynamic_model_   = std::make_shared<AnymalDynamicModel>();
      kinematic_model_ = std::make_shared<AnymalKinematicModel>();
      break;
    case MiniCheetah:
      dynamic_model_ = std::make_shared<MiniCheetahDynamicModel>();
      kinematic_model_= std::make_shared<MiniCheetahKinematicModel>();
      break;
    default:
      assert(false); // Error: Robot model not implemented.
      break;
  }
}
