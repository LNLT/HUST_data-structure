#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*----------预定义--------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2


typedef int status; //数据元素类型定义
typedef char ElemType;
typedef char kElemType;


typedef struct Node{//定义二叉树的结构类型
	ElemType data;
	char key;
	struct Node *lchild;
	struct Node *rchild;
}Tree;

status CreatBiTree(Tree **T,kElemType **definition);//创建
status DestroyBiTree(Tree **T);//销毁
status ClearBiTree(Tree **T);//清空
status BiTreeEmpty(Tree *T);//判断空表
status BiTreeDepth(Tree *T);//求二叉树深度
Tree *LocateNode(Tree *T,kElemType e); //查找结点
status Assign(Tree *T,kElemType e,ElemType value);//结点赋值
status parents(Tree *T,kElemType e);
status GetSibling(Tree *T,kElemType e);//获得兄弟结点
status InsertNode(Tree *T,kElemType e,int LR,Tree *c);//插入结点
status DeleteNode(Tree *T,kElemType e);//删除关键字为e的结点
status Delecel(Tree *T);//删除结点
status Delecer(Tree *T);//删除结点
status PreOrderTraverse(Tree *T);//前序遍历
status InOrderTraverse(Tree *T);//中序遍历
status PostOrderTraverse(Tree *T);//后序遍历
status LevelOrderTraverse(Tree *T);//按层遍历
status Write(Tree *T);
status TreeWrite(Tree *T,FILE *fp);
status Read(Tree **T);
status TreeRead(Tree **T,char *definition);

/*--------------------------------------------*/
int main(void){
    Tree *M[100];
    Tree *T;//声明所需变量
    Tree *p;
    Tree *c;
    int o,i,LR;
    ElemType value;
    kElemType e;
    char *definition;
    o=1;
    while(o){
        int op=1;
        printf("  请输入对哪个二叉树进行操作（1-99），输入0退出！\n");
        scanf("%d",&o);//多个线性表的实现
        if(o==0)
            break;//0时退出
        else {
            if(o>99||o<0){
                printf("选择失败！\n");
                getchar();
            }
            else {
                M[o]=NULL;
                T=M[o];
                while(op){
                    system("cls");	//printf("\n\n");
                    printf("  Menu for Linear Table On Sequence Structure \n");
                    printf("-----------------------------------------------\n");
                    printf("   1. CreatBiTree        9. InsertNode \n");
                    printf("   2. DestroyBiTree     10. DeleteNode\n");
                    printf("   3. ClearBiTree       11. PreOrderTraverse\n");
                    printf("   4. BiTreeEmpty       12. InOrderTraverse\n");
                    printf("   5. BiTreeDepth       13. PostOrderTraverse\n");
                    printf("   6. LocateNode        14. LevelOrderTraverse\n");
                    printf("   7. Assign            15. Write\n");
                    printf("   8. GetSibling        16. Read\n");
                    printf("   0. Exit\n");
                    printf("-----------------------------------------------\n");
                    printf("   请选择你的操作[0~16]:\n");
                    scanf("%d",&op);
                    switch(op){
                       case 1:
                         printf("请输入带空子树的二叉树前序遍历：");
                         getchar();
                         scanf("%[^\n]",definition);
                         T=(Tree *)malloc(sizeof(Tree));
                         T->rchild=NULL;
                         T->key=0;
                         if(CreatBiTree(&(T->lchild),&definition)==OK)
                            printf("二叉树创建成功！\n");
                         else
                            printf("二叉树创建失败！\n");
                         getchar();getchar();
                         break;
                       case 2:
                         if(DestroyBiTree(&T)==OK)
                            printf("二叉树销毁成功！\n");
                         else
                            printf("二叉树销毁失败！\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(T!=NULL){
                            ClearBiTree(&(T->lchild));
                            printf("清空二叉树！\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(T!=NULL){
                             if(BiTreeEmpty(T)==TRUE)
                                printf("二叉树为空！\n");
                             else
                                printf("二叉树不为空！\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 5:
                         if(T!=NULL){
                             i=BiTreeDepth(T->lchild);
                             printf("二叉树的深度为%d！\n",i);
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(T!=NULL){
                             printf("请输入查找的结点的关键字：\n");
                             getchar();
                             scanf("%c",&e);
                             p=LocateNode(T,e);
                             if(p!=NULL){
                                printf("该结点为：%c %c\n",p->key,p->data);
                             }
                             else
                                printf("该结点不存在\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(T!=NULL){
                             printf("请输入需要赋值的结点的关键字及所赋的值：\n");
                             getchar();
                             scanf("%c %c",&e,&value);
                             if(Assign(T,e,value)==OK)
                                printf("赋值成功\n");
                             else
                                printf("赋值失败\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(T!=NULL){
                             printf("请输入需要获得其兄弟结点的关键字：\n");
                             getchar();
                             scanf("%c",&e);
                             p=GetSibling(T->lchild,e);
                             if(p!=NULL)
                                printf("该元素的兄弟结点为%c %c",p->key,p->data);
                            else
                                printf("无兄弟结点\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(T!=NULL){
                             c=(Tree*)malloc(sizeof(Tree));
                             printf("请输入要插入的位置的关键字、左(0)还是右(1)、要插入结点的关键字、数据：\n");
                             getchar();
                             scanf("%c %d %c %c",&e,&LR,&(c->key),&(c->data));
                             if(InsertNode(T,e,LR,c)==OK)
                                printf("插入成功！\n");
                             else
                                printf("插入失败！\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(T!=NULL){
                             printf("请输入需要删除的结点的关键字：\n");
                             getchar();
                             scanf("%c",&e);
                             if(DeleteNode(T,e)==OK)
                                printf("删除成功！\n");
                             else
                                printf("删除失败！\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(T!=NULL){
                             printf("前序遍历：\n");
                             PreOrderTraverse(T->lchild);
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(T!=NULL){
                             printf("中序遍历：\n");
                             InOrderTraverse(T->lchild);
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(T!=NULL){
                             printf("后序遍历：\n");
                             PostOrderTraverse(T->lchild);
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(T!=NULL){
                             printf("按层遍历：\n");
                             LevelOrderTraverse(T->lchild);
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 15:
                         if(T!=NULL){
                             if(Wirte(T)==OK)
                                printf("写入成功！\n");
                             else
                                printf("写入失败！\n");
                         }
                         else
                            printf("二叉树不存在！\n");
                         getchar();getchar();
                         break;
                       case 16:
                         if(Read(&T)==OK)
                            printf("写入成功！\n");
                         else
                            printf("写入失败！\n");
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


status CreatBiTree(Tree **T,kElemType **definition){//创建二叉树，definition为数组
    if(**definition=='#'){//结点不存在
        (*T)=NULL;
        (*definition)++;
        return OK;
    }
    else{
        if(!((*T)=(Tree *)malloc(sizeof(Tree))))
           exit(OVERFLOW);
        else{
            (*T)->key=**definition;//赋关键字
            (*T)->data='x';
            (*definition)++;
            CreatBiTree(&((*T)->lchild),definition);
            CreatBiTree(&((*T)->rchild),definition);
        }
    }
    return OK;
}

status DestroyBiTree(Tree **T){//销毁二叉树T
    Tree *p=*T;
    ClearBiTree(T);
	free(p);
	(*T)=NULL;
	return OK;
}

status ClearBiTree(Tree **T){//将二叉树清空
	if((*T)==NULL)
        return OK;
	else{
        if((*T)->lchild!=NULL)
            ClearBiTree(&(*T)->lchild);
        if((*T)->rchild!=NULL)
        	ClearBiTree(&(*T)->rchild);
        free((*T));
        (*T)=NULL;
        return OK;
	}
}

status BiTreeEmpty(Tree *T){//判断T是否为空
    if(T->lchild==NULL)
        return TRUE;
    else
        return FALSE;
}

status BiTreeDepth(Tree *T){//计算T深度
    int depth,depthleft,depthright;
    if(T==NULL)
        depth=0;
    else{
        depthleft=BiTreeDepth(T->lchild);
        depthright=BiTreeDepth(T->rchild);
        depth=1+(depthleft>depthright?depthleft:depthright);
    }
    return depth;
}

Tree* LocateNode(Tree *T,kElemType e){//查找结点
    Tree *p;
    if(T==NULL)
    	return NULL;
    else if(T->key==e){
        return T;
    }
    else{
        p=LocateNode(T->lchild,e);
		if(p!=NULL)
            return p;
        else{
        	return LocateNode(T->rchild,e);
		}
    }
}

status Assign(Tree *T,kElemType e,ElemType value){//找到关键字为e的结点并赋值
    Tree *p;
    p=LocateNode(T,e);
    if(p!=NULL){
        p->data=value;
        return OK;
    }
    else
        return ERROR;
}

status parents(Tree *T,kElemType e){//寻找关键字为e的父母结点
    Tree *p;
    if(T==NULL)
    	return NULL;
    else if((T->lchild)&&(T->lchild->key==e)){
        return T;
    }
    else if ((T->rchild)&&(T->rchild->key==e)){
        return T;
    }
    else{
        p=parents(T->lchild,e);
		if(p!=NULL)
            return p;
        else{
        	return parents(T->rchild,e);
		}
    }
}

status GetSibling(Tree *T,kElemType e){//寻找关键字为e的兄弟结点
    Tree *p;
    p=parents(T->lchild,e);
    if(p){
        if((p->lchild)&&(p->lchild->key==e)){
            if(p->rchild)
                return p->rchild;
            else
                return NULL;
        }
        else {
            if((p->rchild)&&(p->rchild->key==e))
                if(p->lchild)
                    return p->lchild;
                else
                    return NULL;
        }
    }
}

status InsertNode(Tree *T,kElemType e,int LR,Tree *c){//在关键字为e的结点后插入结点
    if(T!=NULL){
        if(T->key==e){
            if(LR==0){
                c->lchild=T->lchild;
                c->rchild=NULL;
                T->lchild=c;
            }
            else{
                c->rchild=T->rchild;
                c->lchild=NULL;
                T->rchild=c;
            }
        }
        else{
            InsertNode(T->lchild,e,LR,c);
            InsertNode(T->rchild,e,LR,c);
        }
        return OK;
    }
}

status DeleteNode(Tree *T,kElemType e){//在删除关键字为e的结点
    if((T->lchild)&&(T->lchild->key==e)){
        Deletel(T);
        return OK;
    }
    else if((T->rchild)&&(T->rchild->key==e)){
        Deleter(T);
        return OK;
    }
    else{
        if(T->lchild)
            if(DeleteNode(T->lchild,e)==OK)
                return OK;
        if(T->rchild)
            if(DeleteNode(T->rchild,e)==OK)
                return OK;
    }
}

status Deletel(Tree *T){//删除结点
    Tree *p;
    Tree *q;
    Tree *t;
    q=T;
    p=T->lchild;
    t=p->lchild;
    if(p->lchild==NULL){
        if(p->rchild==NULL){//结点度为0
            T->lchild=NULL;
            return OK;
        }
        else{
            p=p->rchild;//结点度为1，有右子树
            q->lchild=p;
            return OK;
        }
    }
    else{
        if(p->rchild==NULL){//结点度为1，有左子树
            p=p->lchild;
            q->lchild=p;
            return OK;
        }
        else{//结点度为2
            while(t->rchild!=NULL)
                t=t->rchild;
            t->rchild=p->rchild;
            p=p->lchild;
            q->lchild=p;
            return OK;
        }
    }
}

status Deleter(Tree *T){//删除结点
    Tree *p;
    Tree *q;
    Tree *t;
    q=T;
    p=T->rchild;
    if(p->lchild==NULL){
        if(p->rchild==NULL){//结点度为0
            T->rchild=NULL;
            return OK;
        }
        else{
            p=p->rchild;//结点度为1，有右子树
            q->rchild=p;
            return OK;
        }
    }
    else{
        if(p->rchild==NULL){//结点度为1，有左子树
            p=p->lchild;
            q->rchild=p;
            return OK;
        }
        else{//结点度为2
            t=p->lchild;
            while(t->rchild!=NULL)
                t=t->rchild;
            t->rchild=p->rchild;
            p=p->lchild;
            q->rchild=p;
            return OK;
        }
    }
}

status PreOrderTraverse(Tree *T){
    if(T){
        printf("%c %c\n",T->key,T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}

status InOrderTraverse(Tree *T){
    Tree *st[100];
    int top=0;
    do{
        while(T){
            if(top==100)
                exit(OVERFLOW);
            st[++top]=T;
            T=T->lchild;
        }
        if(top){
            T=st[top--];
            printf("%c %c\n",T->key,T->data);
            T=T->rchild;
        }
    }while(top||T);
    return OK;
}

status PostOrderTraverse(Tree *T){
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c %c\n",T->key,T->data);
    }
    return OK;
}

status LevelOrderTraverse(Tree *T){
    Tree *que[100];
    Tree *p;
    int top=0;
    int base=0;
    if(T){
        que[top]=T;
        while(base<=top){
            p=que[base];
            printf("%c %c\n",p->key,p->data);
            if(p->lchild)
                que[++top]=p->lchild;
            if(p->rchild)
                que[++top]=p->rchild;
            base++;
        }
    }
}

status Wirte(Tree *T) {
    FILE *fp=NULL;
    char c='#';
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //写文件的方法
    TreeWrite(T->lchild,fp);//遍历二叉树,写入文件
    fclose(fp);
    return OK;
}

status TreeWrite(Tree *T,FILE *fp){
    char c=' ';
    if(T==NULL){
        fwrite(&c,sizeof(kElemType),1,fp);
        return;
    }
    else {
        fwrite(&(T->key),sizeof(kElemType),1,fp);
        fwrite(&(T->data),sizeof(kElemType),1,fp);
        TreeWrite(T->lchild,fp);
        TreeWrite(T->rchild,fp);
    }
}

int Arch;
status Read(Tree **T) {
    FILE  *fp;
    char tree[100];
    char single;
    int i=0;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    //读文件的方法
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    (*T)=(Tree *)malloc(sizeof(Tree));//构造头结点
    (*T)->rchild=NULL;
    (*T)->key=0;
    while(fread(&single,sizeof(ElemType),1,fp))
        tree[i++]=single;
    tree[i]='#';
    Arch=0;
    TreeRead(&((*T)->lchild),&tree);//这里从文件中逐个读取数据元素恢复二叉树
	fclose(fp);
    return OK;
}


status TreeRead(Tree **T,char *definition){//第一种写法 
    if(definition[Arch]=='#')
        return OK;
    if(definition[Arch]==' '){//结点不存在
        (*T)=NULL;
        Arch++;
    }
    else{
        if(!((*T)=(Tree *)malloc(sizeof(Tree))))
           exit(OVERFLOW);
        else{
            (*T)->key=definition[Arch];//赋关键字
            Arch++;
            (*T)->data=definition[Arch];
            Arch++;
            TreeRead(&((*T)->lchild),definition);
            TreeRead(&((*T)->rchild),definition);
        }
    }
    return OK;
}


/*第二种写法 
status TreeRead(Tree **T,char *definition){
   if(*definition=='#')
        return OK;
    if(*definition==' '){//结点不存在
        (*T)=NULL;
        definition++;
    }
    else{
        if(!((*T)=(Tree *)malloc(sizeof(Tree))))
           exit(OVERFLOW);
        else{
            (*T)->key=*definition;//赋关键字
            definition++;
            (*T)->data=**definition;
            definition++;
            TreeRead(&((*T)->lchild),definition);
            TreeRead(&((*T)->rchild),definition);
        }
    }
    return OK;
}
*/
