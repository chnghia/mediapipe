#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/ret_check.h"
#include "mediapipe/framework/formats/rect.pb.h"

namespace mediapipe {


namespace {
constexpr char kRectTag[] = "RECT";
constexpr char kNormRectTag[] = "NORM_RECT";
}  // namespace

class RectDebuggerCalculator : public CalculatorBase {
public:
  static ::mediapipe::Status GetContract(CalculatorContract* cc);
  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
};
REGISTER_CALCULATOR(RectDebuggerCalculator);

::mediapipe::Status RectDebuggerCalculator::GetContract(CalculatorContract* cc) {
  if (cc->Inputs().HasTag(kRectTag)) {
    cc->Inputs().Tag(kRectTag).Set<Rect>();
  }
  if (cc->Inputs().HasTag(kNormRectTag)) {
    cc->Inputs().Tag(kNormRectTag).Set<NormalizedRect>();
  }
  return ::mediapipe::OkStatus();
}

::mediapipe::Status RectDebuggerCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));

  // options_ = cc->Options<::mediapipe::AnglesToDetectionCalculatorOptions>();
  return ::mediapipe::OkStatus();
}

::mediapipe::Status RectDebuggerCalculator::Process(CalculatorContext* cc) {
  if (cc->Inputs().HasTag(kRectTag)) {
    const auto& rect = cc->Inputs().Tag(kRectTag).Get<Rect>();
    // Only use the rect if it is valid.
    // if (rect.width() > 0 && rect.height() > 0 && rect.x_center() >= 0 &&
    //     rect.y_center() >= 0) {
    int x_center = rect.x_center();
    int y_center = rect.y_center();
    int crop_width = rect.width();
    int crop_height = rect.height();
    float rotation = rect.rotation();
    // }
    std::cout << "rect (x_center, y_center, crop_width, crop_height, rotation): " 
              << x_center << "," 
              << y_center << ","
              << crop_width << ","
              << crop_height << ","
              << rotation << std::endl;
  } else if (cc->Inputs().HasTag(kNormRectTag)) {
    const auto& norm_rect =
        cc->Inputs().Tag(kNormRectTag).Get<NormalizedRect>();
    // if (norm_rect.width() > 0.0 && norm_rect.height() > 0.0) {
    float normalized_width = norm_rect.width();
    float normalized_height = norm_rect.height();
    float x_center = norm_rect.x_center();
    float y_center = norm_rect.y_center();
    float rotation = norm_rect.rotation();
    // }
    std::cout << "norm_rect (x_center, y_center, norm_width, norm_height, rotation): " 
              << x_center << "," 
              << y_center << ","
              << normalized_width << ","
              << normalized_height << ","
              << rotation << std::endl;
  }
  // RET_CHECK(!cc->Inputs().Tag(kDetectionsTag).IsEmpty());

  // std::vector<Detection> detections;
  // detections = cc->Inputs().Tag(kDetectionsTag).Get<std::vector<Detection>>();
  // std::cout << "detections size: " << detections.size() << std::endl;

  // debug here

  return ::mediapipe::OkStatus();
}

}