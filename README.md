# Minishell

C로 구현한 Bash 스타일의 간단한 쉘 프로그램

## 📋 프로젝트 개요

Minishell은 Bash 쉘의 핵심 기능을 구현하는 프로젝트입니다. 파이프, 리다이렉션, 환경변수, 내장 명령어 등 실제 쉘의 주요 기능들을 C언어로 직접 구현합니다.

## ✨ 주요 기능

### 핵심 기능
- **명령어 실행** - 시스템 명령어 및 실행파일 실행
- **파이프라인** - 여러 명령어를 파이프(`|`)로 연결
- **리다이렉션** - 입출력 리다이렉션 (`<`, `>`, `>>`)
- **환경변수** - 환경변수 확장 및 관리 (`$VAR`)
- **따옴표 처리** - 단일/이중 따옴표 문자열 처리
- **신호 처리** - Ctrl+C, Ctrl+D, Ctrl+\\ 신호 처리

### 내장 명령어 (Builtin Commands)
- **echo** - 텍스트 출력 (with `-n` option)
- **cd** - 디렉터리 변경
- **pwd** - 현재 디렉터리 출력
- **export** - 환경변수 설정
- **unset** - 환경변수 삭제
- **env** - 환경변수 출력
- **exit** - 쉘 종료

### 고급 기능
- **히스토리** - 명령어 히스토리 관리
- **해시 테이블** - 명령어 경로 캐싱으로 성능 최적화
- **에러 처리** - 적절한 에러 메시지 및 종료 코드
- **메모리 관리** - 메모리 누수 방지

## 🛠️ 기술적 구현

### 아키텍처
- **렉서(Lexer)**: 입력 문자열을 토큰으로 분해
- **파서(Parser)**: 토큰을 명령어 구조로 파싱
- **실행기(Executor)**: 파싱된 명령어 실행
- **환경관리**: 환경변수 및 쉘 상태 관리

### 프로젝트 구조
```
minishell/
├── includes/              # 헤더 파일들
│   └── minishell.h       # 메인 헤더 파일
├── builtin/              # 내장 명령어 구현
│   ├── ms_builtin.c      # 내장 명령어 라우터
│   ├── ms_builtin_cd.c   # cd 명령어
│   ├── ms_builtin_echo.c # echo 명령어
│   ├── ms_builtin_env.c  # env 명령어
│   ├── ms_builtin_exit.c # exit 명령어
│   ├── ms_builtin_export.c # export 명령어
│   ├── ms_builtin_pwd.c  # pwd 명령어
│   └── ms_builtin_unset.c # unset 명령어
├── env/                  # 환경변수 관리
│   ├── ms_env.c          # 환경변수 핵심 로직
│   ├── ms_env_array.c    # 환경변수 배열 관리
│   └── ms_env_utils.c    # 환경변수 유틸리티
├── execute/              # 명령어 실행
│   └── [실행 관련 파일들]
├── parse/                # 파싱 및 토큰화
│   ├── ms_parse_path.c   # 경로 파싱
│   ├── ms_seperate_cmd.c # 명령어 분리
│   ├── ms_make_list.c    # 토큰 리스트 생성
│   ├── handle_quote_*.c  # 따옴표 처리
│   ├── handle_env_*.c    # 환경변수 처리
│   └── check_redirection_*.c # 리다이렉션 처리
├── hash/                 # 해시 테이블 (명령어 캐싱)
│   ├── ft_hash.c         # 해시 테이블 구현
│   └── ft_hash_utils.c   # 해시 유틸리티
├── signal/               # 신호 처리
│   └── [신호 처리 파일들]
├── utils/                # 유틸리티 함수들
│   └── [공통 유틸리티]
├── libft/                # 커스텀 라이브러리
│   └── [libft 함수들]
├── Makefile              # 빌드 설정
└── minishell.c           # 메인 파일
```

## 🚀 설치 및 사용법

### 시스템 요구사항
- C 컴파일러 (gcc, clang)
- Make
- readline 라이브러리
- Linux/macOS 시스템

### 빌드
```bash
make
```

### 실행
```bash
./minishell
```

### 사용 예시
```bash
minishell$ echo "Hello, World!"
Hello, World!

minishell$ ls -la | grep minishell
-rwxr-xr-x 1 user user 45678 Aug 26 22:00 minishell

minishell$ export MY_VAR="test"
minishell$ echo $MY_VAR
test

minishell$ cd .. && pwd
/home/user

minishell$ echo "파일 내용" > test.txt
minishell$ cat < test.txt
파일 내용

minishell$ exit 42
```

## 🧪 테스트

다양한 쉘 기능 테스트:

```bash
# 기본 명령어
echo "Hello World"
ls -la
pwd

# 파이프라인
ls -la | grep minishell | wc -l
cat file.txt | head -10 | tail -5

# 리다이렉션
echo "test" > output.txt
cat < input.txt
echo "append" >> output.txt

# 환경변수
export TEST_VAR="value"
echo $TEST_VAR
unset TEST_VAR

# 따옴표 처리
echo 'single quotes $USER'
echo "double quotes $USER"

# 내장 명령어
cd /tmp
pwd
env | grep PATH
exit 0
```

## 📚 학습 성과

- **시스템 프로그래밍**: 프로세스 관리, 파이프, 리다이렉션 구현
- **파싱 기법**: 토큰화, 구문 분석, AST 구조 이해
- **메모리 관리**: C언어에서의 동적 메모리 할당/해제
- **신호 처리**: Unix 신호 시스템 이해
- **해시 테이블**: 효율적인 데이터 구조 구현
- **Unix 쉘**: 쉘의 내부 동작 원리 이해

## 🎯 42 과제 요구사항

- ✅ Bash 명령어 실행
- ✅ 파이프라인 구현 (`|`)
- ✅ 리다이렉션 구현 (`<`, `>`, `>>`)
- ✅ 환경변수 확장 (`$VAR`)
- ✅ 따옴표 처리 (`'`, `"`)
- ✅ 내장 명령어 구현 (echo, cd, pwd, export, unset, env, exit)
- ✅ 신호 처리 (Ctrl+C, Ctrl+D, Ctrl+\\)
- ✅ 히스토리 기능
- ✅ 메모리 누수 방지
- ✅ Norm 코딩 스타일 준수

*"쉘을 만들어보는 것은 운영체제를 이해하는 가장 좋은 방법이다"* 🐚
