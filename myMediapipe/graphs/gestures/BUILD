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

load(
    "//mediapipe/framework/tool:mediapipe_graph.bzl",
    "mediapipe_binary_graph",
    "mediapipe_simple_subgraph",
)

# static gestures CPU

cc_library(
    name = "static_gestures_desktop_cpu_calculators",
    deps = [
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_detection_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_landmark_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:renderer_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:static_gestures_cpu",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)

# static gestures to file CPU

cc_library(
    name = "static_gestures_to_file_desktop_cpu_calculators",
    deps = [
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_detection_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_landmark_cpu_to_file",
        "//myMediapipe/graphs/gestures/subgraphs_v074:renderer_cpu",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)

# static gestures GPU

cc_library(
    name = "static_gestures_desktop_gpu_calculators",
    deps = [
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_detection_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_landmark_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:renderer_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:static_gestures_cpu",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)

# static gestures to file GPU

cc_library(
    name = "static_gestures_to_file_desktop_gpu_calculators",
    deps = [
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_detection_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_landmark_gpu_to_file",
        "//myMediapipe/graphs/gestures/subgraphs_v074:renderer_gpu",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)

# dynamic gestures CPU

cc_library(
    name = "dynamic_gestures_desktop_cpu_calculators",
    deps = [
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_detection_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_landmark_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:renderer_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:dynamic_gestures_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:dynamic_gestures_cpu_sub_003",
        # ":dynamic_gestures_cpu",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)

# dynamic gestures GPU

cc_library(
    name = "dynamic_gestures_desktop_gpu_calculators",
    deps = [
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_detection_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:hand_landmark_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:renderer_gpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:dynamic_gestures_cpu",
        "//myMediapipe/graphs/gestures/subgraphs_v074:dynamic_gestures_cpu_sub_003",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:gate_calculator",
        "//mediapipe/calculators/core:merge_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/video:opencv_video_decoder_calculator",
        "//mediapipe/calculators/video:opencv_video_encoder_calculator",
    ],
)