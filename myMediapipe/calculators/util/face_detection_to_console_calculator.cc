// Copyright 2020 Lisandro Bravo.
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

#include "absl/memory/memory.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/calculator_options.pb.h"
#include "mediapipe/framework/formats/detection.pb.h"
#include "myMediapipe/framework/formats/angles.pb.h"
#include "mediapipe/framework/port/ret_check.h"
#include "ncurses.h"
#include <fstream>


namespace mediapipe {

namespace {
constexpr char kDetectionsTag[] = "DETECTIONS";
}  // namespace

// Writes Landmarks and Angles to a CSV file with the intention to generate data_ 
// to train a model to recognize static gestures.
// If debug is enabled
// it will also open a terminal to display current data through ncurses lib   
//
// Example config:
// node {
//   calculator: "FaceDetectionToConsoleCalculator"
//   input_stream: "DETECTIONS:face_detections"
// }


class FaceDetectionToConsoleCalculator : public CalculatorBase {
public:
  FaceDetectionToConsoleCalculator() {}
  ~FaceDetectionToConsoleCalculator() override {}
  FaceDetectionToConsoleCalculator(const FaceDetectionToConsoleCalculator&) = delete;
  FaceDetectionToConsoleCalculator& operator=(const FaceDetectionToConsoleCalculator&) = delete;

  static ::mediapipe::Status GetContract(CalculatorContract* cc);

  ::mediapipe::Status Open(CalculatorContext* cc) override;
  ::mediapipe::Status Close(CalculatorContext* cc) override;

  ::mediapipe::Status Process(CalculatorContext* cc) override;

private:
  uint16_t getFPS(double currentUS); 
  FaceDetectionToConsoleCalculator options_;
  uint32_t processedFrames; 
  std::ofstream outputFile;
};

REGISTER_CALCULATOR(FaceDetectionToConsoleCalculator);

::mediapipe::Status FaceDetectionToConsoleCalculator::GetContract(CalculatorContract* cc) {
  RET_CHECK(cc->Inputs().HasTag(kDetectionsTag)
      << "None of the input streams are provided.";

  if (cc->Inputs().HasTag(kDetectionsTag)) {
    cc->Inputs().Tag(kDetectionsTag).Set<std::vector<Detection>>();
  }
  
  return ::mediapipe::OkStatus();
}

::mediapipe::Status FaceDetectionToConsoleCalculator::Open(CalculatorContext* cc) {
  cc->SetOffset(TimestampDiff(0));
  options_ = cc->Options<FaceDetectionToConsoleCalculator>();
  
  processedFrames = 0;

  if(options_.has_file_name()){
    outputFile.open(options_.file_name());  
  }
    
  return ::mediapipe::OkStatus();
  
}
::mediapipe::Status FaceDetectionToConsoleCalculator::Close(CalculatorContext* cc) {
  endwin();
  if (outputFile.is_open()) outputFile.close();    
  return ::mediapipe::OkStatus();

}

::mediapipe::Status FaceDetectionToConsoleCalculator::Process(CalculatorContext* cc) {
  // Only process if there's input landmarks.
  if (cc->Inputs().Tag(kDetectionsTag).IsEmpty())
  {
    return ::mediapipe::OkStatus();
  }

  const auto &detections = cc->Inputs()
                              .Tag(kDetectionsTag)
                              .Get<std::vector<Detection>>();

  //Do not process if no hand is present
  // if(!landmarks[0].x()) return ::mediapipe::OkStatus(); 
  
  const auto fps = getFPS(cc->InputTimestamp().Seconds());
  if(fps < options_.minfps())  return ::mediapipe::OkStatus();

  processedFrames++;

  if(options_.debug_to_terminal()){
     initscr(); /* Start curses mode */
     clear();
     std::string header = "Output: "; 
    //  header.append(options_.file_name());
     header.append("\nNumber of Processed Frames:");
     header.append(std::to_string(processedFrames));
     header.append("\tFPS:");
     header.append(std::to_string(fps));
     printw(header.c_str());
  }
 
  // for (const auto &landmark : landmarks)
  // {
  //   const unsigned char lmIndex = (&landmark - &landmarks[0]);
    
  //   if(options_.debug_to_terminal()){
  //     std::string dispText = "LM:"; 
  //     dispText.append(std::to_string(lmIndex));
  //     dispText.append("\tX:");
  //     dispText.append(std::to_string(landmark.x()));
  //     dispText.append("\tY:");
  //     dispText.append(std::to_string(landmark.y()));
  //     dispText.append("\tDegrees 1:");
  //     dispText.append(std::to_string(angles[lmIndex].angle1()));
  //     dispText.append("\tDegrees 2:");
  //     dispText.append(std::to_string(angles[lmIndex].angle2()));


  //     move(lmIndex + 2,0);
	//     printw(dispText.c_str());	
	    
  //   }

  //   if (outputFile.is_open()){
  //     const char* delimiter = ",";
  //     std::string outText ="";
  //     outText.append(std::to_string(lmIndex));
  //     outText.append(delimiter);
  //     outText.append(std::to_string(landmark.x()));
  //     outText.append(delimiter);
  //     outText.append(std::to_string(landmark.y()));
  //     outText.append(delimiter);
  //     outText.append(std::to_string(angles[lmIndex].angle1()));
  //     outText.append(delimiter);
  //     outText.append(std::to_string(angles[lmIndex].angle2()));
  //     outText.append("\n");
  //     outputFile << outText;

  //   }


    /*if((&landmark - &landmarks[0])==0){
        std::cout  << "X:" << std::to_string(landmark.x()) << " - " << landmark_data->x() << "\n";
      }*/
  }
  if (options_.debug_to_terminal() refresh();			/* Print it on to the real screen */

  // cc->Outputs()
  //     .Tag(kAngleDataTag)
  //     .Add(output_angles.release(), cc->InputTimestamp());
  return ::mediapipe::OkStatus();
}

uint16_t FaceDetectionToConsoleCalculator::getFPS(double currentUS){
  static double oldUS=0;
  double deltaUS = currentUS-oldUS;
  oldUS = currentUS;
  
  if (deltaUS>0) return uint16_t(1/deltaUS);
  else return 0;
} 

}  // namespace mediapipe


