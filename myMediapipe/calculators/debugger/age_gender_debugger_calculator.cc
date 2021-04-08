#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/ret_check.h"
#include "myMediapipe/framework/formats/age_gender.pb.h"

namespace mediapipe {

namespace {
  constexpr char kAgeGenderTag[] = "AGEGENDER";
  constexpr char kAgeGendersTag[] = "AGEGENDERS";
}  // namespace

class AgeGenderDebuggerCalculator : public CalculatorBase {
public:
  static ::mediapipe::Status GetContract(CalculatorContract* cc);
  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
};
REGISTER_CALCULATOR(AgeGenderDebuggerCalculator);

::mediapipe::Status AgeGenderDebuggerCalculator::GetContract(CalculatorContract* cc) {
  
  if (cc->Inputs().HasTag(kAgeGenderTag)) {
    cc->Inputs().Tag(kAgeGenderTag).Set<AgeGender>();
  }

  return ::mediapipe::OkStatus();
}

::mediapipe::Status AgeGenderDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status AgeGenderDebuggerCalculator::Process(CalculatorContext* cc) {
  RET_CHECK(!cc->Inputs().Tag(kAgeGenderTag).IsEmpty());

  const auto& input_agegender =
        cc->Inputs().Tag(kAgeGenderTag).Get<AgeGender>();

  std::cout << "gender: " << input_agegender.gender() << std::endl;
  std::cout << "age: " << input_agegender.age() << std::endl;
  // std::vector<Detection> detections;
  // detections = cc->Inputs().Tag(kDetectionsTag).Get<std::vector<Detection>>();
  // std::cout << "detections size: " << detections.size() << std::endl;

  // debug here

  return ::mediapipe::OkStatus();
}

}