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

  if (cc->Inputs().HasTag(kAgeGendersTag)) {
    cc->Inputs().Tag(kAgeGendersTag).Set<std::vector<AgeGender>>();
  }

  return ::mediapipe::OkStatus();
}

::mediapipe::Status AgeGenderDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status AgeGenderDebuggerCalculator::Process(CalculatorContext* cc) {
  // RET_CHECK(!cc->Inputs().Tag(kAgeGenderTag).IsEmpty());

  if (cc->Inputs().HasTag(kAgeGenderTag)) {
    const auto& input_agegender =
          cc->Inputs().Tag(kAgeGenderTag).Get<AgeGender>();

    std::cout << "gender: " << input_agegender.gender() << std::endl;
    std::cout << "age: " << input_agegender.age() << std::endl;
  }

  if (cc->Inputs().HasTag(kAgeGendersTag)) {
    const auto& input_agegenders =
        cc->Inputs().Tag(kAgeGendersTag).Get<std::vector<AgeGender>>();
    std::cout << "agegenders size: " << input_agegenders.size() << std::endl;
  }
  

  // debug here

  return ::mediapipe::OkStatus();
}

}