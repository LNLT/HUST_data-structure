/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define NO -1

typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //顺序表（顺序结构）的定义
	ElemType *elem;
	int length;
	int listsize;
}SqList;

/*-----page 19 on textbook ---------*/
status InitList(SqList *L);//创建
status DestroyList(SqList *L);//销毁
status ClearList(SqList *L);//清空
status ListEmpty(SqList L);//判断空表
status ListLength(SqList L);//求表长
status GetElem(SqList L,int i,ElemType *e);//获得元素
int LocateElem(SqList L,ElemType e); //查找元素
status PriorElem(SqList L,ElemType cur,ElemType *pre_e);//获得前驱
status NextElem(SqList L,ElemType cur,ElemType *next_e);//获得后驱
status ListInsert(SqList *L,int i,ElemType e);//插入
status ListDelete(SqList *L,int i,ElemType *e);//删除
status ListTrabverse(SqList L);  //遍历
status Wirte(SqList L);//写入文件
status Read(SqList *L);//读取文件

/*--------------------------------------------*/
int main(void){
    SqList M[100];  SqList L;//声明所需变量
    int t,i;
    ElemType p,cur;
    ElemType *pre_e,*next_e,*e;
    t=1;
    while(t){
        int op=1;
        printf("  请输入对哪个线性表进行操作（1-99），输入0退出！\n");
        scanf("%d",&t);//多个线性表的实现
        if(t==0)
            break;//0时退出
        else {
            if(t>99||t<0){
                printf("选择失败！\n");
                getchar();
            }
            else {
                M[t].elem=NULL;
                L=M[t];
                while(op){
                    system("cls");	//printf("\n\n");
                    printf("  Menu for Linear Table On Sequence Structure \n");
                    printf("-----------------------------------------------\n");
                    printf("   1. InitList        8. PriorElem \n");
                    printf("   2. DestroyList     9. NextElem\n");
                    printf("   3. ClearList      10. ListInsert\n");
                    printf("   4. ListEmpty      11. ListDelete\n");
                    printf("   5. ListLength     12. ListTrabverse\n");
                    printf("   6. GetElem        13. Write\n");
                    printf("   7. LocateElem     14. Read\n");
                    printf("   0. Exit\n");
                    printf("-----------------------------------------------\n");
                    printf("   请选择你的操作[0~14]:\n");
                    scanf("%d",&op);
                    switch(op){
                       case 1:
                         if(InitList(&L)==OK)
                            printf("线性表创建成功！\n");
                         else
                            printf("线性表创建失败！\n");
                         getchar();getchar();
                         break;
                       case 2:
                         if(DestroyList(&L)==OK)
                            printf("线性表销毁成功！\n");
                         else
                            printf("线性表销毁失败！\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(L.elem!=NULL){
                            ClearList(&L);
                            printf("清空线性表！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(L.elem!=NULL){
                             if(ListEmpty(L)==TRUE)
                                printf("线性表为空！\n");
                             else
                                printf("线性表不为空！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 5:
                         if(L.elem!=NULL){
                             ListLength(L);
                             printf("线性表的长度为%d！\n",L.length);
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(L.elem!=NULL){
                             printf("请输入想要获得元素的位置：\n");
                             scanf("%d",&i);
                             if(GetElem(L,i,&e)!=ERROR){
                                printf("第%d的元素为%d！\n",i,e);
                             }
                             else
                                printf("该位置不存在\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(L.elem!=NULL){
                             printf("请输入需要查找的元素：\n");
                             scanf("%d",&p);
                             if(LocateElem(L,p))
                                printf("第%d个元素与该元素相同\n",LocateElem(L,p));
                             else
                                printf("不存在相同的元素\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(L.elem!=NULL){
                             printf("请输入需要获得其前驱的元素：\n");
                             scanf("%d",&cur);
                             if(PriorElem(L,cur,&pre_e))
                                printf("该元素的前驱为%d",pre_e);
                             else
                                printf("操作失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(L.elem!=NULL){
                             printf("请输入需要获得其后继的元素：\n");
                             scanf("%d",&cur);
                             if(NextElem(L,cur,&next_e))
                                printf("该元素的后继为%d",next_e);
                             else
                                printf("操作失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(L.elem!=NULL){
                             printf("请依次输入：在第_个位置之前插入元素_\n");
                             scanf("%d",&i);
                             getchar();
                             scanf("%d",&p);
                             if(ListInsert(&L,i,p)==OK)
                                printf("插入成功！\n");
                             else
                                printf("插入失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(L.elem!=NULL){
                             printf("请依次输入：删除第_个位置的元素\n");
                             scanf("%d",&i);
                             if(ListDelete(&L,i,&e)==OK)
                             printf("删除成功！\n");
                             else
                                printf("删除失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(L.elem!=NULL){
                             if(ListTrabverse(L)==0)
                                printf("线性表是空表！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(L.elem!=NULL){
                             if(Wirte(L)==OK)
                                printf("写入成功！\n");
                             else
                                printf("写入失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(L.elem!=NULL){
                             if(Read(&L)==OK)
                                printf("读取成功！\n");
                             else
                                printf("读取失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 0:
                         break;
                     }
                }//end of switch
            }
        }
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()

status InitList(SqList *L){//构造一个空的顺序线性表L
	L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
	if(!L->elem)
        exit(OVERFLOW);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList *L){//销毁线性表L
    if(L->elem){
        free(L->elem);//释放线性表空间
        L->elem=NULL;
        L->length=0;
        L->listsize=0;
        return OK;
    }
    else
        return ERROR;
}

status ClearList(SqList *L){//将L置为空表
    if(L->elem!=NULL){
        L->length=0;
        return OK;
    }
    else
        printf("线性表不存在！\n");
        return NO;
}

status ListEmpty(SqList L){//判断L是否为空
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

status ListLength(SqList L){//计算L中元素个数
    return L.length;
}

status GetElem(SqList L,int i,ElemType *e){//用e返回第i个元素的值
    if(L.length==0||i<1||i>L.length)
        return ERROR;//顺序线性表为空或i的值不合法
    *e=L.elem[i-1];
    return OK;
}

int LocateElem(SqList L,ElemType e){//返回L中与e相等的元素的位序，无返回0
    int i;
    if(L.elem!=NULL){
        for(i=0;i<=(L.length-1);i++)
            if(L.elem[i]==e)
                return ++i;
        return ERROR;
    }
} //简化过

status PriorElem(SqList L,ElemType cur,ElemType *pre_e){//返回cur元素的前驱
    int i;
    i=LocateElem(L,cur);//找到cur的位置
    if(i==1||i==ERROR)
         return ERROR;
    else{
       *pre_e=L.elem[i-2];
        return OK;
    }
}

status NextElem(SqList L,ElemType cur,ElemType *next_e){//返回cur元素的后继
    int i;
    i=LocateElem(L,cur);
	if(i==L.length||i==ERROR)
        return ERROR;
    else{
        *next_e=L.elem[i];
        return OK;
    }
}

status ListInsert(SqList *L,int i,ElemType e){//在顺序线性表中第i个元素之前插入新的元素e，1<=i<=listlenth+1
    ElemType *newbase;
    ElemType *q,*p;
    ElemType t;
    if(i<1||(i>L->length+1))
        return ERROR;//i不合法
    if(L->length>=L->listsize){
        newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT) * sizeof(ElemType));//增加分配
        if(!newbase)
            exit(OVERFLOW);//存储分配失败
        L->elem=newbase;//新基址
        L->listsize+=LISTINCREMENT;
    }
    q=&(L->elem[i-1]);
    for(p=&(L->elem[L->length-1]);q<=p;p--)
        *(p+1)=*p;//插入位置及之后的元素右移
    L->elem[i-1]=e;
    ++(L->length);
    return OK;
}

status ListDelete(SqList *L,int i,ElemType *e){//在顺序线性表中删除第i个元素，并用e返回其值
    ElemType *q,*p;
    if(i<1||(i>L->length))
        return ERROR;//i不合法
    e=L->elem[i-1];//被删除元素值赋给e
    p=L->elem+L->length-1;//令p为表尾位置
    for(q=&(L->elem[i]);q<=p;q++)
        *(q-1)=*q;//被删元素之后的元素依次前移
    --(L->length);
    return OK;
}
status ListTrabverse(SqList L){//遍历表
    int i;
    printf("\n-----------all elements -----------------------\n");
    for(i=0;i<L.length;i++)
        printf("%d ",L.elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L.length;
}

status Wirte(SqList L) {
    FILE  *fp=NULL;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //写文件的方法
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    //这里是1次性写入，对于其它物理结构，
    //也可以先写入表长，再写入全部元素,这样读入会更方便
    fclose(fp);
    return OK;
}

status Read(SqList *L) {
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    //读文件的方法
    L->length=0;
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
    L->length++;
    //这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读取的数据元素恢复内存中的物理结构。
	fclose(fp);
    return OK;
}

