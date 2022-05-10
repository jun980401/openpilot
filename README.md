![](https://i.imgur.com/b0ZyIx5.jpg)

목차
=======================

* [openpilot 이란?](#openpilot-이란)
* [차량 작동법](#차량-작동법)
* [PC 작동법](#pc-작동법)
* [커뮤니티 및 기여](#커뮤니티-및-기여)
* [사용자 데이터 및 comma 계정](#사용자-데이터-및-comma-계정)
* [안전성 및 테스트](#안전성-및-테스트)
* [디렉토리 구조](#디렉토리-구조)
* [라이선스](#라이선스)

---

openpilot 이란?
------

[openpilot](http://github.com/commaai/openpilot) 은 오픈 소스 운전자 지원 시스템입니다. 현재 openpilot은 [지원되는 다양한 제조업체, 모델 및 연식](docs/CARS.md)에 적응형 순항 제어(ACC), 자동 차선 센터링(ALC), 전방 충돌 경고(FCW) 및 차선 이탈 경고(LDW)의 기능을 제공합니다. 또한 openpilot이 작동하는 동안 카메라 기반 DM(운전자 모니터링) 기능은 집중력이 떨어지거나 졸음 운전을 하는 운전자에게 경고기능을 수행합니다. [차량 통합](docs/INTEGRATION.md) 및 [제한 사항](docs/LIMITATIONS.md)에 대해 자세히 알아보세요.

<table>
  <tr>
    <td><a href="https://youtu.be/NmBfgOanCyk" title="Video By Greer Viau"><img src="https://i.imgur.com/1w8c6d2.jpg"></a></td>
    <td><a href="https://youtu.be/VHKyqZ7t8Gw" title="Video By Logan LeGrand"><img src="https://i.imgur.com/LnBucik.jpg"></a></td>
    <td><a href="https://youtu.be/VxiR4iyBruo" title="Video By Charlie Kim"><img src="https://i.imgur.com/4Qoy48c.jpg"></a></td>
    <td><a href="https://youtu.be/-IkImTe1NYE" title="Video By Aragon"><img src="https://i.imgur.com/04VNzPf.jpg"></a></td>
  </tr>
  <tr>
    <td><a href="https://youtu.be/iIUICQkdwFQ" title="Video By Logan LeGrand"><img src="https://i.imgur.com/b1LHQTy.jpg"></a></td>
    <td><a href="https://youtu.be/XOsa0FsVIsg" title="Video By PinoyDrives"><img src="https://i.imgur.com/6FG0Bd8.jpg"></a></td>
    <td><a href="https://youtu.be/bCwcJ98R_Xw" title="Video By JS"><img src="https://i.imgur.com/zO18CbW.jpg"></a></td>
    <td><a href="https://youtu.be/BQ0tF3MTyyc" title="Video By Tsai-Fi"><img src="https://i.imgur.com/eZzelq3.jpg"></a></td>
  </tr>
</table>


차량 작동법
------


차량에서 openpilot을 사용하기 위해 다음 4가지가 필요합니다.
* 먼저 openpilot 소프트웨어가 필요합니다. 여기서 무료로 사용할 수 있습니다.
* 다음으로 [150개 이상의 지원되는 차량](docs/CARS.md) 중 하나가 필요합니다. 현재 혼다, 토요타, 현대, 닛산, 기아, 크라이슬러, 렉서스, Acura, 아우디, 폭스바겐 등을 지원하고 있습니다. 보유한 차량이 공식적으로 지원되지 않아도 적응형 크루즈 컨트롤 및 차선 유지 보조 장치가 있는 경우 개방형 조종 장치를 실행할 수 있습니다.
* 이 소프트웨어를 실행하기 위해 지원되는 장치로 [comma three](https://comma.ai/shop/products/three)가 필요하고, 실험을 하고 싶다면 [웹 카메라가 있는 Ubuntu 컴퓨터](https://github.com/commaai/openpilot/tree/master/tools/webcam)가 필요합니다.
* 자동차에 연결하는 방법. comma three를 이용하면, 오직 [car harness](https://comma.ai/shop/products/car-harness)만 있으면 됩니다. PC를 이용하면, [black panda](https://comma.ai/shop/products/panda)도 함께 필요합니다.

[자동차에 장치를 설치하는 방법](https://comma.ai/setup)에 대한 자세한 지침이 있습니다.

PC 작동법
------

openpilot의 모든 서비스는 특별한 하드웨어나 자동차가 없어도 PC에서 정상적으로 실행할 수 있습니다. openpilot을 개발하거나 실험하기 위해 기록되거나 시뮬레이션된 데이터에 대해 openpilot을 실행할 수 있습니다.

openpilot의 도구를 사용하면 로그를 플로팅하고 드라이브를 재생하고 전체 해상도 카메라 스트림을 볼 수 있습니다. 더 많은 정보는 [tools README](tools/README.md)에서 확인해보세요.

[CARLA simulator](tools/sim/README.md)를 활용하여 시뮬레이션에서 openpilot을 실행할 수도 있습니다. 이를 통해 openpilot은 Ubuntu 시스템에서 가상 자동차를 운전할 수 있습니다. 전체 설정은 몇 분 밖에 걸리지 않지만 권장 사양의 GPU가 필요합니다.


커뮤니티 및 기여
------

openpilot은 [comma](https://comma.ai/)과 여러분과 같은 사용자가 개발하는 소프트웨어입니다. [GitHub](http://github.com/commaai/openpilot)에서 pull requests와 issues는 항상 열려있으니 많은 참여 바랍니다. 현재 버그 수정과 차량 등록을 추진하고 있습니다. [기여 문서](docs/CONTRIBUTING.md)를 확인해보세요.

Documentation related to openpilot development can be found on [docs.comma.ai](https://docs.comma.ai). Information about running openpilot (e.g. FAQ, fingerprinting, troubleshooting, custom forks, community hardware) should go on the [wiki](https://github.com/commaai/openpilot/wiki).

You can add support for your car by following guides we have written for [Brand](https://blog.comma.ai/how-to-write-a-car-port-for-openpilot/) and [Model](https://blog.comma.ai/openpilot-port-guide-for-toyota-models/) ports. Generally, a car with adaptive cruise control and lane keep assist is a good candidate. [Join our Discord](https://discord.comma.ai) to discuss car ports: most car makes have a dedicated channel.

Want to get paid to work on openpilot? [comma is hiring](https://comma.ai/jobs/).

And [follow us on Twitter](https://twitter.com/comma_ai).

사용자 데이터 및 comma 계정
------

By default, openpilot uploads the driving data to our servers. You can also access your data through [comma connect](https://connect.comma.ai/). We use your data to train better models and improve openpilot for everyone.

openpilot is open source software: the user is free to disable data collection if they wish to do so.

openpilot logs the road facing cameras, CAN, GPS, IMU, magnetometer, thermal sensors, crashes, and operating system logs.
The driver facing camera is only logged if you explicitly opt-in in settings. The microphone is not recorded.

By using openpilot, you agree to [our Privacy Policy](https://comma.ai/privacy). You understand that use of this software or its related services will generate certain types of user data, which may be logged and stored at the sole discretion of comma. By accepting this agreement, you grant an irrevocable, perpetual, worldwide right to comma for the use of this data.

안전성 및 테스트
----

* openpilot observes ISO26262 guidelines, see [SAFETY.md](docs/SAFETY.md) for more details.
* openpilot has software in the loop [tests](.github/workflows/selfdrive_tests.yaml) that run on every commit.
* The code enforcing the safety model lives in panda and is written in C, see [code rigor](https://github.com/commaai/panda#code-rigor) for more details.
* panda has software in the loop [safety tests](https://github.com/commaai/panda/tree/master/tests/safety).
* Internally, we have a hardware in the loop Jenkins test suite that builds and unit tests the various processes.
* panda has additional hardware in the loop [tests](https://github.com/commaai/panda/blob/master/Jenkinsfile).
* We run the latest openpilot in a testing closet containing 10 comma devices continuously replaying routes.

디렉토리 구조
------
    .
    ├── cereal              # The messaging spec and libs used for all logs
    ├── common              # Library like functionality we've developed here
    ├── docs                # Documentation
    ├── opendbc             # Files showing how to interpret data from cars
    ├── panda               # Code used to communicate on CAN
    ├── third_party         # External libraries
    ├── pyextra             # Extra python packages
    └── selfdrive           # Code needed to drive the car
        ├── assets          # Fonts, images, and sounds for UI
        ├── athena          # Allows communication with the app
        ├── boardd          # Daemon to talk to the board
        ├── camerad         # Driver to capture images from the camera sensors
        ├── car             # Car specific code to read states and control actuators
        ├── common          # Shared C/C++ code for the daemons
        ├── controls        # Planning and controls
        ├── debug           # Tools to help you debug and do car ports
        ├── locationd       # Precise localization and vehicle parameter estimation
        ├── logcatd         # Android logcat as a service
        ├── loggerd         # Logger and uploader of car data
        ├── modeld          # Driving and monitoring model runners
        ├── proclogd        # Logs information from proc
        ├── sensord         # IMU interface code
        ├── test            # Unit tests, system tests, and a car simulator
        └── ui              # The UI

라이선스
------

openpilot is released under the MIT license. Some parts of the software are released under other licenses as specified.

Any user of this software shall indemnify and hold harmless Comma.ai, Inc. and its directors, officers, employees, agents, stockholders, affiliates, subcontractors and customers from and against all allegations, claims, actions, suits, demands, damages, liabilities, obligations, losses, settlements, judgments, costs and expenses (including without limitation attorneys’ fees and costs) which arise out of, relate to or result from any use of this software by user.

**THIS IS ALPHA QUALITY SOFTWARE FOR RESEARCH PURPOSES ONLY. THIS IS NOT A PRODUCT.
YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS.
NO WARRANTY EXPRESSED OR IMPLIED.**

---

<img src="https://d1qb2nb5cznatu.cloudfront.net/startups/i/1061157-bc7e9bf3b246ece7322e6ffe653f6af8-medium_jpg.jpg?buster=1458363130" width="75"></img> <img src="https://cdn-images-1.medium.com/max/1600/1*C87EjxGeMPrkTuVRVWVg4w.png" width="225"></img>

[![openpilot tests](https://github.com/commaai/openpilot/workflows/openpilot%20tests/badge.svg?event=push)](https://github.com/commaai/openpilot/actions)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/commaai/openpilot.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/commaai/openpilot/alerts/)
[![Language grade: Python](https://img.shields.io/lgtm/grade/python/g/commaai/openpilot.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/commaai/openpilot/context:python)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/commaai/openpilot.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/commaai/openpilot/context:cpp)
[![codecov](https://codecov.io/gh/commaai/openpilot/branch/master/graph/badge.svg)](https://codecov.io/gh/commaai/openpilot)
