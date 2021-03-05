bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 \
    myMediapipe/examples/desktop/dynamicGesture:dynamic_gestures_cpu