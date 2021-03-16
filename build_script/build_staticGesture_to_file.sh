#!/bin/bash
bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 \
    myMediapipe/examples/desktop/staticGestureToFile:static_gestures_cpu_to_file