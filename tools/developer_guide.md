## 이 문서는 openpilot 개발 환경 설정 및 명령어 팁을 위한 개발자 가이드입니다.

### PC 설정

PC 설정은 [tools/README.md](https://github.com/cebu13/openpilot/blob/master/tools/README.md)에 나온 방법대로 진행하면 됩니다.

초기 빌드 명령어는 아래와 같지만
```bash
scons -u -j$(nproc)
```

더 간단하게 하려면 아래의 명령어만 입력해도 됩니다.
```bash
scons
```

그리고 pre-commit을 진행하고 싶다면 아래의 명령어를 입력하십시오.
```bash
pre-commit run --all
```
