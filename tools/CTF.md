## CTF
comma CTF에 오신것을 환영합니다!

* 모든 깃발은 이 경로에 포함되어 있습니다. `0c7f0c7f0c7f0c7f|2021-10-13--13-00-00`
* 각 세그먼트에는 2개의 깃발이 있으며 대략적으로 난이도가 증가합니다.
* 깃발을 찾는 데 필요한 모든 것이 openpilot 저장소에 있습니다.
  * grep 또한 여러분 진영입니다.
  * 먼저 PC를 [설정](https://github.com/cebu13/openpilot/tree/master/tools#pc-%EC%84%A4%EC%A0%95)하세요.
  * read the docs & checkout out the tools in tools/ and selfdrive/debug/
  * 팁: 리플레이와 UI가 작동하면 먼저 리플레이에서 탐색하는 방법을 숙지하세요.

시작하기
```bash
# start the route reply
cd selfdrive/ui/replay
./replay '0c7f0c7f0c7f0c7f|2021-10-13--13-00-00' --dcam --ecam

# start the UI in another terminal
selfdrive/ui/ui
```
