#ifndef NULL
    #define NULL ((void*)0)
#endif
#ifndef size_t
    #define size_t long unsigned int
#endif
#define Null 0

void *memchr(const void *str, int c, size_t n) {
    char *s=(char*)str;
    for(size_t i=0;i<n;i++) {
        if(s[i]==c)
            return (void*)(s+i);
    }
    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) {
    char *s1=(char*)str1;
    char *s2=(char*)str2;
    for(size_t i=0;i<n;i++) {
        if(s1[i]!=s2[i])
            return (s1[i]-s2[i]);
    }
    return 0;
}

void *memcpy(void *dest, const void * src, size_t n) {
    char *s=(char*)src;
    char *d=(char*)dest;
    for(size_t i=0;i<n;i++)
        d[i]=s[i];
    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    char *s=(char*)src;
    char *d=(char*)dest;
    size_t l=0, di=d-s, i;
    if(di<n)
        l=n-di;
    char e[l];
    for(i=0;i<l;i++)
        e[i]=d[i];
    for(i=0;i<di&&i<n;i++)
        d[i]=s[i];
    for(;i<n;i++)
        d[i]=e[i];
    return dest;
}

void *memset(void *str, int c, size_t n) {
    char *s=(char*)str;
    for(size_t i=0;i<n;i++)
        s[i]=c;
    return str;
}

size_t strlen(const char* str) {
    size_t i=0;
    while(str[i++]!=Null);
    return (i-1);
}

char *strcat(char *dest, const char *src) {
    for(size_t l=strlen(dest), i=0;(dest[l]=src[i])!=Null;i++,l++);
    return dest;
}

char *strncat(char *dest, const char *src, size_t n) {
    size_t l, i;
    for(l=strlen(dest), i=0;i<n&&(dest[l]=src[i])!=Null;i++,l++);
    dest[l]=Null;
    return dest;
}

char *strchr(const char *str, int c) {
    char *s=(char*)str;
    while(*s!=c&&*s++!=Null);
    if(*s==c)
        return s;
    return NULL;
}

int strcmp(const char *str1, const char *str2) {
    size_t i;
    for(i=0;str1[i]==str2[i];i++)
        if(str1[i]==Null)
            return 0;
    return str1[i]-str2[i];
}

int strncmp(const char *str1, const char *str2, size_t n) {
    size_t i;
    for(i=0;str1[i]==str2[i]&&i<n;)
        if(str1[i]==Null||++i==n)
            return 0;
    return str1[i]-str2[i];
}

int strcoll(const char *str1, const char *str2) {
    /* LC_COLLATE is unimplemented, hence always "C" */
    return strcmp(str1,str2);
}

char *strcpy(char *dest, const char *src) {
    for(size_t i=0;(dest[i]=src[i])!=Null;i++);
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for(i=0;i<n&&(dest[i]=src[i])!=Null;i++);
    for(;i<=n;i++)
        dest[i]=Null;
}

size_t strcspn(const char *str1, const char *str2) {
    size_t i, j;
    for(i=0;str1[i]!=Null;i++)
        for(j=0;str2[j]!=Null;j++)
            if(str1[i]==str2[j])
                return i;
    return i;
}

char *strpbrk(const char *str1, const char *str2) {
    size_t i, j;
    for(i=0;str1[i]!=Null;i++)
        for(j=0;str2[j]!=Null;j++)
            if(str1[i]==str2[j])
                return (void*)str1+i;
    return NULL;
}

char *strrchr(const char *str, int c) {
    char* r=NULL;
    for(size_t i=0;str[i]!=Null;i++)
        if(str[i]==c)
            r=(char*)str+i;
    return r;
}

size_t strspn(const char *str1, const char *str2) {
    size_t i, j;
    for(i=0;str1[i]!=Null;i++) {
        for(j=0;str2[j]!=Null;j++)
            if(str1[i]==str2[j])
                break;
        if(str2[j]==Null)
            break;
    }
    return i;
}

char *strstr(const char *haystack, const char *needle) {
    size_t i, j;
    size_t hay=strlen(haystack), need=strlen(needle);
    for(i=0;i+need<=hay;i++) {
        for(j=0;j<need;j++)
            if(haystack[i+j]!=needle[j])
                break;
        if(needle[j]==Null)
            return (void*)haystack+i;
    }
    return NULL;
}

char *strtok(char *str, const char *delim) {
    static char*s=NULL;
    if(str==NULL) {
        if(s==NULL)
            return NULL;
    }
    else
        s=str-1;
    size_t j;
    char* c=++s;
    while(*s!=Null) {
        for(j=0;delim[j]!=Null;j++) {
            if(*s==delim[j]) {
                *s=Null;
                return c;
            }
        }
        s++;
    }
    s=NULL;
    return c;
}

size_t strxfrm(char *dest, const char *src, size_t n) {
    size_t i;
    for(i=0;i<n&&(dest[i]=src[i])!=Null;i++);
    for(;src[i]!=Null;i++);
    return i;
}

char* strreverse(char* str) {
    size_t i, j, len=strlen(str);
    int c;
    for(i=0,j=len-1;i<j;i++,j--) {
        c=str[i];
        str[i]=str[j];
        str[j]=c;
    }
    return str;
}