# 실전코딩 2 실습 리포트

### `sshid` : pcc001
### `name` : 곽수정 ✨
### `id` : 201921085

***

## Contents  

1. [ Lecture 1 ](#lecture-1)
2. [ Lecture 2 ](#lecture-2)
3. [ Lecture 3 ](#lecture-3)
4. [ Lecture 4 ](#lecture-4)
5. [ Lecture 5 ](#lecture-5)
6. [ Lecture 6 ](#lecture-6)
7. [ Lecture 7 ](#lecture-7)
8. [ Lecture 8 ](#lecture-8)
9. [ Lecture 9 ](#lecture-9)
10. [ Lecture 10 ](#lecture-10)

***

## Lecture 1  

##### - 2022. 01. 04   

* git을 사용하기 위한 프로그램 설치

* Basic Linux Command

### `ls`

현재 디렉토리에 어떤 파일이 있는지 list를 보여주는 명령어  

```bash
$ ls -l                   # 파일의 상세 정보 표시
$ ls -a                   # 숨어있는 파일들도 표시
$ ls -al pcc001           # pcc001 디렉토리의 모든 파일 표시
```

### `pwd`  

print working directory : 현재 디렉토리 보여줌  

### `hostname`  
내가 지금 어떤 컴퓨터를 쓰는지 알고싶다면 사용  

```bash
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

```bash
$ mkdir pcc         # pcc 디렉토리 생성, 이미 디렉토리가 존재한다면 에러 발생
```  

### `cd`  
change directory  
디렉토리를 이동하는 명령어

```bash
$ cd                # cd 뒤에 디렉토리 입력 안하면 home directory로 이동
$ cd ~              # home directory로 이동, 위 명령어와 동일
$ cd ..             # 윗 디렉토리로 이동
$ cd lec01          # lec01 디렉토리로 이동
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

```bash
$ mv a.out hello.c pcc            # a.out와 hello.c 파일을 pcc 디렉토리로 이동시킴  
$ mv hello.c hola.c               # hello.c 파일의 이름을 hola.c 로 변경 가능
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

```bash
$ whoami
pcc001
```

### `cat`  
어떤 파일의 내용을 보는 명령어

```c
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

```bash
$ ssh pcc001@git.ajou.ac.kr
```

### `ps`  
내가 실행하는 process 보고 싶을 때 사용하는 명령어  

```bash
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

```bash
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

```bash
crw--w----  1  hwan  tty  136,  8  1월  5  14:19  8
```  

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

```bash
$ man cat       # cat 명령어의 메뉴얼을 보여준다.
```  

```bash
$ man cp        # cp 명령어의 메뉴얼을 보여준다.
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

```bash
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
```c
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

```c
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

```c
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

```bash
$ sleep 600             # 600초, 10분 동안 sleep
```  

### `cat`  
파일(들)을 순서대로 읽고 그 내용을 읽은 순서대로 표준 출력에 쓰는 명령  

```bash
$ cat  
aaa                     # 입력
aaa                     # 출력
bbb                     # 입력
bbb                     # 출력
```
작업 끝내고 싶다면 **ctrl + d** 누르기  

### `vi 에디터로 편집 중에 ctrl + z 누른 경우`  
process를 잠시 suspend 시킴 (보류)  

```bash
$ vi hello.c            # 편집 중에 ctrl + z 누른 뒤...
[1]+    Stopped         vi hello.c  

$ps
  PID  TTY          TIME CMD
20145  pts/11    0:00:00 bash
23919  pts/11    0:00:00 vi
27662  pts/11    0:00:00 ps

$ jobs
[1]+    Stopped         vi hello.c 
```  

### `Stopped 시킨 job으로 돌아가기`  
**fg** = background 작업을 foreground로 옮기기
```bash
$ fg %1             # 1번 작업인 vi 에디터로 다시 돌아감  
```

### `(sleep 1000 ; echo "pcc001 - 1000sec") &`  
* 프로그램 실행 시에 끝에 &를 붙여 백그라운드로 실행시킬 수 있다.  
* jobs 명령을 통해 현재 백그라운드에서 동작하고 있는 프로그램의 확인이 가능하다.  
* 백그라운드 프로그램을 죽이고 싶다면 **kill -9 %번호**

```bash
$ sleep 1000 ; echo "pcc001 - 1000sec" &            # 앞 작업이 끝나야 뒤 작업 실행되므로 제대로 작동하지 않음
$ (sleep 1000 ; echo "pcc001 - 1000sec") &          # 묶어주면 background 작업으로 작동함
```

### `cat a.out`  
* a.out는 우리가 읽을 수  있는 텍스트 파일이 아니고 binary 파일이다.  
따라서 cat a.out 실행시 읽을 수 없는 내용이 보여진다.  
* hello.c는 C source, ASCII text 파일이므로 cat hello.c 명령어 실행시 파일 내용을 보여준다.  

### `cat`  
* concatenate files and print on the standard output  
* 파일을 합쳐서 statndard output으로 보여주는 명령어  
* ctrl + d 누르면 cat 프로그램 종료, (EOF)

```bash
$ cat
aaa                 # 파일이 없다면 statndard input을 입력으로 받아서
aaa                 # standard output에 출력한다.  
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

```bash
$ date > date.txt           # stdout이 date.txt 파일로 리디렉션됨.  
$ cat date.txt
2022. 01. 05 (수) 16:02:23 KST  

$ cat date.txt hello.c output.txt > total.txt            
# 파일 3개가 total.txt로 concatenate됨.
$ cat hello.c hello.c hello.c > hello3                   
# hello.c 3개가 hello3에 합쳐짐  

$ cat < hello3                                             
# input으로 hello.c를 받아서 stdout에 출력함.
$ cat hello3                                               
# cat < hello3와 동일  

$ cat < hello3 > hello4
$ diff hello3 hello4        # 두 파일은 동일한 파일이다.  

$ cat hello.c hello.cpp 1>out.txt 2>err.txt 
# hello.c 내용을 받아 stdout이 out.txt에 저장됨. hello.cpp 파일이 없어 발생한 에러 메세지는 err.txt에 저장된다.  
```  

### `stdin, stdout, stderr redirection`  
in.txt 파일에는 학번(201921085)이 저장되어있고 아래 코드는 hello.c 파일이다.

```c
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}
```

```bash
./a.out < in.txt > out.txt 2>err.txt
```

위 명령어 실행시 out.txt에는 Hello stdout 201921085가, err.txt에는 Hello stderr 201921085가 저장된다.  
`>>` 는 계속 내용이 누적되도록 할 수 있다.  

***

## Lecture 3  

##### - 2022. 01. 06 [ Advanced C 언어 (2) 현장의 코딩 규칙 ]  

### `linux command`

교수님의 코드를 카피하였더니 프롬프트가 초록색으로 변경되었다. (색 지정 O)  

```bash
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

```bash
$ which ls
/bin/ls
```  

### `PATH`  

```bash
$ vi ls             # ls에는 ls -lida 저장함
$ chmod +x ls
$ ./ls              # 직접 작성한 ./ls 실행됨
$ ls                # /bin/ls의 ls가 실행됨
```  

* 시스템 안에 존재하는 ls 중 무엇을 실행시킬지 순서를 정해야함: 환경변수 **PATH**  

```bash
$ echo $PATH
/home/course/pcc039/bin:/home/course/pcc039/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:.
```  

* source .profile을 통해 마지막줄 PATH="$HOME/bin:$HOME/.local/bin:$PATH:."이 실행되어 path가 추가되었다.

* 따라서 lec02에 있는 a.out를 ./a.out으로 실행했어야 했는데 path를 추가한 뒤에는 a.out으로 실행시킬 수 있다.  

```bash
$ which a.out
./a.out                         # 현재 디렉토리 밑에 있는 a.out이 실행된다.
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
    <img src=./img/echo.png width="50%" >  
</div>  

### `gitignore`  

* git.ajou.ac.kr에서 내 폴더로 들어간 뒤 new file을 추가함  
* template type을 .gitignore로 선택한 뒤, binary 파일을 git 서버에 백업하지 않도록 아래와 같이 작성하고 commit 하였다.

```bash
*.out
```  

### `clone`  
* clone with https를 눌러 링크를 복사한 뒤 ssh 서버의 pcc 디렉토리에 git clone https://git.ajou.ac.kr/kwaksj329/pcc001.git 으로 clone 하였다.  

* pcc001 디렉토리 안에는 .git과 .gitignore 와 같은 hidden file과 README.md가 있다.  

* . 으로 시작하는 파일은 hidden 파일이다.  

```bash
$ file * .*             # 모든 파일과 hidden 파일
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

```bash
$ mv pcc001/* .                 # pcc 디렉토리에 hidden 파일은 안옮
$ mv .git .gitignore ..         # pcc 디렉토리로 옮김
```  

### `ssh & https`  

* git-scm 설치
* git-bash 실행시 가상의 터미널이 열림 -> 터미널이 열리자마자 bash가 실행됨
* ssh 프로그램 실행시켜 git.ajou.ac.kr 접속함 => 터미널로 들어온 것은 `ssh` 서비스라고 함  
* 웹브라우저로 git.ajou.ac.kr로 접속함 => `https` 서비스로 접속함

### `pipe`  
어떤 출력을 다음에 오는 명령어의 입력으로 넣는 명령어  

```bash
$ ps -ael | grep ssh            # ps -ael의 출력 중 ssh를 찾는 명령어
$ who | wc                      # who 결과의 라인수, 단어수, 글자수 세어줌

$ wc
aaa bbbb cccc
1   3   15                      # 1글자, 3단어, 15글자 (글자 + 줄바꿈까지)

$ grep aaa                      # 파일 없이 standard input을 받아 해당 string이 나타나면 표시해줌  
$ grep printf hello.c | wc      # hello.c 파일의 printf 찾아 라인수, 단어수, 글자수 세어줌
```  

**Q**) 파이프는 어디에 있을까?  
> buffer, output buffer를 input buffer에 symbolic link 시켜둠  
파이프는 메모리에 버퍼 형태로 존재하며 파이프도 디바이스기 때문에 /dev/에 디파이스 파일로 만들 수 있다.  

* 파이프를 자료구조로 생각하면 queue이다. (FIFO)
* 따라서 파이프 만드는 명령어 `mkfifo mypipe`  
* 파이프는 파일의 속성이 **p**이다!  

```bash
$ mkfifo mypipe
```

### `tee`  
stdin을 받아서 stdout과 하나 이상의 파일에 그 입력을 출력하는 명령어

<div style="text-align : center;">
    <img src=./img/tee.png width="70%" >  
</div>  

```bash
$ echo testing | tee test.txt
test
$ cat test.txt
test

$ ls -l | tee aaa           # ls -l의 결과가 stdout에도 출력되고 aaa에도 저장된다. 
```  

### `git 서버에 올리는 방법`  

```bash
$ git pull                  # 혹시 서버에서 update 한게 있다면 가져와 merge 함
$ git add *
$ git commit -m "Added something"
$ git push
```  

* git commit만 치면 nano editor가 실행된다.  
* vi ~/.gitconfig 파일에 아래 코드를 추가하면 nano 에디터가 아닌 vi 에디터가 실행된다.  
    * git commit 실행 후 파일에 commit message 적어서 저장해주면 commit message가 설정된다.  

```bash
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

```bash
$ echo hello > /tmp/out
$ > /tmp/out echo hello             
$ echo > /tmp/out hello                 # 순서 바꿔도 상관 없음
$ echo hello >&2
$ echo >&2 hello                        # stdout을 stderr로 내보냄
$ read -r line < file            
$ < file read -r line
```  

```bash
$ mycomm > outfile 2>&1 을 줄여서 mycomm &> outfile
$ mycomm >> outfile 2>&1 을 줄여서 mycomm &>> outfile
$ mycomm1 2>&1 | mycomm2 을 줄여서 mycomm1 |& mycomm2
```  

```bash
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

```bash
$ cat <<EOF         # EOF 라고 타이핑하기 전까지는 계속 입력을 받으세요.
"200"
EOF                 # 입력 끝냄
"200"
```  

```bash
$ cat <<QQQ
> 200
> Hi
> Print
> QQQ               # 입력 끝냄
200
Hi
Print
```

* `here string`
* `<<<`  : string을 stdin 입력으로 연결 (bash only)

```bash
$ cat <<< $( echo -e "hello\nhere        string" )          
# $ == 명령어 실행한 결과
hello
here        string

$ cat <<< *               # globbing 이 발생하지 않는다.
*
```

```c
//hello.c 파일
#include <stdio.h>  

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}

```

```bash
$ cc hello.c            # hello.c 컴파일하여 a.out 실행파일 생성됨.
$ a.out <<< 99          # here string, bash에서만 가능!
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

```bash
$ echo h*           # h로 시작하는 파일 보여줌
hello.c
$ echo *.c
hello.c
$ echo ?????        # 5글자 파일 보여줌
a.out
$ echo ?????*       # 5글자 넘는 파일 보여줌
$ echo [abc]*       # a/b/c로 시작하는 파일 보여줌
$ echo [a-q]*       # a~q로 시작하는 파일 보여줌
```  

### `b.out | a.out`  

```c
//hello.c               # a.out 실행파일
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}
```

```bash
$ vi hello2.c               # input을 받아 stdout으로 숫자 내보내는 코드 작성
$ cc -o b.out hello2.c
$ b.out | a.out             # b.out의 출력이 a.out의 입력으로 들어가 실행됨
999
Hello stdout 999
Hello stderr 999
```

### `named pipe`  

```bash
# 첫번째 터미널에서..
$ mkfifo pipe
$ b.out > pipe
99

# 동시에 두번째 터미널에서..
$ ./a.out < pipe        # pipe에 담긴 99 읽어와서 실행 + 출력
Hello stdout 99
Hello stderr 99
```  

_pipe: a.out라는 프로그램과 b.out라는 프로그램, 두 프로그램 사이에서 통신하는데 사용 가능_   

**대표적으로 두개의 process 간의 통신하는 방식: pipe**  

### `vi pipe`

```bash
$ vi pipe           # vi 에디터로 pipe 열어서 12345 저장함
$ cat < pipe        # pipe에 저장한 것 보여줌..!
12345
```

신기하다..! 😎

### `basic data type`  

```c
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

### `(터미널에서) python 사용`  

```bash
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

```c
//binary.c
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
```
```bash
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

```bash
$ bin(3)
'0b11'
$ bin(-3)
'-0b11'
```

* 우리가 위에서 짠 bin 프로그램에서는..

```bash
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

```c
// binary.c
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
```

```bash
$ cc -o bin binary.c
$ bin
100 -100                # 100과 -100의 & operation
0000 0000 0000 0000 0000 0000 0110 0100
1111 1111 1111 1111 1111 1111 1001 1100
0000 0000 0000 0000 0000 0000 0000 0100
```

### `in_c = in_a >> 2 수정 (오른쪽으로 shift)`  

* 위 코드에서 in_c = in_a & in_b를 in_c = in_a >> 2로 수정해보았다.

```bash
$ bin
-456 456
1111 1111 1111 1111 1111 1110 0011 1000
0000 0000 0000 0000 0000 0001 1100 1000
1111 1111 1111 1111 1111 1111 1000 1110
```

* 그리고 a, b, c를 unsigned int로 바꿔서 실행해본 결과이다.

```bash
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

```c
//binary.c
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

```c
//hello.c
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
```

```bash
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

### `signed / unsigned & int / short`  

```c
// hello.c
// siA와 sumS는 signed int 형
// unA와 sumU는 unsigned int 형으로 선언함
// shortS는 signed short, ushortS는 unsigned short로 선언
// 이전코드에서 siA를 입력받아 unA에 넣어준 상황

sumS = siA + (signed int) unA;
sumU = (unsigned int) siA + unA;
fprintf(stdout, "sumS %%d %d\n", sumS);
fprintf(stdout, "sumS %%u %u\n", sumS);
fprintf(stdout, "sumU %%d %d\n", sumU);
fprintf(stdout, "sumU %%u %u\n", sumU);

shortS = siA + unA;
ushortS = siA + unA;
fprintf(stdout, "sumS %%d %d\n", shortS);
fprintf(stdout, "sumS %%u %u\n", shortS);
fprintf(stdout, "sumU %%d %d\n", ushortS);
fprintf(stdout, "sumU %%u %u\n", ushortS);
```

```bash
$ cc hello.c
$ ./a.out
-1
sumS %d -2
sumS %u 4294967294
sumU %d -2
sumU %u 4294967294
sumS %d -2
sumS %u 4294967294
sumU %d 65534
sumU %u 65534
```

**Q**) 왜 실행한 결과의 마지막 2줄은 다르게 나왔을까?
> signed int와 unsigned int를 더하여 unsigned short 형 변수에 저장하였으므로 자동으로 type casting이 일어났기 때문이다.

**C언어에서는 연산시에 자동으로 type casting이 일어난다.**  

```c
shortS = siA + unA;
ushortS = siA + unA;
fprintf(stdout, "sumS %%d %d\n", shortS);
fprintf(stdout, "sumS %%u %u\n", shortS);
fprintf(stdout, "sumU %%d %d\n", ushortS);
fprintf(stdout, "sumU %%u %u\n", ushortS);

shortS = (short)siA + (short)unA;
ushortS = (unsigned short)siA + (unsigned short)unA;
fprintf(stdout, "sumS %%d %d\n", shortS);
fprintf(stdout, "sumS %%u %u\n", shortS);
fprintf(stdout, "sumU %%d %d\n", ushortS);
fprintf(stdout, "sumU %%u %u\n", ushortS);
```

**따라서 위 코드에서 type casting이 자동으로 일어나 같은 결과가 출력된다.**

`cc -W hello.c`  
컴파일 시 모든 것에 대해 warning을 출력하고 싶을 때 사용한다.

### `count1.c - 32bit integer에서 1의 개수 세는 프로그램`  

```c
//count1.c
#include <stdio.h>
#define VALUE_ONE 1

//count number of 1 (binary)
int count_one(unsigned int a){

    int count = 0;

    while(a != 0){
        count += a & VALUE_ONE;
        a >>= VALUE_ONE;
    }

    return count;
}

int main()
{
    int i;
    int in_a;
    fscanf(stdin, "%u", &in_a);
    fprintf(stdout, "%u \t : ", in_a);
    for(i = 31 ; i >= 0 ; i--){

        fprintf(stdout, "%d", ((in_a >>i ) &1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, ": %d \n", count_one(in_a));

}
```

* 위의 코드 설명 - 어떻게 1의 개수를 count할까?  

a가 10진수로 6이라면 2진수로 0000 0000 0000 0000 0000 0000 0000 0110이다.

|  shift 횟수  |   a   |
|:------:|:------:|
|0번째|0000 0000 0000 0000 0000 0000 0000 0110|
|1번째|0000 0000 0000 0000 0000 0000 0000 0011|
|2번째|0000 0000 0000 0000 0000 0000 0000 0001|
|3번째|0000 0000 0000 0000 0000 0000 0000 0000|

따라서 1 (VALUE_ONE)과 a의 맨 마지막 bit 가 & 연산을 하여 1의 개수를 계산하기 때문에,  

1번째 shift 결과와 2번째 shift 결과에서 & 연산을 통해 count에 1이 더해지게 된다.  

따라서 6의 1의 개수는 2개임을 구할 수 있다.  


### `if문의 성능`  

```c
// sol1
if((in_a >> i) & 1)
    count++;

// sol2
count += in_a >> i & 1; 
```

* C operator precedence에 따라 shift를 먼저 하고 & operation을 하기 때문에 위 & 아래 코드의 연산은 같다.  

* 대신 우선순위가 헷갈리기 때문에 괄호를 사용하는 것을 추천한다.

* sol1과 sol2의 실행결과는 같은데 실행속도는 sol2가 빠르다.  
    * if문은 굉장히 느리다. if문은 굉장히 비싼 operation이다.  

```c
c = a >> 1 + b;          //case 1
c = (a >> 1) + b;        //case 2
c = a >> (1 + b);        //case 3
```

* shift 연산이 곱하기 / 나누기와 우선순위가 같다고 오해할 수 있다. 하지만 shift 연산은 더하기와 빼기보다 우선순위가 낮다.

* case 1의 결과는 case 2가 아닌 case 3과 같다!

* 따라서 case case 1처럼 코드를 작성하고 a의 shift가 먼저 일어날 것이라고 오해할 수 있으므로, 헷갈리지 않도록 괄호를 사용하는 것을 권장한다.

### `Three basic memory model in C`  

* signed / unsigned 는 int와 같은 자료형의 앞에 붙는다.  

* 나머지 수식은 자료형의 뒤에 붙는다. (ex - const, auto, static)  
    * ex- int const

* `Automatic` : automatic 변수는 현재 블록이 끝나면 자동으로 사라지는 변수이다.  
    * int 이렇게 선언하면 automatic이다.  
    * 처음 사용할 때 변수를 선언한다.
    * 범위를 벗어날 때 제거된다.  

* `Static` : static 변수는 선언된 함수 내에서만 사용이 가능하며, 단 한번만 초기화를 하고 프로그램이 종료될 때까지 메모리 공간에 존재하는 변수이다.  
    * 프로그램이 실행되는 동안 같은 공간에 존재한다.  
    * Array sizes는 고정되지만 values는 변경 가능하다.  
    * main 시작전에 데이터가 초기화된다. 따라서 계산을 필요로 하지 않는 상수를 사용하여 초기화해야 한다.  
    * static 키워드로 함수 밖에서 선언된 variables (in file scope)와 함수 안에서 선언된 variables는 static이다.  
    * static variable을 초기화 하지 않으면, zeros (or NULL)로 초기화된다.  

* `Manual`  
    * manual type에는 malloc과 free가 포함된다.  
    * manual type만 array의 크기가 선언 이후에도 조정할 수 있다.  

### `Noun-Adjective Form`  

* `int const A` constant integer  
    * const가 뒤에서 앞으로 int를 수식함

* `int const * A ` (variable) pointer to a constant integer 
    * const가 int를 수삭한다. A는 const int를 가리키는 포인터이다.

* `int * const A` constant pointer to a (variable) integer 
    * int를 가리키고 있는 포인터인데 그 포인터가 const이다.

* `int * const * A` pointer to a constant pointer to an integer  
    * int를 가리키는 const 포인터를 가리키는 포인터, 이 포인터 값은 변할 수 있다.

* `int const * * A` pointer to a pointer to a constant integer  
    * const int를 가리키는 포인터의 포인터, 두 포인터 다 변경될 수 있다.

* `int const * const * A` pointer to a constant pointer to a constant integer 
    * const int를 가리키는 const 포인터의 포인터

**Q**) `double (*f[10])(int const *a, double (*g[10])(double h));`의 의미는?  

* 함수 이름이 f인 함수를 선언하였으며 이 함수는 double을 리턴한다.  

* 함수 f는 크기가 10인 포인터의 array이며 첫번째 parameter는 int const 형태의 포인터 a이다.  

* 두번째 parameter는 함수 이름이 g이고 크기가 10인 포인터의 array이다.

* g 함수는 double을 리턴하며, double을 리턴하는 상수 h를 parameter로 가진다.  

### `static 변수 예시`  

```c
//count1.c
#include <stdio.h>
#define VALUE_ONE 1

//count number of 1 (binary)
int count_one(unsigned int a){

    int static numCalls = 0;
    int count = 0;

    while(a != 0){
        count += a & VALUE_ONE;
        a >>= VALUE_ONE;
    }

    fprintf(stderr, "Call : %d\n", numCalls);
    numCalls++;

    return count;
}

int main()
{
    int i;
    int in_a;
    fscanf(stdin, "%u", &in_a);
    fprintf(stdout, "%u \t : ", in_a);
    for(i = 31 ; i >= 0 ; i--){

        fprintf(stdout, "%d", ((in_a >>i ) &1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    count_one(in_a);
    count_one(in_a);
    count_one(in_a);
    count_one(in_a);
    fprintf(stdout, ": %d \n", count_one(in_a));

}
```  

* count_one 함수의 parameter로 signed int를 받게 되면 무한루프에 빠질 수 있다.  
    * a가 signed int형 변수이고, 음수 데이터가 저장되어 있을 때, 오른쪽으로 shift를 계속해도 0이 되지 않고 계속 1이 채워지기 때문에 while문에서 무한루프에 빠지게 된다.  
    * a가 unsigned int 형이면 오른쪽으로 shift할 때 맨 왼쪽에 0이 채워지게 되고, 그럼 while문 안에서 shift가 반복해서 일어나면 언젠가 a가 꼭 0이 된다.
    * 따라서 입력이 음수일 때 무한루프에 빠지지 않기 위해서 count_one 함수의 parameter를 unsigned int a라고 선언해야한다.

* count_one을 4번 호출한 결과로 아래와 같이 출력된다.  

```
Call: 0
Call: 1
Call: 2
Call: 3
Call: 4
```

* numCalls 변수가 int 형 변수라면 모두 0이 나왔겠지만, int static 변수이기 때문에 0, 1, 2, 3, 4가 출력되었다.  

* numCalls 변수가 static 변수이기 때문에 한번만 초기화하고, 프로그램이 종료될 때까지 메모리 공간에 계속 존재하기 때문에 0으로 초기화되지 않고 값을 누적해서 출력한 것을 볼 수 있다.

* static 변수는 초기화하지 않으면 자동으로 0 (또는 NULL)으로 초기화 되지만 automatic 변수는 초기화하지 않고 값을 출력해보면 랜덤한 값이 출력된다.  

### `define`  

* preprocessor는 반복되는 값이나 작업을 미리 정의할 때 사용하며, preprocessor에서 #define으로 매크로를 정의할 수 있다.  

* #define 매크로이름 값 : 이렇게 매크로를 정의할 수 있다.  

* 이러한 매크로를 사용하면 preprocessor를 거쳐 내부적으로 소스 코드가 일괄 변환되게 된다.

### `const`  

* const 변수는 값을 변경할 수 없다. 변수가 상수임을 선언하는 예약어이다.

* 상수는 반드시 선언과 동시에 값을 할당하여 초기화해주어야 하며 초기화를 하지 않으면 컴파일 에러가 발생한다.

```c
int const con = 100;
con++;
```

* const 변수로 선언된 값은 변경이 불가능하므로 컴파일 time에 에러가 난다! ( increment of read-only variable 'con' )

***

## Lecture 6
##### - 2022. 01. 12   

### `.bash_logout`  

```bash
if [ "$SHLVL" = 1 ]; then
    [ -x /usr/bin/clear_console ] && /usr/bin/clear_console -q
fi
clear
clear
echo HAVE a NICE DAY - I am Sujong Kwak
```  

logout 시에 clear 명령으로 터미널 명령을 지우고, echo로 원하는 문장을 출력하도록 하였다.  

### `alias`  

alias = bash에 들어있는 built in 명령이다.  

```bash
$ alias -p
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
alias cc='cc -Wall'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'
alias grep='grep --color=auto'
alias h='history'
alias l='ls -CF'
alias la='ls -A'
alias ll='ls -alF'
alias ls='ls --color=auto'
```

* alias cc='cc -Wall' 을 통해 cc 명령어 실행시 자동으로 cc -Wall 명령으로 바뀌도록 할 수 있다.  

* alias를 풀고 싶다면 unalias cc 사용  

* 만약 alias를 사용하고 싶지 않다면 back slash('\')를 사용한다.  

```bash
$ ls            # alias 사용
$ \ls           # alias 사용 X
```

* 로그아웃하면 없어지기 때문에 ~/.bashrc 에 alias 를 추가해야한다.  

* source ~/.bashrc 로 실행하면 적용된다.

### `오늘의 목표 - Pointer 이해하기`  

* pointer basic
    * &val - Address of val
    * *ptr - Value in address val

* increment
    * int *a;       //a++ increment by 4
        * a = integer를 가리키는 주소
    * long long *b; //b++ increment by 8
        * b = long long을 가리키는 주소
    * void *c;      //c++ increment by 1

### `&& 와 ;`

```bash
$ cc hello.c && a.out       #1
$ cc hello.c ; a.out        #2
```

첫번째 명령은 hello.c가 에러가 나지 않을 때만 a.out가 실행되는 반면에,  
두번째 명령은 hello.c가 에러나도 a.out가 항상 실행된다.  

* 앞이 오류나지 않았을 때만 뒤 명령어 실행하고 싶다면 -> 명령어1 && 명령어2  

* 앞이 오류났을 때 뒤 명령어를 실행하고 싶다면 -> 명령어1 || 명령어2  

### `hello.c - a와 b의 주소`  

```c
#include <stdio.h>

int main()
{
    int a = 100;
    int b = 200;
    fprintf(stdout, "%d : %d\n", a, &a);    // 100 : 1893560592
    fprintf(stdout, "%d : %d\n", b, &b);    // 200 : 1893560596
}
```

* a의 주소에서 int형 변수의 크기인 4바이트 떨어진 곳에 b가 위치한 것을 알 수 있다.  

* int * -> long long -> lld로 출력하기! 16진수로 보고싶다면 llx로 출력한다.  

* a와 *&a는 같다. *&a에 값을 넣을수도 있다. ( *&a = 500; )

**Q**) 어떤 사람은 주소 결과가 음수로 나왔는데 왜일까?
> 메모리 주소 길이가 오버플로우 났기 때문이다.  
우리가 쓰고 있는 컴퓨터에서 int * 은 long long과 크기가 같다.

**Q**) 8bit / 16bit / 32bit / 64bit 컴퓨터의 의미??
> 한번에 처리 가능한 데이터의 크기, address line의 크기  
한번의 hardware operation으로 처리할 수 있는 데이터의 길이  
(대부분) 64bit 컴퓨터라면 데이터의 주소도 64bit length이다.  

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int a = 100;
    int b = 200;
    int c;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    c = add(a, b);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
```

* 실행결과로 a, b, c의 주소가 4바이트씩 차이 나는 것을 볼 수 있다.  

### `call by reference`  

```c
#include <stdio.h>

int add(int *a, int *b)
{
    return *a + *b;
}

int main()
{
    int a = 100;
    int b = 200;
    int c;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    c = add(&a, &b);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
```

* call by reference도 실행결과 동일하게 잘 실행된다!  

```c
//a, b, c는 주소가 4바이트씩 차이난다.  
int a = 100;
int b = 200;
int c = 999;
```

**Q**) 이때 `*(a + 4)`는 값이 b의 값인 200일까? [ **X** ]  

**Q**) 이때 `*(a + 8)`는 값이 c의 값인 999일까? [ **X** ]  

**Q**) 이때 `*(a + 1)`는 값이 b의 값인 200일까? [ **O** ]  

**Q**) 이때 `*(a + 2)`는 값이 c의 값인 999일까? [ **O** ]  

* a가 int 형이기 때문에 +1을 하게 되면 4바이트가 더해진다.  
따라서 +1을 하면 4바이트 더해진 주소에 위치한 b값에 접근한다.  
그리고 +2를 하면 8바이트 더해진 주소에 위치한 c값에 접근하게 된다.  

```c
#include <stdio.h>

void add(int *a, int *b, int *c)
{
    *c = *a + *b;
}

int main()
{
    const int a = 100;
    int b = 200;
    const int c = 999;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    add(&a, &b, &c);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
```  

* c가 const int 형임에도 불구하고 값에 바뀔 수 있다.  
    * c의 포인터를 통해 값을 변경할 수 있다.  

```c
#include <stdio.h>

void add(int *a, int *b, int *c)
{
    *c = *a + *b;
}

int main()
{
    const int a = 100;
    int b = 200;
    long long c = 999;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    add(&a, &b, &c);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
    fprintf(stdout, "%d : %lld %llx\n", c, (&c)+1, &c+1);
    //fprintf(stdout, "%d : %lld %llx\n", c, ((void *)(&c))+1, &c+1);
    //원래는 long long 포인터인데 void 포인터로 바껴서 1씩 증가됨 (char 포인터도 1씩 증가)
    fprintf(stdout, "%d : %lld %llx\n", c, (&c)+2, &c+2);
}
```

* 어떤 주소에 1을 더하는 것은 그 데이터 타입의 값(크기)를 더한다!  

* (&c) + 1 이나 (&c) + 2 의 경우에도 주소가 어떤 데이터의 주소인지 물어보게 된다.  
따라서 주소에 + 1 이나 주소에 + 2 되지 않는다.  
c가 long long 형이므로 주소에 + 8바이트, 주소에 + 16바이트가 더해진 결과를 얻을 수 있다.  

* 정말로 주소에 딱 1만 더하고 싶다면 ((void *)(&c))+1 를 사용해야 한다.  
    * 그럼 c가 long long의 포인터였다가 void 포인터로 바뀌게 되어 1씩 증가된다.  
    * void와 char 포인터는 1씩 증가하기 때문이다.  

* const는 automatic과 비슷하지만 다른 점은 이 값을 change하려 하면 컴파일러가 에러를 발생시킨다.  

<div style="text-align : center;">
    <img src=./img/three_model.png width="45%" >  
</div>  

### `int an_array[] vs int *a_pointer`  

* int an_array[32];
    * Program will do;
    * set aside a space on the stack big enough for 32 integers, 
    * declare that an_array is a pointer, and  
    * bind that pointer to point to the newly allocated space  
    * an_array라고 하는 포인터를 만든다!!
    * an_array는 배열의 시작 부분을 가리키고 있다.
    * an_array 값이 저장되는 공간은 8바이트이다. 포인터이기 때문에!

* int *a_pointer;
    * Just pointer
    * a_pointer = malloc(32*4);
    * 포인터에게 어떤 값을 주기 전까지는 제대로 된 값을 갖고있는지 아닌지 알 수 없다.  

### `array & pointer`  

```c
//sumarr.c
#include <stdio.h>

int sumArray3(int *a, int sum)
{   
    sum = *a;
    a++;
    sum += *a;
    a++;
    sum += *a;
    fprintf(stdout, "%d : %lld %llx\n", sum, &sum, &sum);
    return a[3];
}
int main()
{
    int a = 100;
    int b = 200;
    int c = 999;
    const int arr[4] = {100, 200, 300, 400};
    int *parr;
    parr = arr;
    parr++;
    fprintf(stdout, "%d : %lld %lld\n", *parr, parr, arr);
    c = sumArray3(arr, b);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    fprintf(stdout, "%d : %lld %llx\n", arr, arr, arr);
    fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
    fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
    fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
    fprintf(stdout, "%d : %lld %llx\n", arr[3], &arr[3], &arr[3]);
}
```

* arr = integer가 아닌 long long이다.  

* *arr = a[0]이다.  

* arr = &arr = 배열의 시작 부분 주소이다.

* arr[0], arr[1], arr[2], arr[3]은 4바이트씩 떨어져있다.

* arr를 4개짜리로 선언했지만 arr[4]를 print해보면 arr[3]에서 4바이트 떨어진 주소가 출력된다.
    * arr 길이가 4인데 5번째를 access 할 수 있다는 것이 이상하다..!
    * 에러가 나는 것이 정상인데 나지 않는다.

* call by reference - 주소에 대한 데이터 변경하면 주소에 있는 값 변경된다.

* call by value - value 값이 함수에서 아무리 바꾸려해도 바뀌지 않는다.  

* Segmentation fault ( core dumped ) - memory protection
    * a.out 를 실행할 때 주어진 공간을 벗어나서 접근했 때 발생한다.  
    * segmentation violation
    * core dumped - core라고 하는 파일에 프로그램의 snapshot이 만들어짐

```c
sum = a[0];         // a[0] = sum = 100
sum += *(a+1);      // *(a+1) = a[1] = 200
sum += *(a+2);      // *(a+2) = a[3] = 300

sum = *a;           // *a = sum = 100
a++;                // a++ = a는 a[1]의 주소가 됨
sum += *a;          // *a = sum = 200
a++;                // a++ = a는 a[2]의 주소가 됨
sum += *a;          // *a = sum = 300
```

* *a + 1; 이나 *a + 2는 *a인 100에 1과 2를 더한 것이므로 101과 102이다.  
    * value operater는 더하기보다 우선순위가 더 낮다.

* 반면 *(a+1)는 a가 int형 포인터이므로 +1이 4바이트로 더해져 a[1]의 값인 200이 된다.  

* 그리고 *(a+2)도 a가 int형 포인터이므로 +2이 8바이트로 더해져 a[2]의 값인 300이 된다.  

* a 변수를 increment / decrement 할 수 있으므로 a의 저장공간이 있다는 것을 알 수 있다.

```c
int *parr;
parr = arr;
parr++;
```

* *parr = 200이 출력됨!

* parr에 int 형 배열의 주소를 담고 있는 arr이 저장되었기 때문에 parr++ 하면 arr[1]의 위치를 가리키게 된다. 따라서 *parr은 200이다.

***

## Lecture 7
##### - 2022. 01. 13  

### `Noun-Adgective Form - 중요한 차이점!`  

* `int const * A` : int가 상수 정수이며 이를 가리키는 포인터
    * int 상수값은 변경될 수 없다. 대신 이를 가리키는 포인터는 변경될 수 있다.

* `int * const A` : 이 포인터는 상수 포인터인데 변수는 int를 가리키고 있다.
    * int 값은 변경될 수 있다! 주소는 변경 불가능

### `함수의 포인터 연습`  

```c
void mul(int *a, int *b, int *c)
{ *c = *a + *b;}

int main()
{
    int const a = 100;
    int b = 200;
    int c = 9999;
    int *p = &a;
    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
    *p = 200;
    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
```

* 만약 a에 다른 값을 그대로 넣으면 에러가 발생한다.
    * assignment of read-only variable 'a'

* 그런데 위 코드처럼 a의 주소를 p에 넣고, p가 가리키는 a의 주소에 들어있는 값을 변경하면 a의 값이 변하게 된다.  

* const로 선언한 것이 주소를 통해서 값이 바뀐다면 어떤 의미가 있을까?
    * error / warning이 나오게 하려는 의미가 있다! (위 코드에서 warning 발생 O)

```c
int * const p = &a;         // case 1
p = &b;

int const * p = &a;         // case 2
p = &b;
```

1. 포인터가 const인데 b의 주소로 바뀌었으니 에러가 발생한다!  

2. int 상수 값은 변하면 안되지만 이를 가리키는 포인터는 변해도 된다.
    * 따라서 2번째 경우에는 에러가 발생하지 않는다!

```c
void *fp();         // 함수의 포인터
fp = mul;           // 에러 발생
fp(a, b, c)

void (*fp)();
fp = mul
fp(&a, &b, &c);
```

* fp가 가리키는 함수 mul은 parameter 3가지 모두 포인터로 받고 있기 때문에 fp를 호출할 때에도 a, b, c의 주소값을 넘겨줘야한다.  

* mul 과 mul()의 차이점
    * 선언문에 mul()은 함수를 선언한 것이다.  
    * 실행문에 mul()은 함수를 실행하라는 것이다.  
    * 따라서 실행문에는 mul을 사용해야한다.  

### `void (*fp[4])(int *, int *, int *) = {add, sub, mul, div};`  

* 포인터가 4개인 array이며, parameter는 int *, int *, int * 형을 받는다.

* 그리고 그 포인터 4개는 add, sub, mul, div 함수를 각각 가리킨다.  

```c
//fnpointer.c
#include <stdio.h>

void add(int *a, int *b, int *c)
{ *c = *a + *b;}

void sub(int *a, int *b, int *c)
{ *c = *a - *b;}

void div(int *a, int *b, int *c)
{ *c = (*a) / (*b);}

void mul(int *a, int *b, int *c)
{ *c = (*a) * (*b);}


int main()
{
    int a = 100;
    int b = 200;
    int c = 0;
    char ch;
    int op = 0;
    scanf("%d %c %d", &a, &ch, &b);

    void (*fp[4])(int *, int *, int *) = {add, sub, mul, div};

    switch(ch){
        case '+':
            op = 0;
            break;
        case '-':
            op = 1;
            break;
        case '*':
            op = 2;
            break;
        case '/':
            op = 3;
            break;
    }

    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
    fp[op](&a, &b, &c);
    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
    fprintf(stdout, "fp %lld %lld %lld %lld\n", add, sub, mul, div);
}
```

* 입력받은 숫자를 사칙연산하는 프로그램 (함수의 포인터 배열 이용)  

* lld로 add, sub, mul, div를 출력하면?
    * 함수의 주소가 출력된다.

### `od`
a.out 코드 어떻게 생겼는지 보고싶다면 od 명령어를 사용한다.

```bash
$ od a.out
$ od -x a.out       # 16진수로 보여줌
```

### `오늘의 목표`  

* C compile process  
* CPP - C Preprocessor
* Compile options

<div style="text-align : center;">
    <img src=./img/compile.png width="60%" >  
</div> 

1. compile - compile 명령 넣음  
preprocessor directive - C언어에서 #

2. compile user source code - # 되어있던 것 모두 바뀜  
Assembly 를 생성함

3. Link Assembler - printf, scanf와 같은 함수들과 연결시켜줌 & 실행파일 만들어줌  
    1. static link - printf, scanf와 같은 것을 그냥 실행파일에 붙여줌
        * 실행파일 사이즈 커짐, 대신 항상 어떤 기계에서든 실행됨
    2. dynamic link - dynamic library에 있는 함수를 쓰게함
        * 보안상의 이유 등으로 사용, 성능상으로 약간의 문제 있을 수 있다

4. loader, loads the executable code into memory
    * 주소는 실행될 때 결정된다. (실행될 때 메모리에 a.out가 load 된다)

* Natural language
* program language
    1. 한줄 바꿔서 실행하기 반복 = interpreter
        * ex - python
    2. 프로그램 전체 번역해서 한번에 실행코드 생성 = compiler
        * ex - C
* Machine language

### `gcc compile options`  

gcc [-c|-S|-E] [-std=standard]
 [-g] [-pg] [-Olevel]
 [-Wwarn...] [-Wpedantic]
 [-Idir...] [-Ldir...]
 [-Dmacro[=defn]...] [-Umacro]
 [-foption...] [-mmachine-option...]
 [-o outfile] [@file] infile...

* -c : generate .o file
    * preprocessing & compile 까지만 실행
* -g : for debug
* -O : Optimization  
    * 최적화, 의미가 없는 코드는 아예 지워버린다. (빨라짐!)
* -E : generate preprocessing
    * preprocessing만 실행 -> .c 파일 만들어짐
* -pg : for profile
* -m32 -m64
    * 32bit / 64bit 컴파일
    * 64bit는 32bit에서 실행 불가
    * 32bit는 64bit에서 실행 가능

### `gcc option : preprocessor`  

 -Aquestion=answer -A-question[=answer] -C -CC -Dmacro[=defn] -dD -dI
 -dM -dN -dU -fdebug-cpp -fdirectives-only -fdollars-in-identifiers
 -fexec-charset=charset -fextended-identifiers -finput-charset=charset
 -fmacro-prefix-map=old=new -fno-canonical-system-headers -fpch-deps
 -fpch-preprocess -fpreprocessed -ftabstop=width -ftrack-macro-expansion
 -fwide-exec-charset=charset -fworking-directory -H -imacros file
 -include file -M -MD -MF -MG -MM -MMD -MP -MQ -MT
 -no-integrated-cpp -P -pthread -remap -traditional -traditional-cpp
 -trigraphs -Umacro -undef -Wp,option -Xpreprocessor option

> 잘 정리된 문서로 옵션 정리 해보기..!  

### `gcc compile - for multiple file`

```c
//func.h
#define DF(a) ((a) * (a))
extern int func1(int x);

//func.c
#include "func.h"
int func1(int a)
{
    return (a * 10);
}
int func2(int a)
{
    return (a * 2);
}

//main.c
#include <stdio.h>
#include "func.h"

int main()
{
    fprintf(stdout, "func %d %d\n", func1(100), DF(10));
    //func 110 100
}
```  

`gcc main.c func.c`  

1. main.c 컴파일 -> stdio.h preprocessing -> func.h preprocessing  

2. func.h의 DF(a) 대입해주고, func1에 대해 extern임을 마킹해둠  

3. main.o 파일 생성  

4. func.c 컴파일 -> func.h 파일 가져옴, object file 만듦  

5. 링킹 - printf & func1 에 대해 링크를 걸어둠.  

    * printf - dynamic link  

    * func1 - static link  

**main.c에서 func2를 사용하고 싶다면 func.h에 반드시 extern 선언을 해주어야한다.**  

* extern int func2(int x);

`cc -c main.c` : main.c -> main.o 생성해줌 (컴파일 : source code -> object code)
`cc -c func.c` : func.c -> func.o 생성해줌 (컴파일 : source code -> object code)
`cc main.o func.o` : a.out 실행파일 만들어줌  

이 상태에서 main.c를 수정했다면 `cc main.c func.o` 로 실행한다.  

func.c를 수정했다면 `cc func.c main.o` 로 실행한다.  

**Q**) 왜 이렇게 실행할까?
> 만약 func.c를 컴파일 할 때 많은 시간이 걸리고, func.c를 수정하지 않았다면 object code인 func.o를 그대로 사용한다.  
main.c를 수정했다면 main.c와 이전에 생성한 func.o를 컴파일해주면 된다.  

### `C preprocessor (CPP)`  

1. include head files  
2. define macro  
3. conditional compilation  
4. line control  

### `CPP - include file`

* #include file as text  
    * #include <stdio.h> or "file.h"  

* gcc Option - I
    * Include location - ./usr/include/
    * default include location

* prevent multiple include
    * #pragma once
    * #ifndef \_MATH_
    * #include <math.h>
    * #endif

### `CPP - conditional compilation`  

* #if
* #ifdef
* #ifndef
* #elif
* #else
* #endif

```c
#ifdef _VERSION_
#if _VERSION_ >= 3
    printf("Version is greater or equal than 3\n");
#elif _VERSION_ == 2
#error VERSION 2 IS NOT SUPPORTED
#endif
#endif  //ifdef _VERSION_
```

* 버전이 3보다 크면 print문을 출력한다.

* 버전이 2와 같다면 에러가 발생한다.

* ifdef의 짝은 마지막 endif로, \_VERSION_ 이 정의되어있다면 조건을 만족하게 하고, 아니라면 점프한다.  

### `Macro Definition`  

* #define <identifier> <replcement tokenlist>
    * object
* #define <identifier> (<parameter list>) <replacement token list>
    * function-like macro, note parameters

* ex - #define f(a) ((a) * (a)) : 의도는 제곱!

**위 예시에서 주의할 점! 무조건 parameter에 괄호치기**

[ **good ex** ] #define f(a) ((a) * (a))
> f(20+13)으로 사용하면 ((20+13) * (20+13))이 되어 의도대로 작동한다. 

[ **bad ex** ] #define f(a) a*a
> f(20+13)으로 사용하고자 했다면 20 + 13 * 20 + 13이 되어 의도대로 작동하지 않는다.

<div style="text-align : center;">
    <img src=./img/func.png width="20%" >  
</div>  

* cc -E func.c를 통해 func.h에 있던 extern 코드가 func.c로 온 것을 볼 수 있다.
    * -E : preprocessing option

* func.h에서 define한 DF(a)를 func.c에서 사용하면 DF(a) 대신에 ((a)*(a))가 들어가게 된다.

* func.h의 메크로를 수정했다고 해보자.
    * 수정한 이후에 기존에 생성한 object code를 cc main.o func.c 로 컴파일 했다면
    * 수정한 내용이 반영되어 작동하지 않는다!

**func.h처럼 수정된 메크로를 사용하는 모든 소스코드는 반드시 다시 컴파일해야한다.**

따라서 모두 다시 컴파일해야하기 때문에 메크로를 자주 수정하는 것은 좋지 않다.  

```c
#define DF(a) ((-a) * (a))      //의도한대로 잘 동작하지 않는다.
DF(a+1) == ((-a+1) * (a+1))     //이렇게 작동한다.

#define DF(a) (-(a) * (a))
DF(a+1) == (-(a+1) * (a+1)) 
```

* 첫번째처럼 작성하면 10을 대입했을 때 -11 * 11이 나오지 않는다.
    * 대신 -9 * 11이 계산된다.

* 두번째처럼 작성하면 -11 * 11로, 의도대로 잘 작동한다.
    * 따라서 괄호 적절하게 무조건 사용하기!

**ex**) main.c와 func.h 두 파일에서 #include <stdio.h> 를 사용했다면?  

* main.c에서 두번 include 된다. 그럼 오류가 날 가능성이 있다.

* 따라서 func.h에 #pragma once 를 사용한다. 그럼 이 파일은 한번만 include 된다.

```c
#ifdef __FUNC_
#define __FUNC_ 0
//codes....
#endif
```

* 또는 위 코드와 같이 func.h에서 __FUNC_가 정의되어 있다면 ifdef 아래 코드를 실행하고, 아니면 점프를 하게 할 수 있다.
    * 그러면 `__FUNC_` 가 정의되지 않았을 때 한번만 실행하게 되고, 두번째 로딩할 때는 ifdef의 아래 코드가 실행되지 않는다.

```c
#ifndef __FUNC_

#define __FUNC_ 0

#if FUNCTION_NEGATIVE == 1
#define DF(a) (-(a)*(a))
#else
#define DF(a) ((a) * (a))
#endif

extern int func1(int x);
extern int func2(int x);

#endif
```

1. __FUNC_가 정의되어있지 않다면 그 아래 코드 실행, 정의되어 있다면 점프한다.  

2. FUNCTION_NEGATIVE가 1이라면 #define DF(a) (-(a)*(a)) 로 작동한다.  

3. FUNCTION_NEGATIVE가 1이 아니라면 #define DF(a) ((a) * (a)) 로 작동한다.

* #if 0 ~~~ #endif = 이 코드를 사용하지 않겠다! (command 처리하기 복잡할 때 사용하면 좋다.)

***

## Lecture 8
##### - 2022. 01. 17  

### `Macro 순서 예시`  

```c
// macrotest.c
#define HE HI
#define LLO _THERE
#define HELLO "HI THERE"
#define CAT(a, b) a##b
#define XCAT(a, b) CAT(a, b)
#define CALL(fn) fn(HE, LLO)
CAT(HE, LLO)    // "HI THERE", because concatenation occurs before normal expansion
XCAT(HE, LLO),  // HI_THERE, because the tokens originating from parameters ("HE" and "LLO") are expanded first
CALL(CAT)       // "HI THERE", because parameters are expanded first
```

위 코드를 cc -E macrotest.c 로 preprocessing을 하면  

* CAT(HE, LLO) -> "HI THERE"  

    * CAT(a, b)는 a##b이므로 concat 매크로를 통해 HELLO가 된다.  

    * 그럼 HELLO가 매크로를 통해 "HI THERE"가 된다.  

* XCAT(HE, LLO) -> HI_THERE  
    
    * XCAT(HE, LLO)는 CAT(HE, LLO)이며 파라미터가 각각 먼저 expanded 되었기 때문에 CAT(HI, _THERE)가 된다. 따라서 concat 매크로를 통해 HI_THERE가 된다.

* CALL(CAT) -> "HI THERE" 의 결과를 얻게 된다.
    
    * CALL(CAT)은 CALL(HE, LLO)가 되고 concat 매크로를 통해 HELLO가 된다.  


_되도록이면 이런식으로 macro 사용하지 않기..! 간단한 단어들을 매크로 사용하면 오히려 이해하기 어렵다._

* 간단한 단어들을 #define의 identifier로 사용하지 않기.

### `Special Macro and Directives`  

```c
__FILE__
__LINE__
```  

* __FILE__에는 파일 이름이 프린팅 된다.
    
    * 여러 파일 컴파일 할 때 어떤 파일에서 오류가 났는지 모를 때 사용한다.  

* __FILE__은 string, __LINE__은 integer이다.

* #error 는 에러를 발생시키게 할 수 있다.

### `Token stringification`  

* string 토큰으로 바꿔준다.

```c
#define str(s)  #s
str(p = "foo\n";)       //outputs "p = \"foo\\n";"
str(\n)                 //outputs "\n"
```

* #s로 매크로를 정의하면 문자열로 만들어준다.

* print 매크로를 만들고 싶은데 어떤때에는 %d, %c, %s로 프린트 하고 싶을 때 token stringification을 사용하면 유용하다.  

### `Token Concatenation`  

* 두개를 붙여주는 매크로이다.

```c
#define DECLARE_STRUCT_TYPE(name) typedef struct name##_s name##_t
DECLARE_STRUCT_TYPE(g_object);
//outputs: typedef struct g_object_s g_object_t
```

g_object가 매크로의 name이 위치한 곳에 들어가 붙여져서 결과가 typedef struct g_object_s g_object_t 가 된다.  

* 왜 #define sq(a) a*a를 사용할 때 concatenation 해야하는가?  

```c
#define sq(a) a*a
sq(B)
#define sq(a) aaa
sq(C)
#define sq(a) a##a##a
sq(D)
```

* sq(B)는 B*B가 되는 것은 맞다.  

* sq(C)가 출력할 때는 CCC가 나오는 것이 아니라 그냥 aaa의 결과를 얻게 된다.  

* 따라서 붙여쓰고 싶다면 마지막처럼 a##a##a로 concatenation을 정의해야 DDD 라는 결과를 얻을 수 있다.

### `GCC Optimization`  

* 최적화에 대한 table 존재  

|Option|Meaning|
|:--------:|:--------:|
|-O0(기본값)|최적화를 수행하지 않는다.|
|-O / -O1|코드 크기와 실행 시간을 줄이는 것을 제외한 최적화는 실행하지 않는다. |
|-O2|메모리 공간과 속도를 희생하지 않는 범위내의 모든 최적화를 수행한다. loop unrolling과 function inlining에 대한 최적화를 수행하지 않는다.|
|-O3 / -O2|최적화에 인라인 함수와 레지스터에 대한 최적화를 추가로 수행한다.|
|-Os / -O2|최적화 기능을 사용하지만, 코드 크기를 증가시키는 최적화는 생략한다.|

* optimization을 하다보면 코드 크기가 커진다.  

### `함수의 메모리 공간`  

```c
int fun(int a){
    
    int b;
    return a * a;
}

int main(){
    int a = 100;
    fun(a);
}
```

* 실행하기 전에 필요한 데이터 넣어둔다.  
    * main의 메모리 공간에 a의 4바이트 등

* 함수가 호출되면 호출될 때 메모리 stack 만든다.  
    * parameter a를 받기 위한 메모리
    * int b를 위한 메모리
    * return 값 저장하기 위한 메모리  

* main에 있는 a와 함수에 있는 a는 다르다! 다른 위치의 메모리에 위치한다.  

* optimize하면 사용하지 않는 변수인 int b를 사용하지 않는다. (사라진다.)  

* *fn에서 `return a * a`하는 것과, main에서 `b = a *a` 하는 것의 차이는?

**Q**) 함수를 만드는 것이 좋을까? 만들지 않는 것이 좋을까?  
1. 성능은 어느쪽이 빠를까 (main 코드 vs 함수)  
2. 코드 길이는 어떻게 구현하는 것이 짧을까

**Q**) 함수는 stack 만드는 비용이 들어서 main 코드가 성능이 빠를 것 같은데 왜 함수를 사용하는가?
> main함수나 다른 함수들에서 그 함수가 1000번 소스코드에 appear 된다고 가정하면, 코드의 길이 입장에서는 main에  당연히 함수로 만드는 것이 좋다.  

* **#define으로 함수 정의하는 것은 잘 사용하기만 한다면 성능면에서와 코드 길이면에서 좋다!**

* #define으로 함수 정의하면 함수의 내용이 그대로 들어가게 된다.  

* c++에서는 inline으로 코드 끼워넣을 수 있다. (함수의 코드 자체가 그대로 들어간다.)

### `C Compile and Execution`  

* [ C Compile and Execution ](#오늘의-목표)
    * compile 과정 복습

### `gcc -options`  

* 옵션이 매우 많은데 중요한 것만 뽑은 내용이다..!

* -std=<standard> Assume that the input sources are for <standard>.
* -E Preprocess only; do not compile, assemble or link.
    * CPP, c preprocessor만 실행함
* -S Compile only; do not assemble or link.
    * compile만 함
* -c Compile and assemble, but do not link.
    * .o 파일을 만든다.
* -o <file> Place the output into <file>.

### `gcc machine option (x86 & x86 win)`  

* 컴파일된 실행파일 a.out가 다른 기계에서도 실행되면 좋을 것 같을 때 machine option을 사용한다.  

* arm에서 사용하도록 하고 싶다면 arm용 컴파일러를 설치하여야 한다.  

* -m32 -m64 -mx32 -m16 
    * 각각 32bit, 64bit

### `gcc option: preprocessor`  

* -Aquestion=answer
 * preprocessor가 질문하는 경우가 있다. answer에 yes라 해두면 계속 yes로 대답함

* -dI: include 파일은 이 디렉토리에서 가져오도록 설정

### `Must Know..`  

* 여기에 있는 내용은 꼭 알고 있기

gcc [-c|-S|-E] [-std=standard]
 [-g] [-pg] [-Olevel]
 [-Wwarn...] [-Wpedantic]
 [-Idir...] [-Ldir...]
 [-Dmacro[=defn]...] [-Umacro]
 [-foption...] [-mmachine-option...]
 [-o outfile] [@file] infile...

* -c : generate .o file
    * preprocessing & compile 까지만 실행
* -g : for debug
* -O : Optimization  
    * 최적화, 의미가 없는 코드는 아예 지워버린다. (빨라짐!)
* -E : generate preprocessing
    * preprocessing만 실행 -> .c 파일 만들어짐
* -pg : for profile
* -m32 -m64
    * 32bit / 64bit 컴파일
    * 64bit는 32bit에서 실행 불가
    * 32bit는 64bit에서 실행 가능

### `compile 순서와 옵션`  

1. cc -E hello.c > hellocpp.c = c preprocessing, cpp 코드 만들어줌
2. cc -S hellocpp.c = hellocpp.s 만들어짐, compile해서 assembly로 고쳐짐
3. cc -c hellocpp.s = hellocpp.o 만들어짐, object 코드 만들어짐
4. cc -o hellocpp hellocpp.o = 실행파일 hellocpp.out가 만들어진다!  

### `CPP processing`  

* Character set
    * utf-8 = 유니코드

* Initial processing
    1. LF, CR LF and CR processing
        * 줄바꿈 코드를 모드 CR로 바꾼다.  

    2. if –trigraphs

    3. long line with “\” -> merge
        * 긴줄, 여러줄 줄 바꿔서 쓰고 싶을 때 사용한다.
        * \을 사용하면 대신 c preprocessing 이 한줄로 다시 붙인다.

    4. All comments -> “ ”
        * 모든 comment는 " "로 지운다.

* Tokenization with space
    * #define foo() bar
    * foo()bar -> bar bar    not    barbar    // use ## for concat
    * foo()bar를 했을 때는 barbar가 아닌 bar bar의 결과를 얻을 수 있다.
    * barbar처럼 붙어있는 결과를 얻고 싶다면 ## concatenation을 사용한다.

* Preprocessing language
    * inclusion of header / Macro Expansion / Conditional Compile / Line Control Diagnostics (에러 발생)

* od -x -c hello.c

<div style="text-align : center;">
    <img src=./img/od.png width="70%"/>  
</div>

* 여기서 \n이 들어가있고 \n이 0a = 10임을 알 수 있다.  

* pc에서는 \n과 \r이 들어가있는데 유닉스에서는 \n만 들어있다.  

    * 줄바꿈을 표현하는 방법은 시스템과 운영 체제에 따라 여러 가지가 있다. 
    * 윈도우는 ASCII의 CR+LF로 새줄을 나타내고 유닉스는 LF로 새줄을 나타낸다. 
    * 맥 OS은 새줄 문자로 버전 9까지 CR을 썼지만 버전 10부터 LF를 쓰고 있다.
    
* 위에서 언급한 CR processing이 일어나면 \n으로 다 바뀐다.

* MS word 왼쪽, 오른쪽 구분되는 따옴표는 유니코드이다. -> C 언어에서 사용 불가!
    * printf(“Hello World\n”");  

### `Macro Definition (1)`  

* #define PI 3.14159 = 텍스를 대치줌

* 괄호로 묶어주는 것이 안전하다.

### `Macro Definition (2)`  

* Multiple lines
```c
#define NUMBERS 1, \
                2, \
                3  

int x[] = { NUMBERS };  //int x[] = { 1, 2, 3 };  
//define 활용한 예시
```

여러줄로 define 하고 싶을 때 위에서 나온 back slash (\)을 사용한다.  

* Define Where?

```c
    foo = X; 
    #define X 4 
    bar = X;    // foo = X and bar = 4
```

define은 어디에서나 할 수 있는데, 자신 직전에 했던 define이 작동한다.

```c
#define TABLESIZE BUFSIZE
#define BUFSIZE 1024 // TABLESIZE -> BUFSIZE  -> 1024 [X]
```

TABLESIZE 가 BUFSIZE임을 정의하기 전에 BUFSIZE가 1024로 정의되어 있지 않아서 TABLESIZE가 1024로 작동하지 않는다.  

```c
#define BUFSIZE 1020
#define TABLESIZE BUFSIZE
#undef BUFSIZE
#define BUFSIZE 37   // TABLESIZE = 37
```

이 경우에서는 BUFSIZE를 정의하고 그 다음에 TABLESIZE를 정의하였기 때문에 잘 작동한다.  

### `Macro Definition (3) - Function like Macro`  

* C언어에서 if 조건문은 성능을 떨어뜨리는데 C 언어에서 사용하는 ? 조건문은 생각보다 성능이 좋다.  

```c
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
```

조건이 true이면 X이고, false이면 Y가 된다.  

* omit parameter  

```c
min(, b) -> (()<(b) ? ( ) : (b))
```

빈 parameter에 무엇이 들어가든 모든 빈 공간에 paramter가 들어간다.  

따라서 빈 paramter에 값이 들어가면 조건에 따라 새로 들어간 parameter 혹은 b 를 얻게 된다.  

**대신 paramter 개수는 맞춰서 넣어줘야 한다.**
> 위 경우에는 paramter 2개 필요! parameter 개수 맞지 않으면 에러 발생  

### `Macro Definition (4) - Stringization and concat`  

* Stringization
    * Parameter leading with #
    * 위에서 본 예시 참고 -> paramter 안의 모든 것 string으로 바꿔줌

* Concatenation
    * ##을 사용하면 paramter로 들어온 것을 공백없이 합쳐주거나 공백없이 그 자리에 넣어준다.

### `Macro Definition (5) - Variadic`  

```c
eprintf ("%s:%d: ", input_file, lineno) 
fprintf (stderr, "%s:%d: ", input_file, lineno)  

#define eprintf(format, ...) fprintf (stderr, format __VA_OPT__(,) __VA_ARGS__)
```

* 뒤에 parameter들이 개수에 따라 여러개의 parameter 개수가 될 수 있는 함수 만들 수 있다.

### `Macro 예시`  

* Misnesting  

```c
#define twice(x) (2*(x))  
#define call_with_1(x) x(1)  
call_with_1 (twice)  // -> twice(1)  -> (2*(1))  

#define strange(file) fprintf (file, "%s %d", strange(stderr) p, 35); // -> fprintf (stderr, "%s %d", p, 35);  
```

* 위 예시처럼 코드 짜지 않기..  실행이 되긴 되긴 하지만 이해하기 어렵다.

* Operator precedence  

* Newline

### `Predefined Macros`  

* All Standards

```c
__FILE__    // Filename with full path string
__LINE__    // Decimal number of current line
```

* __LINE__으로 line number를 바꿀 수 있다.

```c
//hello.c
#include <stdio.h>

void add(int *a, int *b, int *c)
{
        *c = *a + *b;
}

int main()
{
        int a = 100;
        int b = 200;
        int c = 999;
        // int * = long long

        fprintf(stdout, "%d : %lld %llx\n", a, (long long )&a, (long long)&a);
        fprintf(stdout, "%d : %lld %llx\n", b, (long long)&b, (long long)&b);
        add(&a, &b, &c);
        fprintf(stdout, "%s %d : %d \n", __FILE__, __LINE__, c);
}
```

```bash
$ a.out
100 : 140734210326444 7fff3c9d3fac
200 : 140734210326448 7fff3c9d3fb0
hello.c 18 : 300
```

* 위 hello.c 코드에서 사용한 __FILE__과 __LINE_으로 파일 이름 hello.c와 line number 18이 출력된 것을 볼 수 있다.

* 만약 print문 직전에 `#define __LINE__ 1000` 매크로를 사용했다면 print문의 line number가 1000으로 출력된다.

* `#error 1024`를 사용하면 컴파일 시도할 때 바로 에러가 발생한다.

```c
#define ERR_DATA 1000
#if ERR_DATA > 1000
#error 1024
#else
#warning ERR_DATA
#endif
        fprintf(stdout, "%s %d : %d \n", __FILE__, __LINE__, c);
```

* 위 코드는 ERR_DATA가 1000이므로 에러가 나지 않고 warning과 함께 아래의 print문이 출력된다.

* line number를 define하면 line number가 증가하지 않는다. -> 되도록이면 line number 지정하지 않기.

### `Project`  

* 아주대학교의 임베디드 시스템을 위한 고정소수점 수학 라이브러리 개발  

* 고정소수점 <-> 부동소수점 (뜰 부, floating point)

* 10010101 = 정수로 149 (10진수)

* 2진수 1101.11 = 9.75
    * 소수점 뒤 부분은 1/2, 1/4가 된다.  

* 부동소수점  

<div style="text-align : center;">
    <img src=./img/floating_point.png width="60%"/>  
</div>

* 위 사진에서 1 / 10000101 / 11011010100000000000000 를 10진수로 바꾸고 싶다면
    * 순서대로 각각 s, e, m
    * 1.m * (2 ^ (e-127)) 이다.
    * 부호는 (-2S + 1) 로 이를 곱해줘야한다.

* 만약 32bit signed 정수를 2의 보수로 표현한다면
    * s / 15bit / 16bit
    * signed int a 의 실제 값은 a * 2 ^ (-16) 이다.

### `입력받은 수를 fixed point로 출력하는 프로그램`  

```c
//pcc001_final / test.c
#include <stdio.h>

// #### #### #### #### .  #### #### #### ####
// S 15 . 16

#define FX_Q_NUM 16
#define FX_2_MINUS_16 1.52587890625e-05
#define FX_2_PLUS_16 65536

int main()
{
    int ia;
    float fa;
    fscanf(stdin, "%d", &ia);
    fprintf(stdout, "%d : %d %d\n", 2, 16, 2^16 );
    fprintf(stdout, "%d : %f %f\n", ia, (float)ia, (float)ia *  FX_2_MINUS_16);
    //ia를 fixed point로 출력하고 싶다면 float형으로 바꾸고 2의 -16승을 곱해준다.
    fscanf(stdin, "%f", &fa);
    fprintf(stdout, "%f : %d %d\n", fa, (int)fa, (int) (fa * FX_2_PLUS_16));
    //floating point에 2의 16승을 곱하고 int형으로 바꿔 fixed point로 출력한다.
}
```

* fixed point로 바꾸기
    * int형 데이터 -> float 형으로 바꾸고 2의 -16승을 곱해준다.
    * float형 데이터 -> 2의 16승을 곱하고 int형으로 바꿔준다.

***

## Lecture 9
##### - 2022. 01. 18  

### `아주고정소수점`  

* 아주대학교의 임베디드 시스템을 위한 고정소수점 수학 라이브러리 개발  

* CPU가 하는 중요한 작업 두가지
    * ALU - arithmetic logic unit
    * CU - control unit

* +, -, *, /, &, |, ^, ~, >>, << : 보통 단위 사이클에 끝남
    * 곱셈, 나눗셈 : 어떤 컴퓨터에서는 한 사이클에 끝나지만 어떤 컴퓨터에서는 아닐 수도 있다.

* ex) Processor : Intel(R) Core(TM) i7-8700K CPU 3.70GHz
    * 기본 한 사이클 : 1 / clock speed = 1 / 3.7GHz = 0.27 nano second

* fixed point를 사용하는 이유?
    * floating point 연산은 integer 연산에 비해 매우 비싼 연산이다.
    * 내가 표현하고 싶은 수가 정수가 아니라 유효숫자가 있는 수를 표현하고 싶다면 int로 표현하되 소숫점을 고정해서 표현한다.

* #define FX_S32_31은 signed 32bit + 31bit이니까 64bit long long을 사용해야한다.

* #define FX_S47_16 -> signed long long

* #define FX_S16_15 & #define FX_S23_08 -> signed integer

* #define FX_S8_7 -> signed short

* #define FX_S4_3 -> signed char

### `S 15 . 16`  

```c
#include <stdio.h>

// #### #### #### #### .  #### #### #### ####
// S 15 . 16

#define FX_Q_NUM 16
#define FX_2_MINUS_16 1.52587890625e-05F
#define FX_2_PLUS_16 65536
#define FX_S_15_16 11516
#define FX_SYSTEM FX_S_15_16

typedef int fixed32;

fixed32 fromFloat(float fa)
{
    return (fixed32) (fa * FX_2_PLUS_16);

}

float toFloat(fixed32 xa)
{
    return ((float)(xa)) * FX_2_MINUS_16;

}

fixed32 fxAdd(fixed32 a, fixed32 b)
{
    return fromFloat((toFloat(a) + toFloat(b)));
}

fixed32 fxAdd2(fixed32 a, fixed32 b)
{
    return a + b;
}

int main()
{
    long long i=0;
    int ia, ib, ic, ic2;
    float fa;
    //fscanf(stdin, "%d %d", &ia, &ib);
    for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += (256 * 256))
    {
        ic = fxAdd(i, i);
        ic2 = fxAdd2(i, i);
        fprintf(stdout, "%f + %f : %f, %f diff = %d\n", toFloat(i), toFloat(i), toFloat(ic), toFloat(ic2),ic-ic2 );
    }
    //fprintf(stdout, "%d + %d : %d\n", ia, ib, ic);
    //fprintf(stdout, "%f + %f : %f\n", toFloat(ia), toFloat(ib), toFloat(ic));
}
```

* #define FX_2_PLUS_16의 65536을 (1<<16)으로 사용해도 성능상에서는 차이 없다.

* fromFloat 함수 : fixed point로 변환해서 return

* toFloat 함수 : floating point로 변환해서 return

* fxAdd : fixed point를 floating point로 변환 후에 더하고 다시 fixed point로 변환해서 return 해줌

* fxAdd2 : 그냥 a와 b를 더해서 return  

**Q**) fxAdd와 fxAdd2의 결과는 같을까?
> ic에는 fxAdd의 결과를, ic2에는 fxAdd2의 결과를 저장하였다.  
실행결과는 result.out에 저장함.  

`project - 보고서에 써야할 점`  

* i가 0에서부터 500만까지 i++ 해서 들어갈 때, 결과를 출력해보면 0.000000 + 0.000000....이고 그 다음이 0.000015 였다.  

* 이 숫자가 표현할 수 있는 가장 작은 숫자의 차이가 0.000015라는 뜻이다.

> 이 시스템은 정수파트가 15비트, 소수점 이하 부분이 16비트인 시스템인데 이 시스템에서 표현할 수 있는 가장 작은 차이의 수는 0.000015 입니다.  
정확한 값인지 아닌지는 나중에 계산해봐야함 -> 0.000015가 맞았다면 그 다음이 0.000030이어야 하는데 0.000031이니까 계산해봐야함  

* i = long long, for (i = 0 ; (long long) 256 * 256 * 256 * 256; i += (256 * 256) ) 실행 했을 때 결과 중 오버플로우 발생
    * 이때 16385.000000 + 16385.000000 = -32768.000000 으로 오버플로우 발생

### `debugging`  

* gcc compile options 중에 -g 가 for debug

* pcc001_final/test.c를 수정해서 일부러 &ib를 ib로 scanf 하여 에러가 발생하도록 하였다.

```bash
$ cc -g test.c
test.c: In function ‘main’:
test.c:41:21: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘int’ [-Wformat=]
  fscanf(stdin, "%d %d", &ia, ib);

$ ./a.out
200 200         # 200 200 입력함
Segmentation fault (core dumped)

$ file a.out
a.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=a4867b47f1cd5e4faf38b42c8bde146a4cfc100d, with debug_info, not stripped

# a.out 파일에 디버깅 내용 들어가서 크기가 확 커짐

$ gdb a.out
```

* gdb 사용하는 방법 = gdb 실행파일 = gdb a.out

### `gdb - GNU debugger`  

* gcc -g 옵션으로 컴파일하고 gdb를 통해 디버깅

```bash
(gdb) run           # 실행
Starting program: /home/course/pcc001/pcc/lec09/a.out
500 500             # scanf로 입력받을 값 넣어줌

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7a53932 in _IO_vfscanf_internal (s=s@entry=0x7ffff7dcfa00 <_IO_2_1_stdin_>, format=<optimized out>,
    argptr=argptr@entry=0x7fffffffe0f0, errp=errp@entry=0x0) at vfscanf.c:1898
1898	vfscanf.c: No such file or directory.
# 에러가 scanf에서 발생했음을 알 수 있다.

(gdb) where         # 에러가 발생한 현재 위치가 어디인지 알려줌
#0  0x00007ffff7a53932 in _IO_vfscanf_internal (s=s@entry=0x7ffff7dcfa00 <_IO_2_1_stdin_>, format=<optimized out>,
    argptr=argptr@entry=0x7fffffffe0f0, errp=errp@entry=0x0) at vfscanf.c:1898
#1  0x00007ffff7a60356 in __isoc99_fscanf (stream=0x7ffff7dcfa00 <_IO_2_1_stdin_>, format=<optimized out>)
    at isoc99_fscanf.c:34
#2  0x000055555555485d in main () at test.c:41

(gdb) pwd
Working directory /home/course/pcc001/pcc/lec09.

(gdb) list
1893    in vfscanf.c

(gdb) list main
32  {
33      return a + b;
34  }
35
36  int main()
37  {
38      long long i=0;
39      int ia, ib, ic, ic2;
40      float fa;
41      fscanf(stdin, "%d %d", &ia, ib);
```  

* gdb 명령어  
    * run : 실행
    * where : 에러가 발생한 현재 위치가 어디인지 알려줌
    * pwd : 현재 작업 디렉토리
    * list : 현재 vfscanf.c를 보고있다.
    * list function_name : 함수의 소스코드를 보여준다.

* where를 통해 알게 된 점  
test.c의 41번째 라인에서 에러가 발생했다.  
test.c의 main() 함수에서 __isoc99_fscanf를 호출하였고, 이 함수는 _IO_vfscanf_internal 함수를 호출하였다.  
== `call stack`  

```bash
(gdb) list
29      return a + b;
30  }
31
32  int main()
33  {
34      long long i=0;
35      int ia, ib, ic, ic2;
36      float fa;
37      fscanf(stdin, "%d %d", &ia, ib);

(gdb) break 34
Breakpoint 1 at 0x833: file test.c, line 34

(gdb) run
Starting program: /home/course/pcc001/lec09/a.out

Breakpoint 1, main() at test.c:34
34              int i=0;

(gdb) print i
$i =0

(gdb) step
37              fscanf(stdin, "%d %d", &ia, ib);
# 왜 다음 줄인 35번이 아니라 37번을 실행한 것일까?
# 실행문이 아니라 선언문이므로 다음 실행문이 37번 라인을 실행함

(gdb) print ia
$2 = 32767
(gdb) print ic
$3 = 0
(gdb) print ic2
$4 = 21845              # 변수에 garbage 들어가있는 모습

(gdb) watch ic
Hardware watchpoint 2: ic

(gdb) continue
Continuing.
0.000000 + 0.000000 : 0.000000 , 0.000000 diff = 0

Hardware watchpoint 2:ic

Old value = 0
New value = 131072
main () at test.c:41
41                      ic2 = fxAdd2(i, i);
# ic 값이 40 라인에서 바뀌어서 바로 그 다음줄 41번 라인에서 stop한다.
```

* gdb 명령어
    * break line_number : line number로 breakpoint 지정해줌
        * break 함수명도 가능
    * run : breakpoint 지정했다면 실행 후 그 라인에서 멈춤
    * print 변수 : 현재 변수에 저장된 값 볼 수 있음
    * step : 그 다음 줄 실행 (실행문) - 호출된 함수의 소스코드로 들어갈 수 O
    * next == ni : 현재 소스코드의 다음 줄 실행
    * continue : 계속 실행하고 싶을 때
    * quit : 실행 process 종료
    * clear breakpoints line_number : line number로 지정된 breakpoint 삭제
    * bt :  충돌이 일어난 시점에서 프로그램의 현재 호출 스택 보여줌 (call stack)
        * ex) fromFloat를 fxAdd가 호출하였고, fxAdd를 main이 호출하였음을 알 수 있다.  
    * watch 변수명 : 어떤 변수의 값이 변했을 때 stop 시키고 싶다면 사용

**next vs step**
next : 현재 소스코드의 다음 줄 실행  
step : 다음 줄 실행하긴 하는데 호출된 함수의 소스코드로 들어가고 싶을 때 사용  

***

## Lecture 10
##### - 2022. 01. 19  

### `(1) coredump 시키는 방법 & gdb`  

```bash
$ vi coredump.c
$ cc -g coredump.c
coredump.c: In function ‘main’:
coredump.c:3:12: warning: division by zero [-Wdiv-by-zero]
  int a = 10/0;
            ^
$ ./a.out
Floating point exception (core dumped)
-rw-------  1 pcc001 pcc 245760  1월 19 13:40 core      # core 생성됨
$ gdb a.out core      # gdb 실행
$ rm core             # 메모리를 낭비하기 때문에 디버깅이 끝나고 core 삭제하기

# core생성 안될 때 (관리자가 sudo 안해줬을 때)
$ cd /var/lib/apport/coredump/ 에 core가 위치함
$ cd ~/pcc/lec10
$ gdb a.out /var/lib/apport/coredump/core._home_course_pcc001_pcc_lec10_a_out.4001.34e8117c-1278-4ea4-a8b5-e6131460d25d.22969.84048070

(gdb) where
#0  0x00005621a9052609 in main () at coredump.c:3
```

* coredump = a.out를 실행하며 생긴 메모리를 통째로 dump한 것
    * 따라서 에러가 난 현재 메모리 상태를 볼 수 있다.

### `(2) visual studio 2022에서 debug`  

* new project -> empty project 생성 -> source files -> add -> new item -> c++ File(cpp)에서 hello.c로 생성 -> c 코드 작성  

```c
#include <stdio.h>

int main(){
    int a = 100;
    printf("Hello World\n");
    a = a / 0;
}
```

* f5누르면 컴파일  

* release mode : cc로 컴파일
    * cd /c/Users/hwany/source/repos/Project2/x64/Debug/Project2.exe -> exe 실행파일이 여기에 위치해있다! (소스코드 있는 디렉토리에 위치 X)

* debug : cc -g와 동일

* n번 라인에서 break하기: debug 모드에서 line 수 옆의 dot 누르기 (누르면 빨간색 점이 됨)  -> break point 생성됨, 계속하고 싶다면 continue 누르기

* step into, next

* autos에 a 값 보여줌 == gdb에서의 print a 기능과 같다.  

### `gprof - GNU Profiling`  

```bash
$ cc -pg test.c
$ a.out
$ ls -al
-rw-r--r--  1 pcc001 pcc  714  1월 19 15:45 gmon.out
$ gprof a.out gmon.out
# call graph 볼 수 있다.

Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 31.98      0.07     0.07 33554432     2.10     2.10  toFloat
 29.69      0.14     0.07                             main
 18.27      0.18     0.04 16777216     2.40     2.40  fromFloat
 13.70      0.21     0.03 16777216     1.80     8.39  fxAdd
  6.85      0.22     0.02 16777216     0.90     0.90  fxAdd2

# self: 이 함수 안에서 발생했던 time 

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 4.52% of 0.22 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.07    0.16                 main [1]
                0.03    0.11 16777216/16777216     fxAdd [2]
                0.02    0.00 16777216/16777216     fxAdd2 [5]
-----------------------------------------------
                0.03    0.11 16777216/16777216     main [1]
[2]     63.6    0.03    0.11 16777216         fxAdd [2]
                0.07    0.00 33554432/33554432     toFloat [3]
                0.04    0.00 16777216/16777216     fromFloat [4]
-----------------------------------------------
                0.07    0.00 33554432/33554432     fxAdd [2]
[3]     31.8    0.07    0.00 33554432         toFloat [3]
-----------------------------------------------
                0.04    0.00 16777216/16777216     fxAdd [2]
[4]     18.2    0.04    0.00 16777216         fromFloat [4]
-----------------------------------------------
                0.02    0.00 16777216/16777216     main [1]
[5]      6.8    0.02    0.00 16777216         fxAdd2 [5]
-----------------------------------------------

# i += 25로 바꿔서 10배 더 느리게 실행된 결과

Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 25.80      0.67     0.67 343597384     1.96     1.96  toFloat
 21.95      1.25     0.57                             main
 19.25      1.75     0.50 171798692     2.93     2.93  fromFloat
 18.48      2.23     0.48 171798692     2.81     9.65  fxAdd
 11.94      2.54     0.31 171798692     1.81     1.81  fxAdd2
  3.08      2.62     0.08                             frame_dummy

granularity: each sample hit covers 2 byte(s) for 0.38% of 2.62 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     96.9    0.57    1.97                 main [1]
                0.48    1.18 171798692/171798692     fxAdd [2]
                0.31    0.00 171798692/171798692     fxAdd2 [5]
-----------------------------------------------
                0.48    1.18 171798692/171798692     main [1]
[2]     63.2    0.48    1.18 171798692         fxAdd [2]
                0.67    0.00 343597384/343597384     toFloat [3]
                0.50    0.00 171798692/171798692     fromFloat [4]
-----------------------------------------------
                0.67    0.00 343597384/343597384     fxAdd [2]
[3]     25.7    0.67    0.00 343597384         toFloat [3]
-----------------------------------------------
                0.50    0.00 171798692/171798692     fxAdd [2]
[4]     19.2    0.50    0.00 171798692         fromFloat [4]
-----------------------------------------------
                0.31    0.00 171798692/171798692     main [1]
[5]     11.9    0.31    0.00 171798692         fxAdd2 [5]
-----------------------------------------------
                                                 <spontaneous>
[6]      3.1    0.08    0.00                 frame_dummy [6]
-----------------------------------------------

```

* 함수의 호출은 매우 비싸다!

```c
fixed32 fxAdd(fixed32 a, fixed32 b)
{
        //return fromFloat((toFloat(a) + toFloat(b)));
        return (fixed32)((((float)(a)) * FX_2_MINUS_16 + ((float)(b)) * FX_2_MINUS_16) * FX_2_PLUS_16);

}
```

```bash
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 54.23      0.68     0.68 171798692     3.98     3.98  fxAdd
 27.91      1.04     0.35 171798692     2.05     2.05  fxAdd2
 13.56      1.21     0.17                             main
  4.79      1.27     0.06                             toFloat

  granularity: each sample hit covers 2 byte(s) for 0.79% of 1.27 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     95.2    0.17    1.04                 main [1]
                0.68    0.00 171798692/171798692     fxAdd [2]
                0.35    0.00 171798692/171798692     fxAdd2 [3]
-----------------------------------------------
                0.68    0.00 171798692/171798692     main [1]
[2]     54.0    0.68    0.00 171798692         fxAdd [2]
-----------------------------------------------
                0.35    0.00 171798692/171798692     main [1]
[3]     27.8    0.35    0.00 171798692         fxAdd2 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]      4.8    0.06    0.00                 toFloat [4]
-----------------------------------------------
```

* 함수의 호출이 비싸기 때문에 이렇게 바꿔서 수정해봄

* function call을 하지 않았더니 거의 2배 더 빨라진 결과를 얻을 수 있었다.

```c
//macro를 call 하도록 함
#define fromFloat(fa) ((fixed32)( (fa) * FX_2_PLUS_16))
#define toFloat(xa) (((float)(xa)) * FX_2_MINUS_16)
```

```bash
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 46.79      0.61     0.61 171798692     3.57     3.57  fxAdd
 30.68      1.01     0.40 171798692     2.34     2.34  fxAdd2
 16.11      1.23     0.21                             main
  6.90      1.32     0.09                             toFloat_fn

granularity: each sample hit covers 2 byte(s) for 0.76% of 1.32 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     93.1    0.21    1.01                 main [1]
                0.61    0.00 171798692/171798692     fxAdd [2]
                0.40    0.00 171798692/171798692     fxAdd2 [3]
-----------------------------------------------
                0.61    0.00 171798692/171798692     main [1]
[2]     46.6    0.61    0.00 171798692         fxAdd [2]
-----------------------------------------------
                0.40    0.00 171798692/171798692     main [1]
[3]     30.5    0.40    0.00 171798692         fxAdd2 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]      6.9    0.09    0.00                 toFloat_fn [4]
-----------------------------------------------
```

* 10~20% 오차 발생할 수 있음  

```c
//test2.c
#include <stdio.h>

int fxMul1(int a, int b)
{
    return a * b;
}

int fxMul2(int a, int b)
{
    return (int)((long long) a * (long long) b);
}

int main()
{
    long long i=0;
    int ia, ib, ic, ic2;
    float fa;
    //fscanf(stdin, "%d %d", &ia, &ib);
    for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 25)
    {
        ic = fxMul1(i, i);
    }
    for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 25)
    {
        ic = fxMul2(i, i);
    }
}
```

```bash
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 43.32      0.56     0.56                             main
 32.87      0.99     0.43 171798692     2.49     2.49  fxMul2
 20.89      1.26     0.27 171798692     1.58     1.58  fxMul1
  3.48      1.31     0.05                             frame_dummy

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.76% of 1.31 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     96.5    0.56    0.70                 main [1]
                0.43    0.00 171798692/171798692     fxMul2 [2]
                0.27    0.00 171798692/171798692     fxMul1 [3]
-----------------------------------------------
                0.43    0.00 171798692/171798692     main [1]
[2]     32.7    0.43    0.00 171798692         fxMul2 [2]
-----------------------------------------------
                0.27    0.00 171798692/171798692     main [1]
[3]     20.8    0.27    0.00 171798692         fxMul1 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]      3.5    0.05    0.00                 frame_dummy [4]
-----------------------------------------------
```

* cc -pg -m32 test2.c       //32bit 컴퓨터용으로 컴파일 함
* a.out

```bash
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 46.16      0.79     0.79                             main
 24.25      1.21     0.42 171798692     2.43     2.43  fxMul1
 13.15      1.44     0.23 171798692     1.32     1.32  fxMul2
 12.27      1.65     0.21                             __x86.get_pc_thunk.bx
  3.51      1.71     0.06                             __x86.get_pc_thunk.dx
  0.58      1.72     0.01                             __gmon_start__
  0.58      1.73     0.01                             _dl_relocate_static_pie

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.58% of 1.73 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     83.1    0.79    0.64                 main [1]
                0.42    0.00 171798692/171798692     fxMul1 [2]
                0.23    0.00 171798692/171798692     fxMul2 [3]
-----------------------------------------------
                0.42    0.00 171798692/171798692     main [1]
[2]     24.1    0.42    0.00 171798692         fxMul1 [2]
-----------------------------------------------
                0.23    0.00 171798692/171798692     main [1]
[3]     13.1    0.23    0.00 171798692         fxMul2 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]     12.2    0.21    0.00                 __x86.get_pc_thunk.bx [4]
-----------------------------------------------
                                                 <spontaneous>
[5]      3.5    0.06    0.00                 __x86.get_pc_thunk.dx [5]
-----------------------------------------------
                                                 <spontaneous>
[6]      0.6    0.01    0.00                 __gmon_start__ [6]
-----------------------------------------------
                                                 <spontaneous>
[7]      0.6    0.01    0.00                 _dl_relocate_static_pie [7]
-----------------------------------------------

$ file a.out
a.out: ELF 32-bit LSB shared object, Intel 80386, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=e6b9b35bc23da8fcf7462c1df17b7a2c6063cb88, not stripped
```

* 굉장히 오차가 많이 때문에 통계적인 기법을 사용해서 테스팅해보는 것을 권장한다.
    * ex - outlier 빼고 통계 내보기

### `project`  

* 기본 자료형 c  
    * [unsigned , signed]  X  [long long, int (long), short, char]
    * float, double, (half, quad)

* IEEE754

* IEEE802 - LAN 표준
    * IEEE802.11 - 와이파이 표준

* ex - unsigned char
    * val =  b7 * 27 + b6 * 26 + b5 * 25 + …… + b1 * 21 + b0 * 20

* ex - signed char
    * sign bit가 1이면 : –(~b6 * 26 + ~b5 * 25 + …… + ~b1 * 21 + ~b0 * 20 + 1) 
    * sign bit가 0이면 : b6 * 26 + b5 * 25 + …… + b1 * 21 + b0 * 20

* c언어의 float는 실수를 표현할 수 없다.
    * 실수를 표현하기 위해서는 무한히 큰 메모리가 필요하다.
    * 따라서 어느정도에서 근사치를 컴퓨터에 저장한다. (approximation)

* float
    * (sign * -2 + 1) * (1.0 + fraction * 2-23 ) * 2 ^ (exp – 127) 

* others
    * half – sign 1, exp 5, fraction 11
    * double – sign 1, exp 11, fraction 53
    * quadruple – sing 1, exp 15, fraction 113

* fixed point number
    *  fixed point는 실수를 표현할 때 정밀도가 떨어진다.

***

## Lecture 11
##### - 2022. 01. 20  

* addPointer, addValue 함수 설명

* call by value , call by reference

### `how to use gprof`  

* System을 느리게 하는 것들!

### `What makes different performance`  

* System을 느리게 하는 것들!

* golden rule
    * speed - CPU > Memory > Storage > IO > Human
    * Register > Cache (1st, 2nd) > Memory > ...
    * Locality
    * Pipeline
    * Error

* Depend on HW
    * One cycle execution - +, -, >>, <<, > ?

**Q**) 왜 덧셈이 곱하기보다 느릴까?
> 덧셈 오버플로우 발생 (Error)  
(long long) 256 * 256 * 256 * 256 이렇게 큰 수를 더할 때 오버플로우가 발생  
따라서 64 * 256 * 256 * 256으로 성능 테스트 해보기

```c
#include <stdio.h>

int fxMul1(int a, int b)
{
        return a * b;
}

int fxMul2(int a, int b)
{
        return (int)((long long) a * (long long) b);
}

int main()
{
        long long i=0;
        int ia, ib, ic, ic2;
        float fa;
        //fscanf(stdin, "%d %d", &ia, &ib);
        for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 25)
        {
                ic = fxMul1(i, i);
        }
        for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 5)
        {
                ic = fxMul2(i, i);
        }
}
```

```bash
$ cc -pg -g test3.c
$ a.out
$ gprof -b
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 43.11      0.12     0.12                             main
 34.13      0.22     0.10 42949673     2.23     2.23  fxMul2
 23.35      0.28     0.07 42949673     1.52     1.52  fxMul1


			Call graph


granularity: each sample hit covers 2 byte(s) for 3.55% of 0.28 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.12    0.16                 main [1]
                0.10    0.00 42949673/42949673     fxMul2 [2]
                0.07    0.00 42949673/42949673     fxMul1 [3]
-----------------------------------------------
                0.10    0.00 42949673/42949673     main [1]
[2]     33.9    0.10    0.00 42949673         fxMul2 [2]
-----------------------------------------------
                0.07    0.00 42949673/42949673     main [1]
[3]     23.2    0.07    0.00 42949673         fxMul1 [3]
-----------------------------------------------


Index by function name

   [3] fxMul1                  [2] fxMul2                  [1] main
pcc001@git:~/pcc/lec10$
```

* 왜 mul1이 mul2보다 느릴까?
    * mul1에서는 오버플로우가 발생했지만 mul2에서는 long long으로 바꿨기 때문에 오버플로우가 발생하지 않는다.  

* 32bit 용으로 컴파일하면 더 빨라짐
    * 32bit integer 연산이 많다면 더 빨라진다.
    * 그리고 대부분 32bit integer 연산이다.

```bash
gprof -b
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 25.75      0.11     0.11 42949673     2.46     2.46  fxMul1
 25.75      0.21     0.11 42949673     2.46     2.46  fxMul2
 22.07      0.30     0.09                             __x86.get_pc_thunk.bx
 17.16      0.37     0.07                             main
  9.81      0.41     0.04                             __x86.get_pc_thunk.dx


			Call graph


granularity: each sample hit covers 2 byte(s) for 2.43% of 0.41 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     68.3    0.07    0.21                 main [1]
                0.11    0.00 42949673/42949673     fxMul1 [2]
                0.11    0.00 42949673/42949673     fxMul2 [3]
-----------------------------------------------
                0.11    0.00 42949673/42949673     main [1]
[2]     25.6    0.11    0.00 42949673         fxMul1 [2]
-----------------------------------------------
                0.11    0.00 42949673/42949673     main [1]
[3]     25.6    0.11    0.00 42949673         fxMul2 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]     22.0    0.09    0.00                 __x86.get_pc_thunk.bx [4]
-----------------------------------------------
                                                 <spontaneous>
[5]      9.8    0.04    0.00                 __x86.get_pc_thunk.dx [5]
-----------------------------------------------


Index by function name

   [4] __x86.get_pc_thunk.bx   [2] fxMul1                  [1] main
   [5] __x86.get_pc_thunk.dx   [3] fxMul2
```

* 위 결과로 같은 코드인데 32bit 컴파일하고 실행했더니 이 경우가 더 빨라진 것을 볼 수 있다.  

### `project - ARM Instruction set format`  

### `rgba.c`  

```c
#include <stdio.h>

typedef unsigned int t_rgba;

unsigned int fromRGBA(int r, int g, int b, int a)
{
        return (r<<24|g<<16|b<<8|a);
}

int main(){

        int red, green, blue, alpha;
        t_rgba rgba_1;
        // input value must be in 0~255
        // rgba_1 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]
        printf("Input 4 values with 0~255 ");
        scanf("%d %d %d %d", &red, &green, &blue, &alpha);
        rgba_1 = fromRGBA(red, green, blue, alpha);
        printf("%d %d %d %d : %d 0x08%x\n", red, green, blue, alpha, rgba_1, rgba_1);
}
```

```c
#include <stdio.h>

typedef unsigned int t_rgba;

unsigned int fromRGBA(int r, int g, int b, int a)
{
        //return (r<<24|g<<16|b<<8|a);
        return r*256*256*256 + g*256*256 + b*256 + a*1;
}

int main(){

        int red, green, blue, alpha;
        t_rgba rgba_1;
        // input value must be in 0~255
        // rgba_1 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]
        printf("Input 4 values with 0~255 ");
        scanf("%d %d %d %d", &red, &green, &blue, &alpha);
        rgba_1 = fromRGBA(red, green, blue, alpha);
        printf("%d %d %d %d : %u 0x08%x\n", red, green, blue, alpha, rgba_1, rgba_1);
}
```

```bash
$ a.out
Input 4 values with 0~255 255 255 255 255
255 255 255 255 : 4294967295 0xffffffff
```

* 컴퓨터는 2진수 체계

* chmod ### 은 8진수 체계 , 사용할 수 있는 수가 0~7이다.

```c
return (r<<24 + g<<16 + b<<8 + a);          //case 1
return (r<<24) + (g<<16) + (b<<8) + (a);    //case 2
```

**Q**) |를 +로 바꿔도 잘 계산될까?
> +가 <<<보다 우선순위가 높기 때문에 우선순위 때문에 의도한대로 출력되지 않는다.  
r<<< (24 + g) <<< (16 + b) <<< (8+a);로 계산된다.
따라서 두번째 case 처럼 괄호를 사용해야한다.

```c
#define fromRGBA(r, g, b, a) ((r&0xff)<<24)|((g&0xff)<<16)|((b&0xff)<<8)|(a&0xff)
#define fromRGBA(r, g, b, a) (((r)&0xff)<<24)|(((g)&0xff)<<16)|(((b)&0xff)<<8)|((a)&0xff)
```

* 첫번째 경우에서 꼭 변수에 독립적으로 괄호를 사용해야한다!

* r+3을 첫번째에 넣었다면 (r + 3 & 0xff )<<24 로 계산되었을 것이다.

* 따라서 두번째처럼 메크로 정의하면 사용 가능

* 곱셈보다 나눗셈이 4배정도 빠르다.  

* 따라서 아래 코드에서 나눗셈 대신에 역수 메크로를 정의해서 곱해줌

```c
#define FNUM_1_255      (1.0f/255.0f)

t_rgba mul_float(t_rgba c1, trgba c2){

        float r1, g1, b1, a1;
        float r2, g2, b2, a2;
        r1 = (float) (c1>>24) * F_NUM_1_255;;

}
```

***
