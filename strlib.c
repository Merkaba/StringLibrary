//use C99 mode in makefile
#include "strlib.h"


void *ics53_memchr(const void *str, int c, size_t n){
    char * result = str;
    for(int i = 0; i < n; i++){
        if(result[i] == c){
            return result += i;        
        }
    }
    return NULL;
}

int ics53_memcmp(const void *str1, const void *str2, size_t n){
    char * compare1 = str1, * compare2 = str2;
    for(int i = 0; i < n; i++){
        if(compare1[i] != compare2[i]){
            return compare1[i] > compare2[i] ? -1 : 1;
        }
    }
    return 0;
    
}

void *ics53_memcpy(void *dest, const void *src, size_t n){
    char * input = src, * output = dest;
    for(int i = 0; i < n; i++){
        output[i] = input[i];
    }
    return dest;
     
}   

char * copystr(void * input){
    char * copy = input;
    char result[ics53_strlen(copy) + 1];
    for(int i = 0; i < strlen(copy); i++){
        result[i] = copy[i];
    }
    return result;


}
void *ics53_memmove(void *dest, const void *src, size_t n){
    char * ret = copystr(src), *destination = dest;
    for(int i = 0; i < n; i++){
        destination[i] = ret[i];
    }
    return dest;
}   

void *ics53_memset(void *str, int c, size_t n){
    char * charstr = str;
    
    for(int i = 0; i < n; i++){
        charstr[i] = c;
    }
    return str;
}

char *ics53_strcat(char *dest, const char *src){
    return ics53_strncat(dest, src, ics53_strlen(src));
}

char *ics53_strncat(char *dest, const char *src, size_t n){
    int i;
    for(i = 0; i < ics53_strlen(src); i++){
        dest[ics53_strlen(dest) + i] = src[i];
    }
    dest[strlen(dest) + i] = '\0';
    return dest;
}

char *ics53_strchr(const char *str, int c){
    char* result = str;
    for(int i = 0; i < ics53_strlen(str);i++, result++){
        if(str[i] == c) return result;
    }
    return NULL;
}

int ics53_strcmp(const char *str1, const char *str2){
    for(int i = 0; i < ics53_strlen(str1); i++){
        if(str1[i] != str2[i]){
            return str1[i] > str2[i] ? -1 : 1;
        }
    }
    return 0;
    
}

int ics53_strncmp(const char *str1, const char *str2, size_t n){
    for(int i = 0; i < n; i++){
        if(str1[i] != str2[i]){
            return str1[i] > str2[i] ? -1 : 1;
        }
    }
    return 0;
}

int ics53_strcoll(const char *str1, const char *str2){
    return ics53_strcmp(str1, str2);
}

char *ics53_strcpy(char *dest, const char *src){
    return ics53_strncpy(dest, src, ics53_strlen(src));
}

char *ics53_strncpy(char *dest, const char *src, size_t n){
    int i;
    for( i = 0; i < n; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

size_t ics53_strcspn(const char *str1, const char *str2){ 
    char * result = str1;
    for(int i = 0; i < ics53_strlen(str1); i++){
        for(int j = 0; j < ics53_strlen(str2); j++){
            if(str1[i] == str2[j]) return i + 1;
        }
    }
    return 0;
}

char *ics53_strerror(int errnum){
    char * result = "string error: to be done";
    return result;
}

size_t ics53_strlen(const char *str){
    int counter = 0;
    while (str[counter] != '\0'){
        counter++;
    }
    return counter;
}

char *ics53_strpbrk(const char *str1, const char *str2){
    if(ics53_strcspn(str1, str2) == 0) return NULL;
    return str1 + ics53_strcspn(str1, str2) - 1;
}

char *ics53_strrchr(const char *str, int c){ 
    for(int i = ics53_strlen(str) - 1; i >= 0; i--){
        if(str[i] == c) return str + i;
    }
    return NULL;
}

int isInside(char * str1, char c){
    for(int i = 0; i < ics53_strlen(str1); i++){
        if(str1[i] == c) return 1;
    }
    return 0;

}
size_t ics53_strspn(const char *str1, const char *str2){
    int i = 0;
    for(; i < ics53_strlen(str1); i++){
        if(!isInside(str2, str1[i])) return i; 
    }
    return 0;
}

char *ics53_strstr(const char *haystack, const char *needle){
    char * result = haystack;
    for(int i = 0; i < ics53_strlen(haystack); i++){
        if(!ics53_strncmp(result + i, needle, ics53_strlen(needle))){return result + i;}
    }
    return NULL;
}

char *ics53_strtok(char *str, const char *delim){
    return NULL;
}

size_t ics53_strxfrm(char *dest, const char *src, size_t n){
    ics53_strncpy(dest, src, n);
    return ics53_strlen(src);
}
