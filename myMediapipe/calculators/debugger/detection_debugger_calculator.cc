#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/formats/detection.pb.h"
#include "mediapipe/framework/port/ret_check.h"

namespace mediapipe {

typedef std::vector<Detection> Detections; 

namespace {
constexpr char kDetectionsTag[] = "DETECTIONS";
}  // namespace

class DetectionDebuggerCalculator : public CalculatorBase {
public:
  static ::mediapipe::Status GetContract(CalculatorContract* cc);
  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
};
REGISTER_CALCULATOR(DetectionDebuggerCalculator);

::mediapipe::Status DetectionDebuggerCalculator::GetContract(CalculatorContract* cc) {
  RET_CHECK(cc->Inputs().HasTag(kDetectionsTag))
      << "None of the input streams are provided.";

//   if (cc->Inputs().HasTag(kDetectionTag)) {
//     cc->Inputs().Tag(kDetectionTag).Set<Detection>();
//   }
//   if (cc->Inputs().HasTag(kDetectionListTag)) {
//     cc->Inputs().Tag(kDetectionListTag).Set<DetectionList>();
//   }
  if (cc->Inputs().HasTag(kDetectionsTag)) {
    cc->Inputs().Tag(kDetectionsTag).Set<std::vector<Detection>>();
  }
//   cc->Outputs().Tag(kRenderDataTag).Set<RenderData>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status DetectionDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status DetectionDebuggerCalculator::Process(CalculatorContext* cc) {
  RET_CHECK(!cc->Inputs().Tag(kDetectionsTag).IsEmpty());

  std::vector<Detection> detections;
  detections = cc->Inputs().Tag(kDetectionsTag).Get<std::vector<Detection>>();
  std::cout << "detections size: " << detections.size() << std::endl;

  // debug here

  return ::mediapipe::OkStatus();
}

}