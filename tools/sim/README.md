openpilot 시뮬레이션
=====================

openpilot은 [CARLA 시뮬레이터](https://carla.org/)에서 실행할 수 있는 [브리지](bridge.py)를 구현합니다.

## 시스템 권장 사항

openpilot에는 극단적인 하드웨어 요구 사항이 없지만 CARLA에는 NVIDIA 그래픽 카드가 필요하고 리소스 집약적이며 시스템에서 원활하게 실행되지 않을 수 있습니다.
이러한 경우를 위해 기본적으로 낮은 품질을 제공하는 시뮬레이터가 있습니다.

또한 [CARLA python 문서](https://carla.readthedocs.io/en/latest/python_api/)를 확인하여 시스템 성능을 향상시킬 수 있는 조정 가능한 매개변수를 더 확인해보세요.

## 시뮬레이터 실행
tools/sim 에 있는 Carla 시뮬레이터, openpilot 및 브리지 프로세스를 시작하세요.
``` bash
# Terminal 1
./start_carla.sh

# Terminal 2 - 하나의 Docker에서 openpilot 및 브리지 실행:
./start_openpilot_docker.sh

# 최신 로컬 코드 실행
    # Terminal 2:
    ./launch_openpilot.sh
    # Terminal 3
    ./bridge.py
```

### 브리자 사용
_start_openpilot_docker에 대해 동일한 명령이 유지됩니다._
```
$ ./bridge.py -h
Usage: bridge.py [options]
Bridge between CARLA and openpilot.

Options:
  -h, --help            도움말 메시지를 표시하고 종료
  --joystick            조이스틱을 사용하여 자동차 조종
  --high_quality        시뮬레이터를 더 높은 품질로 설정(좋은 GPU 필요).
  --town TOWN           사용할 지도 선택
  --spawn_point NUM     시작 스폰 지점의 번호
```

openpilot을 사용하려면 bridge.py에 초점을 맞춘 상태에서 1을 몇 번 눌러 순항 속도를 높이십시오.
All inputs:

| 조작키 |  기능 |
|:----:|:-----------------:|
|  1   | 8km/h 이상일 경우 크루즈 작동 |
|  2   | 8km/h 미만일 경우 크루즈 작동 |
|  3   | 크루즈 취소 |
|  q   | 모두 종료 |
| wasd | 수동 조종 |

## 추가 자료

아래 리소스에는 자세한 내용과 문제 해결 팁이 포함되어 있습니다.
* [CARLA on the openpilot wiki](https://github.com/commaai/openpilot/wiki/CARLA)
