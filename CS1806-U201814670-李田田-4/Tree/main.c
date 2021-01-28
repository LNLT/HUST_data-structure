#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*----------Ԥ����--------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2


typedef int status; //����Ԫ�����Ͷ���
typedef char ElemType;
typedef char kElemType;


typedef struct Node{//����������Ľṹ����
	ElemType data;
	char key;
	struct Node *lchild;
	struct Node *rchild;
}Tree;

status CreatBiTree(Tree **T,kElemType **definition);//����
status DestroyBiTree(Tree **T);//����
status ClearBiTree(Tree **T);//���
status BiTreeEmpty(Tree *T);//�жϿձ�
status BiTreeDepth(Tree *T);//����������
Tree *LocateNode(Tree *T,kElemType e); //���ҽ��
status Assign(Tree *T,kElemType e,ElemType value);//��㸳ֵ
status parents(Tree *T,kElemType e);
status GetSibling(Tree *T,kElemType e);//����ֵܽ��
status InsertNode(Tree *T,kElemType e,int LR,Tree *c);//������
status DeleteNode(Tree *T,kElemType e);//ɾ���ؼ���Ϊe�Ľ��
status Delecel(Tree *T);//ɾ�����
status Delecer(Tree *T);//ɾ�����
status PreOrderTraverse(Tree *T);//ǰ�����
status InOrderTraverse(Tree *T);//�������
status PostOrderTraverse(Tree *T);//�������
status LevelOrderTraverse(Tree *T);//�������
status Write(Tree *T);
status TreeWrite(Tree *T,FILE *fp);
status Read(Tree **T);
status TreeRead(Tree **T,char *definition);

/*--------------------------------------------*/
int main(void){
    Tree *M[100];
    Tree *T;//�����������
    Tree *p;
    Tree *c;
    int o,i,LR;
    ElemType value;
    kElemType e;
    char *definition;
    o=1;
    while(o){
        int op=1;
        printf("  ��������ĸ����������в�����1-99��������0�˳���\n");
        scanf("%d",&o);//������Ա��ʵ��
        if(o==0)
            break;//0ʱ�˳�
        else {
            if(o>99||o<0){
                printf("ѡ��ʧ�ܣ�\n");
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
                    printf("   ��ѡ����Ĳ���[0~16]:\n");
                    scanf("%d",&op);
                    switch(op){
                       case 1:
                         printf("��������������Ķ�����ǰ�������");
                         getchar();
                         scanf("%[^\n]",definition);
                         T=(Tree *)malloc(sizeof(Tree));
                         T->rchild=NULL;
                         T->key=0;
                         if(CreatBiTree(&(T->lchild),&definition)==OK)
                            printf("�����������ɹ���\n");
                         else
                            printf("����������ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 2:
                         if(DestroyBiTree(&T)==OK)
                            printf("���������ٳɹ���\n");
                         else
                            printf("����������ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(T!=NULL){
                            ClearBiTree(&(T->lchild));
                            printf("��ն�������\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(T!=NULL){
                             if(BiTreeEmpty(T)==TRUE)
                                printf("������Ϊ�գ�\n");
                             else
                                printf("��������Ϊ�գ�\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 5:
                         if(T!=NULL){
                             i=BiTreeDepth(T->lchild);
                             printf("�����������Ϊ%d��\n",i);
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(T!=NULL){
                             printf("��������ҵĽ��Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c",&e);
                             p=LocateNode(T,e);
                             if(p!=NULL){
                                printf("�ý��Ϊ��%c %c\n",p->key,p->data);
                             }
                             else
                                printf("�ý�㲻����\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(T!=NULL){
                             printf("��������Ҫ��ֵ�Ľ��Ĺؼ��ּ�������ֵ��\n");
                             getchar();
                             scanf("%c %c",&e,&value);
                             if(Assign(T,e,value)==OK)
                                printf("��ֵ�ɹ�\n");
                             else
                                printf("��ֵʧ��\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(T!=NULL){
                             printf("��������Ҫ������ֵܽ��Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c",&e);
                             p=GetSibling(T->lchild,e);
                             if(p!=NULL)
                                printf("��Ԫ�ص��ֵܽ��Ϊ%c %c",p->key,p->data);
                            else
                                printf("���ֵܽ��\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(T!=NULL){
                             c=(Tree*)malloc(sizeof(Tree));
                             printf("������Ҫ�����λ�õĹؼ��֡���(0)������(1)��Ҫ������Ĺؼ��֡����ݣ�\n");
                             getchar();
                             scanf("%c %d %c %c",&e,&LR,&(c->key),&(c->data));
                             if(InsertNode(T,e,LR,c)==OK)
                                printf("����ɹ���\n");
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(T!=NULL){
                             printf("��������Ҫɾ���Ľ��Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c",&e);
                             if(DeleteNode(T,e)==OK)
                                printf("ɾ���ɹ���\n");
                             else
                                printf("ɾ��ʧ�ܣ�\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(T!=NULL){
                             printf("ǰ�������\n");
                             PreOrderTraverse(T->lchild);
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(T!=NULL){
                             printf("���������\n");
                             InOrderTraverse(T->lchild);
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(T!=NULL){
                             printf("���������\n");
                             PostOrderTraverse(T->lchild);
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(T!=NULL){
                             printf("���������\n");
                             LevelOrderTraverse(T->lchild);
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 15:
                         if(T!=NULL){
                             if(Wirte(T)==OK)
                                printf("д��ɹ���\n");
                             else
                                printf("д��ʧ�ܣ�\n");
                         }
                         else
                            printf("�����������ڣ�\n");
                         getchar();getchar();
                         break;
                       case 16:
                         if(Read(&T)==OK)
                            printf("д��ɹ���\n");
                         else
                            printf("д��ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 0:
                         break;
                     }
                }//end of switch
            }
        }
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()


status CreatBiTree(Tree **T,kElemType **definition){//������������definitionΪ����
    if(**definition=='#'){//��㲻����
        (*T)=NULL;
        (*definition)++;
        return OK;
    }
    else{
        if(!((*T)=(Tree *)malloc(sizeof(Tree))))
           exit(OVERFLOW);
        else{
            (*T)->key=**definition;//���ؼ���
            (*T)->data='x';
            (*definition)++;
            CreatBiTree(&((*T)->lchild),definition);
            CreatBiTree(&((*T)->rchild),definition);
        }
    }
    return OK;
}

status DestroyBiTree(Tree **T){//���ٶ�����T
    Tree *p=*T;
    ClearBiTree(T);
	free(p);
	(*T)=NULL;
	return OK;
}

status ClearBiTree(Tree **T){//�����������
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

status BiTreeEmpty(Tree *T){//�ж�T�Ƿ�Ϊ��
    if(T->lchild==NULL)
        return TRUE;
    else
        return FALSE;
}

status BiTreeDepth(Tree *T){//����T���
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

Tree* LocateNode(Tree *T,kElemType e){//���ҽ��
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

status Assign(Tree *T,kElemType e,ElemType value){//�ҵ��ؼ���Ϊe�Ľ�㲢��ֵ
    Tree *p;
    p=LocateNode(T,e);
    if(p!=NULL){
        p->data=value;
        return OK;
    }
    else
        return ERROR;
}

status parents(Tree *T,kElemType e){//Ѱ�ҹؼ���Ϊe�ĸ�ĸ���
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

status GetSibling(Tree *T,kElemType e){//Ѱ�ҹؼ���Ϊe���ֵܽ��
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

status InsertNode(Tree *T,kElemType e,int LR,Tree *c){//�ڹؼ���Ϊe�Ľ��������
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

status DeleteNode(Tree *T,kElemType e){//��ɾ���ؼ���Ϊe�Ľ��
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

status Deletel(Tree *T){//ɾ�����
    Tree *p;
    Tree *q;
    Tree *t;
    q=T;
    p=T->lchild;
    t=p->lchild;
    if(p->lchild==NULL){
        if(p->rchild==NULL){//����Ϊ0
            T->lchild=NULL;
            return OK;
        }
        else{
            p=p->rchild;//����Ϊ1����������
            q->lchild=p;
            return OK;
        }
    }
    else{
        if(p->rchild==NULL){//����Ϊ1����������
            p=p->lchild;
            q->lchild=p;
            return OK;
        }
        else{//����Ϊ2
            while(t->rchild!=NULL)
                t=t->rchild;
            t->rchild=p->rchild;
            p=p->lchild;
            q->lchild=p;
            return OK;
        }
    }
}

status Deleter(Tree *T){//ɾ�����
    Tree *p;
    Tree *q;
    Tree *t;
    q=T;
    p=T->rchild;
    if(p->lchild==NULL){
        if(p->rchild==NULL){//����Ϊ0
            T->rchild=NULL;
            return OK;
        }
        else{
            p=p->rchild;//����Ϊ1����������
            q->rchild=p;
            return OK;
        }
    }
    else{
        if(p->rchild==NULL){//����Ϊ1����������
            p=p->lchild;
            q->rchild=p;
            return OK;
        }
        else{//����Ϊ2
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
    //д�ļ��ķ���
    TreeWrite(T->lchild,fp);//����������,д���ļ�
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
    //���ļ��ķ���
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    (*T)=(Tree *)malloc(sizeof(Tree));//����ͷ���
    (*T)->rchild=NULL;
    (*T)->key=0;
    while(fread(&single,sizeof(ElemType),1,fp))
        tree[i++]=single;
    tree[i]='#';
    Arch=0;
    TreeRead(&((*T)->lchild),&tree);//������ļ��������ȡ����Ԫ�ػָ�������
	fclose(fp);
    return OK;
}


status TreeRead(Tree **T,char *definition){//��һ��д�� 
    if(definition[Arch]=='#')
        return OK;
    if(definition[Arch]==' '){//��㲻����
        (*T)=NULL;
        Arch++;
    }
    else{
        if(!((*T)=(Tree *)malloc(sizeof(Tree))))
           exit(OVERFLOW);
        else{
            (*T)->key=definition[Arch];//���ؼ���
            Arch++;
            (*T)->data=definition[Arch];
            Arch++;
            TreeRead(&((*T)->lchild),definition);
            TreeRead(&((*T)->rchild),definition);
        }
    }
    return OK;
}


/*�ڶ���д�� 
status TreeRead(Tree **T,char *definition){
   if(*definition=='#')
        return OK;
    if(*definition==' '){//��㲻����
        (*T)=NULL;
        definition++;
    }
    else{
        if(!((*T)=(Tree *)malloc(sizeof(Tree))))
           exit(OVERFLOW);
        else{
            (*T)->key=*definition;//���ؼ���
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
