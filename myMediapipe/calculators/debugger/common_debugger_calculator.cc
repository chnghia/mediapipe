#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/ret_check.h"

namespace mediapipe {

namespace {
}  // namespace

class CommonDebuggerCalculator : public CalculatorBase {
public:
  static ::mediapipe::Status GetContract(CalculatorContract* cc);
  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
};
REGISTER_CALCULATOR(CommonDebuggerCalculator);

::mediapipe::Status CommonDebuggerCalculator::GetContract(CalculatorContract* cc) {
  
  return ::mediapipe::OkStatus();
}

::mediapipe::Status CommonDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status CommonDebuggerCalculator::Process(CalculatorContext* cc) {
  // RET_CHECK(!cc->Inputs().Tag(kDetectionsTag).IsEmpty());

  // std::vector<Detection> detections;
  // detections = cc->Inputs().Tag(kDetectionsTag).Get<std::vector<Detection>>();
  // std::cout << "detections size: " << detections.size() << std::endl;

  // debug here

  return ::mediapipe::OkStatus();
}

}