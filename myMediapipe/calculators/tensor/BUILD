load("@bazel_skylib//lib:selects.bzl", "selects")
load("//mediapipe/framework/port:build_config.bzl", "mediapipe_proto_library")

licenses(["notice"])

package(default_visibility = ["//visibility:public"])

mediapipe_proto_library(
    name = "tensors_to_age_gender_calculator_proto",
    srcs = ["tensors_to_age_gender_calculator.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_options_proto",
        "//mediapipe/framework:calculator_proto",
    ],
)

cc_library(
    name = "tensors_to_age_gender_calculator",
    srcs = ["tensors_to_age_gender_calculator.cc"],
    copts = select({
        "//mediapipe:apple": [
            "-x objective-c++",
            "-fobjc-arc",  # enable reference-counting
        ],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        ":tensors_to_age_gender_calculator_cc_proto",
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework/api2:node",
        "//myMediapipe/framework/formats:age_gender_cc_proto",
        "//mediapipe/framework/formats:tensor",
        "//mediapipe/framework/port:ret_check",
    ],
    alwayslink = 1,
)