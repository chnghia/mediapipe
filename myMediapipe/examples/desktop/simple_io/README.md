
# SimpleIO

## Build

$ bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 \
    myMediapipe/examples/desktop/simple_io:simple_io

## Run

$ export GLOG_logtostderr=1
$ bazel-bin/myMediapipe/examples/desktop/simple_io/simple_io --calculator_graph_config_file=myMediapipe/graphs/simple_io/simple_io_graph.pbtxt --input_side_packets=input_video_path=mediapipe/examples/desktop/object_detection/test_video.mp4,output_video_path=myMediapipe/examples/desktop/simple_io/output_video.mp4