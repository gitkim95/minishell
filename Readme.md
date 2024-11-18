readline
char	*readline(const char*)
	- #include <readline/readline.h>
	- #include <readline/history.h>
	- 컴파일 할 때는 -lreadline 플래그를 추가해줘야 한다.
	- 입력된 문자열을 저장하고 해당 주소를 반환한다.
	- 메모리 할당이 되므로 해제에 유의한다.

rl_clear_history
void	rl_clear_history(void)
	- #include <readline/readline.h>
	- 현재 history를 지운다.

rl_on_new_line
int		rl_on_new_line(void)
	- #include <readline/readline.h>
	- 개행 출력 이후 다음 줄로 이동했음을 업데이트 루틴에 알리는 함수.
	- 정상 실행 시 0을 리턴, 오류 시 -1을 리턴

rl_replace_line
void	rl_replace_line(const char str*, int)
	- rl_line_buffer의 내용을 str로 바꿔준다.
	- 2번째 매개변수는 0을 줄 시 내부의 undo_list를 초기화하지 않음
	- 이외의 값을 줄 시 초기화한다.

rl_redisplay
void	rl_redisplay(void);
	- #include <readline/readline.h>
	- #include <readline/history.h>
	- rl_line_buffer의 컨텐츠를 반영하여 현재 화면에 표시되는 내용을 변경한다.
	- rl_replace_line를 출력하지 않으면 작동하지 않는다.
	- readline 함수의 인자로 넣은 문자열을 다시 출력한다.
	- 시그널을 받았을 때의 상황에서 이용한다고 한다.

add_history
int	add_history(const char *);
	- #include <readline/readline.h>
	- #include <readline/history.h>
	- 매개변수로 들어온 문자열을 history에 저장한다.
	- 프롬프트가 열린 상태에서 키보드 방향키 위 아래를 통해 히스토리를 확인 가능하다.

wait
pid_t	wait(int *statloc);
waitpid
pid_t	waitpid(pid_t pid, int *statloc, int options);
wait3
pid_t	wait3(int *statloc, int options, struct rusage *rusage);
wait4
pid_t	wait4(pid_t pid, int *statloc, int options, struct rusage *rusage);
	- #include <sys/wait.h>
	- #include <sys/types.h> // pid_t 자료형
	- #include <sys/resource.h> // 리소스 정보, struct rusage
	- #include <sys/time.h> // struct rusage의 시간 관련 정보
	- statlog : 자식 프로세스의 종료 상태 정보를 담아준다.
	- option : 프로세스의 종료 상태 체크 시 옵션을 걸 수 있다. 보통 0을 씀
	- rusage : 자식 프로세스의 리소스 사용량에 대한 정보를 담아준다.
	- pid : 전달한 pid에 해당하는 프로세스만 기다린다.
	- 성공 시 pid, 에러 시 -1 리턴
	- WNOHANG 옵션으로 실행되었고, 자식 프로세스가 아직 종료되지 않았을 때 0 리턴

signal
void	(*signal (int sig, void (*func)(int)))(int);
	- #include <signal.h>
	- sig : 신호 번호를 나타내는 정수 값, SIGINT나 SIGTERM같은 신호
	- func : 지정된 신호가 발생했을 때 호출할 함수, int형 매개변수(신호 번호)를 받는 함수여야 함.
		- func가 SIG_IGN일 경우 해당 신호를 무시
		- func가 SIG_DFL일 경우 기본 신호 처리 동작을 사용하도록 지정
	- 이전에 등록된 func의 주소를 반환, 즉, 처음 신호를 설정하는 경우 이전 func 주소는 NULL일 수 있다.

sigaction
int		sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);
	- #include <signal.h>
	- act : 신호 번호에 대해서 어떤 action을 할지에 대한 정보를 담고 있고, 즉, 시그널에 대한 동작을 수정하는 정보
	- oldact : 이전에 설정된 동작에 대해 돌려준다. 즉, 시그널에 대한 동작을 조회하는 정보
	- 	struct sigaction
		{
			void     (*sa_handler)(int);
			void     (*sa_sigaction)(int, siginfo_t *, void *);
			sigset_t   sa_mask;
			int        sa_flags;
			void     (*sa_restorer)(void);
		};

sigemptyset
int		sigemptyset(sigset_t *set);
sigaddset
int		sigaddset(sigset_t *set, int signum);
	- #include <signal.h>
	- emptyset : 인자로 주어진 시그널 셋인 set에 포함되어 었는 모든 시그널을 비운다.
	- addset : set으로부터 신호 번호가 signum인 시그널을 추가한다.

kill
int		kill(pid_t pid, int sig);
	- #include <signal.h>
	- 'pid'에 'sig' 시그널을 보낸다.
		- SIGKILL. SIGTERM, SIGSTOP, SIGCONT 등등
	- pid에 따라 대상이 바뀌게 된다.
		- pid > 0 : 해당 pid
		- pid == 0 : 현재 프로세스와 같은 그룹에 속한 모든 프로세스
		- pid == -1 : 시스템의 모든 프로세스
		- pid < -1 : |pid|값이 절댓값이 큰 pid를 가지는 프로세스 그룹
	- 성공 시 0 반환, 실패 시 -1 반환

getcwd
char	*getcwd(char *buffer, size_t size) // get current working directory의 줄임말
	- #include <unistd.h>
	- 현재 작업 디렉토리의 위치를 알려주는 함수
	- buf : 현재 작업 디렉토리를 저장할 buffer
		- NULL을 전달 하는 경우 메모리 할당 후 반환, 이 경우 할당 해제를 해줘야 한다.
	- size : buf에 할당 된 메모리의 크기
	- 실패 시 NULL 리턴, 다음과 같은 사유가 있을 수 있다.
		- EACCES : path 구성 중의 디렉토리에 search 권한이 없음.
		- EFAULT : buf의 메모리가 bad 주소영역임.
		- EINVAL : buf가 NULL이 아닌데, size가 0임.
		- ELOOP  : symbolic link가 순환 link가 존재함.
		- ENAMETOOLONG : Full Path명{PATH_MAX}이 너무 길거나 한 디렉토리명{NAME_MAX}이 너무김.
		- ENOENT : 현재 작업 디렉토리가 unlink됨.
		- ERANGE : 작업디렉토리를 저장할 buf의 size가 적게 잡힘. (null-terminate 값 포함)

chdir
int		chdir(const char *path);
	- #include <unistd.h>
	- 현재 작업 디렉토리를 변경하는 함수
	- path : 변경할 상대 혹은 절대 디렉토리 경로
	- 성공 시 0 리턴, 실패 시 -1 리턴, 다음과 같은 사유가 있을 수 있다.
		- EACCES : path 구성 중의 디렉토리에 search 권한이 없음.
		- EFAULT : path의 메모리가 bad 주소영역임.
		- EIO    : I/O 중에 오류가 발생함.
		- ELOOP  : symbolic link가 순환 link가 존재함.
		- ENAMETOOLONG : Full Path명{PATH_MAX}이 너무 길거나 한 디렉토리명{NAME_MAX}이 너무김.
		- ENOENT : 존재하지 않는 파일임.
		- ENOTDIR: 디렉토리가 아님.

stat // https://www.it-note.kr/173#google_vignette
int		stat(const char *path, struct stat *buf)
lstat
int		lstat(const char *path, struct stat *buf)
fstat
int		fstat(int fd, struct stat *buf)
	- #include <unistd.h>
	- #include <sys/stat.h> // struct stat 구조체
	- #include <sys/types.h>
	- 파일의 상태 및 정보를 얻는 함수
	- symbolic link file을 넘길 시 원본 파일의 정보를 얻는다. // lstat함수의 경우 그 자체의 정보를 얻는다.
	- buf : 파일의 상태 및 정보를 저장할 구조체
	-	struct stat
		{
			dev_t     st_dev;     / ID of device containing file /
			ino_t     st_ino;     / inode number /
			mode_t    st_mode;    / 파일의 종류 및 접근권한 /
			nlink_t   st_nlink;   / hardlink 된 횟수 /
			uid_t     st_uid;     / 파일의 owner /
			gid_t     st_gid;     / group ID of owner /
			dev_t     st_rdev;    / device ID (if special file) /
			off_t     st_size;    / 파일의 크기(bytes) /
			blksize_t st_blksize; / blocksize for file system I/O /
			blkcnt_t  st_blocks;  / number of 512B blocks allocated /
			time_t    st_atime;   / time of last access /
			time_t    st_mtime;   / time of last modification /
			time_t    st_ctime;   / time of last status change /
		};
	- fd : file descriptor
	- 성공 시 0 리턴, 실패 시 -1 리턴, 다음과 같은 사유가 있을 수 있다.
		- EACCES : path를 구성하는 directory중에서 search 권한(x)이 없어서 접근할 수 없습니다.
		- EFAULT : path 변수 자체가 잘못된 주소입니다. 
		- ELOOP  : 너무 많은 symbolic link로 directory가 loop에 빠졌습니다.
		- ENAMETOOLONG : path가 너무 길거나 이름이 너무 깁니다.
		- ENOENT : path가 빈 문자열이거나 path를 구성하는 directory중에서 없는 directory가 있습니다.
		- ENOMEM : 메모리가 부족합니다.
		- ENOTDIR: path를 구성하는 directory중에서 directory가 아닌 것이 있습니다.
		- EOVERFLOW : 32bit OS에서 컴파일시에 -D_FILE_OFFSET_BITS=64 옵션없이 컴파일하여 파일크기나 inode번호가 64bit에 맞지 않은 경우

opendir
DIR 	*opendir(const char *dirname)
closedir
int		closedir(const char *dirname)
readdir
struct dirent	*readdir(DIR *dp)
	- #include <dirent.h>
	- #include <sys/types.h>
	-	struct dirent
		{
			long			d_ino;       //I-노드 번호
			off_t			d_off;      //offset
			unsigned short	d_reclen;  //파일 이름 길이
			char			d_name[NAME_MAX+1]; // 파일 이름
		}
	-	typedef struct
		{
			struct _finddata_t	dd_dta;
			struct dirent		dd_dir;
			intptr_t			dd_handle;
			int					dd_stat;
			char				dd_name[1];
		} DIR;
	- 디렉토리를 열고, 닫고, 읽어들이는 함수
	- opendir로 얻어진 DIR*를 readdir로 읽을 수 있다.
	- 실패하거나 끝까지 읽었을 시 NULL/ -1 리턴, errno 세팅

isatty
int		isatty(int fd)
	- #include <unistd.h>
	- fd가 터미널에 연결되어 있는지 확인한다.
	- 연결이 되어있는 fd라면 1을 리턴, 아니면 0을 리턴

ttyname
char	*ttyname(int fd)
	- #include <unistd.h>
	- fd에 대한 터미널 이름을 반환한다.
	- 실패 시 NULL 리턴

ttyslot
int		ttyslot(void)
	- #include <unistd.h>
	- 현재 사용자의 엔트리 인덱스를 어떤 파일에서 가져오는지 반환

ioctl
int		ioctl(int fd, unsigned long request, ...)
	- #include <sys/ioctl.h>
	- 특수 파일의 기반이 되는 장치 매개변수를 조작
	- fd : ioctl함수가 적용될 파일의 fd
	- request : ioctl를 동작하기 위한 요청 코드, 어떤 동작을 할 지 정해준다.
	- 성공 시 0 반환, 실패 시 -1 반환

getenv
char	*getenv(const char *name)
	- #include <stdlib.h>
	- 환경변수를 얻는다.

tcsetattr
int		tcsetattr(int fd, int optional_actions, const struct termios *termios_p)
tcgetattr
int		tcgetattr(int fd, struct termios *termios_p)
	- #include <termios.h>
	- fd : 설정을 적용할 fd, 일반적으론 터미널 장치 파일을 의미, STDIN, STDOUT 등
	- optional_actions : 속성 설정을 즉시 할지 대기할지 지정하는 옵션
		- TCSANOW : 설정을 즉시 적용합니다.
		- TCSADRAIN : 출력 버퍼가 비워진 후 설정을 적용합니다. (즉, 현재 진행 중인 출력이 끝난 후)
		- TCSAFLUSH : 출력 버퍼가 비워지고 입력 버퍼가 비워진 후 설정을 적용합니다.
	- termios_p : termios 구조체 포인터
		- tcsetattr -> 터미널의 새로운 속성 값이 저장된 구조체
		- tcgetattr -> 터미널의 현재 설정을 저장할 구조체
	-	struct termios
		{
			tcflag_t c_iflag;  // 입력 모드 플래그
			tcflag_t c_oflag;  // 출력 모드 플래그
			tcflag_t c_cflag;  // 제어 모드 플래그
			tcflag_t c_lflag;  // 로컬 모드 플래그
			unsigned char c_line;  // 라인 설정
			unsigned char c_cc[NCCS];  // 제어 문자 (인수에 사용되는 값들)
		};
	- 성공 시 0 리턴, 실패 시 -1 리턴
	
tgetent
int		tgetent(char *buf, const char *term)
	- #include <term.h>
	- 터미널에 대한 정보, capabilities 정보를 가져오는데 사용하는 함수
	- buf : 터미널의 정보를 저장할 버퍼 최소 1024바이트 이상이어야 한다.
	- term : 조회할 터미널의 이름, TERM 환경 변수에 설정된 이름이거나 명시적으로 다른 터미널의 이름을 전달 가능
	- 성공 시 1 반환, 정보가 없을 시 0 반환, 실패 시 -1 반환, errno 세팅

tgetflag
int		tgetflag(const char *capname)
tgetnum
int		tgetnum(const char *capname)
tgetstr
char	*tgetstr(const char *capname, char *buf)
	- #include <term.h>
	- termcap 데이터베이스에서 특정 터미널 capability에 대한/ 대해
		- tgetflag -> 활성화 되어있는지 여부를 확인
		- tgetnum -> 값을 정수 형식으로 가져오는 함수
		- tgetstr -> 값을 문자열 형식으로 가져오는 함수
	- capname : 확인하려는 capability의 이름, termcap에 정의되어있음
	- Return Value
		- tgetflag -> 활성화 되어있으면 1을 반환, 비활성화 시 0을 반환, 실패 시 -1을 반환
		- tgetnum -> 해당 capability의 정수 값을 반환, 실패 시 -1 반환
		- tgetstr -> buf가 전달 되면 buf에 저장, NULL을 전달 시 할당해서 반환, 실패 시 NULL반환

tgoto
char	*tgoto(const char *cap, int col, int row)
	- #include <term.h>
	- termcap 데이터베이스에서 제공되는 터미널 제어 문자열 중 특히 커서 이동과 관련한 문자열을 생성하는 함수
	- cap : 커서 이동을 처리하는 capability의 이름
	- col : 커서를 이동시킬 열 위치, 0부터 시작
	- row : 커서를 이동시킬 행 위치, 0부터 시작
	- 성공 시 커서 이동을 위한 제어 문자열을 반환, 실패 시 NULL을 반환

tputs
int		tputs(const char *str, int affcnt, int (*putc)(int))
	- #include <term.h>
	- 터미널 제어 문자열을 터미널에 출력하는 데 사용되는 함수
	- str : 출력할 제어 문자열 tgetstr이나 tgoto함수 등에서 얻은 제어 시퀀스를 포함하는 문자열
	- affcnt : 제어 문자열이 여러 번 출력되어야 하는 경우, 출력 횟수 지정, 보통 1로 함
	- putc : 제어 문자열을 출력하는 함수, putchar등을 사용함
	- 성공 시 제어 문자열을 출력 후 OK(1) 반환, 실패 시 ERR(-1) 반환

printf
perror
	- #include <stdio.h>

malloc
free
exit
	- #include <stdlib.h>

write - 출력
read - 입력
close - fd 닫기
access - 권한 확인
fork - 프로세스 분기
unlink - 파일 삭제
execve - 프로그램 실행
dup - fd 복제
dup2 - fd 복제
pipe - pipe 생성
	- #include <unistd.h>

open
	- #include <fcntl.h>
	
strerror
	- #include <string.h>

https://velog.io/@sham/minishell%EA%B3%BC-readline
https://www.it-note.kr/157 -> 함수 설명 잘 되어있음.