#!/bin/bash
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 \
    myMediapipe/examples/desktop/face_age_gender:face_age_gender_gpu_tx2
