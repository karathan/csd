   0x8048aac <readString>:      push   %ebp
   0x8048aad <readString+1>:    mov    %esp,%ebp
   0x8048aaf <readString+3>:    sub    $0x34,%esp    #char Name[BUFSIZE];
   0x8048ab2 <readString+6>:    movl   $0x0,-0x4(%ebp)        # int i = 0;
   0x8048ab9 <readString+13>:   mov    0x80d4b44,%eax         
   0x8048abe <readString+18>:   push   %eax
   0x8048abf <readString+19>:   call   0x8050850 <getc>        #c = fgetc(stdin);
   0x8048ac4 <readString+24>:   add    $0x4,%esp
   0x8048ac7 <readString+27>:   mov    %eax,-0x8(%ebp)          
   0x8048aca <readString+30>:   cmpl   $0xffffffff,-0x8(%ebp)  #if ((c == EOF)
   0x8048ace <readString+34>:   je     0x8048ae8 <readString+60>  #break;
   0x8048ad0 <readString+36>:   cmpl   $0xa,-0x8(%ebp)         #if (c == '\n')
   0x8048ad4 <readString+40>:   je     0x8048ae8 <readString+60>  
   0x8048ad6 <readString+42>:   mov    -0x4(%ebp),%eax   
   0x8048ad9 <readString+45>:   lea    0x1(%eax),%edx   
   0x8048adc <readString+48>:   mov    %edx,-0x4(%ebp)
   0x8048adf <readString+51>:   mov    -0x8(%ebp),%edx
   0x8048ae2 <readString+54>:   mov    %dl,-0x34(%ebp,%eax,1)
   0x8048ae6 <readString+58>:   jmp    0x8048ab9 <readString+13>
   0x8048ae8 <readString+60>:   lea    -0x34(%ebp),%edx
   0x8048aeb <readString+63>:   mov    -0x4(%ebp),%eax
   0x8048aee <readString+66>:   add    %edx,%eax
   0x8048af0 <readString+68>:   movb   $0x0,(%eax)


   0x8048af3 <readString+71>:   movl   $0x0,-0x4(%ebp)
   0x8048afa <readString+78>:   jmp    0x8048b15 <readString+105>
   0x8048afc <readString+80>:   mov    -0x4(%ebp),%edx
   0x8048aff <readString+83>:   mov    0x8(%ebp),%eax
   0x8048b02 <readString+86>:   add    %eax,%edx
   0x8048b04 <readString+88>:   lea    -0x34(%ebp),%ecx
   0x8048b07 <readString+91>:   mov    -0x4(%ebp),%eax
   0x8048b0a <readString+94>:   add    %ecx,%eax
   0x8048b0c <readString+96>:   movzbl (%eax),%eax
   0x8048b0f <readString+99>:   mov    %al,(%edx)
   0x8048b11 <readString+101>:  addl   $0x1,-0x4(%ebp)
   0x8048b15 <readString+105>:  cmpl   $0x2b,-0x4(%ebp)
   0x8048b19 <readString+109>:  jle    0x8048afc <readString+80>
   0x8048b1b <readString+111>:  nop
   0x8048b1c <readString+112>:  leave
   0x8048b1d <readString+113>:  ret
   0x8048b1e <main>:    push   %ebp
   0x8048b1f <main+1>:  mov    %esp,%ebp
   0x8048b21 <main+3>:  mov    $0x80d65e0,%eax
   0x8048b26 <main+8>:  and    $0xfffff000,%eax
   0x8048b2b <main+13>: push   $0x7
   0x8048b2d <main+15>: push   $0x1
   0x8048b2f <main+17>: push   %eax


   0x8048b30 <main+18>: call   0x805e180 <mprotect>
   0x8048b35 <main+23>: add    $0xc,%esp
   0x8048b38 <main+26>: push   $0x80ab0a8
   0x8048b3d <main+31>: call   0x804f070 <puts>
   0x8048b42 <main+36>: add    $0x4,%esp
   0x8048b45 <main+39>: push   $0x80d65e0
   0x8048b4a <main+44>: call   0x8048aac <readString>
   0x8048b4f <main+49>: add    $0x4,%esp
   0x8048b52 <main+52>: push   $0x80ab0bb
   0x8048b57 <main+57>: push   $0x80d65e0
   0x8048b5c <main+62>: call   0x805af90 <strcmp>
   0x8048b61 <main+67>: add    $0x8,%esp
   0x8048b64 <main+70>: test   %eax,%eax
   0x8048b66 <main+72>: jne    0x8048b6f <main+81>
   0x8048b68 <main+74>: movb   $0x36,0x80d46e8
   0x8048b6f <main+81>: push   $0x80d65e0
   0x8048b74 <main+86>: push   $0x80ab0c9
   0x8048b79 <main+91>: call   0x804eaf0 <printf>
   0x8048b7e <main+96>: add    $0x8,%esp
   0x8048b81 <main+99>: movzbl 0x80d46e8,%eax
   0x8048b88 <main+106>:        movsbl %al,%eax
   0x8048b8b <main+109>:        push   %eax
   0x8048b8c <main+110>:        push   $0x80ab0dc


   0x8048b91 <main+115>:        call   0x804eaf0 <printf>
   0x8048b96 <main+120>:        add    $0x8,%esp
   0x8048b99 <main+123>:        push   $0x0
   0x8048b9b <main+125>:        call   0x804e110 <exit>
   0x8048ba0 <__libc_start_main>:       push   %ebp
   0x8048ba1 <__libc_start_main+1>:     mov    $0x0,%eax
   0x8048ba6 <__libc_start_main+6>:     push   %edi
   0x8048ba7 <__libc_start_main+7>:     push   %esi
   0x8048ba8 <__libc_start_main+8>:     push   %ebx
   0x8048ba9 <__libc_start_main+9>:     sub    $0x4c,%esp


data section:  0x80d46e8 <grade> "3"
               51 '3'

bss section:  (char (*)[44]) 0x80d65e0 <Name>
 