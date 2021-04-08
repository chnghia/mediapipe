#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/ret_check.h"

namespace mediapipe {

namespace {
  constexpr char kTensorsTag[] = "TENSORS";
}  // namespace

class TensorDebuggerCalculator : public CalculatorBase {
public:
  static ::mediapipe::Status GetContract(CalculatorContract* cc);
  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
};
REGISTER_CALCULATOR(TensorDebuggerCalculator);

::mediapipe::Status TensorDebuggerCalculator::GetContract(CalculatorContract* cc) {
  
  RET_CHECK(cc->Outputs().HasTag(kTensorsTag));
  cc->Outputs().Tag(kTensorsTag).Set<std::vector<Tensor>>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status TensorDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status TensorDebuggerCalculator::Process(CalculatorContext* cc) {
  const auto& input_tensors =
      cc->Inputs().Tag(kTensorsTag).Get<std::vector<Tensor>>();

  int num_values = input_tensors[0].shape().num_elements();
  std::cout << "tensor shape: " << num_values << std::endl;
  // RET_CHECK(!cc->Inputs().Tag(kDetectionsTag).IsEmpty());

  // std::vector<Detection> detections;
  // detections = cc->Inputs().Tag(kDetectionsTag).Get<std::vector<Detection>>();
  // std::cout << "detections size: " << detections.size() << std::endl;

  // debug here

  return ::mediapipe::OkStatus();
}

}