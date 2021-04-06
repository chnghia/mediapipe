#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/ret_check.h"
#include "mediapipe/framework/formats/image_frame.h"

namespace mediapipe {

namespace {
  constexpr char kImageFrameTag[] = "IMAGE";
}  // namespace

class ImageDebuggerCalculator : public CalculatorBase {
public:
  static ::mediapipe::Status GetContract(CalculatorContract* cc);
  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
};
REGISTER_CALCULATOR(ImageDebuggerCalculator);

::mediapipe::Status ImageDebuggerCalculator::GetContract(CalculatorContract* cc) {
  if (cc->Inputs().HasTag(kImageFrameTag)) {
    cc->Inputs().Tag(kImageFrameTag).Set<ImageFrame>();
  }
  return ::mediapipe::OkStatus();
}

::mediapipe::Status ImageDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status ImageDebuggerCalculator::Process(CalculatorContext* cc) {
  // RET_CHECK(!cc->Inputs().Tag(kDetectionsTag).IsEmpty());
  const auto& input_img = cc->Inputs().Tag(kImageFrameTag).Get<ImageFrame>();
  // cv::Mat input_mat = formats::MatView(&input_img);

  // RectSpec specs = GetCropSpecs(cc, input_img.Width(), input_img.Height());
  std::cout << "image size: w=" << input_img.Width() << ", h=" << input_img.Height() << std::endl; 

  // std::vector<Detection> detections;
  // detections = cc->Inputs().Tag(kDetectionsTag).Get<std::vector<Detection>>();
  // std::cout << "detections size: " << detections.size() << std::endl;

  // debug here

  return ::mediapipe::OkStatus();
}

}