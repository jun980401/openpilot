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

### CTF

CTF에서 replay 파일을 실행해야 하는데,
우리가 실행해서 번역할 파일은 **이 명령어가 아니라**
```bash
cd selfdrive/ui/replay
./replay '0c7f0c7f0c7f0c7f|2021-10-13--13-00-00' --dcam --ecam
```

아래의 명령어를 사용해서 나오는 파일입니다.
```bash
cd selfdrive/ui/replay
./ replay --demo
```


### 그 외

코드 수정 시 vscode에서 수정한 후 GitHub 리포지토리로 바로 commit 하는 것이 일반적이지만
필자는 오류로 인해 vscode에서의 commit이 불가했던 관계로 vscode에서 먼저 작업하여
컴파일 및 정상 구동 확인 후 코드를 그대로 복사해와서 GitHub 웹에 있는 코드 수정 기능으로 코드를 붙여넣었습니다.
둘 중 어느 방법을 써도 상관없으니 필자와 같은 오류가 발생하는 사람은 후자의 방법을 사용해도 좋습니다.

그리고 간혹 텍스트만 번역하였는데 컴파일 및 구동은 정상적으로 되나 pre commit이 실패하는 경우가 있습니다.
이는 수정한 텍스트가 해당 코드뿐만 아니라 여러 군데에 같이 사용되기 때문에 그럴 가능성이 높습니다.
웬만하면 굳이 번역하지 않아도 알아볼 수 있는 간단한 단어 위주이므로 해당 요소는 번역항목에서 제외해도 됩니다.
