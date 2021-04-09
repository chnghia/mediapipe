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

exports_files(["LICENSE"])

load("//mediapipe/framework/port:build_config.bzl", "mediapipe_cc_proto_library")

cc_library(
    name = "landmarks_to_angles_calculator",
    srcs = ["landmarks_to_angles_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//mediapipe/framework/formats:landmark_cc_proto",
        "//myMediapipe/framework/formats:angles_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/strings",
    ],
    alwayslink = 1,
)

proto_library(
    name = "landmarks_and_angles_to_file_calculator_proto",
    srcs = ["landmarks_and_angles_to_file_calculator.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_proto",
    ],
)

mediapipe_cc_proto_library(
    name = "landmarks_and_angles_to_file_calculator_cc_proto",
    srcs = ["landmarks_and_angles_to_file_calculator.proto"],
    cc_deps = [
        "//mediapipe/framework:calculator_cc_proto",
    ],
    visibility = ["//mediapipe:__subpackages__",
                  "//myMediapipe:__subpackages__"],
    deps = [":landmarks_and_angles_to_file_calculator_proto"],
)

cc_library(
    name = "landmarks_and_angles_to_file_calculator",
    srcs = ["landmarks_and_angles_to_file_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        ":landmarks_and_angles_to_file_calculator_cc_proto",
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//mediapipe/framework/formats:landmark_cc_proto",
        "//myMediapipe/framework/formats:angles_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/strings",
        "@system_libs//:libncurses",
        "@system_headers//:headers",
    ],
    alwayslink = 1,
)

proto_library(
    name = "angles_to_detection_calculator_proto",
    srcs = ["angles_to_detection_calculator.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_proto",
    ],
)

mediapipe_cc_proto_library(
    name = "angles_to_detection_calculator_cc_proto",
    srcs = ["angles_to_detection_calculator.proto"],
    cc_deps = [
        "//mediapipe/framework:calculator_cc_proto",
    ],
    visibility = ["//mediapipe:__subpackages__"],
    deps = [":angles_to_detection_calculator_proto"],
)

cc_library(
    name = "angles_to_detection_calculator",
    srcs = ["angles_to_detection_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        ":angles_to_detection_calculator_cc_proto",
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//mediapipe/framework/formats:detection_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "@com_google_absl//absl/memory",
        "@org_tensorflow//tensorflow/lite:framework",

    ],
    alwayslink = 1,
)

cc_library(
    name = "landmarkslist_to_vector_landmarks_calculator",
    srcs = ["landmarkslist_to_vector_landmarks_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//mediapipe/framework/formats:landmark_cc_proto",
        "//mediapipe/framework/port:ret_check",
    ],
    alwayslink = 1,
)

proto_library(
    name = "mqtt_publisher_calculator_proto",
    srcs = ["mqtt_publisher_calculator.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_proto",
    ],
)

mediapipe_cc_proto_library(
    name = "mqtt_publisher_calculator_cc_proto",
    srcs = ["mqtt_publisher_calculator.proto"],
    cc_deps = [
        "//mediapipe/framework:calculator_cc_proto",
    ],
    visibility = ["//mediapipe:__subpackages__"],
    deps = [":mqtt_publisher_calculator_proto"],
)

cc_library(
    name = "mqtt_publisher_calculator",
    srcs = ["mqtt_publisher_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        ":mqtt_publisher_calculator_cc_proto",
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//myMediapipe/framework/formats:mqtt_message_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "//myMediapipe/third_party/simple-mqtt-client:simple-mqtt-client",
    ],
    alwayslink = 1,
)

cc_library(
    name = "face_detection_to_console_calculator",
    srcs = ["face_detection_to_console_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//mediapipe/framework/formats:detection_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/strings",
        "@system_libs//:libncurses",
        "@system_headers//:headers",
    ],
    alwayslink = 1,
)

proto_library(
    name = "age_genders_to_render_data_calculator_proto",
    srcs = ["age_genders_to_render_data_calculator.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_options_proto",
        "//mediapipe/framework:calculator_proto",
        "//mediapipe/util:color_proto",
        "//mediapipe/util:render_data_proto",
    ],
)

mediapipe_cc_proto_library(
    name = "age_genders_to_render_data_calculator_cc_proto",
    srcs = ["age_genders_to_render_data_calculator.proto"],
    cc_deps = [
        "//mediapipe/framework:calculator_cc_proto",
        "//mediapipe/util:color_cc_proto",
    ],
    visibility = ["//mediapipe:__subpackages__",
                  "//myMediapipe:__subpackages__"],
    deps = [":age_genders_to_render_data_calculator_proto"],
)


cc_library(
    name = "age_genders_to_render_data_calculator",
    srcs = ["age_genders_to_render_data_calculator.cc"],
    visibility = ["//visibility:public"],
    deps = [
        ":age_genders_to_render_data_calculator_cc_proto",
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//myMediapipe/framework/formats:age_gender_cc_proto",
        "//mediapipe/framework/formats:video_stream_header",
        "//mediapipe/framework/port:ret_check",
        "//mediapipe/framework/port:status",
        "//mediapipe/framework/port:statusor",
        "//mediapipe/util:color_cc_proto",
        "//mediapipe/util:render_data_cc_proto",
        "@com_google_absl//absl/strings",
    ],
    alwayslink = 1,
)