#ifndef TOWR_MODELS_NEW_ROBOT_MODEL_H_
#define TOWR_MODELS_NEW_ROBOT_MODEL_H_

#include <map>
#include <string>

#include <towr/models/dynamic_model.h>
#include <towr/models/kinematic_model.h>

namespace towr {

  struct NewRobotModel{
    /**
     * @brief Robots for which kinematic and dynamic models are implemented.
     *
     * See folder: \ref include/towr/models/examples for more information.
     * @ingroup Robots
     */
    enum Robot { Monoped, ///< one-legged hopper
                 Biped,   ///< two-legged
                 Hyq,     ///< four-legged robot from IIT
                 Anymal,  ///< four-legged robot from Anybotics
                 MiniCheetah, ///< four-legged robot from MIT
                 ROBOT_COUNT };


    NewRobotModel() = default;
    NewRobotModel(Robot robot);

    KinematicModel::Ptr kinematic_model_;
    DynamicModel::Ptr   dynamic_model_;
  };


  const static std::map<NewRobotModel::Robot, std::string> robot_names =
  {
    {NewRobotModel::Monoped, "Monoped"},
    {NewRobotModel::Biped,   "Biped"},
    {NewRobotModel::Hyq,     "Hyq"},
    {NewRobotModel::Anymal,  "Anymal"},
    {NewRobotModel::MiniCheetah, "MiniCheetah"}
  };

} /* namespace towr */

#endif
