# 실전코딩 2 실습 리포트

### `sshid` : pcc001
### `name` : 곽수정 ✨
### `id` : 201921085

***

## Lecture 1  

##### - 2022. 01. 04   [ C Development Platform ]  

* git을 사용하기 위한 프로그램 설치

* Basic Linux Command

### `ls`

현재 디렉토리에 어떤 파일이 있는지 list를 보여주는 명령어  

```
$ ls -l                   ; 파일의 상세 정보 표시
$ ls -a                   ; 숨어있는 파일들도 표시
$ ls -al pcc001           ; pcc001 디렉토리의 모든 파일 표시
```

### `pwd`  

print working directory : 현재 디렉토리 보여줌  

### `hostname`  
내가 지금 어떤 컴퓨터를 쓰는지 알고싶다면 사용  

```
$ hostname  
Kwakui-MacBookPro.local
```

### `who`  
컴퓨터에 누가 들어왔는지 보고싶을 때 사용  
호스트에 로그인한 사용자의 정보를 출력

### `wc`  
word count  
주어지는 파일 또는 표준 입력의 바이트, 문자, 단어 그리고 줄(라인) 수를 출력해주는 명령어

### `who | wc`  
who의 output이 다음 명령 wc에 들어감 : 현재 접속자 수 보여줌  

### `who | sort`  
who의 output 정렬해서 보여줌

### `mkdir`  
디렉토리 생성하는 명령어  

```
$ mkdir pcc         ; pcc 디렉토리 생성, 이미 디렉토리가 존재한다면 에러 발생
```  

### `cd`  
change directory  
디렉토리를 이동하는 명령어

```
$ cd                ; cd 뒤에 디렉토리 입력 안하면 home directory로 이동
$ cd ~              ; home directory로 이동, 위 명령어와 동일
$ cd ..             ; 윗 디렉토리로 이동
$ cd lec01          ; lec01 디렉토리로 이동
```

### `vi hello.c`  
vi 에디터로 파일 생성 후 편집  

 * 3가지 mode: normal, insert, command mode  

    * normal 모드에서 i 를 눌러 insert mode로 전환 후 타이핑  

        * 한 글자 지우기: delete 키 / x 키, undo: u 키, 커서 뒤에 append: a 키  

    * insert mode에서 esc 눌러 빠져나오면 normal mode로 전환됨  

    * normal mode에서 command mode로 들어가려면 : 누름  

        * ex) **:wq** = write & quit  



### `cc hello.c`  
hello.c 파일 컴파일 -> 기본적으로 a.out 실행파일 생성됨  

### `mv`  
파일을 이동시키는 명령어  

```
$ mv a.out hello.c pcc            ; a.out와 hello.c 파일을 pcc 디렉토리로 이동시킴  
$ mv hello.c hola.c               ; hello.c 파일의 이름을 hola.c 로 변경 가능
```

_cp는 원본 파일이 남아있지만 mv는 원본 파일이 남아있지 않아 파일 이름 변경시에도 사용 가능하다._  

### `passwd`  
비밀번호 변경 가능, 현재 비밀번호 입력한 뒤 새로운 비밀번호로 변경  

### `chmod`  
파일의 모드를 변경하는 명령어
  
| 파일 소유자 | 그룹 | 그 외 사용자 |
|:--------:|:----:|:--------:|
|read, write, execute| read, write, execute | read, write, execute|
|4 2 1| 4 2 1 | 4 2 1 |

|  변경 전  |  명령어  |  변경 후  |
|:-------:|:-------:|:-------:|
|drwxrwxrwx| chmod 700 pcc001 | drwx------|
| drwx------| chmod 777 forAll | drwxrwxrwx|  

* 예시) `drwxrw----- pcc039 pcc forAll`  
    * forAll이라는 디렉토리의 소유자는 pcc039이며 그룹은 pcc 이다.
    * 디렉토리의 소유자인 pcc039는 read, write, execute 권한을 가진다.
    * 그룹 pcc에 속한 사용자는 read와 write 권한을 갖는다.
    * 그 외 사용자는 아무 권한도 갖지 않는다.
    * _super user는 항상 모든 권한을 갖고 있다._

* 예시) `d---rwx--- pcc039 pcc forAll`
    * 디렉토리의 소유자인 pcc039는 아무 권한도 갖지 않는다.
    * 따라서 소유자 pcc039는 forAll 디렉토리에 들어가지 못한다!
    * **디렉토리에 들어가려면 실행 권한(x = execute)이 필요하다.**
    * 디렉토리 소유자와 others는 아무 권한이 없고, pcc group에 속한 사용하즌 read, write, execute 권한을 갖는다.

* 예시) `d---rwxrwx pcc039 pcc forAll`
    * forAll 디렉토리에 들어갈 수 있는 사람은 소유자 pcc039 빼고 모두이다.  
    즉, group에 속한 사용자, 그 외 사용자, 그리고 super user이다.
    * super user = root = 이 기계를 관리하는 사람

### `groups`  
내가 속한 그룹 보여줌

### `whoami`  
현재 로그인한 사용자의 id 출력
```
$ whoami
pcc001
```

### `cat`  
어떤 파일의 내용을 보는 명령어
```
$ cat hello.c
#include <stdio.h>

int main()
{
	printf("Hello World \n"); //Comment
}
```

### `whoami >> output`  
whoami의 결과인 pcc001이 output 파일에 추가됨

### `history`  
내가 입력한 명령어 이력들 보기  

***

## Lecture 2
  
##### - 2022. 01. 05 [ Advanced C 언어 (1) 및 편집 도구 ]  
  

### `Computer Hardware System`  

<div style="text-align : center;">
    <img src=./img/hardware_sys.png width="70%"/>  
</div>

_lec01 실습: output device에 Hello World를 출력하도록 명령함  
실행 파일명: a.out_  

* CPU: central processing unit  
* Memory: RAM, ROM  
* Input Devices: 키보드, 마우스, 마이크  
* Output Devices: 모니터, 프린터, 스피커  
* Storage Devices: hhd, ssd, 파일이 들어있는 곳

**Q**) Storage에 들어있는 a.out 파일을 CPU가 바로 실행할 수 있다? [ **X** ]
> CPU는 storage device에 들어있는 파일을 직접 실행할 수 있는 경우가 없다!

**Q**) CPU는 output device에 데이터를 내보낼 수 있다? [ **X** ]
> 직접 output device에 데이터를 내보낼 수 없다! 따라서 메모리에 두어야함.  

* Storage에 저장되어 있는 a.out 프로그램을 실행하려면 메모리에 두어야하고, 그럼 CPU가 메모리에서 하나씩 가져다가 실행함  

* 메모리 중에서 초록색으로 표시된 부분은? **buffer**
> input device가 쓰는 버퍼: input buffer  
> output device가 쓰는 버퍼: output buffer  

### `Computer system 구성요소`  
 
<div style="text-align : center;">
    <img src=./img/computer_sys.png width="70%"/>  
</div>

* User, data, hardware, software 로 구성되어 있다.

### `Software`  
* Application software  
* System software: os, compiler, device driver  
    * system software, os: 사용자가 하드웨어를 쓰기 쉽게 해주는 기능 제공
    * os ( 운영체제 ): 하드웨어 바로 위에 존재  

<div style="text-align : center;">
    <img src=./img/software.png width="70%"/>  
</div>

* bash: git-scm 설치 후 프롬프트 나오고 대화형으로 이 유틸리티를 사용할 수 있도록 만들어주는 것

* HW에 Hello world! 가 출력 되려면?  
    * hello.c를 컴파일해서 a.out 이라는 app 을 만든다. -> bash에서 a.out을 실행시킨다.  
    * HW에 출력하기 위해 shell에서 실행되어 system call 중 printf를 사용하여 커널에게 요청하고, 커널이 hw에게 출력하기를 요청하여 모니터에 Hello World! 가 출력된다.  

### `Linux kernel`

<div style="text-align : center;">
    <img src=./img/linux_kernel.png width="75%"/>  
</div>

* Linux Kernel에서도 위 **Computer hardware system** 그림에서 볼 수 있는 5가지 구성 요소를 모두 가지고 있다.  
즉 OS는 Input & Output device, Memory, CPU, Storage devices와 같은 hw를 사용자가 사용하기 쉽게 만들어준다.

* Linux kernel & Computer hardware system
    * I/O subsystem - _Input & Output device_
    * Memory management subsystem - _Memory_
    * Process management subsystem - _CPU_
    * File systems - _Storage devices_  

* 위로 갈 수록 sw, 아래로 갈 수록 hw와 가깝다. 예를 들어 Network 장치를 이용한 통신을 위한 sw는 socket이다.  

* Processor != Process != Thread  

<div style="text-align : center;">
    <img src=./img/terminal.png />  
</div>

* Terminal을 이해하기 위해서는 옛날 컴퓨터 사용방법 생각해보기  
    * 하나의 컴퓨터에 통신선을 통해 터미널과 연결하여 사용했었음  
    * 옛날에 사용하던 터미널에도 CPU, memory, I/O device 등 존재했지만 실제로 계산하는 중심적인 서비스를 제공하는 것은 async mainframe host였기 때문에 상대적으로 터미널(단말)이라고 불렀다.  

* 사용자가 hw를 사용하기 편리하도록 기본적으로 설치되는 시스템 소프트웨어: 운영체제  

* 터미널 앞에는 컴퓨터의 4대 구성요소 중 하나인 user가 있고, HW 관점으로 봤을 때 사용자와 직접적으로 맞닥뜨리는 종점( 단말 )이 **Terminal**이다.  

* Terminal = character device = Input 장치이면서 output 장치이다.  

### `Lec02 실습`

* 리눅스에서는 모든 컴퓨터 자원, resource를 파일로 관리한다.  

* git bash를 여는 순간 터미널이 열린다. 터미널의 타입을 xterm-256color로 설정하면 색이 설정되어 나온다.

* $ = prompt = 예전에는 컴퓨터 사용하는 시간만큼 돈을 냈었다.  

* 명령어를 기다리고 있다가 명령어를 수행하는 프로그램 이름은? **shell**

### `ssh`  
리눅스 서버에 원격 접속할 때 사용하는 명령어
```
$ ssh pcc001@git.ajou.ac.kr
```

### `ps`  
내가 실행하는 process 보고 싶을 때 사용하는 명령어  

```
$ ps
    PID    TTY      TIME        CMD
    5655   pts/8    00:00:00    bash
    9159   pts/8    00:00:00    ps
```
_bash를 실행하는 중 & ps 명령어도 실행되고 있었으므로 표시됨_  
* `PID` = process id = 리눅스 내부에서는 process들이 번호로 관리됨  
* `TTY` = terminal  

### `tty`  
리눅스 device 중 콘솔/터미널을 의미함  

```
$ tty
/dev/pts/8
```  

* 리눅스 운영체제는 컴퓨터의 모든 자원을 파일로 관리하며, 그 파일은 disk이다.  
Disk는 디렉토리를 찾아서 갈 수 있다.  

### `cd /dev`  

/dev = device 파일을 위한 디렉토리이다.  
장치 드라이버, 터미널, 프린터 등 주변 장치들을 나타내는 파일들이 존재한다.  

* d - directory
* c - character device
* b - block device
* l - simbolic link  

_permission 앞에 붙은 문자는 파일의 종류를 나타낸다._

### `cd /dev/pts`  

내 device pts가 존재하는 디렉토리  

`crw--w----  1  hwan  tty  136,  8  1월  5  14:19  8`  

**Q**) 위 /dev/pts에 존재하는 8번 파일에 대해 설명하세요.  
> 8이라고 하는 파일은 character device 입니다.  
8 device를 소유한 hwan은 read, write 할 수 있습니다.  
8 파일을 소유한 tty 그룹은 write 할 수 있는 권한이 있으며 이 외의 사용자는 아무 권한도 없습니다.  

* 위 8번 device에 대해 권한 변경 가능 -> ex) chmod 777 8
> echo pcc001 > 8 으로 입력 가능  

### `wall`  
write all = 모두에게 메세지 보낼 수 있음, ctrl + d 로 메세지 입력 종료  

### `write pcc001`  
wall과 같이 메세지를 보낼 수 있는 명령어, write pcc001은 pcc001에게 메세지를 보내게 된다.  

### `mesg n`  
message no = write permission turned off  

### `biff`  
이메일이 오면 벨을 울리게 하는 명령어, 개발한 사람의 옆집 개 이름  

> 리눅스 명령어에서 어떤 규칙을 찾는 것은 불가능하다.  
명령어의 word 선택은 규칙이 없다.

### `man`  
각종 명령어와 프로그램 사용법, 메뉴얼을 보여준다.

```
$ man cat       ; cat 명령어의 메뉴얼을 보여준다.
```  

```
$ man cp        ; cp 명령어의 메뉴얼을 보여준다.
```  

<div style="text-align : center;">
    <img src=./img/man_cp.png width="75%"/>  
</div>  

* `cp [OPTION]` -> [OPTION]은 생략할 수 있다.  
* `cp [OPTION] ...` -> ...은 여러 옵션이 붙을 수 있음을 의미한다.  
* `cp [OPTION] ... SOURCE ... DIRECTORY` -> SOURCE ...은 SOURCE가 여러개 붙을 수 있다는 뜻이다.  

**tab을 습관적으로 사용하기! -> 파일명 입력할 때 실수를 줄여주는 방법**  

### `반드시 알아야 할 단축키`  
* ctrl + d: exit, EOF (End Of File)  
* ctrl + c: kill signal  
* ctrl + z: suspend signal  

**Q**) ssh로 팔달관에 있는 git.ajou.ac.kr 컴퓨터로 들어갈 수 있다. git.ajou.ac.kr이 우리에게 device를 하나씩 줬는데 무슨 device일까?  
> Terminal  

**Q**) 나에게 준 터미널이 무엇인지 물어보고 싶다면?  
> tty 명령어 입력 -> /dev/pts/11  
/dev/pts/11 터미널을 주고 passward를 물어봐서 일치하면 첫번째로 실행되는 process는 bash임을 알 수 있다.  
(ps 명령어로 실행중인 process 알 수 있다.)  

### `ls -l 과 ps -l`  
* ls -l: 파일이 자세히 보임
* ps -l: process가 상세히 보임
* 명령어 자체에는 규칙성이 없지만 명령어의 옵션이나 syntex의 규칙은 서로 매우 비슷하다!  

```
$ ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  4001 18126 18125  2  80   0 -  6054 wait   pts/2    00:00:00 bash
0 R  4001 18143 18126  0  80   0 -  7551 -      pts/2    00:00:00 ps
```  

* UID: user id  
* PID: process id  
* PPID: parent process id
* ps process의 부모가 bash임을 알 수 있다.  
    * ps의 PPID: 18126 == bash의 PID: 18126  

**ls -al 명령어가 hidden 파일 보여주는 것처럼 ps -al 명령어도 hidden process 보여준다.**  

<div style="text-align : center;">
    <img src=./img/hello_world.png width="75%"/>  
</div>  

**Q**) a.out를 실행하면 왜 모니터에 Hello World! 가 출력될까?  
> 지금 내가 사용하고 있는 shell 입장에서 shell의 가장 기본이 되는 input 장치와 output 장치 = **표준입출력장치**  
stdio.h 를 include 했기 때문에 표준입출력장치에 Hello World! 가 출력된다.  

### `stdio.h`  

**Q**) stdio.h 파일은 어디에 있을까?  
> /usr/bin/include 에 stdio.h가 존재한다!  
```
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
```

* **리눅스는 모든 device가 파일이다!!!**  

* I/O stream은 buffer로 이해하면 좋다.  

* vi editor 명령:  
    * if에 해당하는 endif 찾고 싶다면 **%** 누르기  
    * 괄호의 짝을 찾을 때도 **%** 누르기
    * line number 보고 싶다면 **:set number**
    * 검색하고 싶을 때는 **/검색어** 로 찾기

* /vmlinuz: 커널 파일, boot/vmlinuz-4.15.0-163-generic에 링크되어있다.  

* /var: variable length, log 파일 등 가변 데이터 파일들이 저장된다.  

### `lec02의 hello.c`  

```
#include <stdio.h>

int main()
{
    FILE *fout;
    fout = fopen("output.txt", "w");
    fprintf(fout, "Hello World\n");
}
```

**Q**) 위 코드를 통해 Hello World가 output.txt 파일에 써질까? [ **X** ]  
> buffer를 닫지 않았기 때문에 output.txt에 써지지 않는다.  

### `hello.c 수정한 버전`  

```
#include <stdio.h>

int main()
{
    FILE *fout;
    fout = fopen("output.txt", "w");
    fprintf(fout, "Hello World\n");
    fclose(fout);
}
```

_이제 Hello World가 output.txt에 저장된다!_  

* CPU가 Hello World라고 쓰면 storage device에 써지지 않음! buffer에 쓰여진다.  

* buffer에 있는 것이 storage device에 저장되는 때는..? 3가지 mode 존재
    1. memory 크기는 유한대이므로 buffer가 꽉 차면 그 때 storage device에 저장한다.
    2. 한글자 buffer에 올때마다 storage device에 저장한다. (buffer size: 1byte)
        * 대신 성능이 나쁘다. -> 일반적으로 memory보다 storage가 속도가 느리기 때문에
    3. buffer control하는 명령이 왔을 때 storage device에 저장한다.  

### `sleep`  
뒤 입력 초만큼 sleep 하는 명령어, kill하고 싶다면 **ctrl + c** 누르기  

```
$ sleep 600             ; 600초, 10분 동안 sleep
```  

### `cat`  
파일(들)을 순서대로 읽고 그 내용을 읽은 순서대로 표준 출력에 쓰는 명령  

```
$ cat  
aaa                     ; 입력
aaa                     ; 출력
bbb                     ; 입력
bbb                     ; 출력
```
작업 끝내고 싶다면 **ctrl + d** 누르기  

### `vi 에디터로 편집 중에 ctrl + z 누른 경우`  
process를 잠시 suspend 시킴 (보류)  
```
$ vi hello.c            ; 편집 중에 ctrl + z 누른 뒤...
[1]+    Stopped         vi hello.c  

$ps
  PID  TTY          TIME CMD
20145  pts/11    0:00.00 bash
23919  pts/11    0:00.00 vi
27662  pts/11    0:00.00 ps

$ jobs
[1]+    Stopped         vi hello.c 
```  

### `Stopped 시킨 job으로 돌아가기`  
**fg** = background 작업을 foreground로 옮기기
```
$ fg %1             ; 1번 작업인 vi 에디터로 다시 돌아감  
```

### `(sleep 1000 ; echo "pcc001 - 1000sec") &`  
* 프로그램 실행 시에 끝에 &를 붙여 백그라운드로 실행시킬 수 있다.  
* jobs 명령을 통해 현재 백그라운드에서 동작하고 있는 프로그램의 확인이 가능하다.  
* 백그라운드 프로그램을 죽이고 싶다면 **kill -9 %번호**

```
$ sleep 1000 ; echo "pcc001 - 1000sec" &            ; 앞 작업이 끝나야 뒤 작업 실행되므로 제대로 작동하지 않음
$ (sleep 1000 ; echo "pcc001 - 1000sec") &          ; 묶어주면 background 작업으로 작동함
```

### `cat a.out`  
* a.out는 우리가 읽을 수  있는 텍스트 파일이 아니다. 따라서 cat a.out 실행시 읽을 수 없는 내용이 보여진다.  
* hello.c는 C source, ASCII text 파일이므로 cat hello.c 명령어 실행시 파일 내용을 보여준다.  

### `cat`  
* concatenate files and print on the standard output  
* 파일을 합쳐서 statndard output으로 보여주는 명령어  
* ctrl + d 누르면 cat 프로그램 종료, (EOF)
```
$ cat
aaa                 ; 파일이 없다면 statndard input을 입력으로 받아서
aaa                 ; standard output에 출력한다.  
```
* 터미널 사용할 때 기본 입력장치: 키보드, 기본 출력장치: 모니터  
* 버퍼 종류 중에 대표적인 것: 한줄씩 보내줌.
    * stdin으로 aaa 엔터 입력 -> CPU가 처리 -> stdoout으로 한줄 내보냄.

### `redirection`  
* `< file` : stdin 대신에 이 파일을 쓰세요
* `0< file` : < file 과 동일
* `> file` : stdout 디바이스(/dev/pts/8)로 나갈 것을 file에 써주세요.  
* `1> file`: > file과 동일  
* `2> file`: stderr를 이 file로 내보내주세요.  

### `date`  
현재의 시간과 날짜를 stdout에 출력해주는 명령어  

```
$ date > date.txt           ; stdout이 date.txt 파일로 리디렉션됨.  
$ cat date.txt
2022. 01. 05 (수) 16:02:23 KST  

$ cat date.txt hello.c output.txt > total.txt            ;파일 3개가 total.txt로 concatenate됨.
$ cat hello.c hello.c hello.c > hello3                   ; hello.c 3개가 hello3에 합쳐짐  

$ cat < hello3                                             ; input으로 hello.c를 받아서 stdout에 출력함.
$ cat hello3                                               ; cat < hello3와 동일  

$ cat < hello3 > hello4
$ diff hello3 hello4        ; 두 파일은 동일한 파일이다.  

$ cat hello.c hello.cpp 1>out.txt 2>err.txt 
; hello.c 내용을 받아 stdout이 out.txt에 저장됨. hello.cpp 파일이 없어 발생한 에러 메세지는 err.txt에 저장된다.  
```  

### `stdin, stdout, stderr redirection`  
in.txt 파일에는 학번(201921085)이 저장되어있고 아래 코드는 hello.c 파일이다.
```
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}
```

```
./a.out < in.txt > out.txt 2>err.txt
```

위 명령어 실행시 out.txt에는 Hello stdout 201921085가, err.txt에는 Hello stderr 201921085가 저장된다.  
`>>` 는 계속 내용이 누적되도록 할 수 있다.  

***

## Lecture 3  

##### - 2022. 01. 06 [ Advanced C 언어 (2) 및 편집 도구 ]

### linux command

교수님의 코드를 카피함

```
cp ~hwan/.profile  ~hwan/.bashrc  ~hwan/.bash_logout ~
source .profile
```

이렇게 하니까 프롬프트가 초록색이 됨

***

## Lecture 4  

##### - 2022. 01. 10

***

## Lecture 5
##### - 2022. 01. 11

***