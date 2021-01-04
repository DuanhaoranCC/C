# 心得体会

* float类型会有误差，比如12.00，他会变成12.0000002，所以向下取整一般为floor(x+0.5);

* 谨防注意char型数据类型，不管是数组还是单量；

* 灵活运用**常量数组**，会使程序变得更加简洁，Smart Power；

* cctype库函数中的**isdigit，isalpha，toupper**，ccstring中的**memset，strlen，strchr(return char*)**熟记；

* getchar，fgetc返回值都为int，EOF；

* sprintf，freopen文件重定向

~~~
    char s[] = "qwertyuiop";
    s[1] = toupper(s[1])
    
    const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    const char* msg[] = {"not a palindrom", "a regular palindrom",
                     "a mirrored string", "a mirrored palindrom"};
    
    int c;
    freopen("E:\\C1/272.txt", "r", stdin);
    *//*while ((c = fgetc(stdin)) != EOF){
        printf("%c", c);
    }*//*
    if (stdin == NULL){
        perror("发生错误");
        return -1;
    }
    while (1){
        c = fgetc(stdin);
        if (feof(stdin))
            break;
        printf("%c", c);
    }
    
    sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
~~~
