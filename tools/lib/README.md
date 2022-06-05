## LogReader

루트는 사용자 경로의 모든 [로그](/selfdrive/loggerd/)에 편리하게 액세스할 수 있는 클래스입니다. LogReader 클래스는 비디오가 아닌 로그(예: rlog.bz2 및 qlog.bz2)를 읽습니다. 비디오를 읽기 위한 일치 FrameReader 클래스도 있습니다.

```python
from tools.lib.route import Route
from tools.lib.logreader import LogReader

r = Route("4cf7a6ad03080c90|2021-09-29--13-46-36")

# get a list of paths for the route's rlog files
print(r.log_paths())

# and road camera (fcamera.hevc) files
print(r.camera_paths())

# setup a LogReader to read the route's first rlog
lr = LogReader(r.log_paths()[0])

# print out all the messages in the log
import codecs
codecs.register_error("strict", codecs.backslashreplace_errors)
for msg in lr:
  print(msg)

# setup a LogReader for the route's second qlog
lr = LogReader(r.log_paths()[1])

# print all the steering angles values from the log
for msg in lr:
  if msg.which() == "carState":
    print(msg.carState.steeringAngleDeg)
```

### MultiLogIterator

`MultiLogIterator`는 `LogReader`와 유사하지만 여러 로그를 읽는다는 차이점이 있습니다. 

```python
from tools.lib.route import Route
from tools.lib.logreader import MultiLogIterator

# setup a MultiLogIterator to read all the logs in the route
r = Route("4cf7a6ad03080c90|2021-09-29--13-46-36")
lr = MultiLogIterator(r.log_paths())

# print all the steering angles values from all the logs in the route
for msg in lr:
  if msg.which() == "carState":
    print(msg.carState.steeringAngleDeg)
```
