# SSH

## Quick Start

장치에 SSH로 연결하려면 SSH 키가 있는 GitHub 계정이 필요합니다. SSH 키로 계정 설정을 하려면 이 [GitHub 문서](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh)를 참조하십시오.

* 디바이스 설정에서 SSH 활성화
* 디바이스 설정에 GitHub 사용자 이름 입력
* 기기 연결
  * 사용자 이름: `comma` (comma three)
  * 포트: `22` 또는 `8022`

다음은 테더링 연결을 사용하여 장치에 연결하는 명령어의 예시입니다.
`ssh root@192.168.43.1`

디바이스에서 개발 작업을 하기 위해서는 [SSH 에이전트 포워딩](https://docs.github.com/en/developers/overview/using-ssh-agent-forwarding) 사용을 권장합니다.

## Notes

공개 키는 GitHub 계정에서 한 번만 가져옵니다. 기기의 승인된 키를 업데이트하려면 GitHub 사용자 이름을 다시 입력해야 합니다.

이 디렉토리의 'id_rsa' 키는 장치가 소프트웨어가 설치되지 않은 설정 상태에 있는 동안에만 작동합니다. 설치 후 해당 기본 키가 제거됩니다.

자세한 지침 및 정보는 [커뮤니티 위키](https://github.com/commaai/openpilot/wiki/SSH)를 참조하십시오.
