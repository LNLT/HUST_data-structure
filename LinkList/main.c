#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*----------预定义--------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define NO -1

typedef int status;
typedef int ElemType; //数据元素类型定义

typedef struct LNode{  //链式表（链式结构）的定义
	ElemType data;
	struct LNode *next;
}LinkList;

/*-----page 19 on textbook ---------*/
status InitList(LinkList **L);//创建
status DestroyList(LinkList **L);//销毁
status ClearList(LinkList *L);//清空
status ListEmpty(LinkList *L);//判断空表
status ListLength(LinkList *L);//求表长
status GetElem(LinkList *L,int i,ElemType *e);//获得元素
int LocateElem(LinkList *L,ElemType e); //查找元素
status PriorElem(LinkList *L,ElemType cur,ElemType *pre_e);//获得前驱
status NextElem(LinkList *L,ElemType cur,ElemType *next_e);//获得后驱
status ListInsert(LinkList *L,int i,ElemType e);//插入
status ListDelete(LinkList *L,int i,ElemType *e);//删除
status ListTrabverse(LinkList *L);  //遍历
status Wirte(LinkList *L);//写入文件
status Read(LinkList **L);//读取文件

/*--------------------------------------------*/
int main(void){
    LinkList *M[100];  LinkList *L;//声明所需变量
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
                M[t]=NULL;
                L=M[t];
                while(op){
                    system("cls");	//菜单目录;
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
                    switch(op){//进入switch选择 
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
                         if(L!=NULL){
                            ClearList(L);
                            printf("清空线性表！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(L!=NULL){
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
                         if(L!=NULL){
                             i=ListLength(L);
                             printf("线性表的长度为%d！\n",i);
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(L!=NULL){
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
                         if(L!=NULL){
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
                         if(L!=NULL){
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
                         if(L!=NULL){
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
                         if(L!=NULL){
                             printf("请依次输入：在第_个位置之前插入元素_\n");
                             scanf("%d",&i);
                             getchar();
                             scanf("%d",&p);
                             if(ListInsert(L,i,p)==OK)
                                printf("插入成功！\n");
                             else
                                printf("插入失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(L!=NULL){
                             printf("请依次输入：删除第_个位置的元素\n");
                             scanf("%d",&i);
                             if(ListDelete(L,i,&e)==OK)
                             printf("删除成功！\n");
                             else
                                printf("删除失败！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(L!=NULL){
                             if(ListTrabverse(L)==0)
                                printf("线性表是空表！\n");
                         }
                         else
                            printf("线性表不存在！\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(L!=NULL){
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
                         if(L!=NULL){
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

status InitList(LinkList **L){//构造一个线性表L
	*L = (LinkList*)malloc(sizeof(LinkList)); //创建一个头结点
    LinkList *p=*L;
    p->next=NULL;
	return OK;
}

status DestroyList(LinkList **L){//销毁线性表L
    LinkList *p=*L;
    LinkList *q;
    if(p){
        for(;p!=NULL;){//遍历单链表
            q=p;
            p=p->next;
            free(q);//释放线性表空间
        }
        p=NULL;
        *L=p;
        return OK;
    }
    else
        return ERROR;
}

status ClearList(LinkList *L){//将L置为空表
    LinkList *p;
    LinkList *q;
    if(L!=NULL){
        for(p=L->next;p!=NULL;){//遍历单链表
            q=p;
            p=p->next;
            free(q);//释放线性表空间
        }
        L->next=NULL;//将头节点置为空
        return OK;
    }
    else
        printf("线性表不存在！\n");
        return NO;
}

status ListEmpty(LinkList *L){//判断L是否为空
    if(L->next==NULL)
        return TRUE;
    else
        return FALSE;
}

status ListLength(LinkList *L){//计算L中元素个数
    int i;
    LinkList *p=L->next;
    for(i=0;p!=NULL;i++)//遍历单链表，计数
        p=p->next;
    return i;
}

status GetElem(LinkList *L,int i,ElemType *e){//用e返回第i个元素的值
    int j;
    if(i<1||i>ListLength(L))
        return ERROR;//链式线性表为空或i的值不合法
    LinkList *p=L->next;//p指向首结点
    for(j=1;j<i;j++)//遍历到第i位
        p=p->next;
    *e=p->data;
    return OK;
}

int LocateElem(LinkList *L,ElemType e){//返回L中与e相等的元素的位序，无返回0
    int i;
    LinkList *p=L->next;//p指向首结点
    for(i=1;p!=NULL;i++){//遍历单链表，查找是否有相同元素
        if(p->data==e)
            return i;
        else
            p=p->next;
    }
    return ERROR;
}

status PriorElem(LinkList *L,ElemType cur,ElemType *pre_e){//返回cur元素的前驱
    int i;
    LinkList *p=L;//p指向头结点
    LinkList *q=p->next;//q指向首结点
    if(LocateElem(L,cur)==1||LocateElem(L,cur)==ERROR)//遍历单链表，查找是否有相同元素并判断位置合法
        return ERROR;
    else{
        for(;q!=NULL;){//遍历到相同元素的前一个结点
            if(q->data==cur){
                *pre_e=p->data;
                return OK;
            }
            else{
                p=q;
                q=q->next;
            }
        }
        return ERROR;
    }
}

status NextElem(LinkList *L,ElemType cur,ElemType *next_e){//返回cur元素的后继
    int i;
    LinkList *p=L->next;//p指向首结点
    if(LocateElem(L,cur)==ListLength(L)||LocateElem(L,cur)==ERROR)//遍历单链表，查找是否有相同元素并判断位置合法
        return ERROR;
    else{
        for(;p!=NULL;){//遍历到相同元素的位置
            if(p->data==cur){
                *next_e=p->next->data;
                return OK;
            }
            else
                p=p->next;
        }
        return ERROR;
    }
}

status ListInsert(LinkList *L,int i,ElemType e){//在链式线性表中第i个元素之前插入新的元素e
    int j;
    LinkList *t;//定义新的结点并分配空间
    t=(LinkList*)malloc(sizeof(LinkList));
    t->data=e;//将新的元素值赋给新结点
    LinkList *p=L;
    LinkList *q=L->next;
    if(i>ListLength(L)+1||i<1)//判断i是否合法
        return ERROR;
    else{
        for(j=1;j<i;j++){//遍历到i-1位
            p=q;
            q=q->next;
        }
        t->next=p->next;
        p->next=t;
    }
    return OK;
}

status ListDelete(LinkList *L,int i,ElemType *e){//在链式线性表中删除第i个元素，并用e返回其值
    int j;
    LinkList *p=L;
    LinkList *q=L->next;
    if(i>ListLength(L)||i<1)//判断i是否合法
        return ERROR;
    else{
        for(j=1;j<i;j++){//遍历到i-1位
            p=q;
            q=q->next;
        }
        p->next=q->next;
        free(q);
    }
    return OK;
}
status ListTrabverse(LinkList *L){//遍历表
    LinkList *p=L->next;//p指向首结点
    printf("\n-----------all elements -----------------------\n");
    for(;p!=NULL;){//遍历单链表
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n------------------ end ------------------------\n");
    return OK;
}

status Wirte(LinkList *L) {
    FILE  *fp=NULL;
    char filename[30];
    LinkList *p=L->next;
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //写文件的方法
    for(;p!=NULL;){//遍历单链表,写入文件
        fwrite(&(p->data),sizeof(ElemType),1,fp);
        p=p->next;
    }
    fclose(fp);
    return OK;
}

status Read(LinkList **L) {
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    //读文件的方法
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    LinkList *t=*L;
    LinkList *p,*q;
    p=(LinkList*)malloc(sizeof(LinkList));
    q=(LinkList*)malloc(sizeof(LinkList));//为指针分配空间
    t->next=q;//q为首结点
    while(fread(&(q->data),sizeof(ElemType),1,fp)){//从文件中读取数据到单链表中
        p->next=q;
        q->next=NULL;
        p=p->next;
        q=(LinkList*)malloc(sizeof(LinkList));
    }//这里从文件中逐个读取数据元素恢复链式表
	free(q);//释放指针q
	fclose(fp);
    return OK;
}
