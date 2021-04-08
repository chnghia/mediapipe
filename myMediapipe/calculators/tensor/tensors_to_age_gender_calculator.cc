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

#include "myMediapipe/calculators/tensor/tensors_to_age_gender_calculator.pb.h"
#include "mediapipe/framework/api2/node.h"
#include "mediapipe/framework/calculator_framework.h"
#include "myMediapipe/framework/formats/age_gender.pb.h"
#include "mediapipe/framework/formats/tensor.h"
#include "mediapipe/framework/port/ret_check.h"

namespace mediapipe {
namespace api2 {

namespace {

inline float Sigmoid(float value) { return 1.0f / (1.0f + std::exp(-value)); }

// float ApplyActivation(
//     ::mediapipe::TensorsToLandmarksCalculatorOptions::Activation activation,
//     float value) {
//   switch (activation) {
//     case ::mediapipe::TensorsToLandmarksCalculatorOptions::SIGMOID:
//       return Sigmoid(value);
//       break;
//     default:
//       return value;
//   }
// }

}  // namespace

// A calculator for converting Tensors from regression models into landmarks.
// Note that if the landmarks in the tensor has more than 5 dimensions, only the
// first 5 dimensions will be converted to [x,y,z, visibility, presence]. The
// latter two fields may also stay unset if such attributes are not supported in
// the model.
//
// Input:
//  TENSORS - Vector of Tensors of type kFloat32. Only the first tensor will be
//  used. The size of the values must be (num_dimension x num_landmarks).
//
//  FLIP_HORIZONTALLY (optional): Whether to flip landmarks horizontally or
//  not. Overrides corresponding side packet and/or field in the calculator
//  options.
//
//  FLIP_VERTICALLY (optional): Whether to flip landmarks vertically or not.
//  Overrides corresponding side packet and/or field in the calculator options.
//
// Input side packet:
//   FLIP_HORIZONTALLY (optional): Whether to flip landmarks horizontally or
//   not. Overrides the corresponding field in the calculator options.
//
//   FLIP_VERTICALLY (optional): Whether to flip landmarks vertically or not.
//   Overrides the corresponding field in the calculator options.
//
// Output:
//  LANDMARKS(optional) - Result MediaPipe landmarks.
//  NORM_LANDMARKS(optional) - Result MediaPipe normalized landmarks.
//
// Notes:
//   To output normalized landmarks, user must provide the original input image
//   size to the model using calculator option input_image_width and
//   input_image_height.
// Usage example:
// node {
//   calculator: "TensorsToAgeGenderCalculator"
//   input_stream: "TENSORS:agegender_tensors"
//   output_stream: "LANDMARKS:landmarks"
//   output_stream: "NORM_LANDMARKS:landmarks"
//   options: {
//     [mediapipe.TensorsToLandmarksCalculatorOptions.ext] {
//       num_landmarks: 21
//
//       input_image_width: 256
//       input_image_height: 256
//     }
//   }
// }
class TensorsToAgeGenderCalculator : public Node {
 public:
  static constexpr Input<std::vector<Tensor>> kInTensors{"TENSORS"};
  // static constexpr Input<bool>::SideFallback::Optional kFlipHorizontally{
  //     "FLIP_HORIZONTALLY"};
  // static constexpr Input<bool>::SideFallback::Optional kFlipVertically{
  //     "FLIP_VERTICALLY"};
  static constexpr Output<AgeGender>::Optional kOutAgeGender{"AGEGENDER"};
  static constexpr Output<NormalizedAgeGender>::Optional
      kOutNormalizedAgeGenderList{"NORM_AGEGENDER"};
  MEDIAPIPE_NODE_CONTRACT(kInTensors, kOutAgeGender, kOutNormalizedAgeGender);

  mediapipe::Status Open(CalculatorContext* cc) override;
  mediapipe::Status Process(CalculatorContext* cc) override;

 private:
  mediapipe::Status LoadOptions(CalculatorContext* cc);
//   int num_landmarks_ = 0;
  ::mediapipe::TensorsToAgeGenderCalculatorOptions options_;
};
MEDIAPIPE_REGISTER_NODE(TensorsToAgeGenderCalculator);

mediapipe::Status TensorsToAgeGenderCalculator::Open(CalculatorContext* cc) {
  MP_RETURN_IF_ERROR(LoadOptions(cc));

  // if (kOutNormalizedAgeGenderList(cc).IsConnected()) {
  //   RET_CHECK(options_.has_input_image_height() &&
  //             options_.has_input_image_width())
  //       << "Must provide input with/height for getting normalized landmarks.";
  // }
  // if (kOutAgeGenderList(cc).IsConnected() &&
  //     (options_.flip_horizontally() || options_.flip_vertically() ||
  //      kFlipHorizontally(cc).IsConnected() ||
  //      kFlipVertically(cc).IsConnected())) {
  //   RET_CHECK(options_.has_input_image_height() &&
  //             options_.has_input_image_width())
  //       << "Must provide input with/height for using flipping when outputing "
  //          "landmarks in absolute coordinates.";
  // }
  return mediapipe::OkStatus();
}

mediapipe::Status TensorsToAgeGenderCalculator::Process(CalculatorContext* cc) {
  if (kInTensors(cc).IsEmpty()) {
    return mediapipe::OkStatus();
  }
  // bool flip_horizontally =
  //     kFlipHorizontally(cc).GetOr(options_.flip_horizontally());
  // bool flip_vertically = kFlipVertically(cc).GetOr(options_.flip_vertically());

  const auto& input_tensors = *kInTensors(cc);
  // std::cout << "input_tensors size: " << input_tensors.size() << "\n";
  // std::cout << "input_tensors age: " << input_tensors[0];
  int num_classes1 = input_tensors[0].shape().num_elements();
  int num_classes2 = input_tensors[1].shape().num_elements();
  // std::cout << "input_tensors age: " << num_classes1  << std::endl;
  auto a_view = input_tensors[0].GetCpuReadView();
  auto a_raw_scores = a_view.buffer<float>();
  std::vector<float> a_scores {a_raw_scores, a_raw_scores+num_classes1};
  
  std::vector<float> matrix_a(101);
  std::iota(matrix_a.begin(), matrix_a.end(), 0);
  double result = 0;
  result = std::inner_product(a_scores.begin(), a_scores.end(), matrix_a.begin(), 0.0);

  // std::cout << "age score: " << result << std::endl;

  // std::cout << "input_tensors gender: " << num_classes2  << std::endl;
    
  auto view = input_tensors[1].GetCpuReadView();
  auto raw_scores = view.buffer<float>();
  // std::cout << "gender score: " << raw_scores[0] << "," << raw_scores[1] << std::endl;
    
  int num_values = input_tensors[0].shape().num_elements();

  auto output_object = absl::make_unique<AgeGender>();

  output_object->set_age(result);
  if (raw_scores[0] > 0.5) {
    output_object->set_gender(0)
  } else {
    output_object->set_gender(1)
  }

  // Output absolute age gender.
  if (kOutAgeGender(cc).IsConnected()) {
    kOutAgeGender(cc).Send(std::move(output_object));
  }

  return mediapipe::OkStatus();
}

mediapipe::Status TensorsToAgeGenderCalculator::LoadOptions(
    CalculatorContext* cc) {
  // Get calculator options specified in the graph.
  options_ = cc->Options<::mediapipe::TensorsToAgeGenderCalculatorOptions>();
  // RET_CHECK(options_.has_num_landmarks());
  // num_landmarks_ = options_.num_landmarks();

  return mediapipe::OkStatus();
}
}  // namespace api2
}  // namespace mediapipe
