
# gpu tx2

bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 mediapipe/examples/desktop/upper_body_pose_tracking:upper_body_pose_tracking_gpu
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 mediapipe/examples/desktop/hand_tracking:hand_tracking_gpu --verbose_failures --sandbox_debug --show_progress
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 mediapipe/examples/desktop/multi_hand_tracking:multi_hand_tracking_gpu
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 mediapipe/examples/desktop/upper_body_pose_tracking:upper_pose_tracking_gpu
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 mediapipe/examples/desktop/upper_body_pose_tracking:upper_body_pose_tracking_gpu

bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt mediapipe/examples/desktop/hand_tracking:hand_tracking_gpu
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS mediapipe/examples/desktop/hand_tracking:hand_tracking_gpu


## gpu run

GLOG_logtostderr=1 bazel-bin/mediapipe/examples/desktop/hand_tracking/hand_tracking_gpu --calculator_graph_config_file=mediapipe/graphs/hand_tracking/hand_tracking_mobile.pbtxt
GLOG_logtostderr=1 bazel-bin/mediapipe/examples/desktop/hand_tracking/hand_tracking_gpu --calculator_graph_config_file=mediapipe/graphs/hand_tracking/hand_tracking_mobile.pbtxt

bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11     mediapipe/examples/desktop/hand_tracking:hand_tracking_gpu
GLOG_logtostderr=1 bazel-bin/mediapipe/examples/desktop/hand_tracking/hand_tracking_gpu --calculator_graph_config_file=mediapipe/graphs/hand_tracking/hand_tracking_mobile.pbtxt


bazel-bin/mediapipe/examples/desktop/multi_hand_tracking/multi_hand_tracking_cpu --calculator_graph_config_file=mediapipe/graphs/hand_tracking/multi_hand_tracking_desktop_live.pbtxt
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11  mediapipe/examples/desktop/hand_tracking:hand_tracking_gpu


# docker


##
bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 mediapipe/examples/desktop/upper_body_pose_tracking:upper_body_pose_tracking_gpu

bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 myMediapipe/projects/staticGestures/staticGestures:static_gestures_cpu_tflite

bazel build -c opt --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 myMediapipe/projects/staticGestures/staticGestures:static_gestures_cpu_tflite


##
git clone https://github.com/lisbravo/mediapipe.git
cd mediapipe
git clone https://github.com/lisbravo/myMediapipe.git

### setup opencv
https://github.com/lisbravo/mediapipe/blob/master/setup_opencv.sh

### update WORKSPACE

### update some paths

### build without GPU

bazel build --sandbox_debug -c opt --define MEDIAPIPE_DISABLE_GPU=1^CyMediapipe/projects/dynamicGestures:dynamic_gestures_cpu_tflite_cam

### build with GPU

bazel build  --copt -DMESA_EGL_NO_X11_HEADERS --copt -DEGL_NO_X11 myMediapipe/projects/dynamicGestures:dynamic_gestures_gpu_tflite_cam
