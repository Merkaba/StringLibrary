#include "strlib.h"
#include <stdio.h>
// #include <string.h>



int test_memchr(){
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = '.';
    char *ret = ics53_memchr(str, ch, ics53_strlen(str));
    if(ret != str + 10){ fprintf(stderr, "went bad on memchr 1\n"); return 0;}
    const char str2[] = "fffFfff";
    const char ch2 = 'F';
    ret = ics53_memchr(str2, ch2, ics53_strlen(str2));
    if(ret != str2 + 3){ fprintf(stderr, "went bad on memchr 2\n"); return 0;}
    const char str3[] = "its not here";
    const char ch3 = 'd';
    ret = ics53_memchr(str3, ch3, ics53_strlen(str3));
    if(ret != NULL){ fprintf(stderr, "went bad on memchr 3\n"); return 0;}
    return 1;
}

int test_memcmp(){
    char str[] = "hello", str2[] = "help!";
    if( ics53_memcmp(str, str2, strlen(str)) != 1 ){ fprintf(stderr, "went bad on memcmp 1\n"); return 0; }
    char str3[] = "hello", str4[] = "Hello";
    if( ics53_memcmp(str3, str4, strlen(str3)) != -1 ){ fprintf(stderr, "went bad on memcmp 2\n"); return 0; }
    char str5[] = "hello", str6[] = "hello";
    if( ics53_memcmp(str5, str6, strlen(str5)) != 0 ){ fprintf(stderr, "went bad on memcmp 3\n"); return 0; }

    return 1;

}

int test_memcpy(){
    char str[] = "hello", str2[] = "not hello";
    char * ret = ics53_memcpy(str2, str, strlen(str));
    if (ics53_memcmp(ret, "helloello", 9) != 0){ fprintf(stderr, "went bad on memcpy 1\n"); return 0;}
    char str3[] = "hello again", str4[] = "still not hello";
    ret = ics53_memcpy(str3, str4, 5);
    if (ics53_memcmp(ret, "still again", 10) != 0){ fprintf(stderr, "went bad on memcpy 2\n"); return 0;}
    char str5[] = "test hello", str6[] = "wont do hello";
    ret = ics53_memcpy(str5, str6, 10);
    if (ics53_memcmp(ret, "wont do he", 10) != 0){ fprintf(stderr, "went bad on memcpy2\n"); return 0;}
    return 1;
}

int test_memmove(){
    char str[] = "my grade is not good........";
    memmove(str+16, str+12, 8);
    if (strcmp(str, "my grade is not not good....") != 0) { fprintf(stderr, "went bad on memmove 1\n"); return 0;}
    memmove(str+12, str+10, 5);
    if (strcmp(str, "my grade is s notot good....") != 0) { fprintf(stderr, "went bad on memmove 2\n"); return 0;}
    memmove(str+5, str, 8);
    if (strcmp(str, "my grmy grade notot good....") != 0) { fprintf(stderr, "went bad on memmove 3\n"); return 0;}
    return 1;
}
int test_memset(){
    char str[50];
    ics53_memset(str, '$', 7);
    int i;
        
    for (i = 0; i < 7; i++)
        if (str[i] != '$'){
            fprintf(stderr, "went bad on memset 1\n"); return 0;
            }
    ics53_memset(str, 'F', 2);
    for(i = 0; i < 2; i++){
        if (str[i] != 'F'){ fprintf(stderr, "went bad on memset 2\n"); return 0;}
    }
    ics53_memset(str, 'L', 4);
    for(i = 0; i < 4; i++){
        if (str[i] != 'L'){ fprintf(stderr, "went bad on memset 3\n"); return 0;}
    }
    return 1;
}

int test_strcat(){
    char src[50], dest[50];
    ics53_strcpy(src,  "src");
    ics53_strcpy(dest,  "dest");
    ics53_strcat(dest, src);
    //printf("%s\n", dest);
    char res[] = "destsrc";
    int i;
    for (i = 0; res[i]; i++)
        if (res[i] != dest[i]){ fprintf(stderr, "went bad on strcat 1\n"); return 0;}
    ics53_strcat(dest, src);
    char res2[] = "destsrcsrc";
    for (i = 0; res2[i]; i++)
        if (res2[i] != dest[i]){ fprintf(stderr, "went bad on strcat 2\n"); return 0;} 
    ics53_strcat(dest, src);
    char res3[] = "destsrcsrcsrc";
    for (i = 0; res3[i]; i++)
        if (res3[i] != dest[i]){ fprintf(stderr, "went bad on strcat 3\n"); return 0;}

    return 1;
}

int test_strncat(){
    return test_strcat();//its the same one as strcat
}

int test_strchr(){
    char res[] = "aaxxxgfgkgggaaaagggggga";
    if (ics53_strchr(res, 'x') != (res + 2)){ fprintf(stderr, "went bad on strchr 1\n"); return 0;}
    if (ics53_strchr(res, 'a') != (res)){ fprintf(stderr, "went bad on strchr 2\n"); return 0;}
    if (ics53_strchr(res, 'z') != NULL){ fprintf(stderr, "went bad on strchr 3\n"); return 0;}
    return 1;
}

int test_strcmp(){
    char str[] = "hello", str2[] = "help!";
    if( ics53_strcmp(str, str2) != 1 ){ fprintf(stderr, "went bad on strcmp 1\n"); return 0; }
    char str3[] = "hello", str4[] = "Hello";
    if( ics53_strcmp(str3, str4) != -1 ){ fprintf(stderr, "went bad on strcmp 2\n"); return 0; }
    char str5[] = "hello", str6[] = "hello";
    if( ics53_strcmp(str5, str6) != 0 ){ fprintf(stderr, "went bad on strcmp 3\n"); return 0; }
    return 1;
}

int test_strncmp(){
    char str[] = "aaaab", str2[] = "aaaaa";
    if( ics53_strncmp(str, str2, 4) != 0){ fprintf(stderr, "went bad on strncmp 1\n"); return 0; }
    if( ics53_strncmp(str, str2, 5) != -1){ fprintf(stderr, "went bad on strncmp 2\n"); return 0; }
    char str3[] = "ABCD", str4[] = "abcd";
    if( ics53_strncmp(str3, str4, 3) != 1){ fprintf(stderr, "went bad on strncmp 3\n"); return 0; }
    return 1;
}

int test_strcoll(){
    return test_strncmp(); //both are the same in the code
}

int test_strncpy(){
    char str[] = "aaaaaa", str2[] = "bbbbbbb", str3[] = "cccccc";
    ics53_strncpy(str, str2, 4);
    if( ics53_strcmp(str, "bbbbaa") != 0){ fprintf(stderr, "went bad on strncpy 1\n"); return 0; }
    ics53_strncpy(str, str3, 2);
    if( ics53_strcmp(str, "ccbbaa") != 0){ fprintf(stderr, "went bad on strncpy 2\n"); return 0; }
    ics53_strncpy(str, str2, 1);
    if( ics53_strcmp(str, "bcbbaa") != 0){ fprintf(stderr, "went bad on strncpy 3\n"); return 0; }
    return 1;
}

int test_strcpy(){
    return test_strncpy();//both are the same in the code
}


int test_strcspn(){
    char str[] = "abcdeabcde", str2[] = "xyc", str3[] = "hge", str4[] = "eea";
    //printf("%d\n", ics53_strcspn(str, str3));
    if( ics53_strcspn(str, str2) != 3){ fprintf(stderr, "went bad on strcspn 1\n"); return 0; }
    if( ics53_strcspn(str, str3) != 5){ fprintf(stderr, "went bad on strcspn 2\n"); return 0; }
    if( ics53_strcspn(str, str4) != 1){ fprintf(stderr, "went bad on strcspn 3\n"); return 0; }
    return 1;

}

int test_strlen(){
    char str[] = "abc", str2[] = "", str3[] = "xyz123";
    if( ics53_strlen(str) != 3){ fprintf(stderr, "went bad on strlen 1\n"); return 0; }
    if( ics53_strlen(str2) != 0){ fprintf(stderr, "went bad on strlen 2\n"); return 0; }
    if( ics53_strlen(str3) != 6){ fprintf(stderr, "went bad on strlen 3\n"); return 0; }
    return 1;
}

int test_strpbrk(){
    char str[] = "abcdefghello", str2[] = "gfe", str3[] = "zxy", str4[] = "lak";
    //printf("%d %d\n", str, ics53_strpbrk(str, str2));
    if( ics53_strpbrk(str, str2) != str + 4){ fprintf(stderr, "went bad on strpbrk 1\n"); return 0; }
    if( ics53_strpbrk(str, str3) != NULL){ fprintf(stderr, "went bad on strpbrk 2\n"); return 0; }
    if( ics53_strpbrk(str, str4) != str){ fprintf(stderr, "went bad on strpbrk 3\n"); return 0; }
    return 1;
}

int test_strrchr(){
    char str[] = "abcdedcba";
    if( ics53_strrchr(str, 'e') != str + 4){ fprintf(stderr, "went bad on strrchr 1\n"); return 0; }
    if( ics53_strrchr(str, 'a') != str + 8){ fprintf(stderr, "went bad on strrchr 2\n"); return 0; }
    if( ics53_strrchr(str, 'c') != str + 6){ fprintf(stderr, "went bad on strrchr 3\n"); return 0; }
    return 1;
}

int test_strspn(){
    char str1[] = "ABCDEFGHIJKLMNOP", str2[] = "ABC", str3[] = "ABcde", str4[] = "EDCBA";
    //printf("%d\n", ics53_strspn(str1, str2));
    if( ics53_strspn(str1, str2) != 3){ fprintf(stderr, "went bad on strspn 1\n"); return 0; }
    if( ics53_strspn(str1, str3) != 2){ fprintf(stderr, "went bad on strspn 2\n"); return 0; }
    if( ics53_strspn(str1, str4) != 5){ fprintf(stderr, "went bad on strspn 3\n"); return 0; }
    return 1;
}

int test_strstr(){
    char haystack[] = "hello bob book", needle1[] = "hello", needle2[] = "bob", needle3[] = "book";
    if( ics53_strstr(haystack, needle1) != haystack + 0){ fprintf(stderr, "went bad on strstr 1\n"); return 0; }
    //printf("%d %d", haystack, ics53_strstr(haystack, needle3));
    if( ics53_strstr(haystack, needle2) != haystack + 6){ fprintf(stderr, "went bad on strstr 2\n"); return 0; }
    if( ics53_strstr(haystack, needle3) != haystack + 10){ fprintf(stderr, "went bad on strstr 3\n"); return 0; }
    return 1;

}

int test_strxfrm(){
    return test_strncpy();//same as previous code
}


int test(){
    int score = 100;
    if (!test_memchr())
        score -= 5;
    if (!test_memcmp())
        score -= 5;
    if (!test_memcpy())
        score -= 5;
    if (!test_memmove())
        score -= 5;
    if (!test_memset())
        score -= 5;
    if (!test_strcat())
        score -= 5;
    if (!test_strncat())
        score -= 5;
    if (!test_strchr())
        score -= 5;
    if (!test_strcmp())
        score -= 5;
    if (!test_strncmp())
        score -= 5;
    if (!test_strcoll())
        score -= 5;
    if (!test_strcpy())
        score -= 5;
    if (!test_strncpy())
        score -= 5;
    if (!test_strcspn())
        score -= 5;
    if (!test_strlen())
        score -= 5;
    if (!test_strpbrk())
        score -= 5;
    if (!test_strrchr())
        score -= 5;
    if (!test_strspn())
        score -= 5;
    if (!test_strstr())
        score -= 5;
    if (!test_strxfrm())
        score -= 5;
    // other test cases omitted
    return score;
}


int main(void){
    printf("score is %d\n", test());
    exit(1);
    return 0;
}
