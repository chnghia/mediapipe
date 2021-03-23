#!/bin/bash
bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 \
    myMediapipe/examples/desktop/face_age_gender:face_age_gender_cpu