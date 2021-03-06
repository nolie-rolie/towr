/******************************************************************************
Copyright (c) 2018, Alexander W. Winkler. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#ifndef TOWR_TOWR_ROS_INCLUDE_TOWR_ROS_MINI_CHEETAH_MODEL_H_
#define TOWR_TOWR_ROS_INCLUDE_TOWR_ROS_MINI_CHEETAH_MODEL_H_

#include <towr/models/kinematic_model.h>
#include <towr/models/single_rigid_body_dynamics.h>
#include <towr/models/endeffector_mappings.h>

namespace towr {

/**
 * @brief The Kinematics of the quadruped robot Mini Cheetah.
 */
class MiniCheetahKinematicModel : public KinematicModel {
public:
  MiniCheetahKinematicModel () : KinematicModel(4)
  {

    nominal_stance_.at(LF) <<  0.175, 0.11, -0.30;
    nominal_stance_.at(RF) <<  0.175,  -0.11, -0.30;
    nominal_stance_.at(LH) << -0.2, 0.11, -0.30;
    nominal_stance_.at(RH) << -0.2,  -0.11, -0.30;

    max_dev_from_nominal_ << 0.15, 0.06, 0.10;
  }
};

/**
 * @brief The Dynamics of the quadruped robot Mini Cheetah.
 source: https://github.com/mit-biomimetics/Cheetah-Software/blob/master/common/
 include/Dynamics/MiniCheetah.h
 */
class MiniCheetahDynamicModel : public SingleRigidBodyDynamics {
public:
  MiniCheetahDynamicModel()
  : SingleRigidBodyDynamics(3.3,
                    11253*1e-6, 0, 0, 36203*1e-6, 0, 42673*1e-6,
                    4) {}
};

} // namespace towr

#endif /* TOWR_TOWR_ROS_INCLUDE_TOWR_ROS_MINI_CHEETAH_MODEL_H_ */
