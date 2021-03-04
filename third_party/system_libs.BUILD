# Description:
#   The system packages
#   and scaling.

licenses(["notice"])  # BSD license

exports_files(["LICENSE"])

cc_library(
    name = "libmosquittopp-dev",
    srcs = glob(
        [
            "libmosquittopp.so",
            "libmosquitto.so"
        ],
    ),
    visibility = ["//visibility:public"],
)