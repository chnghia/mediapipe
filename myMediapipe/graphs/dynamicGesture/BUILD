# Copyright 2020 Lisandro Bravo.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

licenses(["notice"])  # Apache 2.0

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "dynamic_gestures_desktop_cpu_calculators",
    deps = [
        # ":hand_detection_cpu",
        # ":hand_landmark_cpu",
        # ":renderer_cpu",
        # ":gestures_cpu",
        # ":dynamic_gestures_cpu",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)