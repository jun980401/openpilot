### 여기는 한국인들을 위해 openpilot 위키의 한글화 작업을 진행 중인 리포지토리입니다.
### 기존 comma.ai의 openpilot을 그대로 번역하였으며 직역 및 일부 의역으로 이루어져 있습니다.
### 현재도 계속 번역을 진행중이며 적절한 의역 및 기술번역 제의를 기다리고 있습니다.

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

[openpilot](http://github.com/commaai/openpilot) 은 오픈 소스 운전자 지원 시스템입니다. 현재 openpilot은 [지원되는 다양한 제조업체, 모델 및 연식](docs/CARS_KOREAN.md)에 적응형 순항 제어(ACC), 자동 차선 센터링(ALC), 전방 충돌 경고(FCW) 및 차선 이탈 경고(LDW)의 기능을 제공합니다. 또한 openpilot이 작동하는 동안 카메라 기반 DM(운전자 모니터링) 기능은 집중력이 떨어지거나 졸음 운전을 하는 운전자에게 경고기능을 수행합니다. [차량 통합](docs/INTEGRATION.md) 및 [제한 사항](docs/LIMITATIONS.md)에 대해 자세히 알아보세요.

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
* 다음으로 [150개 이상의 지원되는 차량](docs/CARS_KOREAN.md) 중 하나가 필요합니다. 현재 혼다, 토요타, 현대, 닛산, 기아, 크라이슬러, 렉서스, Acura, 아우디, 폭스바겐 등을 지원하고 있습니다. 보유한 차량이 공식적으로 지원되지 않아도 적응형 크루즈 컨트롤 및 차선 유지 보조 장치가 있는 경우 개방형 조종 장치를 실행할 수 있습니다.
* 이 소프트웨어를 실행하기 위해 지원되는 장치로 [comma three](https://comma.ai/shop/products/three)가 필요하고, 실험을 하고 싶다면 [웹 카메라가 있는 Ubuntu 컴퓨터](https://github.com/cebu13/openpilot/tree/master/tools/webcam)가 필요합니다.
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

Openpilot 개발과 관련된 문서는 [docs.comma.ai](https://docs.comma.ai)에서 찾을 수 있습니다. Openpilot 실행에 대한 정보(예: FAQ, 지문, 문제 해결, 사용자 정의 포크, 커뮤니티 하드웨어)는 [위키](https://github.com/commaai/openpilot/wiki)에 있어야 합니다.

[브랜드](https://blog.comma.ai/how-to-write-a-car-port-for-openpilot/) 및 [모델](https://blog.comma.ai/openpilot-port-guide-for-toyota-models/) 등록에 대해 작성한 가이드에 따라 지원 차량을 추가할 수 있습니다. 일반적으로 적응형 순항 제어 및 차선 유지 보조 기능이 있는 차량이 등록에 적합한 후보입니다. [디스코드](https://discord.comma.ai)에 참여하여 차량 등록에 대해 토론해보세요. 각 차량 제조업체에 맞는 전용 채널이 있습니다.

openpilot에 입사하고 싶으신가요? [여기서 지원해보세요](https://comma.ai/jobs/).

그리고 [트위터를 팔로우해주세요](https://twitter.com/comma_ai).

사용자 데이터 및 comma 계정
------

기본적으로 openpilot은 운전 데이터를 당사 서버에 업로드합니다. [comma connect](https://connect.comma.ai/)를 통해 데이터에 액세스할 수도 있습니다. 당사는 사용자 데이터를 사용하여 더 나은 모델을 훈련하고 모든 운전자를 위해 openpilot을 개선합니다.

openpilot은 오픈 소스 소프트웨어입니다. 단, 사용자의 의사에 따라 데이터 수집을 비활성화할 수 있습니다.

openpilot은 도로 직면 카메라, CAN, GPS, IMU, 자력계, 열 센서, 충돌 및 운영 체제 로그를 기록합니다.
운전자 직면 카메라는 설정에 명시적으로 opt-in한 경우에만 기록됩니다. 마이크는 녹음되지 않습니다.

openpilot을 사용하면 [당사의 개인정보 보호정책](https://comma.ai/privacy)에 동의하는 것입니다. 여러분이 이 소프트웨어 및 관련 서비스를 사용하면 comma의 단독 재량에 따라 기록 및 저장될 수 있는 사용자 데이터가 생성된다는 것에 동의하는 것입니다. 이 내용에 동의함으로써 여러분은 이 데이터 사용에 대해 철회를 할 수 없으며 어디서든 comma를 사용할 수 있는 권한을 영구적으로 갖게 됩니다.

안전성 및 테스트
----

* openpilot은 ISO26262 지침을 따릅니다. 자세한 내용은 [SAFETY.md](docs/SAFETY.md)를 참조하십시오.
* openpilot에는 모든 커밋에서 실행되는 루프 [테스트](.github/workflows/selfdrive_tests.yaml)에 소프트웨어가 있습니다.
* 안전 모델을 적용하는 코드는 panda에 있으며 C로 작성되었습니다. 자세한 내용은 [code rigor](https://github.com/commaai/panda#code-rigor)를 참조하십시오.
* 소프트웨어는 panda에 있는 [안전 테스트](https://github.com/commaai/panda/tree/master/tests/safety) 루프에 있습니다.
* 내부적으로 다양한 프로세스를 빌드하고 단위 테스트하는 루프 Jenkins 테스트 제품군에 하드웨어가 있습니다.
* 추가 하드웨어는 panda에 있는 [테스트](https://github.com/commaai/panda/blob/master/Jenkinsfile) 루프에 있습니다.
* 당사는 지속적으로 경로를 replay하는 10개의 comma 장치가 포함된 테스트 공간에서 최신 openpilot을 실행합니다.

디렉토리 구조
------
    .
    ├── cereal              # 모든 로그에 사용되는 메시징 사양 및 라이브러리
    ├── common              # 여기에서 개발한 기능과 같은 라이브러리
    ├── docs                # 기록문서
    ├── opendbc             # 차량 데이터 해석 방법이 있는 파일
    ├── panda               # CAN에서 통신하는 데 사용되는 코드
    ├── third_party         # 외부 라이브러리
    ├── pyextra             # 추가 파이썬 패키지
    └── selfdrive           # 자동차 운전에 필요한 코드
        ├── assets          # UI에 사용될 글꼴, 이미지 및 사운드
        ├── athena          # 앱과의 통신 허용
        ├── boardd          # 보드와 대화 가능한 데몬
        ├── camerad         # 카메라 센서에서 이미지를 캡처하는 드라이버
        ├── car             # 상태를 읽고 작동기를 제어하기 위한 자동차 전용 코드
        ├── common          # 데몬용 공유 C/C++ 코드
        ├── controls        # 계획 및 컨트롤
        ├── debug           # 차량 등록을 디버깅하고 수행하는 데 도움이 되는 도구
        ├── locationd       # 차량 매개변수의 정확한 위치 파악 및 추정
        ├── logcatd         # 안드로이드 logcat 서비스
        ├── loggerd         # 차량 데이터 기록장치 및 업로더
        ├── modeld          # Driving and monitoring model runners
        ├── proclogd        # proc에서 기록한 정보
        ├── sensord         # IMU 인터페이스 코드
        ├── test            # 유닛 테스트, 시스템 테스트 및 자동차 시뮬레이터
        └── ui              # UI

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
