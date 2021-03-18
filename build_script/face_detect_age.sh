#!/bin/bash
bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 \
    myMediapipe/examples/desktop/face_detection_age:face_detection_cpu