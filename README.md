# 실전코딩 2 실습 리포트

### `sshid` : pcc001
### `name` : 곽수정 ✨
### `id` : 201921085

***

## Lecture 1  

##### - 2022. 01. 04   

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
  
##### - 2022. 01. 05 
  

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
* a.out는 우리가 읽을 수  있는 텍스트 파일이 아니고 binary 파일이다.  
따라서 cat a.out 실행시 읽을 수 없는 내용이 보여진다.  
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
    * stdin으로 aaa 엔터 입력 -> CPU가 처리 -> stdout으로 한줄 내보냄.

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

##### - 2022. 01. 06 [ Advanced C 언어 (2) 현장의 코딩 규칙 ]  

### `linux command`

교수님의 코드를 카피하였더니 프롬프트가 초록색으로 변경되었다. (색 지정 O)  

```
cp ~hwan/.profile  ~hwan/.bashrc  ~hwan/.bash_logout ~
source .profile
```  

### `which`  
* 특정 명령어의 위치를 찾아주는 명령어  
* which 명령어를 사용하면 현재 사용하고 있는 명령어 실행파일의 위치를 알 수 있다.

### `grep`  
텍스트 파일에서 원하는 문자열이 들어간 행을 찾아 출력하는 명령어  

### `ls`  
ls 명령어가 처음에 위치해 있는 곳은?? **storage**, storage에 들어있는 것은 파일이다.  
```
$ which ls
/bin/ls
```  

### `PATH`  

```
$ vi ls             ; ls에는 ls -lida 저장함
$ chmod +x ls
$ ./ls              ; 직접 작성한 ./ls 실행됨
$ ls                ; /bin/ls의 ls가 실행됨
```  

* 시스템 안에 존재하는 ls 중 무엇을 실행시킬지 순서를 정해야함: 환경변수 **PATH**  

```
$ echo $PATH
/home/course/pcc039/bin:/home/course/pcc039/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:.
```  
* source .profile을 통해 마지막줄 PATH="$HOME/bin:$HOME/.local/bin:$PATH:."이 실행되어 path가 추가되었다.

* 따라서 lec02에 있는 a.out를 ./a.out으로 실행했어야 했는데 path를 추가한 뒤에는 a.out으로 실행시킬 수 있다.  

```
$ which a.out
./a.out                         ; 현재 디렉토리 밑에 있는 a.out이 실행된다.
```  

_그래도 .을 빼는 것이 보안상 안전하다..!_  

### `Markdown`  

* `#`: 제목
* `##`: 부제목
* `###`: 부부부제목  
* 문단을 나누고 싶을 때는 빈 줄을 한줄 더 만들기  
* `*` 또는 `1. `: 목록 또는 숫자 붙은 목록이 만들어진다.
    * 계속 1. 로 적어도 자동으로 1, 2, 3 순서대로 숫자 붙여준다.

* git.ajou.ac.kr 에서 마크다운 language를 사용하여 README.md 수정한 뒤 commit message를 쓰고 commit 하였다.  

> 마크다운 공부하려면 Markdown 클릭! [Markdown](https://www.youtube.com/playlist?list=PLKseYrrlvWNpYJxtfoUj5FLuMHv7Wrmid)  

### `주의할 점`  

* 코드로 쓰는 쌍 따옴표, 단 따옴표와 MS word가 바꾸는 코드는 다르다..!
* MS word에서는 ASCII 코드가 아니라 유니코드임  

<div style="text-align : center;">
    <img src=./img/echo.png width="70%" >  
</div>  

### `gitignore`  

* git.ajou.ac.kr에서 내 폴더로 들어간 뒤 new file을 추가함  
* template type을 .gitignore로 선택한 뒤, binary 파일을 git 서버에 백업하지 않도록 아래와 같이 작성하고 commit 하였다.

```
*.out
```  

### `clone`  
* clone with https를 눌러 링크를 복사한 뒤 ssh 서버의 pcc 디렉토리에 git clone https://git.ajou.ac.kr/kwaksj329/pcc001.git 으로 clone 하였다.  

* pcc001 디렉토리 안에는 .git과 .gitignore 와 같은 hidden file과 README.md가 있다.  

* . 으로 시작하는 파일은 hidden 파일이다.  

```
$ file * .*             ; 모든 파일과 hidden 파일
README.md:  UTF-8 Unicode text  
.:          directory
..:         directory
.git        directory
.gitignore:  ASCII text
```

.gitignore는 한글이 하나도 포함되어 있지 않기 때문에 ASCII text이다.  

### `clear`  
터미널 내용을 지우고 싶을 때 사용하는 명령어  

### `unicode`  
unicode는 1바이트, 2바이트, 4바이트, 8바이트로 이루어져 있다.  
한글을 쓰려면 unicode, UTF-8 을 써야한다.  

### `git 프로젝트를 전체 프로젝트로 만들기`  

1. lec01 & lec02 를 pcc001로 옮기기  
2. pcc001에 있는 모든 파일을 pcc 디렉토리 밑으로 옮기기  
    * 아래 코드는 2번 방법에 해당함

``` 
$ mv pcc001/* .                 ; pcc 디렉토리에 hidden 파일은 안옮
$ mv .git .gitignore ..         ; pcc 디렉토리로 옮김
```  

### `ssh & https`  

* git-scm 설치
* git-bash 실행시 가상의 터미널이 열림 -> 터미널이 열리자마자 bash가 실행됨
* ssh 프로그램 실행시켜 git.ajou.ac.kr 접속함 => 터미널로 들어온 것은 `ssh` 서비스라고 함  
* 웹브라우저로 git.ajou.ac.kr로 접속함 => `https` 서비스로 접속함

### `pipe`  
어떤 출력을 다음에 오는 명령어의 입력으로 넣는 명령어  

```
$ ps -ael | grep ssh            ; ps -ael의 출력 중 ssh를 찾는 명령어
$ who | wc                      ; who 결과의 라인수, 단어수, 글자수 세어줌

$ wc
aaa bbbb cccc
1   3   15                      ; 1글자, 3단어, 15글자 (글자 + 줄바꿈까지)

$ grep aaa                      ; 파일 없이 standard input을 받아 해당 string이 나타나면 표시해줌  
$ grep printf hello.c | wc      ; hello.c 파일의 printf 찾아 라인수, 단어수, 글자수 세어줌
```  

**Q**) 파이프는 어디에 있을까?  
> buffer, output buffer를 input buffer에 symbolic link 시켜둠  
파이프는 메모리에 버퍼 형태로 존재하며 파이프도 디바이스기 때문에 /dev/에 디파이스 파일로 만들 수 있다.  

* 파이프를 자료구조로 생각하면 queue이다. (FIFO)
* 따라서 파이프 만드는 명령어 `mkfifo mypipe`  
* 파이프는 파일의 속성이 **p**이다!  

```
$ mkfifo mypipe
```

### `tee`  
stdin을 받아서 stdout과 하나 이상의 파일에 그 입력을 출력하는 명령어

<div style="text-align : center;">
    <img src=./img/tee.png width="70%" >  
</div>  

```
$ echo testing | tee test.txt
test
$ cat test.txt
test

$ ls -l | tee aaa           ; ls -l의 결과가 stdout에도 출력되고 aaa에도 저장된다. 
```  

### `git 서버에 올리는 방법`  

```
$ git pull                  ; 혹시 서버에서 update 한게 있다면 가져와 merge 함
$ git add *
$ git commit -m "Added something"
$ git push
```  

* git commit만 치면 nano editor가 실행된다.  
* vi ~/.gitconfig 파일에 아래 코드를 추가하면 nano 에디터가 아닌 vi 에디터가 실행된다.  
    * git commit 실행 후 파일에 commit message 적어서 저장해주면 commit message가 설정된다.  

```
[editor]
    editor = vi
[color]
    ui = auto
```

* 내 PC 에서 git bash 실행하여 Desktop/new_folder로 이동한 다음 git clone 해옴  
* 내 PC 에서도 파일을 수정하고 git add, git commit, git push 가능!  

***

## Lecture 4  

##### - 2022. 01. 10   [ Data Type ]

### `pipe`  

* standard I/O는 기본적으로 메모리에 들어있다.  
* 그 메모리에 구성되어있는 디바이스는 /dev/stdin, /dev/stderr, /dev/stdout, /dev/fd 에 있다.  
* 추가로 사용자가 3, 4, 5 ... 도 만들어서 stdin이나 stdout으로 내보낼 수 있다.  

<div style="text-align : center;">
    <img src=./img/stdio.png width="70%" >  
</div>  

### `redirection`  

* `<` == `0<`  : 파일로부터 표준 입력을 받도록 redirection
* `>` == `1>`  : stdout의 출력을 파일의 출력으로 redirection
* `>>` == `1>>`  :stdout의 출력을 파일에 내용 추가 (append)
* `2>`  : stderr의 출력을 파일의 출력으로 redirection
* `2>>`  : stderr의 출력을 파일에 내용 추가 (append)  

```
$ echo hello > /tmp/out
$ > /tmp/out echo hello             
$ echo > /tmp/out hello                 ; 순서 바꿔도 상관 없음
$ echo hello >&2
$ echo >&2 hello                        ; stdout을 stderr로 내보냄
$ read -r line < file            
$ < file read -r line
```  

```
$ mycomm > outfile 2>&1 을 줄여서 mycomm &> outfile
$ mycomm >> outfile 2>&1 을 줄여서 mycomm &>> outfile
$ mycomm1 2>&1 | mycomm2 을 줄여서 mycomm1 |& mycomm2
```  

```
$ a.out <<< 300 &> out.txt
$ more out.txt
Hello stderr 300
Hello stdout 300
```

**Q**) 코드는 stdout -> stderr 순서로 작성했는데 왜 out.txt에는 반대 순서로 저장되어 있을까?  
> stdout에서 stdout device로, 그리고 stderr에서 stderr device로 나가는 순서는 누가 먼저 나갈지 아무도 모름!  
만약 stdout 먼저 나가게 하고 싶다면 stdout buffer에 쓰고 flush 명령으로 버퍼 비우게 해야함. 그 다음에 stderr buffer에 쓰고 stderr device에 내보내야 순서대로 저장된다.  

* 리디렉션 공부시 참고! [Redirection](https://mug896.github.io/bash-shell/redirections.html)  

### `here document, here string`  

* `here document`
* `<<` == `0<<`  : 임시 파일을 만들어 stdin으로 연결  

```
$ cat <<EOF         ; EOF 라고 타이핑하기 전까지는 계속 입력을 받으세요.
"200"
EOF                 ; 입력 끝냄
"200"
```  

```
$ cat <<QQQ
> 200
> Hi
> Print
> QQQ               ; 입력 끝냄
200
Hi
Print
```

* `here string`
* `<<<`  : string을 stdin 입력으로 연결 (bash only)

```
$ cat <<< $( echo -e "hello\nhere        string" )          ; $ == 명령어 실행한 결과
hello
here        string

$ cat <<< *               ; globbing 이 발생하지 않는다.
*
```

```
$ cat hello.c
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}

$ cc hello.c            ; hello.c 컴파일하여 a.out 실행파일 생성됨.
$ a.out <<< 99          ; here string, bash에서만 가능!
Hello stdout 99
Hello stderr 99
```

### `pipe order of execution`  

`$ cmd1 | cmd2`  
* cmd1 과 cmd2 는 동시에 병렬로 실행된다.  

* cmd1 이 cmd2 보다 빠르면 파이프에 write 은 블록되고 더이상 진행되지 않는다.  

* cmd2 가 cmd1 보다 빠르면 파이프 로부터의 read 는 블록된다.  

* cmd1 이 먼저 종료하면 파이프는 close 되고 cmd2 는 End-Of-File 로 인식해 종료한다.  

* cmd2 가 먼저 종료하면 파이프는 close 되고 cmd1 은 다음번 write 에 SIGPIPE 신호를 받게되고 종료된다. (파이프가 깨졌다는 신호)  

**Q**) cmd1 이 cmd2 보다 빠르면 파이프에 write 은 블록되고 더이상 진행되지 않는 이유?  
> stdin buffer와 stdout buffer 둘다 1024 바이트일 때, stdin이 stdout 보다 느린 경우 stdout을 안가져가면 버퍼가 꽉차서 stdout에 더 이상 내보내면 안된다.  
버퍼가 꽉 차있는데 내보내면 버퍼 플로우가 일어나서 데이터를 잃게 된다.  

**Q**) cmd2가 cmd1보다 빠른 반대의 경우에는?
> cmd2 이 cmd1 보다 빠르면 파이프에 read 은 블록되고 더이상 진행되지 않는다.  

### `named pipe`  

* Pipe는 자동으로 생성 / 소멸
* Named Pipe
    * mkfifo 명령으로 생성 – 파일처럼 생성됨 
    * redirection으로 sending
* 읽는 상대편이 없으면 Block 된다
* Buffer Control 이 필요

### `globbing, wild card`  

* glob 문자에 의해 매칭된 파일들로 치환되는 것: globbing
* \* = 없는 것을 포함하여, 어떠한 수의 문자라도 일치
* ? = 어떤 한 문자를 일치
* [abc] = 대괄호 안의 하나의 문자를 일치
* [a-c] =  대괄호 안의 범위에 속하는 하나의 문자를 일치  

```
$ echo h*           ; h로 시작하는 파일 보여줌
hello.c
$ echo *.c
hello.c
$ echo ?????        ; 5글자 파일 보여줌
a.out
$ echo ?????*       ; 5글자 넘는 파일 보여줌
$ echo [abc]*       ; a/b/c로 시작하는 파일 보여줌
$ echo [a-q]*       ; a~q로 시작하는 파일 보여줌
```  

### `b.out | a.out`  

```
$ cat hello.c               ; a.out 실행파일
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}

$ vi hello2.c               ; input을 받아 stdout으로 숫자 내보내는 코드 작성
$ cc -o b.out hello2.c
$ b.out | a.out             ; b.out의 출력이 a.out의 입력으로 들어가 실행됨
999
Hello stdout 999
Hello stderr 999
```

### `named pipe`  

```
# 첫번째 터미널에서..
$ mkfifo pipe
$ b.out > pipe
99

# 동시에 두번째 터미널에서..
$ ./a.out < pipe        ; pipe에 담긴 99 읽어와서 실행 + 출력
Hello stdout 99
Hello stderr 99
```  

_pipe: a.out라는 프로그램과 b.out라는 프로그램, 두 프로그램 사이에서 통신하는데 사용 가능_   

**대표적으로 두개의 process 간의 통신하는 방식: pipe**  

### `vi pipe`

```
$ vi pipe           ; vi 에디터로 pipe 열어서 12345 저장함
$ cat < pipe        ; pipe에 저장한 것 보여줌..!
12345
```

신기하다..! 😎

### `basic data type`  

```
int ifuncAdd(int a, int b)
{
    return a+b;
}
```

**Q**) 여기서 a, b는 정수이다 -> [ X ]
> 정수는 -무한대 ~ 무한대이기 때문에 a, b는 정수형이다. (정수 타입)  

**Q**) int가 4바이트라고 표준화 기구가 정했다 -> [ X ]  
> 기계에 따라 다르다. 어떤 기계에서는 4바이트, 8바이트, 2바이트로 달라진다.  

**위 코드는 이 컴퓨터와 컴파일러에서 정희한 정수형 데이터타입이 허용하는 범위 내의 a, b를 합하여 니온 결과가 다시 한번 허용하는 정수 범위 내에 있어야한다.**

* int: 4바이트, 2바이트, 8바이트, 1바이트
* char, unsigned char: 1바이트, 2바이트

* Standard signed integer type
    * signed char, short int, int, long int, long long int
* Unsigned
    * unsigned ...
* floating type
    * flout, double, (long double) 
* Definition in standard
    * char - large enough to store any execution character set
    * floating - The set of values of the type float is a subset of the set of values of the type double; the set of values of the type double is a subset of the set of values of the type long double.
    * Complex
    * Bool - 0,1을 저장하면 된다. (따라서 일반적으로 int형 사용)  
    * void - char의 포인터라고 생각하면 쉽다.  

* c언어에서 half float (2byte), float (4byte) double (8byte) long double(16byte)로 몇 바이트인지 정의하고 있지 않다. 

* 대신 half float ⊆ float ⊆ double ⊆ long double처럼 부분집합 (subset)으로 정의하고 있다!

### `Negative integer`  

`음수 표현 방법 3가지`  

* signed bit + value  
* two's complement: -를 곱하고 +1
* one's complement: not (bitwise)  

* C 언어에서는..? 음수를 표현하기 위해 위 3가지 경우 중 하나 사용하면 된다.  

### `signed & unsigend`

* signed & unsigend: noun-adjective format  
* 그래서 int나 char같은 타입 앞에 signed / unsigend를 쓴다.

### `Memory model`  

* Automatic
* Static
* Manual  

### `(터미널에서) python 사용`  

```
$ python
$ bin(-4)
'-0b100'
$ bin(-7)
'-0b111'
```

* python의 integer
    * 2 ** 32, 2 ** 64, 2 ** 1024... 표현 가능
    * 따라서 python의 integer는 크기의 제한이 없다.

* python에서는 음수 표현할 때 대부분 two's complement를 사용한다.

### `limits.h`

* /usr/include/limits.h에 타입과 그 크기가 정의되어 있다.
* Maximum length of any multibyte character in any locale.
    * define MB_LEN_MAX     16 
    * = 이 컴퓨터에서는 multibyte character 16 바이트보다는 크지 않아야한다.

**limits.h는 기계마다, 컴파일러마다 다르다!**

### `10진수를 2진수로 출력해주는 코드`

```
$ cat binary.c
# include <stdio.h>

int main()
{
    int i;
    int in_a;
    fscanf(stdin, "%d", &in_a);
    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_a>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}

$ cc -o bin binary.c
$ bin <<< 3
0000 0000 0000 0000 0000 0000 0000 0011
```

* int 형 변수 in_a 를 입력받아 shitf 연산을 한 후에 1과 &(and) 연산을 하여 2진수로 변환하여 출력하는 코드이다.
* `>>` 는 right shift이고 나누기 2와 같다.
* `<<` 는 left shift이고 곱하기 2와 같다.

### `음의 10진수 <-> 2진수 변환 방법`  

* 음의 10진수 정수를 2진수로 바꾸고 싶을 때
    1. 해당 정수를 양수로 바꾸어 2진수로 표현한 후, 
    2. 구한 2진수에서 1은 0으로, 0은 1로 바꾼 다음,
    3. 1을 더한다.

* 2진수를 음의 10진수 정수로 바꾸고 싶을 때
    1. 2진수에서 1은 0으로, 0은 1로 바꾼 다음,
    2. 바꾼 2진수에서 1을 더하고
    3. 더한 2진수를 10진수로 변환하여, 음을 붙인다.

<div style="text-align : center;">
    <img src=./img/twos.png width="65%" >  
</div>  

* 사진에서 위의 식은 2진수를 양의 10진수로, 아래 식은 음의 10진수로 변환하는 식이다.

* 00000000 = 0 (10진수)
* 00000001 = 1 (10진수)
* 00000010 = 2 (10진수)
* 10000000 = -128 (10진수)
* 10000001 = -127 (10진수)
* 11111111 = -1 (10진수)
* 11111110 = -2 (10진수)

### `python과 bin에서의 정수형`

* python에서는..

```
$ bin(3)
'0b11'
$ bin(-3)
'-0b11'
```

* 우리가 위에서 짠 bin 프로그램에서는..

```
$ bin <<< 3
0000 0000 0000 0000 0000 0000 0000 0011

$ bin <<< -3
1111 1111 1111 1111 1111 1111 1111 1101
```

* 우리가 짠 bin 프로그램을 바탕으로 3과 -3을 & operation하면 0000 0000 0000 0000 0000 0000 0000 0001이 나온다.

* 파이썬에서도 bin(3&-3)을 하면 '0b1'이 나온다.

* 파이썬에는 정수형 데이터의 길이가 정해져있지 않다.

* 파이썬에서는 모든 음수를 two's complement로 표현한다.
    * 내부적으로는 bin(-3)이 '-0b11' 이렇게 bit가 표현되어 있지 않다는 뜻이다.

* 파이썬에서 3은 0000000....0000011 로 앞에 0이 무한대로 있다.

* 파이썬에서 -3은 11111111......1101로 앞에 1이 무한대로 있다.

### `2진수의 & operation 코드`  

* 앞 코드에서 in_c = in_a & in_b 추가함

```
$ cat binary.c
# include <stdio.h>

int main()
{
    int i;
    int in_a, in_b, in_c;
    fscanf(stdin, "%d %d", &in_a, &in_b);
    in_c = in_a & in_b;
    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_a>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");

    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_b>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");

    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_c>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
    
}

$ cc -o bin binary.c
$ bin
100 -100                ; 100과 -100의 & operation
0000 0000 0000 0000 0000 0000 0110 0100
1111 1111 1111 1111 1111 1111 1001 1100
0000 0000 0000 0000 0000 0000 0000 0100
```

### `in_c = in_a >> 2 수정 (오른쪽으로 shift)`  

* 위 코드에서 in_c = in_a & in_b를 in_c = in_a >> 2로 수정해보았다.

```
$ bin
-456 456
1111 1111 1111 1111 1111 1110 0011 1000
0000 0000 0000 0000 0000 0001 1100 1000
1111 1111 1111 1111 1111 1111 1000 1110
```

* 그리고 a, b, c를 unsigned int로 바꿔서 실행해본 결과이다.

```
$ bin
-456 456
1111 1111 1111 1111 1111 1110 0011 1000
0000 0000 0000 0000 0000 0001 1100 1000
0011 1111 1111 1111 1111 1111 1000 1110
```

* 위 두가지 case로 알 수 있는 점!

* int 형(signed int)일 때 오른쪽으로 shift하는 경우에는 가장 왼쪽에 1이 들어간다.

* 반면 unsigned int 형일 때는 오른쪽으로 shift하면 가장 왼쪽에 0이 들어간다.

* 오른쪽으로 1 shift는 나누기 2와 같다. 아래 예시는 signed int 형일 때 0이 아닌 1이 가장 왼쪽에 들어가는 모습을 보여준다.
    * 1000 0000 = -128 (10진수)
    * 1100 0000 = -64 (10진수)
    * 1110 0000 = -32 (10진수)
    * 1111 0000 = -16 (10진수)

* 주의해서 봐야할 점!!

|signed int|unsigned int|
|:---------:|:---------:|
|-456 = 1111 1111 1111 1111 1111 1110 0011 1000|-456 = 1111 1111 1111 1111 1111 1110 0011 1000|
|-456을 오른쪽으로 2번 shift한 결과 1111 1111 1111 1111 1111 1111 1000 1110|-456을 오른쪽으로 2번 shift한 결과 0011 1111 1111 1111 1111 1111 1000 1110|

* -456 2번 shift한 결과를 보면 signed int는 맨 앞에 11이 들어갔는데 unsigned int는 맨 앞에 00이 들어가게 되었다.

**signed int일 때, 즉 맨 앞이 1이어서 음수일 때는 오른쪽으로 shift 연산이 일어나면 1이 들어간다.**  

**unsigned int일 때, 즉 맨 앞이 1이지만 양수일 때는 오른쪽으로 shift 연산이 일어나면 0이 들어가게 된다.**  

***

## Lecture 5
##### - 2022. 01. 11   

* more: cat 과 비슷한데 다음 페이지 보고싶으면 space 키 누름

* man cc -> gcc가 나옴

* which cc -> /usr/bin/cc
    * cc -> /etc/alternatives/cc
    * /etc/alternatives/cc -> /usr/bin/gcc
    * gcc -> gcc-7
    * gcc-7 -> x86_64-linux-gnu-gcc-7
    * x86_64-linux-gnu-gcc-7 : 이게 진짜 실행파일  

* x86_64-linux-gnu-gcc-7  
    * x86: cpu가 intel cpu 용이며, 
    * _64: intel cpu를 위한 64bit, 
    * linux: 운영체제는 리눅스를 위한,
    * gnu gcc compiler이다.  

* cpp = C preprocessor

* 우리가 cc 하면 제일 먼저 cpp가 돌고, gcc compiler가 돌고, loader가 돌아서 a.out가 만들어진다.  

### `unsigned int`  

* binary.c 파일 아래와 같이 수정함

```
$ cat binary.c
# include <stdio.h>

int main()
{
    int i;
    unsigned int in_a;
    fscanf(stdin, "%u", &in_a);
    fprintf(stdout, "%u \t : ", in_a);
    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_a>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}
```

* unsigned int 범위를 넘어가는 입력이나 음수를 입력받으면 입력한 수와 다른 수로 출력된다.
    * -1 입력하면 4294967295가 출력됨. (unsigned int로!)

### `signed & unsigned int`

* hello.c 아래와 같이 수정함 (실행파일 : a.out)

```
$ cat hello.c
#include <stdio.h>

int main()
{
    signed int siA;
    unsigned int unA;

    fscanf(stdin, "%d", &siA);
    fprintf(stdout, "signed integer : %d\n", siA);
    unA = siA;
    fprintf(stdout, "unsigned integer : %u\n", unA);
    fprintf(stdout, "unsigned integer percent d : %d\n", unA);
    fprintf(stdout, "signed integer percent u : %u\n", siA);

    fscanf(stdin, "%u", &unA);
    fprintf(stdout, "unsigned integer : %u\n", unA);
    siA = unA;
    fprintf(stdout, "signed integer : %d\n", siA);
}

$ a.out
-1
signed integer : -1
unsigned integer : 4294967295
unsigned integer percent d : -1
signed integer percent u : 4294967295
4294967295
unsigned integer : 4294967295
signed integer : -1
```

* -1이 signed integer로 저장되면 메모리 상에 1111 1111 1111 1111 1111 1111 1111 1111로 저장된다.

* 따라서 저장된 데이터 1111 1111 1111 1111을 unsigned integer로 읽으면 2진수 그대로 읽어서 4294967295로 출력하게 되는 것이다.

* signed int로 받은 입력 -1을 signed int 변수와 unsigned int에 저장해서 출력해보기  

|signed integer|unsigned integer|
|:-------------:|:-------------:|
|%d로 출력하기: -1|%d로 출력하기: -1|
|%u로 출력하기: 4294967295|%u로 출력하기: 4294967295|

* 이를 통해서 signed integer 변수에 저장하거나 unsigned integer 변수에 같은 값을 저장해도 %d, %u에 따라 출력된다는 것을 알 수 있다.

**unsigned 와 signed 는 bitwise 똑같은 데이터이고, bit 상태가 구분되지 않는 똑같은 데이터임을 알 수 있다.**

**다만 print할 때 %d로 print하면 signed int로, %u로 print하면 unsiged int로 출력된다.**

**Q**) 어떤 숫자에 unsigned integer 값을 더하면 그 값은 절대로 증가한다? [ X ]
> 오버플로우가 일어난다면 증가하지 않는다!  

### `vi editor`  

* yy + p : 복사 & 붙여넣기

* 6yy + p : 6줄 복사 후 붙여넣기

* dd : 한줄 삭제

* dd + p : 삭제 한 줄 붙여넣기

//1시간 8분부터

***

## Lecture 6
##### - 2022. 01. 12   

***


## Lecture 7
##### - 2022. 01. 13  

***