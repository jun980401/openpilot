# Replay

## Replay driving data

`replay`는 openpilot을 실행하는 동안 기록된 모든 메시지를 재생합니다.

```bash
# 비공개 경로에 액세스하려면 브라우저를 통해 로그인하십시오.
python lib/auth.py

# 다시보기 시작
selfdrive/ui/replay/replay <route-name>

# 예시:
# selfdrive/ui/replay/replay '4cf7a6ad03080c90|2021-09-29--13-46-36'
# 또는 --demo를 사용하여 기본 데모 경로를 재생합니다.
# selfdrive/ui/replay/replay --demo

# 일반 openpilot UI로 다시보기 시청
cd selfdrive/ui && ./ui

# 또는 디버그 시각화 도우미를 사용해보십시오.
python replay/ui.py
```

## 사용법
``` bash
$ selfdrive/ui/replay/replay -h
Usage: selfdrive/ui/replay/replay [options] route
Mock openpilot components by publishing logged messages.

Options:
  -h, --help             Displays this help.
  -a, --allow <allow>    whitelist of services to send
  -b, --block <block>    blacklist of services to send
  -s, --start <seconds>  start from <seconds>
  --demo                 use a demo route instead of providing your own
  --dcam                 load driver camera
  --ecam                 load wide road camera

Arguments:
  route                  the drive to replay. find your drives at
                         connect.comma.ai
```

## watch3

watch3를 사용하여 comma three 경로에서 동시에 3개의 카메라 모두 시청

`--dcam` 및 `--ecam` 플래그를 사용하여 경로를 재생하기만 하면 됩니다.

```bash
# 다시보기 시작
cd selfdrive/ui/replay && ./replay --demo --dcam --ecam

# 그런 다음 watch3 시작
cd selfdrive/ui && ./watch3
```

![](https://i.imgur.com/IeaOdAb.png)

## CAN 메시지를 디바이스로 스트리밍

[panda jungle](https://comma.ai/shop/products/panda-jungle)을 사용하여 녹음된 CAN 메시지를 재생합니다. jungle에는 모든 comma 디바이스를 연결하기 위한 6개의 OBD-C 포트가 있습니다. 자세한 내용은 [jungle repo](https://github.com/commaai/panda_jungle)를 확인하세요.

'can_replay.py'는 CAN 데이터가 필요할 때 사용하기 편리한 스크립트입니다.

특정 경로를 재생하려면
```bash
MOCK=1 selfdrive/boardd/tests/boardd_old.py

# 다른 터미널에서
selfdrive/ui/replay/replay <route-name>
```
