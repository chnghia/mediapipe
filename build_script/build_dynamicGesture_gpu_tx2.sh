bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 \
    myMediapipe/examples/desktop/dynamicGesture:dynamic_gestures_gpu_tx2