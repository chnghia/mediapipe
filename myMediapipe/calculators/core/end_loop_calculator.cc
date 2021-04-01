// Copyright 2019 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "end_loop_calculator.h"

#include <vector>

#include "myMediapipe/framework/formats/age_gender.pb.h"
#include "mediapipe/util/render_data.pb.h"
#include "tensorflow/lite/interpreter.h"

namespace mediapipe {

// testing detection loop
typedef EndLoopCalculator<std::vector<AgeGenderList>> EndLoopAgeGendersCalculator;
REGISTER_CALCULATOR(EndLoopAgeGendersCalculator);

}  // namespace mediapipe
