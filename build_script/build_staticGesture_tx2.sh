bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 \
    myMediapipe/examples/desktop/staticGesture:static_gestures_cpu_tx2