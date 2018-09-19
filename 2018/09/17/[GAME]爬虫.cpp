#include <stdio.h>
#include <windows.h>
#include <conio.h>
#ifdef URLDownloadToFile
#undef URLDownloadToFile
#endif
typedef int(__stdcall *UDF)(LPVOID,LPCSTR,LPCSTR,DWORD,LPVOID);
UDF URLDownloadToFile = (UDF)GetProcAddress(LoadLibrary("urlmon.dll"),"URLDownloadToFileA");
char* strfind(char *text,char *temp) {
    int i = -1,j,l = strlen(temp);

    while(text[++i]) {
        for(j=0; j<l; j++)if(text[i+j] == 0 || text[i+j] != temp[j])break;

        if(j == l)return text+i+l;
    }

    return 0;
}
void UTF8ToANSI(char *str) {
    int len = MultiByteToWideChar(CP_UTF8,0,str,-1,0,0);
    WCHAR *wsz = new WCHAR[len+1];
    len = MultiByteToWideChar(CP_UTF8,0,str,-1,wsz,len);
    wsz[len] = 0;
    len = WideCharToMultiByte(CP_ACP,0,wsz,-1,0,0,0,0);
    len = WideCharToMultiByte(CP_ACP,0,wsz,-1,str,len,0,0);
    str[len] = 0;
    delete []wsz;
}
HANDLE hOutput;
char name[32];
int count[8];
void problem(char *str) {
    int i = 0,len;
    DWORD unused;
    char prob[32],url[128],*file,*ptr;
    HANDLE hFile;
    COORD pos = {0,2};

    while(*str != '<')prob[i++] = *str++;

    prob[i] = 0;
    sprintf(url,"https://www.luogu.org/problemnew/show/%s",prob);
    URLDownloadToFile(0,url,"download.tmp",0,0);
    hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    len = GetFileSize(hFile,0);
    file = ptr = new char[len+3];
    ReadFile(hFile,file,len,&unused,0);
    file[len] = file[len+1] = 0;
    CloseHandle(hFile);
    file = strfind(file,"\xE9\x9A\xBE\xE5\xBA\xA6");

    if(file == 0) {
        delete []ptr;
        return;
    }

    file = strfind(file,"lg-bg-");

    if(file[0] == 'r')count[0]++;
    else if(file[0] == 'o')count[1]++;
    else if(file[0] == 'y')count[2]++;
    else if(file[0] == 'g' && file[2] == 'e')count[3]++;
    else if(file[0] == 'b' && file[4] == 'l')count[4]++;
    else if(file[0] == 'p')count[5]++;
    else if(file[0] == 'b' && file[4] == 'd')count[6]++;
    else if(file[0] == 'g' && file[2] == 'a')count[7]++;

    delete []ptr;
    SetConsoleCursorPosition(hOutput,pos);
    printf(
        "%s 的统计:    %s        \n"
        "入门难度:       %d\n"
        "普及-:          %d\n"
        "普及/提高-:     %d\n"
        "普及+/提高:     %d\n"
        "提高+/省选-:    %d\n"
        "省选/NOI-:      %d\n"
        "NOI/NOI+/CTSC:  %d\n"
        "尚无评定:       %d\n",name,prob,count[0],count[1],count[2],count[3],
        count[4],count[5],count[6],count[7]);
}
int main() {
    int uid,len,i = 0;
    DWORD unused;
    char url[128],user[16],*file,*ptr;
    HANDLE hFile;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("请输入你的洛谷UID: ");
    scanf("%d",&uid);
    sprintf(url,"https://www.luogu.org/space/show?uid=%d",uid);
    URLDownloadToFile(0,url,"download.tmp",0,0);
    hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    len = GetFileSize(hFile,0);
    file = new char[len+3];
    ReadFile(hFile,file,len,&unused,0);
    file[len] = file[len+1] = 0;
    CloseHandle(hFile);
    UTF8ToANSI(file);
    sprintf(user,"U%d ",uid);
    ptr = strfind(file,user);

    if(ptr) {
        while(ptr[0] != '<' || ptr[1] != '/' || ptr[2] != 'h')name[i++] = *ptr++;

        printf("\n%s 的统计: ",name);
        ptr = strfind(file,"通过题目</h2>\n[<");

        if(ptr)while(*ptr != '<') {
                ptr = strfind(ptr,"\">");
                problem(ptr);
                ptr = strfind(ptr,"]\n");
            } else printf("还没有通过任何题目\n");
    } else printf("用户不存在\n");

    DeleteFile("download.tmp");
    delete []file;
    printf("\nPress any key to exit. . .");
    getch();
    return 0;
}
