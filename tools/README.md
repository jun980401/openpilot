# openpilot 툴

## 시스템 권장 사항

openpilot은 [지원되는 임베디드 하드웨어](https://github.com/cebu13/openpilot#pc-%EC%9E%91%EB%8F%99%EB%B2%95)를 제외하고 주 개발 환경인 **Ubuntu 20.04**에서 개발 및 테스트가 진행되었습니다. 또한 openpilot이 macOS에서 빌드되는지 확인하기 위해 CI 테스트가 진행되지만 툴은 테스트되지 않았습니다. 기능을 온전하게 사용하려면 Ubuntu 20.04 환경을 사용하십시오. 그렇지 않으면 openpilot 및 툴이 macOS 및 기타 Linux 시스템에서 제대로 호환되지 않은 채로 작동할 수 있습니다.

## PC 설정


먼저, openpilot을 클론하세요.
``` bash
cd ~
git clone https://github.com/commaai/openpilot.git

cd openpilot 
git submodule update --init
```

그런 다음 설정 스크립트를 실행합니다.

``` bash
# for Ubuntu 20.04 LTS
tools/ubuntu_setup.sh

# for macOS
tools/mac_setup.sh
```

파이썬 의존성을 설치하여 셸을 활성화합니다.

``` bash
cd openpilot && pipenv shell
```

Build openpilot with this command:
``` bash
scons -u -j$(nproc)
```

### 윈도우

openpilot과 어떠한 툴도 Windows에서 개발되거나 테스트되지 않았지만 [WSL](https://docs.microsoft.com/en-us/windows/wsl/about)을 사용하면 Windows 사용자도 Ubuntu 환경을 사용할 수 있습니다. [WSL 2](https://docs.microsoft.com/en-us/windows/wsl/compare-versions)는 특히 사용자들로부터 원활하게 작동된다는 평을 받았습니다.

[이 지침](https://docs.microsoft.com/en-us/windows/wsl/install)에 따라 WSL을 설정하고 `Ubuntu-20.04` 배포판을 설치하십시오. Ubuntu WSL 환경이 설정되면 Linux 설정 지침에 따라 환경 설정을 완료합니다.

GUI 응용 프로그램은 기본적으로 WSL과 호환되지 않습니다. [시스템을 Windows 11로 업그레이드](https://docs.microsoft.com/en-us/windows/wsl/tutorials/gui-apps)하거나 [Xorg 서버를 설정](https://techcommunity.microsoft.com/t5/windows-dev-appconsult/running-wsl-gui-apps-on-windows-10/ba-p/1493242)해야 합니다.  


## CTF
[CTF](/tools/CTF.md)를 플레이하여 openpilot 생태계와 툴에 대해 알아보세요.

## 디렉토리 구조

```
├── ubuntu_setup.sh     # Ubuntu용 설정 스크립트
├── mac_setup.sh        # macOS용 설정 스크립트
├── joystick/           # 조이스틱으로 차량 조종
├── lib/                # 툴 지원 및 openpilot 로그 라이브러리
├── plotjuggler/        # openpilot 로그 플롯하는 툴
├── replay/             # 드라이브 및 모의 openpilot 서비스를 리플레이
├── scripts/            # 기타 스크립트
├── serial/             # comma 시리얼 사용을 위한 툴
├── sim/                # 시뮬레이터에서openpilot 실행
├── ssh/                # SSH를 comma 장치로
└── webcam/             # 웹캠이 있는 PC에서 openpilot 
```
